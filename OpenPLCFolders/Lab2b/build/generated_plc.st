PROGRAM program0
  VAR
    St0 : BOOL := 1;
    St1 : BOOL := 0;
    St2 : BOOL := 0;
  END_VAR
  VAR
    B1 AT %IX0.0 : BOOL := 0;
    B2 AT %IX0.1 : BOOL := 0;
    B3 AT %IX0.2 : BOOL := 0;
    DC AT %QX0.2 : BOOL := 0;
  END_VAR
  VAR
    StepDone : BOOL;
  END_VAR
  VAR
    StepRun AT %QX0.1 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
  END_VAR

  St0 := B2 OR NOT(St2) AND NOT(St1);
  St1 := NOT(B2) AND (St1 OR NOT(St1) AND B1 AND St0);
  StepRun := B3;
  TON0(IN := StepRun, PT := T#1000ms);
  StepDone := TON0.Q;
  DC := St1;
END_PROGRAM


CONFIGURATION Config0
  VAR_GLOBAL
    StepRun : BOOL;
    StepDone : BOOL;
  END_VAR

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
