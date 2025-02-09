classdef conveyor_assembly < handle
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

        function make_tread(obj.conveyor_base)
            
        end
    end
end