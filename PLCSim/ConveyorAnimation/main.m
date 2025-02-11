% clc; clear; close all
% addpath("src");

% %duration, velocity
% b.move_box(4, [1 0]);
% b.push_box(1);

%%
% Need to make sure sim time is appropriate in the .slx

clc; clear; close all; format compact
addpath("src")

c = conveyor_assembly(10, 1, 0, 0);
c.draw_conveyor;
b = box();
b.X_Position = 0;
b.Y_Position = 1;


simin = [boolean(ones(10, 1)); boolean(zeros(10, 1)); boolean(ones(10, 1))];
simin = timeseries(simin);
out = run_simulink_plc("MIMO", '0', '30');
% edit_simulink_plc is a good function to mess with the .slx
figure(); plot(out.simout); ylim([-.1 1.1])

%{
Next, can call the objects. Make a new input dt.  Make that an input to the
run_simulink_plc as well.  Use the current output to control M1. Don't push
box yet.  Maybe use of a counter would be a good trigger for when to push
the box, i.e. move the box for 10s, then push it off (regardless of
position)
%}
