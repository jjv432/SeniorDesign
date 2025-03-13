function out = run_simulink_plc(FileName, StartTime, EndTime)

    % Function will create a slx model in src if there isn't one already.
    % Else, it will open the existing model


    plcloadtypes

    if exist(FileName, 'file') == 4
        out = sim(FileName, 'StartTime',string(StartTime),'StopTime',string(EndTime), 'FixedStep', '.001');
    else
        disp("You will need to create the ladder logic first... please wait while file is generated")
        new_system(FileName)
        plcladderlib
        save_system(FileName)
        out = [];
        open_system(FileName)

        plcladderoption(FileName, 'Animation', 'on');
    end


end
