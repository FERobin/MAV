#ifndef __c8_DFA_PID_Controller_ESC_h__
#define __c8_DFA_PID_Controller_ESC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_DFA_PID_Controller_ESCInstanceStruct
#define typedef_SFc8_DFA_PID_Controller_ESCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_isStable;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_DFA_PID_Controller_ESC;
  uint32_T c8_method;
  boolean_T c8_method_not_empty;
  uint32_T c8_state[2];
  boolean_T c8_state_not_empty;
  uint32_T c8_b_method;
  boolean_T c8_b_method_not_empty;
  uint32_T c8_b_state;
  boolean_T c8_b_state_not_empty;
  uint32_T c8_c_state[2];
  boolean_T c8_c_state_not_empty;
  uint32_T c8_d_state[625];
  boolean_T c8_d_state_not_empty;
} SFc8_DFA_PID_Controller_ESCInstanceStruct;

#endif                                 /*typedef_SFc8_DFA_PID_Controller_ESCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c8_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
extern void c8_DFA_PID_Controller_ESC_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
