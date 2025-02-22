clc; clear; close all
addpath("src");



%% Draw the conveyor belt assembly

c = conveyor_assembly(6, .5, 0, 0);
c.draw_conveyor;

%% Place Box in Starting Position
b = box(1, 1, 0, c.Height);
b.draw_box;

for i = 1:30
    b.move_box(.1, .5, 0);
end
%% Draw actuator
LA = LinearActuator();
LA.MakePatches
LA.PlaceActuator(-5, 5);


%% 
LA.Energize
pause(1)
LA.Deenergize


