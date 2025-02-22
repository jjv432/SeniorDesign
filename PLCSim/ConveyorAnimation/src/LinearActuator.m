classdef LinearActuator < handle
    %LINEARACTUATOR Summary of this class goes here
    %   Detailed explanation goes here

    properties
        X_Position = 0
        Y_Position = 0
        InnerRadius = .5
        BaseHeight = 2
        LightDiameter = .2
        Figures
    end

    methods
        function obj = LinearActuator(X_Position, Y_Position)
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

            % Piston
            thetas = linspace(0, 2*pi, 100);
            piston_x_coords = obj.InnerRadius*cos(thetas) + obj.X_Position;
            piston_y_coords = obj.InnerRadius*sin(thetas) + obj.Y_Position;

            % Base
            base_x_coords = obj.BaseHeight * [.5 .5 -.5 -.5] + obj.X_Position;
            base_y_coords = obj.BaseHeight * [-.5 .5 .5 -.5] + obj.Y_Position;

            % Indicating Light
            light_x_coords = obj.LightDiameter*cos(thetas) + obj.X_Position + obj.BaseHeight/2 - obj.LightDiameter;
            light_y_coords = obj.LightDiameter*sin(thetas) + obj.Y_Position + obj.BaseHeight/2 - obj.LightDiameter;

            % ax = gca;
            obj.Figures = [patch(base_x_coords, base_y_coords, 'b'); patch(piston_x_coords, piston_y_coords, 'k'); patch(light_x_coords, light_y_coords, 'r', 'FaceAlpha', .5)];
            axis equal

        end

        function PlaceMotor(obj, new_x, new_y)
            if nargin == 3
                close % Bad?
                obj.X_Position = new_x;
                obj.Y_Position = new_y;
                obj.MakePatches
            end

            % ax = gca;
            obj.Figures;

        end

        function Energize(obj)
            ax = gca;
            obj.Figures(3).FaceAlpha = 1;

        end

        function Deenergize(obj)
            ax = gca;
            obj.Figures(3).FaceAlpha = .5;

        end
    end
end

