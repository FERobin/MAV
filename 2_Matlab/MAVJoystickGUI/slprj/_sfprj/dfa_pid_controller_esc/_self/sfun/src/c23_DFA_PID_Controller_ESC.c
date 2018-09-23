/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DFA_PID_Controller_ESC_sfun.h"
#include "c23_DFA_PID_Controller_ESC.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DFA_PID_Controller_ESC_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c23_debug_family_names[6] = { "nargin", "nargout",
  "beta_d_no_sat", "gamma_d_no_sat", "beta_desired", "gamma_desired" };

/* Function Declarations */
static void initialize_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance);
static void initialize_params_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance);
static void enable_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance);
static void disable_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance);
static void c23_update_debugger_state_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance);
static void set_sim_state_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance, const mxArray
   *c23_st);
static void finalize_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance);
static void sf_gateway_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance);
static void initSimStructsc23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance, const mxArray *c23_gamma_desired, const char_T *c23_identifier);
static real_T c23_b_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_c_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_d_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_DFA_PID_Controller_ESC,
  const char_T *c23_identifier);
static uint8_T c23_e_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_is_active_c23_DFA_PID_Controller_ESC = 0U;
}

static void initialize_params_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c23_update_debugger_state_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  real_T c23_hoistedGlobal;
  real_T c23_u;
  const mxArray *c23_b_y = NULL;
  real_T c23_b_hoistedGlobal;
  real_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  uint8_T c23_c_hoistedGlobal;
  uint8_T c23_c_u;
  const mxArray *c23_d_y = NULL;
  real_T *c23_beta_desired;
  real_T *c23_gamma_desired;
  c23_gamma_desired = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c23_beta_desired = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellmatrix(3, 1), false);
  c23_hoistedGlobal = *c23_beta_desired;
  c23_u = c23_hoistedGlobal;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_b_hoistedGlobal = *c23_gamma_desired;
  c23_b_u = c23_b_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  c23_c_hoistedGlobal = chartInstance->c23_is_active_c23_DFA_PID_Controller_ESC;
  c23_c_u = c23_c_hoistedGlobal;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 2, c23_d_y);
  sf_mex_assign(&c23_st, c23_y, false);
  return c23_st;
}

static void set_sim_state_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance, const mxArray
   *c23_st)
{
  const mxArray *c23_u;
  real_T *c23_beta_desired;
  real_T *c23_gamma_desired;
  c23_gamma_desired = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c23_beta_desired = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c23_doneDoubleBufferReInit = true;
  c23_u = sf_mex_dup(c23_st);
  *c23_beta_desired = c23_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 0)), "beta_desired");
  *c23_gamma_desired = c23_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 1)), "gamma_desired");
  chartInstance->c23_is_active_c23_DFA_PID_Controller_ESC =
    c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 2)),
    "is_active_c23_DFA_PID_Controller_ESC");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_DFA_PID_Controller_ESC(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance)
{
  real_T c23_hoistedGlobal;
  real_T c23_b_hoistedGlobal;
  real_T c23_beta_d_no_sat;
  real_T c23_gamma_d_no_sat;
  uint32_T c23_debug_family_var_map[6];
  real_T c23_nargin = 2.0;
  real_T c23_nargout = 2.0;
  real_T c23_beta_desired;
  real_T c23_gamma_desired;
  real_T *c23_b_beta_d_no_sat;
  real_T *c23_b_beta_desired;
  real_T *c23_b_gamma_d_no_sat;
  real_T *c23_b_gamma_desired;
  c23_b_gamma_desired = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c23_b_gamma_d_no_sat = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_b_beta_desired = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_b_beta_d_no_sat = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 20U, chartInstance->c23_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c23_b_beta_d_no_sat, 0U);
  chartInstance->c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c23_sfEvent);
  c23_hoistedGlobal = *c23_b_beta_d_no_sat;
  c23_b_hoistedGlobal = *c23_b_gamma_d_no_sat;
  c23_beta_d_no_sat = c23_hoistedGlobal;
  c23_gamma_d_no_sat = c23_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c23_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 0U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 1U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_beta_d_no_sat, 2U, c23_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c23_gamma_d_no_sat, 3U, c23_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_beta_desired, 4U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_gamma_desired, 5U,
    c23_sf_marshallOut, c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 3);
  c23_beta_desired = c23_beta_d_no_sat;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 4);
  c23_gamma_desired = c23_gamma_d_no_sat;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c23_beta_desired > 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 7);
    c23_beta_desired = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 8);
    if (CV_EML_IF(0, 1, 1, c23_beta_desired < -1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 9);
      c23_beta_desired = -1.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 12);
  if (CV_EML_IF(0, 1, 2, c23_gamma_desired > 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 13);
    c23_gamma_desired = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 14);
    if (CV_EML_IF(0, 1, 3, c23_gamma_desired < -1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 15);
      c23_gamma_desired = -1.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 18);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  *c23_b_beta_desired = c23_beta_desired;
  *c23_b_gamma_desired = c23_gamma_desired;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c23_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DFA_PID_Controller_ESCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c23_b_beta_desired, 1U);
  _SFD_DATA_RANGE_CHECK(*c23_b_gamma_d_no_sat, 2U);
  _SFD_DATA_RANGE_CHECK(*c23_b_gamma_desired, 3U);
}

static void initSimStructsc23_DFA_PID_Controller_ESC
  (SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber)
{
  (void)c23_machineNumber;
  (void)c23_chartNumber;
  (void)c23_instanceNumber;
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance;
  chartInstance = (SFc23_DFA_PID_Controller_ESCInstanceStruct *)
    chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance, const mxArray *c23_gamma_desired, const char_T *c23_identifier)
{
  real_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_gamma_desired),
    &c23_thisId);
  sf_mex_destroy(&c23_gamma_desired);
  return c23_y;
}

static real_T c23_b_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_gamma_desired;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance;
  chartInstance = (SFc23_DFA_PID_Controller_ESCInstanceStruct *)
    chartInstanceVoid;
  c23_gamma_desired = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_gamma_desired),
    &c23_thisId);
  sf_mex_destroy(&c23_gamma_desired);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray *sf_c23_DFA_PID_Controller_ESC_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  sf_mex_assign(&c23_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance;
  chartInstance = (SFc23_DFA_PID_Controller_ESCInstanceStruct *)
    chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static int32_T c23_c_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i0, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance;
  chartInstance = (SFc23_DFA_PID_Controller_ESCInstanceStruct *)
    chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_d_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance, const mxArray *c23_b_is_active_c23_DFA_PID_Controller_ESC,
  const char_T *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_active_c23_DFA_PID_Controller_ESC), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_DFA_PID_Controller_ESC);
  return c23_y;
}

static uint8_T c23_e_emlrt_marshallIn(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_DFA_PID_Controller_ESCInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c23_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(650668200U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3538839179U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4080782128U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2172398947U);
}

mxArray *sf_c23_DFA_PID_Controller_ESC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SuwAjpNPxn8UuejP4TROxC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c23_DFA_PID_Controller_ESC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c23_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c23_DFA_PID_Controller_ESC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"beta_desired\",},{M[1],M[7],T\"gamma_desired\",},{M[8],M[0],T\"is_active_c23_DFA_PID_Controller_ESC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_DFA_PID_Controller_ESC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc23_DFA_PID_Controller_ESCInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DFA_PID_Controller_ESCMachineNumber_,
           23,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_DFA_PID_Controller_ESCMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DFA_PID_Controller_ESCMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DFA_PID_Controller_ESCMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"beta_d_no_sat");
          _SFD_SET_DATA_PROPS(1,2,0,1,"beta_desired");
          _SFD_SET_DATA_PROPS(2,1,1,0,"gamma_d_no_sat");
          _SFD_SET_DATA_PROPS(3,2,0,1,"gamma_desired");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,353);
        _SFD_CV_INIT_EML_IF(0,1,0,149,169,192,217);
        _SFD_CV_INIT_EML_IF(0,1,1,192,217,-1,217);
        _SFD_CV_INIT_EML_IF(0,1,2,246,267,291,317);
        _SFD_CV_INIT_EML_IF(0,1,3,291,317,-1,317);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);

        {
          real_T *c23_beta_d_no_sat;
          real_T *c23_beta_desired;
          real_T *c23_gamma_d_no_sat;
          real_T *c23_gamma_desired;
          c23_gamma_desired = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            2);
          c23_gamma_d_no_sat = (real_T *)ssGetInputPortSignal(chartInstance->S,
            1);
          c23_beta_desired = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c23_beta_d_no_sat = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c23_beta_d_no_sat);
          _SFD_SET_DATA_VALUE_PTR(1U, c23_beta_desired);
          _SFD_SET_DATA_VALUE_PTR(2U, c23_gamma_d_no_sat);
          _SFD_SET_DATA_VALUE_PTR(3U, c23_gamma_desired);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DFA_PID_Controller_ESCMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3CDC68qIUG56orub9hQWiH";
}

static void sf_opaque_initialize_c23_DFA_PID_Controller_ESC(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_DFA_PID_Controller_ESCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_DFA_PID_Controller_ESC
    ((SFc23_DFA_PID_Controller_ESCInstanceStruct*) chartInstanceVar);
  initialize_c23_DFA_PID_Controller_ESC
    ((SFc23_DFA_PID_Controller_ESCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_DFA_PID_Controller_ESC(void *chartInstanceVar)
{
  enable_c23_DFA_PID_Controller_ESC((SFc23_DFA_PID_Controller_ESCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c23_DFA_PID_Controller_ESC(void *chartInstanceVar)
{
  disable_c23_DFA_PID_Controller_ESC((SFc23_DFA_PID_Controller_ESCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c23_DFA_PID_Controller_ESC(void *chartInstanceVar)
{
  sf_gateway_c23_DFA_PID_Controller_ESC
    ((SFc23_DFA_PID_Controller_ESCInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c23_DFA_PID_Controller_ESC
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_DFA_PID_Controller_ESC
    ((SFc23_DFA_PID_Controller_ESCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_DFA_PID_Controller_ESC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c23_DFA_PID_Controller_ESC(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c23_DFA_PID_Controller_ESC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_DFA_PID_Controller_ESC
    ((SFc23_DFA_PID_Controller_ESCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c23_DFA_PID_Controller_ESC
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c23_DFA_PID_Controller_ESC(S);
}

static void sf_opaque_set_sim_state_c23_DFA_PID_Controller_ESC(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c23_DFA_PID_Controller_ESC(S, st);
}

static void sf_opaque_terminate_c23_DFA_PID_Controller_ESC(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_DFA_PID_Controller_ESCInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DFA_PID_Controller_ESC_optimization_info();
    }

    finalize_c23_DFA_PID_Controller_ESC
      ((SFc23_DFA_PID_Controller_ESCInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_DFA_PID_Controller_ESC
    ((SFc23_DFA_PID_Controller_ESCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_DFA_PID_Controller_ESC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c23_DFA_PID_Controller_ESC
      ((SFc23_DFA_PID_Controller_ESCInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_DFA_PID_Controller_ESC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DFA_PID_Controller_ESC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,23,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,23);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2419419652U));
  ssSetChecksum1(S,(1291609424U));
  ssSetChecksum2(S,(2228794502U));
  ssSetChecksum3(S,(3407384440U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_DFA_PID_Controller_ESC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_DFA_PID_Controller_ESC(SimStruct *S)
{
  SFc23_DFA_PID_Controller_ESCInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc23_DFA_PID_Controller_ESCInstanceStruct *)utMalloc(sizeof
    (SFc23_DFA_PID_Controller_ESCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_DFA_PID_Controller_ESCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_DFA_PID_Controller_ESC;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c23_DFA_PID_Controller_ESC_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_DFA_PID_Controller_ESC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_DFA_PID_Controller_ESC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_DFA_PID_Controller_ESC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_DFA_PID_Controller_ESC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
