%{

Create a conveyor belt object:
c2 = conveyor_belt(2, 4)
or
c = converyor_belt to get default values of height and width
%}

%{
To do:

make tread it's own class, then make conveyor belt a super class of base
and tread?

Might make more sense to just move the box, and keep the conveyor static
%}

clc; clear; close all; format compact
% Create an instance
c = conveyor_assembly(5, 1, 0, 0);
c.draw_conveyor;

%%
b = box();
% b.make_box_coordinates;
b.draw_box;
b.X_Position = 3;
b.Y_Position = 3;
b.draw_box;