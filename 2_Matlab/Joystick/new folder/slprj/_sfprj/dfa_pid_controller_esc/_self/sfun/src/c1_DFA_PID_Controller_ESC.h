#ifndef __c1_DFA_PID_Controller_ESC_h__
#define __c1_DFA_PID_Controller_ESC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_DFA_PID_Controller_ESCInstanceStruct
#define typedef_SFc1_DFA_PID_Controller_ESCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_DFA_PID_Controller_ESC;
  uint32_T c1_method;
  boolean_T c1_method_not_empty;
  uint32_T c1_state[2];
  boolean_T c1_state_not_empty;
  uint32_T c1_b_method;
  boolean_T c1_b_method_not_empty;
  uint32_T c1_b_state;
  boolean_T c1_b_state_not_empty;
  uint32_T c1_c_state[2];
  boolean_T c1_c_state_not_empty;
  uint32_T c1_d_state[625];
  boolean_T c1_d_state_not_empty;
} SFc1_DFA_PID_Controller_ESCInstanceStruct;

#endif                                 /*typedef_SFc1_DFA_PID_Controller_ESCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
extern void c1_DFA_PID_Controller_ESC_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
