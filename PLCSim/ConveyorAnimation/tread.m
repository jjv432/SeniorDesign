classdef tread
    %UNTITLED4 Summary of this class goes here
    %   Detailed explanation goes here

    properties
        Height
        Width
    end

    methods
        function obj = tread(Height, Width)
            if nargin == 2
            obj.Height = Height;
            obj.Width = Width;
            end

        end

        function make_tread_coords(obj)
            % Making the base of the conveyor belt
            y_vals_base = obj.Height * [0 1 1 0] + obj.Y_Position;
            x_vals_base = obj.Length * [0 0 1 1]+ obj.X_Position;

            [obj.BaseXCoordinates, obj.BaseYCoordinates]  = poly2cw(x_vals_base, y_vals_base);

            % Making the tread
            x_vals_tread = x_vals_base(1):obj.TreadLength:x_vals_base(end);
            obj.TreadXCoordinates = sort([x_vals_tread, x_vals_tread]); % Need to double up to make the patch easier
        end
    end
end