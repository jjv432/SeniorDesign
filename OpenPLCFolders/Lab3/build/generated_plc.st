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
    BoxBut AT %IX0.1 : BOOL := 0;
    StartBut AT %IX0.0 : BOOL := 0;
  END_VAR
  VAR
    TimeDN : BOOL := 0;
  END_VAR
  VAR
    BreakBeam AT %IX0.2 : BOOL := 0;
    BreakBeam2 AT %IX0.3 : BOOL := 0;
    StopBut AT %IX0.4 : BOOL := 0;
    Motor AT %QX0.1 : BOOL := 0;
  END_VAR
  VAR
    TON0 : TON;
  END_VAR
  VAR
    LinearAct AT %QX0.2 : BOOL := 0;
  END_VAR

  St0 := StopBut OR NOT(St5) AND NOT(St4) AND NOT(St3) AND NOT(St2) AND NOT(St1);
  St2 := NOT(St3) AND (St2 OR BoxBut AND St1);
  St3 := NOT(St4) AND (St3 OR BreakBeam AND St2);
  St4 := NOT(St5) AND (St4 OR TimeDN AND St3);
  St5 := NOT(St0) AND (St5 OR BreakBeam2 AND St4);
  Motor := NOT(St0);
  Motor := St1 OR St2 OR St3 OR St4 OR St5;
  TON0(IN := St3, PT := T#1000ms);
  TimeDN := TON0.Q;
  St1 := NOT(St2) AND (St1 OR StartBut AND St0);
  LinearAct := St4;
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
    VAR_GLOBAL
      LocalVar0 : DINT;
    END_VAR
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
