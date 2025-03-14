# Arduino OPTA PLC

This repository was developed to satisfy the requirements of the Mechanical Engineering Senior Design course at the FAMU-FSU College of Engineering by Team 519. 
Team 519 was tasked with developing curriculum for the Introduction to Mechatronics course to enable students to learn how to use PLCs. In this repository, there 
are a number of learning tools, including MATLAB simulation tools, instructions on using OpenPLC, wiring diagrams, and lab designs and solutions.


## Table of Contents

- [Background](#background)
- [Install](#install)
  * [1. Download OpenPLC](#1-download-openplc)
  * [2. Download MATLAB](#2-download-matlab)
    + [2.a. Packages](#2a-packages)
  * [3. Download Arduino IDE](#3-download-arduino-ide)
- [Usage](#usage)
  * [MATLAB: Simulations](#matlab--simulations)
  * [Open PLC Coding](#open-plc-coding)
- [MATLAB Functions](#matlab-functions)
  * [edit_simulink_plc.m](#edit-simulink-plcm)
  * [run_simulink_plc.m;](#run-simulink-plcm-)
- [MATLAB Objects](#matlab-objects)
  * [box.m](#boxm)
  * [LED.m](#ledm)
  * [motor.m](#motorm)
  * [conveyor_assembly.m](#conveyor-assemblym)
- [Lab Setups](#lab-setups)
- [Helpful Links](#helpful-links)
- [Troubleshooting](#troubleshooting)
- [License](#license)

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
useful as it allows us to use Arduino packages such as LiquidCrystalI2c.

## Usage

### MATLAB: Simulations

The MATLAB simulations are used to provide students an oppurtunity to learn ladder logic without being being concerned about using or damaging hardware. A number of 
objects have been included to make the simulation as straight-forward as possible.

This simulation is meant to be used for Lab 1.


### Open PLC Coding

Examples are provided for Ladder Logic diagrams that can be used as Solutions to Labs 1 and 2.

INSERT EXAMPLE LINKS ON CONNECTIONS AND PROGRAMMING


## MATLAB Functions

There are a number of useful functions and objects provided to make the process of 
learning ladder logic smoother. All of these exist in the _src_ folder of this repo.

### edit_simulink_plc.m
```
>> edit_simulink_plc(<FILENAME>);
```
 __Overview__: This function helps in editing a simulink PLC simulation by: 
running the _plcloadtypes_ command which is necessary for the Ladder Logic to 
execute; opens the Simulink PLC Ladder Library, which contains all of the PLC 
Simulink blocks; and opens or a creates a Simulink file called <FILENAME>.

__Inputs__: A filename, either of an already existing Simulink file in the current 
directory, or the name of a new Simulink file (if that filename is not already being 
used in the current directory).

__Outputs__: N/a

### run_simulink_plc.m;
```
>> <OUT> = run_simulink_plc(<FILENAME>);
```

 __Overview__: This function helps in running a simulink PLC simulation by: running 
the _plcloadtypes_ command which is necessary for the Ladder Logic to execute; opens 
the Simulink PLC Ladder Library, which contains all of the PLC Simulink blocks; and 
runs a Simulink file called <FILENAME>. If <FILENAME> does not exist in the 
currently directory, the user will be prompted to edit the file, similar to _edit_ 
_simulink_ _plc_.

__Inputs__: A filename, either of an already existing Simulink file in the current 
directory, or the name of a new Simulink file (if that filename is not already being 
used in the current directory).

__Outputs__: If created in the Simulink file, the 'out' structure that is generated 
using a "to workspace" block in the highest level of the PLC Simulation.

## MATLAB Objects 

There are also some MATLAB objects that are provided to allow for ease of simulation 
using Simulink. These objects provide a way to animate the outputs of the Simulink 
file.

Notes: for an object, _methods_ are functions that the object can complete. For 
example, this could be turning on and off the LED for the LED object. _Properties_ 
are characteristics of the object that the object stores. A simple example of this 
would be X-Position.

### box.m
 __Overview__:

 __Methods__:

 __Properties__:

### LED.m
 __Overview__:

 __Methods__:

 __Properties__:

### motor.m
 __Overview__:

 __Methods__:

 __Properties__:

### conveyor_assembly.m
 __Overview__:

 __Methods__:

 __Properties__:


## Lab Setups

Lab 1: Simulation lab using only the simulation tools that we have developed in MATLAB [manual](Resources/LabManuals/Lab1Manual.txt)

Lab 2: Conveyor actuation lab using two buttons and the OPTA. [manual](Resources/LabManuals/Lab2Manual.txt)


Lab 3: Competition between user and PLC for pushing boxes off of the conveyor belt. [manual](Resources/LabManuals/Lab3Manual.txt)

## Helpful Links

[Open PLC Manual](https://autonomylogic.com/docs/openplc-overview/)

[Memory Partitioning](https://docs.arduino.cc/tutorials/opta/memory-partitioning/)

[Arduino OPTA User Manual](https://docs.arduino.cc/tutorials/opta/user-manual/)

[Arduino OPTA Memory Addresses](https://autonomylogic.com/docs/2-4-physical-addressing/)
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

