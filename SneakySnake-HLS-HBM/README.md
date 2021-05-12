# HLS_HBM_SNEAKY

* Performs pre-alignment filtering step of the genome pipeline:
  * Data is moved from the HOST memory to the HBM memory on the FPGA board
  * Read and reference sequences are processed on the FPGA
  * Data is sent back to the HOST memory


* The code is organized in three main directories:

*  hw: The application code that is used for generating the programming file for the FPGA with the use of OC-ACCEL framework and Xilinx Vivado HLS tool.

* sw: The application code part running on host (POWER9): Reading of input dataset files stored on disk, preparing of WED struct, feeding of image data to FPGA with DMA, reading of results from FPGA.

*  include: The place of common code for the two subsystems (host & fpga). It includes header files with i) application parameters, ii) compilation parameters and iii) runtime parameters.


# Dependencies


* OC-ACCEL
The HLS_HBM_SNEAKY example has been developed with [OC-ACCEL framework](https://github.com/OpenCAPI/oc-accel). As such, it inherits the files hierarchy and coding style of this framework.

* Xilinx Vivado
The code has been tested with Xilinx Vivado 2019.2 up to 2020.1

* PSL (CAPI module on FPGA)
Access to CAPI from the FPGA card requires the Power Service Layer (PSL).

* Build process
The HLS_HBM_SNEAKY example can be directly cloned into OC-ACCEL's example directory. Building the code and running the make environment requires the usual development tools gcc, make, sed, awk.  
