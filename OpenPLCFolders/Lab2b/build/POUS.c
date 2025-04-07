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





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->ST0,1,retain)
  __INIT_VAR(data__->ST1,0,retain)
  __INIT_VAR(data__->ST2,0,retain)
  __INIT_LOCATED(BOOL,__IX0_0,data__->B1,retain)
  __INIT_LOCATED_VALUE(data__->B1,0)
  __INIT_LOCATED(BOOL,__IX0_1,data__->B2,retain)
  __INIT_LOCATED_VALUE(data__->B2,0)
  __INIT_LOCATED(BOOL,__IX0_2,data__->B3,retain)
  __INIT_LOCATED_VALUE(data__->B3,0)
  __INIT_LOCATED(BOOL,__QX0_2,data__->DC,retain)
  __INIT_LOCATED_VALUE(data__->DC,0)
  __INIT_VAR(data__->STEPDONE,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__QX0_1,data__->STEPRUN,retain)
  __INIT_LOCATED_VALUE(data__->STEPRUN,__BOOL_LITERAL(FALSE))
  TON_init__(&data__->TON0,retain);
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,ST0,,(__GET_LOCATED(data__->B2,) || (!(__GET_VAR(data__->ST2,)) && !(__GET_VAR(data__->ST1,)))));
  __SET_VAR(data__->,ST1,,(!(__GET_LOCATED(data__->B2,)) && (__GET_VAR(data__->ST1,) || ((!(__GET_VAR(data__->ST1,)) && __GET_LOCATED(data__->B1,)) && __GET_VAR(data__->ST0,)))));
  __SET_LOCATED(data__->,STEPRUN,,__GET_LOCATED(data__->B3,));
  __SET_VAR(data__->TON0.,IN,,__GET_LOCATED(data__->STEPRUN,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,STEPDONE,,__GET_VAR(data__->TON0.Q,));
  __SET_LOCATED(data__->,DC,,__GET_VAR(data__->ST1,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





