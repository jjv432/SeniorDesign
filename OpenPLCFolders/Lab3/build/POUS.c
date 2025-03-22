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
  __INIT_EXTERNAL(BOOL,ST0,data__->ST0,retain)
  __INIT_EXTERNAL(BOOL,ST1,data__->ST1,retain)
  __INIT_EXTERNAL(BOOL,ST2,data__->ST2,retain)
  __INIT_EXTERNAL(BOOL,ST3,data__->ST3,retain)
  __INIT_EXTERNAL(BOOL,ST4,data__->ST4,retain)
  __INIT_EXTERNAL(BOOL,ST5,data__->ST5,retain)
  __INIT_LOCATED(BOOL,__IX0_1,data__->BOXBUT,retain)
  __INIT_LOCATED_VALUE(data__->BOXBUT,0)
  __INIT_LOCATED(BOOL,__IX0_0,data__->STARTBUT,retain)
  __INIT_LOCATED_VALUE(data__->STARTBUT,0)
  __INIT_VAR(data__->TIMEDN,0,retain)
  __INIT_VAR(data__->TIME2DN,0,retain)
  __INIT_LOCATED(BOOL,__IX0_2,data__->BREAKBEAM,retain)
  __INIT_LOCATED_VALUE(data__->BREAKBEAM,0)
  __INIT_LOCATED(BOOL,__IX0_3,data__->BREAKBEAM2,retain)
  __INIT_LOCATED_VALUE(data__->BREAKBEAM2,0)
  __INIT_LOCATED(BOOL,__IX0_4,data__->STOPBUT,retain)
  __INIT_LOCATED_VALUE(data__->STOPBUT,0)
  __INIT_LOCATED(BOOL,__QX0_1,data__->MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR,0)
  TON_init__(&data__->TON0,retain);
  __INIT_LOCATED(BOOL,__QX0_2,data__->LINEARACT,retain)
  __INIT_LOCATED_VALUE(data__->LINEARACT,0)
  __INIT_EXTERNAL(INT,COUNT_VALUE,data__->COUNT_VALUE,retain)
  __INIT_VAR(data__->COUNTERDN,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU0,retain);
  TON_init__(&data__->TON1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_EXTERNAL(data__->,ST0,,((__GET_VAR(data__->COUNTERDN,) || __GET_LOCATED(data__->STOPBUT,)) || ((((!(__GET_EXTERNAL(data__->ST5,)) && !(__GET_EXTERNAL(data__->ST4,))) && !(__GET_EXTERNAL(data__->ST3,))) && !(__GET_EXTERNAL(data__->ST2,))) && !(__GET_EXTERNAL(data__->ST1,)))));
  __SET_LOCATED(data__->,MOTOR,,!(__GET_EXTERNAL(data__->ST0,)));
  __SET_LOCATED(data__->,MOTOR,,((((__GET_EXTERNAL(data__->ST1,) || __GET_EXTERNAL(data__->ST2,)) || __GET_EXTERNAL(data__->ST3,)) || __GET_EXTERNAL(data__->ST4,)) || __GET_EXTERNAL(data__->ST5,)));
  __SET_VAR(data__->TON0.,IN,,__GET_EXTERNAL(data__->ST3,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,TIMEDN,,__GET_VAR(data__->TON0.Q,));
  __SET_LOCATED(data__->,LINEARACT,,__GET_EXTERNAL(data__->ST4,));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_EXTERNAL(data__->ST5,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_EXTERNAL(data__->ST0,));
  __SET_VAR(data__->CTU0.,PV,,5);
  CTU_body__(&data__->CTU0);
  __SET_EXTERNAL(data__->,COUNT_VALUE,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->TON1.,IN,,__GET_EXTERNAL(data__->ST5,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,TIME2DN,,__GET_VAR(data__->TON1.Q,));
  __SET_EXTERNAL(data__->,ST2,,(!(__GET_EXTERNAL(data__->ST3,)) && (__GET_EXTERNAL(data__->ST2,) || (__GET_LOCATED(data__->BOXBUT,) && __GET_EXTERNAL(data__->ST1,)))));
  __SET_EXTERNAL(data__->,ST3,,(!(__GET_EXTERNAL(data__->ST4,)) && (__GET_EXTERNAL(data__->ST3,) || (__GET_LOCATED(data__->BREAKBEAM,) && __GET_EXTERNAL(data__->ST2,)))));
  __SET_EXTERNAL(data__->,ST4,,(!(__GET_EXTERNAL(data__->ST5,)) && (__GET_EXTERNAL(data__->ST4,) || (__GET_VAR(data__->TIMEDN,) && __GET_EXTERNAL(data__->ST3,)))));
  __SET_EXTERNAL(data__->,ST5,,(!(__GET_EXTERNAL(data__->ST1,)) && (__GET_EXTERNAL(data__->ST5,) || (__GET_LOCATED(data__->BREAKBEAM2,) && __GET_EXTERNAL(data__->ST4,)))));
  __SET_EXTERNAL(data__->,ST1,,(!(__GET_EXTERNAL(data__->ST2,)) && ((__GET_EXTERNAL(data__->ST1,) || (__GET_LOCATED(data__->STARTBUT,) && __GET_EXTERNAL(data__->ST0,))) || (__GET_VAR(data__->TIME2DN,) && __GET_EXTERNAL(data__->ST5,)))));
  __SET_VAR(data__->,COUNTERDN,,__GET_VAR(data__->CTU0.Q,));

  goto __end;

__end:
  return;
} // MAIN_body__() 





