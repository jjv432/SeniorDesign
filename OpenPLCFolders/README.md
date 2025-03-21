### Open PLC Coding

OpenPLC is the IDE that will be used to program the PLCs. Examples are provided for Ladder Logic diagrams that can be used as Solutions to Labs 2 and 3.

## Getting Started with OpenPLC
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
(Ground) PowerRails. Also, we can select the number of pins. Let's start with 2, and create a left and right power rail parallel to each other by completing this 
process twice. You can click on the rails and then drag then to reposition.

Next, add an input to your system. This symbol looks like two parallel lines with the word 'var' above it. Click this symbol, then click into the dot matrix to 
place the input symbol. Use the 'Normal' modifier, and call the variable 'my_input.'

Now, add an output to the diagram using the output symbol, the two curved lines with the word 'var' above it. Call this 'my_output'.

### 5. Define your variables
In the same window, above the dot matrix, there is a table. This is where we must define the variables that we just referenced in the diagram. To do this, click the 
green plus at the top of the window. Adjust the name, leave class as 'local', change the type to BOOL (Type > Base Types > Bool), and set the initial value to 0.

### 6. 'Wire' the diagram
To connect the symbols, click and drag between the terminals that you want to connect. For this example connect the Left PowerRail to the input, the input to the 
output, then the output to the Right PowerRail. 

### 7. Test the program 
OpenPLC allows you to simulate your system. To do this, click the symbol at the top of the screen that looks like a blue person running. This will compile and begin 
a simulation of your system. You will know the simulation is running when the blue-runner symbol is replaced by a stop sign.

On the left-hand-side of the screen, click the sunglasses next to the drop-down window named something like: "Config0.Res0.instance0". This will begin a debugging 
instance. You should now be able to see that wires that are energized are highlighted green.

Now, we can force values to be true of false. Right click the center of the 'my\_\input' symbol, and select 'Force True.' You should now see that 'my\_\output' is 
highlighted green, signifying that it is on. To set the input back to its normal behavior, right click the symbol and select 'Release Value'.


### 8. Upload the progam

At this point, you should see something that looks like this: 

<img width="959" alt="OpenPLC_Example" src="https://github.com/user-attachments/assets/771a0a71-793c-4f5d-ad99-97c2ae133df6" />

ADJUST IO TO SHOW HOW TO USE THE USER BUTTON, ADDRESSES, AND LEDs

INSERT EXAMPLE LINKS ON CONNECTIONS AND PROGRAMMING

>[!WARNING]
> The inputs and user button of the PLC will operate properly when only provided power via a USB-C cable. However, to use the relay outputs, the PLC _must_ be 
> connected to 12-24V at it's power input terminals.

## Using Arduino Sketches with OpenPLC

## Using an Expansion Module with OpenPLC and Arduino IDE

