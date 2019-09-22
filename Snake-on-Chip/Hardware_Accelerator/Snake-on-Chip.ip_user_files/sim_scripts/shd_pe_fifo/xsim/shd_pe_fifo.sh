#!/bin/bash -f
# Vivado (TM) v2015.4 (64-bit)
#
# Filename    : shd_pe_fifo.sh
# Simulator   : Xilinx Vivado Simulator
# Description : Simulation script for compiling, elaborating and verifying the project source files.
#               The script will automatically create the design libraries sub-directories in the run
#               directory, add the library logical mappings in the simulator setup file, create default
#               'do/prj' file, execute compilation, elaboration and simulation steps.
#
# Generated by Vivado on Wed Jul 18 20:00:34 +0300 2018
# IP Build 1412160 on Tue Nov 17 13:47:24 MST 2015 
#
# usage: shd_pe_fifo.sh [-help]
# usage: shd_pe_fifo.sh [-lib_map_path]
# usage: shd_pe_fifo.sh [-noclean_files]
# usage: shd_pe_fifo.sh [-reset_run]
#
# ********************************************************************************************************

# Script info
echo -e "shd_pe_fifo.sh - Script generated by export_simulation (Vivado v2015.4 (64-bit)-id)\n"

# Script usage
usage()
{
  msg="Usage: shd_pe_fifo.sh [-help]\n\
Usage: shd_pe_fifo.sh [-lib_map_path]\n\
Usage: shd_pe_fifo.sh [-reset_run]\n\
Usage: shd_pe_fifo.sh [-noclean_files]\n\n\
[-help] -- Print help information for this script\n\n\
[-lib_map_path <path>] -- Compiled simulation library directory path. The simulation library is compiled\n\
using the compile_simlib tcl command. Please see 'compile_simlib -help' for more information.\n\n\
[-reset_run] -- Recreate simulator setup files and library mappings for a clean run. The generated files\n\
from the previous run will be removed. If you don't want to remove the simulator generated files, use the\n\
-noclean_files switch.\n\n\
[-noclean_files] -- Reset previous run, but do not remove simulator generated files from the previous run.\n\n"
  echo -e $msg
  exit 1
}

if [[ ($# == 1 ) && ($1 != "-lib_map_path" && $1 != "-noclean_files" && $1 != "-reset_run" && $1 != "-help" && $1 != "-h") ]]; then
  echo -e "ERROR: Unknown option specified '$1' (type \"./shd_pe_fifo.sh -help\" for more information)\n"
  exit 1
fi

if [[ ($1 == "-help" || $1 == "-h") ]]; then
  usage
fi

# STEP: setup
setup()
{
  case $1 in
    "-lib_map_path" )
      if [[ ($2 == "") ]]; then
        echo -e "ERROR: Simulation library directory path not specified (type \"./shd_pe_fifo.sh -help\" for more information)\n"
        exit 1
      fi
      # precompiled simulation library directory path
    ;;
    "-reset_run" )
      reset_run
      echo -e "INFO: Simulation run files deleted.\n"
      exit 0
    ;;
    "-noclean_files" )
      # do not remove previous data
    ;;
    * )
  esac

  # Add any setup/initialization commands here:-

  # <user specific commands>

}

# Remove generated data from the previous run and re-create setup files/library mappings
reset_run()
{
  files_to_remove=(xelab.pb xsim.jou xvhdl.log xvlog.log compile.log elaborate.log simulate.log xelab.log xsim.log run.log xvhdl.pb xvlog.pb shd_pe_fifo.wdb xsim.dir)
  for (( i=0; i<${#files_to_remove[*]}; i++ )); do
    file="${files_to_remove[i]}"
    if [[ -e $file ]]; then
      rm -rf $file
    fi
  done
}

# Main steps
run()
{
  setup $1 $2
  compile
  elaborate
  simulate
}


# RUN_STEP: <compile>
compile()
{
  # Command line options
  opts_vhd="-m64 --relax"

  # Compile design files
  xvhdl $opts_vhd -prj vhdl.prj 2>&1 | tee compile.log

}

# RUN_STEP: <elaborate>
elaborate()
{
  xelab --relax --debug typical --mt auto -wto c8de24a6f19148128a87cb40682a2a02 -m64 -L fifo_generator_v13_0_1 -L xil_defaultlib -L secureip --snapshot shd_pe_fifo xil_defaultlib.shd_pe_fifo -log elaborate.log
}

# RUN_STEP: <simulate>
simulate()
{
  xsim shd_pe_fifo -key {Behavioral:sim_1:Functional:shd_pe_fifo} -tclbatch cmd.tcl -log simulate.log
}
# Script usage
usage()
{
  msg="Usage: shd_pe_fifo.sh [-help]\n\
Usage: shd_pe_fifo.sh [-lib_map_path]\n\
Usage: shd_pe_fifo.sh [-reset_run]\n\
Usage: shd_pe_fifo.sh [-noclean_files]\n\n\
[-help] -- Print help information for this script\n\n\
[-lib_map_path <path>] -- Compiled simulation library directory path. The simulation library is compiled\n\
using the compile_simlib tcl command. Please see 'compile_simlib -help' for more information.\n\n\
[-reset_run] -- Recreate simulator setup files and library mappings for a clean run. The generated files\n\
from the previous run will be removed. If you don't want to remove the simulator generated files, use the\n\
-noclean_files switch.\n\n\
[-noclean_files] -- Reset previous run, but do not remove simulator generated files from the previous run.\n\n"
  echo -e $msg
  exit 1
}


# Launch script
run $1 $2
