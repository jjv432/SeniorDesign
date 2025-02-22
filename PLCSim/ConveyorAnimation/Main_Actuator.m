clc; clear; close all
addpath("src");

LA = LinearActuator();
LA.MakePatches
LA.PlaceMotor(-5, 5);


%% 
LA.Energize
pause(1)
LA.Deenergize
