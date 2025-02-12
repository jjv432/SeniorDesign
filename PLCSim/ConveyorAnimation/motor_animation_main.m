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

for i = 1:50
    m1.rotate_motor(omega, direction);
    m2.rotate_motor(omega, -direction);
end