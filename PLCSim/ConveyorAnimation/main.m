clc; clear; close all
addpath("src");
c = conveyor_assembly(10, 1, 0, 0);
c.draw_conveyor;
b = box();
b.X_Position = 0;
b.Y_Position = 1;
%duration, velocity
b.move_box(4, [1 0]);
b.push_box(1);

%%
addpath("src")
clc; clear; close all
o = run_simulink_plc("SISO");
