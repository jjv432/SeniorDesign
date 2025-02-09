classdef conveyor_belt < handle
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here

    properties
        % Length int {mustBePositive} = 3
        % Height int {mustBePositive} = 1
        Length = 3
        Height = 1
        X_Position = 0;
        Y_Position = 0;
        XCoordinates
        YCoordinates
    end

    methods

        % Constructor
        function obj = conveyor_belt(Length, Height, X_Position, Y_Position)
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

        function make_conveyor_coords(obj)
            y_vals = obj.Height * [0 1 1 0] + obj.Y_Position;
            x_vals = obj.Length * [0 0 1 1]+ obj.X_Position;

            [obj.XCoordinates, obj.YCoordinates]  = poly2cw(x_vals, y_vals);

        end

        function draw_conveyor(obj)
            if ~exist(obj.XCoordinates) || ~exist(obj.YCoordinates)
                obj.make_conveyor_coords;
            end
            figure()
            patch(obj.XCoordinates, obj.YCoordinates, 'b')
            axis( 2*[-obj.Length, obj.Length, -obj.Height, obj.Height]);
        end
    end
end