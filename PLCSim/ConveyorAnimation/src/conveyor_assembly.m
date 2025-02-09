classdef conveyor_assembly < handle
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
        function obj = conveyor_assembly(Length, Height, X_Position, Y_Position)
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

            % Making the tread
            x_vals_tread = x_vals_base(1):obj.TreadLength:x_vals_base(end);
            obj.TreadXCoordinates = sort([x_vals_tread, x_vals_tread]); % Need to double up to make the patch easier

            % % Not Working
            % for i = 1:(numel(x_vals_tread) /2 + 1)
            %     temp = [max(y_vals_base), max(y_vals_base), max(y_vals_base) + obj.TreadHeight, max(y_vals_base) + obj.TreadHeight];
            %     obj.TreadYCoordinates = [obj.TreadYCoordinates, temp];
            % end

        end

        % Plots the conveyor belt in a figure.  Calls make_conveyor_coords
        % if there aren't any coords made yet.
        function draw_conveyor(obj)
            if isempty(obj.BaseXCoordinates) || isempty(obj.BaseYCoordinates)
                obj.make_conveyor_coords;
            end
            figure()
            hold on
            patch(obj.BaseXCoordinates, obj.BaseYCoordinates, 'b')
            % patch(obj.TreadXCoordinates, obj.TreadYCoordinates, 'r');
            axis( 2*[mean(obj.BaseXCoordinates)-obj.Length, mean(obj.BaseXCoordinates) + obj.Length/2, -obj.Height, obj.Height]);
            axis equal
        end
    end
end