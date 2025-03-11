classdef LED < handle
    %UNTITLED3 Summary of this class goes here
    %   Detailed explanation goes here

    properties
        Position_X = 0;
        Position_Y = 0;
        X_Coords;
        Y_Coords;
        Color = "Green";
        Transparency
        Diameter = .25;
        figure = [];
    end

    methods
        function obj = LED(Position_X, Position_Y, Color)

            if nargin == 3
                obj.Position_X = Position_X;
                obj.Position_Y = Position_Y;
                obj.Color = Color;

            end
        end

        function obj = draw_LED(obj)
            thetas = linspace(0, 2*pi, 100);
            obj.X_Coords = obj.Diameter * cos(thetas) + obj.Position_X;
            obj.Y_Coords = obj.Diameter * sin(thetas) + obj.Position_Y;

            if obj.Color == 'Green'
                color = 'g';
            end

            ax = gca;
            obj.figure = patch(obj.X_Coords, obj.Y_Coords, color, 'Parent', ax);

        end

        function LED_On(obj)
            if isempty(obj.figure)
                obj.draw_LED
            end

            obj.figure.FaceAlpha = 1;


        end

        function LED_Off(obj)
            if isempty(obj.figure)
                obj.draw_LED
            end

            obj.figure.FaceAlpha = .1;

        end
    end
end