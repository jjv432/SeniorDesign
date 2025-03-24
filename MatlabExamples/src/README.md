This folder contains useful functions and objects that can be used when working with the MATLAB Simulink PLC Simulations.

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

