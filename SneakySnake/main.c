/*
 * Copyright (c) <2017 - 2030>, ETH Zurich and Bilkent University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list
 * of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or other
 *   materials provided with the distribution.
 * - Neither the names of the ETH Zurich, Bilkent University,
 *   nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without specific
 *   prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  Authors: 
  Mohammed Alser
	  mohammed.alser AT inf DOT ethz DOT ch
  Date:
  September 22nd, 2019
*/


/* Include Files */
#include "stdio.h" 
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <immintrin.h>
#include "SneakySnake.h"

/* to compile type the following 
sudo ldconfig -v
gcc -g -O3 -Wall -o main *.c -lz -lm 
./main 0 100 100 100 ../Datasets/ERR240727_1_E2_30million.txt 3000
OR: use the following to check the memory leaks
valgrind --leak-check=yes --show-leak-kinds=all ./main
*/

void cudaCheckError(cudaError_t cudaStatus, char* err)
{
    if(cudaStatus != cudaSuccess)
    {
        fprintf(stderr, err);
        cudaDeviceReset();
       exit(EXIT_FAILURE);
    }
}

int main(int argc, const char * const argv[]) {
	//(void)argc;
	//(void)argv;

	/*int DebugMode=0;
	int KmerSize=100;
	int ReadLength = 100; 
	int IterationNo =100;
	*/
	if (argc!=7){
		printf("missing argument..\n./main [DebugMode] [KmerSize] [ReadLength] [IterationNo] [ReadRefFile] [# of reads]\n");
		exit(-1);
	}
	int DebugMode=atoi(argv[1]);
	int KmerSize=atoi(argv[2]);
	int ReadLength = atoi(argv[3]);
	int IterationNo = atoi(argv[4]); 

	int n;
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char *p;
	int j,i;
	int loopPar;
	char RefSeq[ReadLength] ;
	char ReadSeq[ReadLength];
	int EditThreshold;
	int Accepted1;
	int FP1;
	int FN1;
	clock_t begin1;
	clock_t end1;
	double time1;
	double time_spent1;
        printf("Edit Distance \t CPU Time(seconds) \t Alignment_Needed \t Not_Needed \n");
	printf("Threshold \n");
	for (loopPar =0; loopPar<=10;loopPar++) {
		EditThreshold=(loopPar*ReadLength)/100;
		//printf("\n<-------------------Levenshtein Distance = %d------------------->\n", EditThreshold);

		FP1=0;
		FN1=0;
		time1= 0;
		//fp = fopen("/home/alser-xilinx/Desktop/Filters_29_11_2016/ReadRef_39999914_pairs_ERR240727_1_with_NW_2017.fastq", "r");

		fp = fopen(argv[5], "r");
		if (!fp){
			printf("Sorry, the file does not exist or you do not have access permission\n");
		}
		else {
			for (i = 1; i <= atoi(argv[6]); i++) {
				read = getline(&line, &len, fp);
				j=1;
				for (p = strtok(line, "\t"); p != NULL; p = strtok(NULL, "\t")) {
					if (j==1){
						for (n = 0; n < ReadLength; n++) {
							ReadSeq[n]= p[n];
							//printf("%c",ReadSeq[n]);
						}
						//printf(" ");
					}
					else if (j==2){
						for (n = 0; n < ReadLength; n++) {
							RefSeq[n]= p[n];
							//printf("%c",RefSeq[n]);
						}
						//printf("\n");
					}
					j=j+1;
				}		  

				begin1 = clock();
				Accepted1 = SneakySnake(ReadLength, RefSeq, ReadSeq, EditThreshold, KmerSize, DebugMode, IterationNo);
				/*if (Accepted1==1){
					EdlibAlignResult resultEdlib1 = edlibAlign(RefSeq, ReadLength, ReadSeq, ReadLength, edlibNewAlignConfig(EditThreshold, EDLIB_MODE_NW, EDLIB_TASK_PATH, NULL, 0)); // with alignment
					edlibFreeAlignResult(resultEdlib1);
				}*/
				end1 = clock();

				
				
				/////////////////////////////////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////////////////////////////////


				//NWAccepted = Accepted8;

				if (Accepted1==0  ){//&& NWAccepted==1
					FN1++;
					//SneakySnake(ReadLength, RefSeq, ReadSeq, EditThreshold, KmerSize, 1, IterationNo);
				}
				else if (Accepted1==1 ){//&& NWAccepted==0){
					FP1++;		
				}

				time1 = time1 + (end1 - begin1);
			}

			time_spent1 = (double)time1 / CLOCKS_PER_SEC;

			//printf("Fastest implementation of Myers’s bit-vector algorithm (Edlib 2017):\n");
			//printf("CPU Time(seconds): %5.4f,    Accepted Mapping: %d,    Rejected Mapping: %d\n", time_spent8, FP8,FN8);
			//printf("----------------------------------------------------------------- \n");
			//printf("Filter Name \t    CPU Time(seconds) \t\t FPs# \t FNs# \n");
			printf(" %d \t\t %5.4f \t %10d \t %d\n", EditThreshold, time_spent1, FP1,FN1);


			fclose(fp);
		}
	}
	return 0;
}
