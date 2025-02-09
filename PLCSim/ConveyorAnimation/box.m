classdef box < handle
    %UNTITLED6 Summary of this class goes here
    %   Detailed explanation goes here

    properties
        Height {mustBePositive} = 2;
        Width {mustBePositive} = 2;
        X_Coordinates
        Y_Coordinates
        X_Position = 0
        Y_Position = 0
        figure

    end

    methods
        function obj = box(Height, Width)
            if nargin == 2
                obj.Height = Height;
                obj.Width = Width;
            end
        end

        function make_box_coordinates(obj)

            y_vals_base = obj.Height * [0 1 1 0] + obj.Y_Position;
            x_vals_base = obj.Width * [0 0 1 1]+ obj.X_Position;

            [obj.X_Coordinates, obj.Y_Coordinates]  = poly2cw(x_vals_base, y_vals_base);
        end

        function draw_box(obj)
            obj.make_box_coordinates;

            ax = gca;
            obj.figure = patch(obj.X_Coordinates, obj.Y_Coordinates, 'k', 'Parent', ax);
            axis( 2*[-obj.Width, obj.Width, -obj.Height, obj.Height]);

        end

        function move_box(obj, velocity, duration)
            dt = .1;
            dx = velocity*dt;
            time = 0;
            while time < duration
                obj.X_Position = obj.X_Position + dx;
                draw_box(obj)
                pause(dt);
                time = time + dt;
                delete(obj.figure)
            end

        end



    end
end