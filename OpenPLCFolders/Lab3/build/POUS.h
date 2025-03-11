#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM MAIN
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_EXTERNAL(BOOL,ST0)
  __DECLARE_EXTERNAL(BOOL,ST1)
  __DECLARE_EXTERNAL(BOOL,ST2)
  __DECLARE_EXTERNAL(BOOL,ST3)
  __DECLARE_EXTERNAL(BOOL,ST4)
  __DECLARE_EXTERNAL(BOOL,ST5)
  __DECLARE_VAR(BOOL,BOXBUT)
  __DECLARE_VAR(BOOL,STARTBUT)
  __DECLARE_VAR(BOOL,MY_TIME)
  __DECLARE_VAR(BOOL,BB)
  __DECLARE_VAR(BOOL,BB2)
  __DECLARE_VAR(BOOL,MOTOR)

} MAIN;

void MAIN_init__(MAIN *data__, BOOL retain);
// Code part
void MAIN_body__(MAIN *data__);
#endif //__POUS_H
