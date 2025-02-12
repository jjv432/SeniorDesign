function edit_simulink_plc(FileName)

    % Function will create a slx model in src if there isn't one already.
    % Else, it will open the existing model

        
    plcloadtypes
    % plcladderoption(FileName, 'Animation', 'on');
    if exist(FileName, 'file') == 4
        open_system(FileName);
        disp("Opening your file...")
    else
        disp("You will need to create the ladder logic first... please wait while file is generated")
        new_system(FileName)
        
        save_system(FileName)
        open_system(FileName)

    end

    plcladderlib
end
