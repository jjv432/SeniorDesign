classdef Sensor < handle
    %LINEARACTUATOR Summary of this class goes here
    %   Detailed explanation goes here

    properties
        X_Position = 0
        Y_Position = 0
        Height = 2
        Width = .1
        Figures
        FigureVisibility = 'off'
    end

    methods
        function obj = Sensor(X_Position, Y_Position)
            %LINEARACTUATOR Construct an instance of this class
            %   Detailed explanation goes here
            if nargin == 2
                obj.X_Position = X_Position;
                obj.Y_Position = Y_Position;
            end
        end

        function MakePatches(obj)
            %METHOD1 Summary of this method goes here
            %   Detailed explanation goes here

            thetas = linspace(0, 2*pi, 100);

            % Base
            base_x_coords = obj.Width* [1 1 0 0] + obj.X_Position;
            base_y_coords = obj.Height * [0 1 1 0] + obj.Y_Position;

            % Indicating Light
            light_x_coords = (obj.Width/2)*cos(thetas) + obj.X_Position + obj.Width/2;
            light_y_coords = (obj.Width/2)*sin(thetas) + obj.Y_Position + obj.Height - obj.Width/2;

            % ax = gca;
            obj.Figures = [patch(base_x_coords, base_y_coords, 'w', 'visible', obj.FigureVisibility); patch(light_x_coords, light_y_coords, 'g', 'FaceAlpha', .05, 'visible', obj.FigureVisibility)];
            axis equal

        end

        function PlaceSensor(obj, new_x, new_y)
            
            if nargin == 3
                obj.X_Position = new_x;
                obj.Y_Position = new_y;
                obj.FigureVisibility = 'on';
                obj.MakePatches
            end
        end

        function Energize(obj)
            ax = gca;
            obj.Figures(2).FaceAlpha = 1;

        end

        function Deenergize(obj)
            ax = gca;
            obj.Figures(2).FaceAlpha = .5;

        end
    end
end

