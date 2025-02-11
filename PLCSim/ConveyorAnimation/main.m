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
% Need to make sure sim time is appropriate in the .slx

clc; clear; close all; format compact
addpath("src")
clc; clear; close all
simin = [boolean(ones(10, 1)); boolean(zeros(10, 1)); boolean(ones(10, 1))];
simin = timeseries(simin);
out = run_simulink_plc("MIMO", '0', '30');
% edit_simulink_plc is a good function to mess with the .slx
figure(); plot(out.simout); ylim([-.1 1.1])

