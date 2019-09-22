## Instructions:

```
make
./Snake-on-GPU 100 ../Datasets/ERR240727_1_E2_30million.txt 30000 
./Snake-on-GPU [ReadLength] [ReadandRefFile] [#reads]
```

## Output [DebugMode OFF]:
```
./Snake-on-GPU `head -n 1 ../Datasets/ERR240727_1_E2_30million.txt | awk '{print length($1)}'`  ../Datasets/ERR240727_1_E2_30million.txt  `wc -l  ../Datasets/ERR240727_1_E2_30million.txt|awk '{print $1}'`
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 0 	 Snake-on-GPU: 	 0.1071 	 Accepted: 	          8 	 Rejected: 	       2992
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 1 	 Snake-on-GPU: 	 0.0898 	 Accepted: 	         18 	 Rejected: 	       2982
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 2 	 Snake-on-GPU: 	 0.0939 	 Accepted: 	         23 	 Rejected: 	       2977
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 3 	 Snake-on-GPU: 	 0.1154 	 Accepted: 	         25 	 Rejected: 	       2975
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 4 	 Snake-on-GPU: 	 0.1305 	 Accepted: 	         41 	 Rejected: 	       2959
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 5 	 Snake-on-GPU: 	 0.1452 	 Accepted: 	         90 	 Rejected: 	       2910
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 6 	 Snake-on-GPU: 	 0.2435 	 Accepted: 	        247 	 Rejected: 	       2753
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 7 	 Snake-on-GPU: 	 0.1800 	 Accepted: 	        467 	 Rejected: 	       2533
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 8 	 Snake-on-GPU: 	 0.2652 	 Accepted: 	        786 	 Rejected: 	       2214
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 9 	 Snake-on-GPU: 	 0.2467 	 Accepted: 	       1142 	 Rejected: 	       1858
GPU Device 0: "TITAN V" with compute capability 7.0

E: 	 10 	 Snake-on-GPU: 	 0.2715 	 Accepted: 	       1434 	 Rejected: 	       1566
