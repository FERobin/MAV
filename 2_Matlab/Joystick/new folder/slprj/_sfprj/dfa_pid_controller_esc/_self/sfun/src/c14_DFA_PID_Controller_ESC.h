#ifndef __c14_DFA_PID_Controller_ESC_h__
#define __c14_DFA_PID_Controller_ESC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc14_DFA_PID_Controller_ESCInstanceStruct
#define typedef_SFc14_DFA_PID_Controller_ESCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c14_sfEvent;
  boolean_T c14_isStable;
  boolean_T c14_doneDoubleBufferReInit;
  uint8_T c14_is_active_c14_DFA_PID_Controller_ESC;
  uint32_T c14_method;
  boolean_T c14_method_not_empty;
  uint32_T c14_state[2];
  boolean_T c14_state_not_empty;
  uint32_T c14_b_method;
  boolean_T c14_b_method_not_empty;
  uint32_T c14_b_state;
  boolean_T c14_b_state_not_empty;
  uint32_T c14_c_state[2];
  boolean_T c14_c_state_not_empty;
  uint32_T c14_d_state[625];
  boolean_T c14_d_state_not_empty;
} SFc14_DFA_PID_Controller_ESCInstanceStruct;

#endif                                 /*typedef_SFc14_DFA_PID_Controller_ESCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c14_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c14_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
extern void c14_DFA_PID_Controller_ESC_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
