We provide two types of datasets: 1) short sequence pairs (100bp and 250bp long) & 2) long sequence pairs (10Kbp and 100Kbp long).

## Short sequence pairs (100bp and 250bp long)
The short read-reference pair sets are generated using mrFAST by mapping the following datasets to the human reference genome (GRCh37):
1. https://www.ebi.ac.uk/ena/data/view/ERR240727
2. https://www.ebi.ac.uk/ena/data/view/SRR826471

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
./mrfast-2.6.1.0/mrfast --search ../human_g1k_v37.fasta --seq ../ERR240727_1.fastq -e 2 | awk -F'\t' '{ if (substr($2,1,1) ~ /^[A,C,G,T]/ ) print $0}' | head -n 30000 > ERR240727_1_E2_30000Pairs.txt
```

You can download the human reference genome from here: 
```
ftp://ftp.ncbi.nlm.nih.gov/1000genomes/ftp/technical/reference/human_g1k_v37.fasta.gz
```
Or a more recent assembly from here:
```
https://www.ncbi.nlm.nih.gov/assembly?term=GRCh38&cmd=DetailsSearch
```
Above, we only provide the first 30,000 read-reference pairs of each dataset we used in this work, due to a maximum file size restriction of 25 MB. Please feel free to contact us to get the complete datasets. 


## Long sequence pairs (10Kbp and 100Kbp long)
We use [PBSIM](https://github.com/pfaucon/PBSIM-PacBio-Simulator) to simulate long sequence pairs. This simulator already provides read-ref pairs; a simulated read along with its original segment on the reference genome. We use the [first chromosome of Human genome](https://www.ncbi.nlm.nih.gov/nuccore/NC_000001.1) as PBSIM's reference gneome. We use the following command lines to generate the two datasets using the default error count and distribution.

```
/PBSIM-PacBio-Simulator/src/pbsim --data-type CLR --depth 30 --prefix LongSequences_10K_PBSIM --length-max 10000 --length-min 10000 --model_qc /PBSIM-PacBio-Simulator/data/model_qc_clr --length-mean 10000 NC_000001_11_Chromosome1.fasta

/PBSIM-PacBio-Simulator/src/pbsim --data-type CLR --depth 30 --prefix LongSequences_100K_PBSIM --length-max 100000 --length-min 100000 --model_qc /PBSIM-PacBio-Simulator/data/model_qc_clr --length-mean 100000 NC_000001_11_Chromosome1.fasta
```

