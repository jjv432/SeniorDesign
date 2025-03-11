function out = run_simulink_plc(FileName, StartTime, EndTime)

    % Function will create a slx model in src if there isn't one already.
    % Else, it will open the existing model

    persistent firstRun
    firstRun = [];

    if isempty( firstRun)
        firstRun = 1;
    end

    if firstRun
        plcloadtypes
        firstRun = 0;

        if exist(FileName, 'file') ~= 4
            disp("You will need to create the ladder logic first... please wait while file is generated")
            new_system(FileName)
            plcladderlib
            save_system(FileName)
            out = [];
            open_system(FileName)

            plcladderoption(FileName, 'Animation', 'on');
        end

    end


    plcladderoption(FileName, 'Animation', 'off')
    out = sim(FileName, 'StartTime',string(StartTime),'StopTime',string(EndTime), 'FastRestart', 'off');
    
    % Can try to change this so that u is an array, that way not running
    % sim every time
    
    % SensorActuator([],[],[],'compile')
    % out = SensorActuator();
end
