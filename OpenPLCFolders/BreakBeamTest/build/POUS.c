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
  __INIT_LOCATED(WORD,__IW0,data__->DIGITALREAD,retain)
  __INIT_LOCATED_VALUE(data__->DIGITALREAD,0)
  __INIT_EXTERNAL(WORD,DIGITALREADOUT,data__->DIGITALREADOUT,retain)
  __INIT_LOCATED(BOOL,__IX1_0,data__->USERBUTTON,retain)
  __INIT_LOCATED_VALUE(data__->USERBUTTON,0)
  __INIT_VAR(data__->GTBOOL,0,retain)
  __INIT_LOCATED(BOOL,__QX0_1,data__->MYOUT,retain)
  __INIT_LOCATED_VALUE(data__->MYOUT,1)
  __INIT_VAR(data__->_TMP_GT1_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE12_OUT,0,retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_GT1_OUT,,GT__BOOL__WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (WORD)100,
    (WORD)__GET_LOCATED(data__->DIGITALREAD,)));
  __SET_VAR(data__->,GTBOOL,,__GET_VAR(data__->_TMP_GT1_OUT,));
  __SET_LOCATED(data__->,MYOUT,,(__GET_VAR(data__->GTBOOL,) || __GET_LOCATED(data__->USERBUTTON,)));
  __SET_VAR(data__->,_TMP_MOVE12_OUT,,MOVE__WORD__WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)__GET_LOCATED(data__->DIGITALREAD,)));
  __SET_EXTERNAL(data__->,DIGITALREADOUT,,__GET_VAR(data__->_TMP_MOVE12_OUT,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





