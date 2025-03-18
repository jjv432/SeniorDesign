# Arduino OPTA PLC

This repository was developed to satisfy the requirements of the Mechanical Engineering Senior Design course at the FAMU-FSU College of Engineering by Team 519. 
Team 519 was tasked with developing curriculum for the Introduction to Mechatronics course to enable students to learn how to use PLCs. In this repository, there 
are a number of learning tools, including MATLAB simulation tools, instructions on using OpenPLC, wiring diagrams, and lab designs and solutions.


## Table of Contents


<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>

	
## Background

PLC's were developed to replace physical relays. Previously, rewiring relays was a time consuming process that led to waste as boards would frequently be thrown 
away instead of repurposed. Now, PLCs are used widely in industrial settings as they provide flexibile and robust programming of industrial equipment.

## Install

This project uses OpenPLC and MATLAB

### 1. Download OpenPLC

See [OpenPLC Download Page](https://autonomylogic.com/download) to download this software.

It is not recommended to use the Arduino PLC IDE as it has demonstrated worse compatability and insufficient error-correcting documentation.
### 2. Download MATLAB

See [MATLAB Download Page](https://www.mathworks.com/help/install/ug/install-products-with-internet-connection.html) to download MATLAB if you have not already.

#### 2.a. Packages

You will need to download [Simulink](https://www.mathworks.com/products/simulink.html)

You will need to download the [Simulink PLC Coder](https://www.mathworks.com/help//releases/R2021a/plccoder/index.html?s_tid=CRUX_lftnav) package to run the MATLAB simulations of Ladder Diagrams.

### 3. Download Arduino IDE

You will need to download the Arduino IDE in order to [partition the memory](https://autonomylogic.com/docs/2-4-physical-addressing/). Follow the steps at the 
provided link to partition the memory on the PLC, a step that is necessary to allow Arduino sketches and Ladder Logic sketches to exist simultaneously. This is 
useful as it allows us to use Arduino packages such as _LiquidCrystalI2c_.

## Usage

### MATLAB: Simulations

The MATLAB simulations are used to provide students an oppurtunity to learn ladder logic without being concerned about using or damaging hardware. A number of 
objects and functions have been included to make the simulation as straight-forward as possible.

For Lab 1, only the simulation tools will be used. For Labs 2 and 3, students may choose to use the simulation to debug their logic, but it is not required.


There are a number of useful functions provided to make the process of 
learning ladder logic smoother. All of these exist in [this](MATLAB/MATLAB_Functions) folder.

See the [Matlab Functions Readme](MATLAB/README.md) to understand the functions that have been provided for using Simulink.


### Open PLC Coding

Review the [Open PLC Readme](OpenPLCFolders/README.md) to get started with OpenPLC.

OpenPLC is the IDE that will be used to program the PLCs. Examples are provided for Ladder Logic diagrams that can be used as Solutions to Labs 2 and 3.


## Lab Setups

Lab 1: Simulation lab using only the simulation tools that we have developed in MATLAB [manual](Resources/LabManuals/Lab1Manual.txt)

Lab 2: Conveyor actuation lab using two buttons and the OPTA. [manual](Resources/LabManuals/Lab2Manual.txt)


Lab 3: Competition between user and PLC for pushing boxes off of the conveyor belt. [manual](Resources/LabManuals/Lab3Manual.txt)

## Helpful Links

[Open PLC Manual](https://autonomylogic.com/docs/openplc-overview/)

[Memory Partitioning](https://docs.arduino.cc/tutorials/opta/memory-partitioning/)

[Arduino OPTA User Manual](https://docs.arduino.cc/tutorials/opta/user-manual/)

[Arduino OPTA Memory Addresses](https://autonomylogic.com/docs/2-4-physical-addressing/)

[Getting Started with OPTA](https://opta.findernet.com/en/tutorial/getting-started)

## Troubleshooting

__Error:__

```
Failed uploading: uploading error: exit status 74

```
__Solution:__

Press the 'reset' button on the top of the OPTA. You will need to use a pen or something thin to access the button.

__Error:__

```
Unrecognized function or variable 'BOOL'

```
__Solution:__

The PLC types required have not been loaded. Run: 
```
>> plcloadtypes
```

## License
[MIT](LICENSE) © Jack Vranicar

