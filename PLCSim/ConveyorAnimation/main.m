% clc; clear; close all
% addpath("src");

% %duration, velocity
% b.move_box(4, [1 0]);
% b.push_box(1);

%%
% Need to make sure sim time is appropriate in the .slx

clc; clear; close all; format compact
addpath("src")


%% Simulation parameters
start_time = 0;
end_time = 30;
time_step = 0.2;

times = start_time:time_step:end_time;
% simin = [boolean(ones(floor(numel(times)/2), 1)); boolean(zeros(ceil(numel(times)/2), 1))];
simin = ones(numel(times), 1);
simin = boolean(simin);
simin = timeseries(simin, times);

%% Running simulation
out = run_simulink_plc("SISO_Timer", string(start_time), string(end_time), string(time_step));
% edit_simulink_plc is a good function to mess with the .slx

% !! Need to make a way to take user input for time
%% Simulation results
% 
% % Creating objects
% c = conveyor_assembly(10, 1, 0, 0);
% b = box();
% c.draw_conveyor;
% 
% b.X_Position = 0;
% b.Y_Position = 1;
% 
% % Running loop
% for i = 1:numel(out.simout.Data)
%     b.move_box(time_step, out.simout.Data(i), 0)
% end

%% Creating a figure to validate simout
figure(); plot(out.simout); ylim([-.1 1.1])
