clc; clearvars -except out; close all; format compact

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

vid = VideoWriter("MotorSimulation.avi");
vid.FrameRate = 60;
vid.Quality = 85;
open(vid);

for i = 1:numel(out.motor1.Data)
    omega1 = out.motor1.Data(i) * omega;
    omega2 = out.motor2.Data(i) * omega;
    m1.rotate_motor(omega1, direction);
    m2.rotate_motor(omega2, -direction);
    writeVideo(vid, getframe(gcf));
    delay(dt);
end

close(vid);
%%
figure(); 
hold on; 
plot(out.motor1.Data); 
plot(out.motor2.Data);  
hold off;
title("Expected Results");
legend("Motor 1", "Motor 2");