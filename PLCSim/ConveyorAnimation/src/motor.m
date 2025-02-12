classdef motor < handle
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here

    properties
        Diameter = 2
        X_Position = 0
        Y_Position = 0
        X_Coordinates_Inner
        Y_Coordinates_Inner
        X_Coordinates_Outer
        Y_Coordinates_Outer
        X_Coordinates_Line
        Y_Coordinates_Line
        figureOut
        figureIn
        figureLine
        theta = 0;
    end

    methods
        function obj = motor(OuterDiameter, X, Y)

            if nargin == 3
                obj.Diameter = OuterDiameter;
                obj.X_Position = X;
                obj.Y_Position = Y;
            end
        end

        function make_motor_coordinates(obj)
            inner_diameter = obj.Diameter/4;

            thetas = linspace(0, 2*pi, 50);

            % Outer
            x_vals_outer = obj.Diameter * [-.5 -.5 .5 .5];
            y_vals_outer = obj.Diameter * [-.5 .5 .5 -.5];

            % Innner
            x_vals_inner = inner_diameter * cos(thetas);
            y_vals_inner = inner_diameter * sin(thetas);

            % Line
            line_height = inner_diameter;
            line_width = line_height/4;

            x_vals_line = line_width*[-.5 -.5 .5 .5];
            y_vals_line = line_height*[0 1 1 0];


            % Assigning to object
            obj.X_Coordinates_Inner = x_vals_inner + obj.X_Position;
            obj.Y_Coordinates_Inner = y_vals_inner + obj.Y_Position;
            obj.X_Coordinates_Outer = x_vals_outer + obj.X_Position;
            obj.Y_Coordinates_Outer = y_vals_outer + obj.Y_Position;
            obj.X_Coordinates_Line = x_vals_line + obj.X_Position;
            obj.Y_Coordinates_Line = y_vals_line + obj.Y_Position;

        end

        function draw_motor(obj)
            if isempty(obj.Y_Coordinates_Line)
                obj.make_motor_coordinates;
            end

            ax = gca;
            hold on
            axis equal
            obj.figureOut = patch(obj.X_Coordinates_Outer, obj.Y_Coordinates_Outer, [.502 .502 .502], 'Parent', ax);
            obj.figureIn = patch(obj.X_Coordinates_Inner, obj.Y_Coordinates_Inner, [.8 .8 .8], 'Parent', ax);
            obj.figureLine = patch(obj.X_Coordinates_Line, obj.Y_Coordinates_Line, 'k', 'Parent', ax);

            hold off

        end

        function rotate_motor(obj, omega, direction)
            arguments
                obj
                omega
                direction {mustBeMember(direction, [-1 1])}
            end
            if isempty(obj.Y_Coordinates_Line)
                obj.make_motor_coordinates;
                obj.draw_motor;
            end

            delete(obj.figureLine);

            dt = .1;

            rot_matrix = [cos(obj.theta), -sin(obj.theta); sin(obj.theta), cos(obj.theta)];

            temp = rot_matrix * [obj.X_Coordinates_Line - obj.X_Position; obj.Y_Coordinates_Line - obj.Y_Position];
            obj.X_Coordinates_Line = temp(1, :) + obj.X_Position;
            obj.Y_Coordinates_Line = temp(2, :) + obj.Y_Position;

            obj.theta = obj.theta + direction *(omega * dt);
            
            ax = gca;
            obj.figureLine = patch(obj.X_Coordinates_Line, obj.Y_Coordinates_Line, 'k', 'Parent', ax);
            pause(dt);


        end
    end
end