PROGRAM main
  VAR
    led1 AT %QX0.0 : BOOL;
  END_VAR
  VAR
    led2 : BOOL;
    TON0 : TON;
    TOF0 : TOF;
  END_VAR

  TON0(IN := NOT(led1), PT := T#500ms);
  TOF0(IN := TON0.Q, PT := T#500ms);
  led1 := TOF0.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
