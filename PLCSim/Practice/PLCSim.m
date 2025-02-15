% Plc Simscape
% plcladderlib is the command to access it

% plcloadtypes to load in the built-in data types
% plcladderoption('<FILENAME>', 'Animation', 'on)

% ctrl + d is used to update the model once the LL diagram is done
clc; clear; close all
plcladderlib
plcloadtypes
Counters_Basic
plcladderoption('Counters_Basic', 'Animation', 'on')

% In order to do a counter, you need to go to the 'CTU_InitialValue' struct
% in the workspace. Here, you can edit what PRE and ACC values are

% For timers, do the same idea.  The PRE value is in ** milliseconds **.


%% Automatically creating slx files
% new_system("<file name>")
% open_system("<file name>")
% save_system("<file name>")


%% Animations
% out = sim("SISO_To_Workspace_Animation")
% data = out.simout

%{
If getting the error: "Unrecognized variable BOOL", need to run PLC load
types.  

If there's still errors, clear the variable that the simulation is plotting
to.  

Example block: 

out = sim("SISO_To_Workspace_Animation")
data = out.s2
time = out.tout
figure();
plot(time, data)

%}