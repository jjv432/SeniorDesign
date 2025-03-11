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
  __INIT_VAR(data__->BOXBUT,0,retain)
  __INIT_VAR(data__->STARTBUT,0,retain)
  __INIT_VAR(data__->MY_TIME,0,retain)
  __INIT_VAR(data__->BB,0,retain)
  __INIT_VAR(data__->BB2,0,retain)
  __INIT_VAR(data__->MOTOR,0,retain)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_EXTERNAL(data__->,ST1,,((!(__GET_EXTERNAL(data__->ST0,)) && (__GET_EXTERNAL(data__->ST1,) || (__GET_VAR(data__->MY_TIME,) && __GET_EXTERNAL(data__->ST5,)))) || (!(__GET_EXTERNAL(data__->ST2,)) && (__GET_EXTERNAL(data__->ST1,) || (__GET_VAR(data__->STARTBUT,) && __GET_EXTERNAL(data__->ST0,))))));
  __SET_EXTERNAL(data__->,ST0,,((((!(__GET_EXTERNAL(data__->ST5,)) && !(__GET_EXTERNAL(data__->ST4,))) && !(__GET_EXTERNAL(data__->ST3,))) && !(__GET_EXTERNAL(data__->ST2,))) && !(__GET_EXTERNAL(data__->ST1,))));
  __SET_EXTERNAL(data__->,ST2,,(!(__GET_EXTERNAL(data__->ST3,)) && (__GET_EXTERNAL(data__->ST2,) || (__GET_VAR(data__->BOXBUT,) && __GET_EXTERNAL(data__->ST0,)))));
  __SET_EXTERNAL(data__->,ST3,,(!(__GET_EXTERNAL(data__->ST4,)) && (__GET_EXTERNAL(data__->ST3,) || (__GET_VAR(data__->BB,) && __GET_EXTERNAL(data__->ST2,)))));
  __SET_EXTERNAL(data__->,ST4,,(!(__GET_EXTERNAL(data__->ST5,)) && (__GET_EXTERNAL(data__->ST4,) || (__GET_VAR(data__->MY_TIME,) && __GET_EXTERNAL(data__->ST3,)))));
  __SET_EXTERNAL(data__->,ST5,,(!(__GET_EXTERNAL(data__->ST0,)) && (__GET_EXTERNAL(data__->ST5,) || (__GET_VAR(data__->BB2,) && __GET_EXTERNAL(data__->ST4,)))));
  __SET_VAR(data__->,MOTOR,,!(__GET_EXTERNAL(data__->ST0,)));
  __SET_VAR(data__->,MOTOR,,((((__GET_EXTERNAL(data__->ST1,) || __GET_EXTERNAL(data__->ST2,)) || __GET_EXTERNAL(data__->ST3,)) || __GET_EXTERNAL(data__->ST4,)) || __GET_EXTERNAL(data__->ST5,)));

  goto __end;

__end:
  return;
} // MAIN_body__() 





