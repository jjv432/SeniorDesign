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

        end

        function move_box(obj, dt, velocity_x, velocity_y)
            arguments
                obj
                dt (1,1) {mustBeNonnegative}
                velocity_x (1,1) = 0
                velocity_y(1,1) = 0;

            end
            delete(obj.figure)
            dx = velocity_x*dt;
            dy = velocity_y*dt;

            obj.X_Position = obj.X_Position + dx;
            obj.Y_Position = obj.Y_Position + dy;
            draw_box(obj)
            pause(dt);
            


        end

        function push_box(obj, direction, dt)
            arguments
                obj
                direction (1, 1) {mustBeMember(direction, [1, -1])}
                dt
            end

            scale_factor = 1.1;

            if direction == -1
                scale_factor = 1/scale_factor;
            end

            for i = 1:3
                delete(obj.figure)
                obj.Height = obj.Height*scale_factor;
                obj.Width = obj.Width*scale_factor;
                draw_box(obj)
                pause(dt);                
            end

            move_box(obj, 2, 0, -1)

        end
    end
end