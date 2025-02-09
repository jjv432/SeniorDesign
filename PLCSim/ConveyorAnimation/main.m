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
%}

clc; clear; close all; format compact
% Create an instance
c = conveyor_assembly(5, 1, 0, 0);
c.draw_conveyor;
