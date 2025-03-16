clc; clearvars -except out; close all; format compact
saveBool = 0;

addpath("src")
m1 = motor();
m1.X_Position = 3;

m2 = motor();
m2.X_Position = -3;

m1.draw_motor();
m2.draw_motor();

axis([-5 5 -5 5]);

omega = .1;
direction = -1;
dt = .1;

button1 = timeseries([boolean(zeros(10, 1)); boolean(ones(20, 1))]);
button2 = timeseries([boolean(zeros(20, 1)); boolean(ones(10, 1))]);

out = run_simulink_plc("MIMO_FixedIO", '0', '30', string(dt));

%% Running the simulation

if saveBool
    vid = VideoWriter("MotorSimulation.avi");
    vid.FrameRate = 60;
    vid.Quality = 85;
    open(vid);
end

for i = 1:numel(out.motor1.Data)
    omega1 = out.motor1.Data(i) * omega;
    omega2 = out.motor2.Data(i) * omega;
    m1.rotate_motor(omega1, direction);
    m2.rotate_motor(omega2, -direction);
    if saveBool
        writeVideo(vid, getframe(gcf));
    end
    pause(dt);
end

if saveBool
    close(vid);
end
%%
figure();
subplot(2, 1, 1)
hold on
plot(out.motor1.Time, out.motor1.Data, '--or');
plot(out.motor2.Time, out.motor2.Data, '--kx');
hold off;
title("Simulation Results");
legend("Motor 1", "Motor 2");
% xlim([0 30])
ylim([-.1 1.1])
grid on
subplot(2, 1, 2);
hold on
plot(linspace(0, max(out.motor1.Time), numel(button1.Data)), button1.Data, '--ro');
plot(linspace(0, max(out.motor2.Time), numel(button1.Data)),button2.Data, '--kx');
legend("Button 1", "Button 2");
title("Button Inputs")
% xlim([0 30])
ylim([-.1 1.1])
grid on
hold off