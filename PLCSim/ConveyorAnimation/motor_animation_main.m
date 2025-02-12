clc; clear; close all; format compact

addpath("src")
m = motor();

omega = .1;
direction = -1;

for i = 1:50
    m.rotate_motor(omega, direction);
end