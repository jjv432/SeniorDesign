/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

#include "accessor.h"

#include "POUS.h"

// CONFIGURATION CONFIG0
__DECLARE_GLOBAL(BOOL,CONFIG0,STEPRUN)
__DECLARE_GLOBAL(BOOL,CONFIG0,STEPDONE)

void RES0_init__(void);

void config_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(BOOL,STEPRUN,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  __INIT_GLOBAL(BOOL,STEPDONE,__INITIAL_VALUE(__BOOL_LITERAL(FALSE)),retain)
  RES0_init__();
}

void RES0_run__(unsigned long tick);

void config_run__(unsigned long tick) {
  RES0_run__(tick);
}
unsigned long long common_ticktime__ = 20000000ULL; /*ns*/
unsigned long greatest_tick_count__ = (unsigned long)0UL; /*tick*/
