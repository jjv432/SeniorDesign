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


PROGRAM program0
  VAR
    DigitalRead AT %IW0 : WORD := 0;
  END_VAR
  VAR_EXTERNAL
    DigitalReadOut : WORD;
  END_VAR
  VAR
    userButton AT %IX1.0 : BOOL := 0;
  END_VAR
  VAR
    gtBool : BOOL := 0;
  END_VAR
  VAR
    myout AT %QX0.1 : BOOL := 1;
  END_VAR
  VAR
    _TMP_GT1_OUT : BOOL;
    _TMP_MOVE12_OUT : WORD;
  END_VAR

  _TMP_GT1_OUT := GT(100, DigitalRead);
  gtBool := _TMP_GT1_OUT;
  myout := gtBool OR userButton;
  _TMP_MOVE12_OUT := MOVE(DigitalRead);
  DigitalReadOut := _TMP_MOVE12_OUT;
END_PROGRAM


CONFIGURATION Config0
  VAR_GLOBAL
    DigitalReadOut : WORD;
  END_VAR

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
