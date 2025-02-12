clc; clear; close all; format compact
addpath("src");

%{
The edit_simulink_plc function will open the .slx file that you list as an
input. If it doesn't exist yet, it will create it.
%}

edit_simulink_plc("Demo");

%{
Once this command runs, there should be a new simulink model and the plc
ladder library.  These will be used to generate the ladder logic.
%}

%{
There is also a function called 'run_simulink_plc'. This function is useful
if you just want to get output data from your ladder logic, and don't want
to make any edits.
%}

%% Using the box and conveyor objects

%{
There are two objects, along with the two functions above, that exist in
the src folder.  These objects are useful for animating the box-conveyor
system.

Here's how to use these objects:

---------------------
b = box(H, W);
This creates a box called 'b', with height and width H and W

---------------------
c = conveyor_assembly(L, H, X, Y)
This creates a conveyor belt (rectangle) of length L, height H, and x and y
positions X and Y (as referenced from the bottom left corner

---------------------
b.move_box(t, vx, vy)
This function creates an animation of the box moving for time t at
velocities vx and vy

---------------------
b.move_box(t, vx, vy)
This function creates an animation of the box moving for time t at
velocities vx and vy


%}