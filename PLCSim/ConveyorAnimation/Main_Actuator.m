clc; clear; close all
addpath("src");



%% Draw the conveyor belt assembly

c = conveyor_assembly(6, .5, 0, 0);
c.draw_conveyor;

%% Place Box in Starting Position
b = box(1, 1, 0, c.Height);
b.draw_box;

%% Draw actuator
LA = LinearActuator();
LA.MakePatches
LA.PlaceActuator(3, c.Height);

%% Move Box

while mean(b.X_Coordinates) < (LA.X_Position + LA.BaseHeight/2)
    b.move_box(.1, .5, 0);
end

%%
LA.Energize

b.push_box(1, .1)

LA.Deenergize


