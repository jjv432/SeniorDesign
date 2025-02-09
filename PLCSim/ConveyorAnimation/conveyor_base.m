classdef conveyor_base < handle
    % Making this a handle class so that values can be more readily changed

    properties
        Length = 3
        Height = 1
        X_Position = 0;
        Y_Position = 0;
        BaseXCoordinates
        BaseYCoordinates
        TreadHeight = 0.1
        TreadLength = 0.25
        TreadXCoordinates
        TreadYCoordinates
    end

    methods

        % Constructor
        function obj = conveyor_base(Length, Height, X_Position, Y_Position)
            % Setting default values
            if nargin < 2
                Height = 3;
                Length = 1;
                X_Position = 0;
                Y_Position = 0;
            end
            obj.Length = Length;
            obj.Height = Height;
            obj.X_Position = X_Position;
            obj.Y_Position = Y_Position;
        end

        % Creates the necessary coordinates to make a patch of the conveyor
        % belt
        function make_conveyor_coords(obj)

            % Making the base of the conveyor belt
            y_vals_base = obj.Height * [0 1 1 0] + obj.Y_Position;
            x_vals_base = obj.Length * [0 0 1 1]+ obj.X_Position;

            [obj.BaseXCoordinates, obj.BaseYCoordinates]  = poly2cw(x_vals_base, y_vals_base);

        end

        % Plots the conveyor belt in a figure.  Calls make_conveyor_coords
        % if there aren't any coords made yet.
        function draw_conveyor(obj)
            if ~exist(obj.BaseXCoordinates, 'var') || ~exist(obj.BaseYCoordinates, 'var')
                obj.make_conveyor_coords;
            end
            figure()
            hold on
            patch(obj.BaseXCoordinates, obj.BaseYCoordinates, 'b')
            
            axis( 2*[-obj.Length, obj.Length, -obj.Height, obj.Height]);
        end
    end
end