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


for i = 1:3
    l1.LED_Off;
    l2.LED_On;
    m.rotate_motor(1,1);
    pause(1);
    l2.LED_Off;
    l1.LED_On;
    m.rotate_motor(1,1);
    pause(1)
    
end
