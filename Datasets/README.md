read-reference pair sets are generated using mrFAST by mapping the following datasets to the human reference genome (GRCh37):
1. https://www.ebi.ac.uk/ena/data/view/ERR240727
2. https://www.ebi.ac.uk/ena/data/view/SRR826460
3. https://www.ebi.ac.uk/ena/data/view/SRR826471

To generate these datasets, you need to extract the read-reference pairs using mrFAST by doing the following two steps:

1. Add the following to line 1786 of https://github.com/BilkentCompGen/mrfast/blob/master/MrFAST.c 
	
```
//Extract reference segment:
for (n = 0; n < 100; n++) 
  printf(“%d”, _msf_refGen[n + genLoc + _msf_refGenOffset - 1 - leftSeqLength]);
  
//Extract read sequence:
printf("\t%s\n", _tmpSeq);
```

2. Use the following command to capture the read-reference pairs:
```
./mrfast-2.6.1.0/mrfast --search ../human_g1k_v37.fasta --seq ../ERR240727_1.filt.fastq -e 2 | awk -F'\t' '{ if (substr($2,1,1) ~ /^[A,C,G,T]/ ) print $0}' |head -n 30000000 > ../../ERR240727_1_E1_50million_new2.txt
```

You can download the human reference genome from here: 
```
ftp://ftp.ncbi.nlm.nih.gov/1000genomes/ftp/technical/reference/human_g1k_v37.fasta.gz
```
Or a more recent assembly from here:
```
https://www.ncbi.nlm.nih.gov/assembly?term=GRCh38&cmd=DetailsSearch
```
Above, we only provide sample of the 4 read-reference sets generated from Illumina 100 bp reads. 
