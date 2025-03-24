clc; clear; close all;
addpath("src");
l1 = LED(-1, 0, "Green");
l2 = LED(1, 0, "Green");

figure();
hold on
axis equal
l1.draw_LED;
l2.draw_LED;
m = motor(1, 0, -1);
m.draw_motor()

%% Creating inputs
times = linspace(0, 3, 100);
tot_time = linspace(0, 9, 300);
dt = times(2) - times(1);
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

out = run_simulink_plc("Motor_and_LED", '0', '9', string(dt));

%% Animating objects based on output
vid = VideoWriter("ButtonAndLEDSimulation.avi");
vid.FrameRate = 5;
vid.Quality = 85;
open(vid);
omega = 1;
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
    writeVideo(vid, getframe(gcf));
end

close(vid);

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
saveas(gcf, "SimulateInputs.jpg");