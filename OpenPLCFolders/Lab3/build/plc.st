TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM main
  VAR_EXTERNAL
    St0 : BOOL;
    St1 : BOOL;
    St2 : BOOL;
    St3 : BOOL;
    St4 : BOOL;
    St5 : BOOL;
  END_VAR
  VAR
    BoxBut : BOOL := 0;
  END_VAR
  VAR
    StartBut AT %IX0.0 : BOOL := 0;
  END_VAR
  VAR
    My_Time : BOOL := 0;
    BB : BOOL := 0;
    BB2 : BOOL := 0;
    Motor : BOOL := 0;
  END_VAR

  St1 := NOT(St0) AND (St1 OR My_Time AND St5) OR NOT(St2) AND (St1 OR StartBut AND St0);
  St0 := NOT(St5) AND NOT(St4) AND NOT(St3) AND NOT(St2) AND NOT(St1);
  St2 := NOT(St3) AND (St2 OR BoxBut AND St0);
  St3 := NOT(St4) AND (St3 OR BB AND St2);
  St4 := NOT(St5) AND (St4 OR My_Time AND St3);
  St5 := NOT(St0) AND (St5 OR BB2 AND St4);
  Motor := NOT(St0);
  Motor := St1 OR St2 OR St3 OR St4 OR St5;
END_PROGRAM


CONFIGURATION Config0
  VAR_GLOBAL
    St0 : BOOL := 1;
    St1 : BOOL := 0;
    St2 : BOOL := 0;
    St3 : BOOL := 0;
    St4 : BOOL := 0;
    St5 : BOOL := 0;
  END_VAR

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
