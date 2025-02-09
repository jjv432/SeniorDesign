classdef conveyor
    %UNTITLED5 Summary of this class goes here
    %   Detailed explanation goes here

    properties
        tread
        conveyor_base
    end

    methods
        function obj = conveyor(tread, conveyor_base)
            if nargin == 2
                obj.tread = tread;
                obj.conveyor_base = conveyor_base;
            end
        end

        % function outputArg = method1(obj,inputArg)
        %     %METHOD1 Summary of this method goes here
        %     %   Detailed explanation goes here
        %     outputArg = obj.Property1 + inputArg;
        % end
    end
end