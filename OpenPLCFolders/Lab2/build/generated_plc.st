PROGRAM main
  VAR
    St0 : BOOL := 1;
    St1 : BOOL := 0;
    St2 : BOOL := 0;
    StartBut : BOOL := 00;
    BoxBut : BOOL := 0;
    StopBut : BOOL := 0;
    Stepper : BOOL := 0;
    Motor : BOOL := 0;
    STOP : BOOL := 0;
    TON0 : TON;
    TM_DN : BOOL;
    F_TRIG1 : F_TRIG;
  END_VAR

  St0 := StopBut OR NOT(St2) AND NOT(St1);
  Motor := NOT(St0);
  Motor := St1 OR St2;
  F_TRIG1(CLK := TON0.Q);
  St1 := NOT(STOP) AND NOT(St2) AND (F_TRIG1.Q OR St1 OR StartBut AND St0);
  St2 := NOT(STOP) AND (BoxBut AND St1 OR NOT(TON0.Q) AND St2);
  Stepper := St2;
  STOP := StopBut;
  TON0(IN := St2, PT := T#1000ms);
END_PROGRAM


CONFIGURATION Config0
  VAR_GLOBAL
    St0 : BOOL := 1;
    St1 : BOOL := 0;
    St2 : BOOL := 0;
    St3 : BOOL := 0;
    St4 : BOOL := 0;
    St5 : BOOL := 0;
    Count_Value : INT := 0;
  END_VAR

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      LocalVar0 : DINT;
    END_VAR
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
