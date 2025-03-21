clc; clear; close all
addpath("src");



%% Draw the conveyor belt assembly

c = conveyor_assembly(6, .5, 0, 0);
c.draw_conveyor;

%% Place Box in Starting Position
b = box(1, 1, 0, c.Height);
b.draw_box;

%% Draw actuator
LA = LinearActuator();
LA.MakePatches
LA.PlaceActuator(3, c.Height);

%% Draw sensor
s = Sensor();
s.MakePatches
s.PlaceSensor(2, c.Height);

%% Run sim

time_steps = [0, .001];
start_button = timeseries(boolean(ones(numel(time_steps), 1)));
sensor = timeseries(boolean(ones(numel(time_steps), 1)));


while mean(b.X_Coordinates) < (LA.X_Position + LA.BaseHeight/2)
    out = run_simulink_plc("SensorActuator", '0', '.001');
    if out.motor.Data(end)
        b.move_box(.1, .5, 0);
    end

    if (mean(b.X_Coordinates) >= (s.X_Position))
        sensor = timeseries(boolean(1));
        s.Energize;
    end

    if (out.actuator.Data(end))
        b.push_box(1, .1)
    end
end


%% Move Box

% while mean(b.X_Coordinates) < (LA.X_Position + LA.BaseHeight/2)
%     b.move_box(.1, .5, 0);
%     if (mean(b.X_Coordinates) >= (s.X_Position))
%         s.Energize;
%     end
% end
% 
% %%
% LA.Energize
% 
% b.push_box(1, .1)
% 
% LA.Deenergize
% 
% 
