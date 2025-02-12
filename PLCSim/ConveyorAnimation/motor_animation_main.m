clc; clear; close all; format compact

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

out = run_simulink_plc("MIMO_ManualSwitch", '0', '10', '.1');
for i = 1:50
    omega1 = out.motor1.Data(i);
    omega2 = out.motor2.Data(i);
    m1.rotate_motor(omega1, direction);
    m2.rotate_motor(omega2, -direction);
end