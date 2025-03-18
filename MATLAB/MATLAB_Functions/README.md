This folder contains useful functions and objects that can be used when working with the MATLAB Simulink PLC Simulations.

## Programming with OpenPLC
Follow these steps to begin programming with Open PLC, as well as reviewing the [Open PLC Manual.](https://autonomylogic.com/docs/openplc-overview/)

### 1. Start Open PLC

### 2. Create a new file
At the top right of the IDE, select the "New" button, denoted by a sheet with a green + sign. This will prompt you to select a folder that you want the project to
exist in. Create the folder, then click 'Select Folder.'

Once you've done this, a pop-up window will appear titled 'Create a new POU.' Name the program whatever you'd like, then select the language you'd like the program
to be in (IL: Instruction List, ST: Structured Text, __LD__: Ladder Diagram, FBD: Function Block Diagram, or SFC: Sequential Function Chart). Select LD, then click 'OK.'

### 3. Add symbols to the Ladder Diagram
In the file tree on the right of the window, double click on the program that you just created. You should see a dot matrix in the middle of the screen. This is
where you can begin you ladder diagram.

First, you will need to add in the power and ground rails. All of the symbols for the Ladder are in the top of the window, and are to the right of the block that
says "CMT." Click the first symbol to the right of the "CMT" block, then click into the dot-matrix. Once the pop-up appears, we can select Left (Positive) or Right
(Ground) PowerRails. Also, we can select the number of pins. Let's start with 2,
