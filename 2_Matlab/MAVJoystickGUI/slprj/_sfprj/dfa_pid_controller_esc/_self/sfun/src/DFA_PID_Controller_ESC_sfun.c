/* Include files */

#include "DFA_PID_Controller_ESC_sfun.h"
#include "DFA_PID_Controller_ESC_sfun_debug_macros.h"
#include "c1_DFA_PID_Controller_ESC.h"
#include "c2_DFA_PID_Controller_ESC.h"
#include "c3_DFA_PID_Controller_ESC.h"
#include "c4_DFA_PID_Controller_ESC.h"
#include "c5_DFA_PID_Controller_ESC.h"
#include "c6_DFA_PID_Controller_ESC.h"
#include "c7_DFA_PID_Controller_ESC.h"
#include "c8_DFA_PID_Controller_ESC.h"
#include "c9_DFA_PID_Controller_ESC.h"
#include "c10_DFA_PID_Controller_ESC.h"
#include "c11_DFA_PID_Controller_ESC.h"
#include "c12_DFA_PID_Controller_ESC.h"
#include "c13_DFA_PID_Controller_ESC.h"
#include "c14_DFA_PID_Controller_ESC.h"
#include "c15_DFA_PID_Controller_ESC.h"
#include "c16_DFA_PID_Controller_ESC.h"
#include "c17_DFA_PID_Controller_ESC.h"
#include "c18_DFA_PID_Controller_ESC.h"
#include "c19_DFA_PID_Controller_ESC.h"
#include "c20_DFA_PID_Controller_ESC.h"
#include "c21_DFA_PID_Controller_ESC.h"
#include "c23_DFA_PID_Controller_ESC.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _DFA_PID_Controller_ESCMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void DFA_PID_Controller_ESC_initializer(void)
{
}

void DFA_PID_Controller_ESC_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DFA_PID_Controller_ESC_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_DFA_PID_Controller_ESC_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DFA_PID_Controller_ESC_process_check_sum_call( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(33080317U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2097275721U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3966074886U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(857405134U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(32205325U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(200927115U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3752556696U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4278901220U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c1_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c2_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c3_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c4_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c5_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c6_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c7_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c8_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c9_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c10_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c11_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c12_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c13_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c14_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c15_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c16_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c17_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c18_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c19_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c20_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c21_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_DFA_PID_Controller_ESC_get_check_sum(mxArray *plhs[]);
          sf_c23_DFA_PID_Controller_ESC_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1507291035U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2987879926U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4231484720U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3823050707U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DFA_PID_Controller_ESC_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "3ovIhrZcf4EW5Hux3XztBD") == 0) {
          extern mxArray *sf_c1_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "HzWwRvYiLmGq9dZBCrIqdH") == 0) {
          extern mxArray *sf_c2_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "Izck0mi7GFv3xTrpJp067G") == 0) {
          extern mxArray *sf_c3_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c3_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "HAf8S56zIOyn4whJrSBhGC") == 0) {
          extern mxArray *sf_c4_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "dYN1bO6fFo70i8OQxpuSBF") == 0) {
          extern mxArray *sf_c5_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "TWaZlOrtRhj5IQ1GpyRsWF") == 0) {
          extern mxArray *sf_c6_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c6_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "AXKQhXtAuZLx05RXnJPcyE") == 0) {
          extern mxArray *sf_c7_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c7_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "qphuKQm7jgjnjQY0Wbqu0D") == 0) {
          extern mxArray *sf_c8_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "NumFC8UhOoIH6XIGxbqXWG") == 0) {
          extern mxArray *sf_c9_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "FE47lASv8eTFGAt0rELzLG") == 0) {
          extern mxArray *sf_c10_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c10_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "boqJfXJ9P0DOx4bBZQJJmH") == 0) {
          extern mxArray *sf_c11_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "WpeMYXCyhqBTZ92SlK5rhE") == 0) {
          extern mxArray *sf_c12_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c12_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "2GqiI5aCyLlaUooDgGPFMD") == 0) {
          extern mxArray *sf_c13_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c13_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "dRRy911oOIEZyzhioHCLzG") == 0) {
          extern mxArray *sf_c14_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c14_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "x6ZXlBHLjSBCQjDHPdwY9C") == 0) {
          extern mxArray *sf_c15_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c15_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "a8D2uyZg3jACBIeLU4W34E") == 0) {
          extern mxArray *sf_c16_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c16_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "2OQ9aU8kURCmQBm0N8WDjF") == 0) {
          extern mxArray *sf_c17_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c17_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "dmoHaK2N4Nwa7u9Dh89m3E") == 0) {
          extern mxArray *sf_c18_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c18_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "ooj4suocicp49YvHGTOB7D") == 0) {
          extern mxArray *sf_c19_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c19_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "S2Vd976CUAmV2037qXDaME") == 0) {
          extern mxArray *sf_c20_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c20_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "KVIh3lGiSlKmD2onNEbI9B") == 0) {
          extern mxArray *sf_c21_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c21_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
        if (strcmp(aiChksum, "SuwAjpNPxn8UuejP4TROxC") == 0) {
          extern mxArray *sf_c23_DFA_PID_Controller_ESC_get_autoinheritance_info
            (void);
          plhs[0] = sf_c23_DFA_PID_Controller_ESC_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DFA_PID_Controller_ESC_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_DFA_PID_Controller_ESC_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_DFA_PID_Controller_ESC_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DFA_PID_Controller_ESC_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "nzGJGmykdifDqJsM7OEyP") == 0) {
          extern mxArray *sf_c1_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c1_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "JXZ1FMRLIFEEOqXYs4vr5D") == 0) {
          extern mxArray *sf_c2_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c2_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "hcBj7agYjfgKOAjwrNZHX") == 0) {
          extern mxArray *sf_c3_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c3_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "eQd54rJh5wFQG4lv6ploxG") == 0) {
          extern mxArray *sf_c4_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c4_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "3Tj8DrJeWC9AQrHnR6K6QD") == 0) {
          extern mxArray *sf_c5_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c5_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "2NOIiRZu99KmZ81eqBvCSE") == 0) {
          extern mxArray *sf_c6_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c6_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "A5NUSzcVjbLjunDr9wgBTG") == 0) {
          extern mxArray *sf_c7_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c7_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "mAp2klrbPXt53h1iLPLCWG") == 0) {
          extern mxArray *sf_c8_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c8_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "dMJD8axvMJRRGa1QtW30WD") == 0) {
          extern mxArray *sf_c9_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c9_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "RtuO8zVPVEieVZiR8EN6fF") == 0) {
          extern mxArray *sf_c10_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c10_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "cTAXdnFSgtFXXf60U0uZeB") == 0) {
          extern mxArray *sf_c11_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c11_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "MGdsaK2jJhTuM0okFg4uiH") == 0) {
          extern mxArray *sf_c12_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c12_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "Nio4Mb7BeSb34BxbwjElLG") == 0) {
          extern mxArray *sf_c13_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c13_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "rLEIQd7Umlx8TnMNjFTFDE") == 0) {
          extern mxArray *sf_c14_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c14_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "wMGZHqdwXSN2yzMOzIrot") == 0) {
          extern mxArray *sf_c15_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c15_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "dhHhJdfRnVzJAh5iXGXmqF") == 0) {
          extern mxArray *sf_c16_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c16_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "UEDfr585FdRmPJDCg8lanD") == 0) {
          extern mxArray *sf_c17_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c17_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "y1F7wcKsAlKjyKQSaV2wrD") == 0) {
          extern mxArray *sf_c18_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c18_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "TjFYNUcxzmmQLJSbzL39q") == 0) {
          extern mxArray *sf_c19_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c19_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "rTpe0Stry7zaso4EkhPeLH") == 0) {
          extern mxArray *sf_c20_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c20_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "Ihwtnb7Yqk0zUGt2ss4bGC") == 0) {
          extern mxArray *sf_c21_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c21_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "3CDC68qIUG56orub9hQWiH") == 0) {
          extern mxArray *sf_c23_DFA_PID_Controller_ESC_third_party_uses_info
            (void);
          plhs[0] = sf_c23_DFA_PID_Controller_ESC_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DFA_PID_Controller_ESC_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "nzGJGmykdifDqJsM7OEyP") == 0) {
          extern mxArray *sf_c1_DFA_PID_Controller_ESC_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c1_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "JXZ1FMRLIFEEOqXYs4vr5D") == 0) {
          extern mxArray *sf_c2_DFA_PID_Controller_ESC_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c2_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "hcBj7agYjfgKOAjwrNZHX") == 0) {
          extern mxArray *sf_c3_DFA_PID_Controller_ESC_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c3_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "eQd54rJh5wFQG4lv6ploxG") == 0) {
          extern mxArray *sf_c4_DFA_PID_Controller_ESC_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c4_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "3Tj8DrJeWC9AQrHnR6K6QD") == 0) {
          extern mxArray *sf_c5_DFA_PID_Controller_ESC_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c5_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "2NOIiRZu99KmZ81eqBvCSE") == 0) {
          extern mxArray *sf_c6_DFA_PID_Controller_ESC_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c6_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "A5NUSzcVjbLjunDr9wgBTG") == 0) {
          extern mxArray *sf_c7_DFA_PID_Controller_ESC_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c7_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "mAp2klrbPXt53h1iLPLCWG") == 0) {
          extern mxArray *sf_c8_DFA_PID_Controller_ESC_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c8_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "dMJD8axvMJRRGa1QtW30WD") == 0) {
          extern mxArray *sf_c9_DFA_PID_Controller_ESC_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c9_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "RtuO8zVPVEieVZiR8EN6fF") == 0) {
          extern mxArray
            *sf_c10_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "cTAXdnFSgtFXXf60U0uZeB") == 0) {
          extern mxArray
            *sf_c11_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "MGdsaK2jJhTuM0okFg4uiH") == 0) {
          extern mxArray
            *sf_c12_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "Nio4Mb7BeSb34BxbwjElLG") == 0) {
          extern mxArray
            *sf_c13_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "rLEIQd7Umlx8TnMNjFTFDE") == 0) {
          extern mxArray
            *sf_c14_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "wMGZHqdwXSN2yzMOzIrot") == 0) {
          extern mxArray
            *sf_c15_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c15_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "dhHhJdfRnVzJAh5iXGXmqF") == 0) {
          extern mxArray
            *sf_c16_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c16_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "UEDfr585FdRmPJDCg8lanD") == 0) {
          extern mxArray
            *sf_c17_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c17_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "y1F7wcKsAlKjyKQSaV2wrD") == 0) {
          extern mxArray
            *sf_c18_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c18_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "TjFYNUcxzmmQLJSbzL39q") == 0) {
          extern mxArray
            *sf_c19_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c19_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "rTpe0Stry7zaso4EkhPeLH") == 0) {
          extern mxArray
            *sf_c20_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c20_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "Ihwtnb7Yqk0zUGt2ss4bGC") == 0) {
          extern mxArray
            *sf_c21_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c21_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "3CDC68qIUG56orub9hQWiH") == 0) {
          extern mxArray
            *sf_c23_DFA_PID_Controller_ESC_updateBuildInfo_args_info(void);
          plhs[0] = sf_c23_DFA_PID_Controller_ESC_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void DFA_PID_Controller_ESC_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _DFA_PID_Controller_ESCMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"DFA_PID_Controller_ESC","sfun",0,22,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _DFA_PID_Controller_ESCMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _DFA_PID_Controller_ESCMachineNumber_,0);
}

void DFA_PID_Controller_ESC_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_DFA_PID_Controller_ESC_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "DFA_PID_Controller_ESC", "DFA_PID_Controller_ESC");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_DFA_PID_Controller_ESC_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
