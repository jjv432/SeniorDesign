void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void MAIN_init__(MAIN *data__, BOOL retain) {
  __INIT_VAR(data__->ST0,1,retain)
  __INIT_VAR(data__->ST1,0,retain)
  __INIT_VAR(data__->ST2,0,retain)
  __INIT_VAR(data__->STARTBUT,0,retain)
  __INIT_VAR(data__->BOXBUT,0,retain)
  __INIT_VAR(data__->STOPBUT,0,retain)
  __INIT_VAR(data__->STEPPER,0,retain)
  __INIT_VAR(data__->MOTOR,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->TM_DN,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG1,retain);
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,ST0,,(__GET_VAR(data__->STOPBUT,) || (!(__GET_VAR(data__->ST2,)) && !(__GET_VAR(data__->ST1,)))));
  __SET_VAR(data__->,MOTOR,,!(__GET_VAR(data__->ST0,)));
  __SET_VAR(data__->,MOTOR,,(__GET_VAR(data__->ST1,) || __GET_VAR(data__->ST2,)));
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->TON0.Q,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->,ST1,,((!(__GET_VAR(data__->STOP,)) && !(__GET_VAR(data__->ST2,))) && ((__GET_VAR(data__->F_TRIG1.Q,) || __GET_VAR(data__->ST1,)) || (__GET_VAR(data__->STARTBUT,) && __GET_VAR(data__->ST0,)))));
  __SET_VAR(data__->,ST2,,(!(__GET_VAR(data__->STOP,)) && ((__GET_VAR(data__->BOXBUT,) && __GET_VAR(data__->ST1,)) || (!(__GET_VAR(data__->TON0.Q,)) && __GET_VAR(data__->ST2,)))));
  __SET_VAR(data__->,STEPPER,,__GET_VAR(data__->ST2,));
  __SET_VAR(data__->,STOP,,__GET_VAR(data__->STOPBUT,));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->ST2,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);

  goto __end;

__end:
  return;
} // MAIN_body__() 





