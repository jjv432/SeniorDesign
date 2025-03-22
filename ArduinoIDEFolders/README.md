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

Also, you can get an introduction to all IO at once using our [Expansion Module GPIO Sketch](ExpansionModuleGPIO/ExpansionModuleGPIO.ino). This sketch shows a simple GPIO example and is referrenced off of 
the Arduino example sketches.

## Troubleshooting

The LED on the expansion module will have different behaviors for different states. The following list contains what some of the behaviors represent:

> Solid Green

The firmware is installed to the module

> Solid Red

Firmware must be installed to the module

There are also a couple of error messages that may present themselves: 

```
Being used by another process
```
Close any other programs that may be connected to the PLC, likely an instance of OpenPLC.
