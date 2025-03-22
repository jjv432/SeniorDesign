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

At this point, you should see something that looks like this: 

<img width="959" alt="OpenPLC_Example" src="https://github.com/user-attachments/assets/771a0a71-793c-4f5d-ad99-97c2ae133df6" />

### 8. Set IO addresses

To associate variables with the OPTA's IO, you must assign a memory address to the variable. To do this, you will need to adjust the "Location" column of the 
variable. For this example, we'll use the user button and the first relay as \'my_input' and 'my_output'\, respectively.

For a full list of digital IO memory addresses, see [this page of the OpenPLC manual](https://autonomylogic.com/docs/2-4-physical-addressing/).

Also, reference the following two images from the Arduino PLC IDE for the addresses of the user button and the LEDs.

![image](https://github.com/user-attachments/assets/e4055240-5ba1-4b2c-ac85-572262143c9d)

![image](https://github.com/user-attachments/assets/124bd6ee-8584-416b-abb7-e758179cc9da)

In this case, these addresses correspond to: %IX1.0 and %QX0.0, respectively.
Update the locations of each variable.

>[!NOTE]
>To better understand the address syntax, see [this page of the OpenPLC manual](https://autonomylogic.com/docs/2-3-input-output-and-memory-addressing/)


### 9. Upload the progam

For the final step, upload the program to the PLC. To do this, connect to the PLC from your compute via the USB-C connector. Then, in the 
OpenPLC program, click the icon that looks like a red circle with a CPU inside of it. This will compile your code and return any compilation 
errors.

Next, in the window that pops up, select the board type (Arduino Opta) and the COM Port (likely the largest number listed).

Finally, click "Transfer to PLC". You should now be able to start interacting with the PLC using GPIO methods.
>[!WARNING]
> The inputs and user button of the PLC will operate properly when only provided power via a USB-C cable. However, to use the relay outputs, the PLC _must_ be 
> connected to 12-24V at it's power input terminals.

## Using Arduino Sketches with OpenPLC

OpenPLC is capable with Arduino, which is great because most of the communication (that we've implemented) uses I2C, a communication protocol commonly used with 
Arduinos. The following will be a continuation of the previous example, but allowing us to print to an LCD screen connected to the OPTA's AUX port.

_Requires and I2C LCD and proper OPTA AUX connector_


### 1. Make shared variables External

Because the memory is partition in the OPTA, you must share the variables between the two cores. 

To do this, change the "Class" of "my_output" to "External" instead of "Local".

### 2. Create an Arduino Sketch

Click on the whitespace in the "Project" tab on the left-hand-side of the window. Then, select "Arduino extension". Double click the new tab that was created to 
access the Arduino Sketch.

### 3. Access shared variables

Once you've started editing the sketch, there will be a variable window at the top similar to the Ladder Logic editor. Click the green "+" to create a new variable, 
then enter the name of the shared variable. In this case it will be "my_output".

Make sure that the "Type" and name are correct, and that any initial values are set properly.

>[!NOTE]
>Now that you've made these variables external, you will only be able to change their initial values from Arduino Sketch editor window.

### 4. Program the sketch

Now, you can begin programming in the sketch just like any other Arduino. You can access any public library that any other Arduino may be able to access. In this 
case, we will be using the **LiquidCrystal_I2C** to write to the LCD.

Following the image below, write code to write the value of 'my_output' to the LCD.

![image](https://github.com/user-attachments/assets/00c17cd9-aa6e-4ef4-a63e-e61ddee1527e)

>[!NOTE]
>Notice that the 'setup' and 'loop' functions are actually called \'sketch_setup' and 'sketch_loop'\. Make sure to catch this difference if uploading directly from an Arduino.

### 5. Upload the sketch

You can now upload the sketch as normal. 
>[!WARNING] 
>Sometimes, compilation errors in the script may cause it to be deleted when uploading the program. To avoid this, try [starting a PLC 
>simulation](#7-test-the-program) first to catch any errors.

## Using an Expansion Module with OpenPLC and Arduino IDE

When connecting an expansion module, the addressing is not as simple as it was for the PLC. In this case, the expansion modules communicate through I2C. Arduino has 
developed a library to give users examples and functions to perform this communication. To see their documentation on this library, go to the 
[Opta Digital Expansion Documentation](https://docs.arduino.cc/tutorials/opta/user-manual/#opta-digital-expansions). 

### 1. Connect the expansion module

The expansion module locks onto the Opta easily. Ensure that the AUX connections are made properly, doing so slowly to avoid damaging the board.


### 2. Update the firmware

You will need to update the firmware on the expansion module if it is the first time it has been used. Arduino provides a sketch to do so. To access the sketch, in 
the Arduino IDE go to the following path:
```
File > Examples > Arduino_Opta_Blueprint > updateExpansionFw 
```

### 3. Check connectivity

Next, run this example sketch in Arduino IDE which will allow you to see a list of expansion modules connected to the Opta (up to 5 can be daisy-chained). 

```
File > Examples > Arduino_Opta_Blueprint > getExpansions
```

### 4. Use other IO examples
There are a number of othe examples in this library that provide for IO. Look through these to get a better understanding of how to program the modules.

Also, you can get an introduction to all IO at once using our [Expansion Module GPIO Sketch](). This sketch shows a simple GPIO example and is referrenced off of 
the Arduino example sketches.

To get started quickly with expansion modules, look through some of the example sketches that Arduino provides. 
