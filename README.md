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
useful as it allows us to use Arduino packages such as _LiquidCrystalI2c_.

## Usage

### MATLAB: Simulations

The MATLAB simulations are used to provide students an oppurtunity to learn ladder logic without being concerned about using or damaging hardware. A number of 
objects and functions have been included to make the simulation as straight-forward as possible.

For Lab 1, only the simulation tools will be used. For Labs 2 and 3, students may choose to use the simulation to debug their logic, but it is not required.


### Open PLC Coding

Examples are provided for Ladder Logic diagrams that can be used as Solutions to Labs 2 and 3.

Follow these steps to begin programming with Open PLC, as well as reviewing the [Open PLC Manual.](https://autonomylogic.com/docs/openplc-overview/)

#### 1. Start Open PLC

#### 2. Create a new file
At the top right of the IDE, select the "New" button, denoted by a sheet with a green + sign. This will prompt you to select a folder that you want the project to 
exist in. Create the folder, then click 'Select Folder.' 

Once you've done this, a pop-up window will appear titled 'Create a new POU.' Name the program whatever you'd like, then select the language you'd like the program 
to be in (IL: Instruction List, ST: Structured Text, __LD__: Ladder Diagram, FBD: Function Block Diagram, or SFC: Sequential Function Chart). Select LD, then click 'OK.'

#### 3. Add symbols to the Ladder Diagram
In the file tree on the right of the window, double click on the program that you just created. You should see a dot matrix in the middle of the screen. This is 
where you can begin you ladder diagram.

First, you will need to add in the power and ground rails. All of the symbols for the Ladder are in the top of the window, and are to the right of the block that 
says "CMT." Click the first symbol to the right of the "CMT" block, then click into the dot-matrix. Once the pop-up appears, we can select Left (Positive) or Right 
(Ground) PowerRails. Also, we can select the number of pins. Let's start with 2, and create a left and right power rail parallel to each other by completing this 
process twice. You can click on the rails and then drag then to reposition.

Next, add an input to your system. This symbol looks like two parallel lines with the word 'var' above it. Click this symbol, then click into the dot matrix to 
place the input symbol. Use the 'Normal' modifier, and call the variable 'my_input.'

Now, add an output to the diagram using the output symbol, the two curved lines with the word 'var' above it. Call this 'my_output'.

#### 5. Define your variables
In the same window, above the dot matrix, there is a table. This is where we must define the variables that we just referenced in the diagram. To do this, click the 
green plus at the top of the window. Adjust the name, leave class as 'local', change the type to BOOL (Type > Base Types > Bool), and set the initial value to 0.

#### 6. 'Wire' the diagram
To connect the symbols, click and drag between the terminals that you want to connect. For this example connect the Left PowerRail to the input, the input to the 
output, then the output to the Right PowerRail. 

#### 7. Test the program 
OpenPLC allows you to simulate your system. To do this, click the symbol at the top of the screen that looks like a blue person running. This will compile and begin 
a simulation of your system. You will know the simulation is running when the blue-runner symbol is replaced by a stop sign.

On the right-hand-side of the screen, click the sunglasses next to the drop-down window named something like: "Config0.Res0.instance0". This will begin a debugging 
instance. You should now be able to see that wires that are energized are highlighted green.

Now, we can force values to be true of false. Right click the center of the 'my\_\input' symbol, and select 'Force True.' You should now see that 'my\_\output' is 
highlighted green, signifying that it is on. To set the input back to its normal behavior, right click the symbol and select 'Release Value'.

<<<<<<< HEAD
#### 8. Upload the progam

At this point, you should see something that looks like this: 

<img width="959" alt="OpenPLC_Example" src="https://github.com/user-attachments/assets/771a0a71-793c-4f5d-ad99-97c2ae133df6" />

ADJUST IO TO SHOW HOW TO USE THE USER BUTTON, ADDRESSES, AND LEDs

INSERT EXAMPLE LINKS ON CONNECTIONS AND PROGRAMMING

>[!WARNING]
> The inputs and user button of the PLC will operate properly when only provided power via a USB-C cable. However, to use the relay outputs, the PLC _must_ be 
> connected to 12-24V at it's power input terminals.

## MATLAB Functions

There are a number of useful functions provided to make the process of 
learning ladder logic smoother. All of these exist in the _src_ folder of this repo.

### edit_simulink_plc.m
```
>> edit_simulink_plc(<FILENAME>);
```
 __Overview__: This function helps in editing a Simulink PLC simulation by: 
running the _plcloadtypes_ command which is necessary for the Ladder Logic to 
execute; opens the Simulink PLC Ladder Library, which contains all of the PLC 
Simulink blocks; and opens or a creates a Simulink file called \<FILENAME>\.

__Inputs__: A filename, either of an already existing Simulink file in the current 
directory, or the name of a new Simulink file (if that filename is not already being 
used in the current directory).

__Outputs__: N/a

### run_simulink_plc.m
```
>> <OUT> = run_simulink_plc(<FILENAME>);
```

 __Overview__: This function helps in running a simulink PLC simulation by: running 
the _plcloadtypes_ command which is necessary for the Ladder Logic to execute; opens 
the Simulink PLC Ladder Library, which contains all of the PLC Simulink blocks; and 
runs a Simulink file called \<FILENAME\>. If \<FILENAME\> does not exist in the 
currently directory, the user will be prompted to edit the file, similar to *edit_simulink_plc*.

__Inputs__: A filename, either of an already existing Simulink file in the current 
directory, or the name of a new Simulink file (if that filename is not already being 
used in the current directory).

__Outputs__: If created in the Simulink file, the "out" structure that is generated 
using a "to workspace" block in the highest level of the PLC Simulation.

## MATLAB Objects 

There are also some MATLAB objects that are provided to allow for ease of simulation 
using Simulink. These objects provide a way to animate the outputs of the Simulink 
file.

>[!NOTE]
> For an object, _methods_ are functions that the object can complete. For example, this could be turning on and off the LED for the LED object. _Properties_ are 
>characteristics of the object that the object stores. A simple example of this would be X-Position. Both methods and properties are accesses via dot notation. A 
>_constructor_ is used to initialize an object. See the course [Object-Oriented Programming in 
>MATLAB](https://www.mathworks.com/products/matlab/object-oriented-programming.html) or the tutorial [Introduction to Object-Oriented Programming in 
>MATLAB](https://www.mathworks.com/company/technical-articles/introduction-to-object-oriented-programming-in-matlab.html) for more.

### box.m
 __Overview__:

The _box_ object is used to animate the motion of a 2D box on a conveyor belt. 

__Constructor__:

A box object can be created as follows: 

```
>> <Example_Box> = box(<HEIGHT>, <WIDTH>, <Initial_X_Position>, <Initial_Y_Position>);
```
 __Methods__:

Assuming we have a _Box_ object called _b_:

```
>> b.draw_box(); 
```
Generates the _figure_ property and plots it.

```
>> b.move_box(<dt>, <velocity_x>, <velocity_y>);
```

Updates the position of a box moving at *velocity_x* and *velocity_y* after *dt* seconds. The previous *figure* property is deleted and replaced by the updated 
 version, then plotted. This method lends itself to use within a for-loop to achieve smooth animations.

```
>> b.push_box(<direction>, <dt>);
```

Creates an animation of the box being pushed off the conveyor belt, then falling down. _dt_ is the change in time between updating the box position, and direction 
 is if the box gets pushed forward (1) or backward (-1).

__Properties__:

_Box_ objects have these properties: *Height*, *Width*, *X_Coordinates* (of the corners of the box), *Y_Coordinates* (of the corners of the box), *X_Position* (of 
the XXXX of the box), *Y_Position* (of the XXXX of the box), and *figure* (the handle to a MATLAB fig of the box).

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

