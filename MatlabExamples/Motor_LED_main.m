clc; clear; close all;

% This allows access to the PLC simulation functions
addpath("src");

%% Creating and plotting objects
% Create two LED objects. These will be used to animate the system response
l1 = LED(-1, 0, "Green");
l2 = LED(1, 0, "Green");

% Create a motor object. Useful for animating the system response.
m = motor(1, 0, -1);

% Create a new figure, then plot the initial positions of the LEDs and motors.
figure();
hold on
axis equal
l1.draw_LED;
l2.draw_LED;
m.draw_motor()

%% Creating inputs
%{
The behavior of these inputs is such that one button is on for 6 seconds, then off for 3, and the other is off for 3 seconds, then on for 
6 seconds. The majority of these lines are used to put the inputs into the correct format for Simulink to accept them.
%}

% Make a 3 second chunk
times = linspace(0, 3, 100);

% 3, 3 second chunks
tot_time = linspace(0, 9, 300);

button_1_a = boolean(ones(numel(times), 1));
button_2_a = boolean(zeros(numel(times), 1));

button_1_b = boolean(ones(numel(times), 1));
button_2_b = boolean(ones(numel(times), 1));

button_1_c = boolean(zeros(numel(times), 1));
button_2_c = boolean(ones(numel(times), 1));

button_1 = [button_1_a; button_1_b; button_1_c];
button_2 = [button_2_a; button_2_b; button_2_c];

button_1 = timeseries(button_1, tot_time);
button_2 = timeseries(button_2, tot_time);

%% Simulate the system for 9 seconds
out = run_simulink_plc("Motor_and_LED", '0', '9');

%% Animating objects based on output

% code to create a video file of this animation
% vid = VideoWriter("ButtonAndLEDSimulation.avi");
% vid.FrameRate = 5;
% vid.Quality = 85;
% open(vid);

omega = 1;

% For every element in the simulation output, check to see if the LEDs or the motor is on. If so, apply the appropriate animation method.
for i = 1:numel(out.tout)
    if out.LED1.Data(i)
        l1.LED_On;
    else
        l1.LED_Off;
    end
    if out.LED2.Data(i)
        l2.LED_On;
    else
        l2.LED_Off;
    end

    if out.LED1.Data(i) && out.LED2.Data(i)
        m.rotate_motor(omega, 1);
    else
        pause(out.tout(2) - out.tout(1));
    end
    % writeVideo(vid, getframe(gcf));
end

%close(vid);

%% Making figure of inputs

figure()
hold on
plot(button_1, 'b', 'LineWidth' ,3)
plot(button_2, 'r', 'LineWidth' ,3)
grid on
ylim([-.3 1.3])
legend("Button 1", "Button 2")
title("Simulated Button Inputs")
ylabel("Logic Level");
xlabel("Time (s)")
%saveas(gcf, "SimulateInputs.jpg");
