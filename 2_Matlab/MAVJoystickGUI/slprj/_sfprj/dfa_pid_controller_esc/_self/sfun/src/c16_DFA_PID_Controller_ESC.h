#ifndef __c16_DFA_PID_Controller_ESC_h__
#define __c16_DFA_PID_Controller_ESC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc16_DFA_PID_Controller_ESCInstanceStruct
#define typedef_SFc16_DFA_PID_Controller_ESCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c16_sfEvent;
  boolean_T c16_isStable;
  boolean_T c16_doneDoubleBufferReInit;
  uint8_T c16_is_active_c16_DFA_PID_Controller_ESC;
} SFc16_DFA_PID_Controller_ESCInstanceStruct;

#endif                                 /*typedef_SFc16_DFA_PID_Controller_ESCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c16_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
extern void c16_DFA_PID_Controller_ESC_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
