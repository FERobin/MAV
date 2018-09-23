//use the following command
//mex  libport_ss.cpp SerialPort.cpp SerialStream.cc SerialStreamBuf.cc PosixSignalDispatcher.cpp -lpthread

#include "SerialStream.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iomanip>

#include "mex.h"

using namespace std;
using namespace LibSerial ;
SerialStream serial_port ;

#define NUM_STATES 16
#define CMD_STATES 3
const int CMD_OPEN_PORT =0;
const int CMD_READ = 1;
const int CMD_WRITE = 2;
const int CMD_CLOSE_PORT = 3;
const int CMD_START_MOTOR = 4;
const int CMD_STOP_MOTOR = 5;
const int CMD_READ_GAIN=6;
const int CMD_UPDATE_GAIN=7;
const int CMD_START_UPDATE_GAIN=8;
const int CMD_CALIB=9;
const int CMD_ANG_GAIN=10;
const int CMD_POS_GAIN=11;
const int CMD_WRITE_CLIMB=12;
const int CMD_GAIN_STATES=9;
const int CMD_WRITE_CLIMB_ASSIST=13;
double inputData[NUM_STATES]={0};

//Name: SetUp
//Function: Set up the serial port. Including the port number and the baud rate
//Input: None
//Output: None
void SetUp(char* port)
{
    //
    // Open the serial port.
    //

    //serial_port.Open( string(port) ) ;
    serial_port.Open( "/dev/ttyUSB0" ) ;
   
    //
    // Set the baud rate of the serial port.
    //
    serial_port.SetBaudRate( SerialStreamBuf::BAUD_57600) ;
  
    //
    // Set the number of data bits.
    //
    serial_port.SetCharSize( SerialStreamBuf::CHAR_SIZE_8 ) ;
    
    //
    // Disable parity.
    //
    serial_port.SetParity( SerialStreamBuf::PARITY_NONE ) ;
     
    //
    // Set the number of stop bits.
    //
    serial_port.SetNumOfStopBits( 1 ) ;
    
    // Turn off hardware flow control.
    //
    serial_port.SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE ) ;
}
//Name: WriteGain
//Function: update the gain for the LQR controller
//Input: state array (NUM_STATES x 1)
//Output: None
void WriteGain(double state[],int cmd)
{
    stringstream ss;
    
    //formate the input. Begin with d
    if (cmd==CMD_ANG_GAIN)
    {
        ss<<fixed<<setprecision(3)<<'a';
    }
    else if (cmd==CMD_POS_GAIN)
    {
        ss<<fixed<<setprecision(3)<<'g';
    }
    for (int i =0; i<CMD_GAIN_STATES; i++){
        ss<<state[i]<<'z';
    }
    ss<<endl;
    cout<<ss.str();
    //convert from string stream to char array
    string str;
    str=ss.str();
    
    //write it to the port
    serial_port.write(str.c_str(),str.length());
}
//Name: WriteData
//Function: Write the data in a special format to the serial port
//Input: state array (NUM_STATESx1)
//Output: None
void WriteData(double state[],int flag)
{
    stringstream ss;
    if (flag==CMD_WRITE_CLIMB)
    {
    //formate the input. Begin with d
        ss<<fixed<<setprecision(3)<<'e';
        for (int i =0; i<CMD_STATES; i++)
        {
            ss<<state[i]<<'z';
         }
    }
    else if (flag==CMD_WRITE_CLIMB_ASSIST)
    {
        ss<<fixed<<setprecision(3)<<'f';//start with f
        for (int i =0; i<CMD_STATES; i++)
        {
            ss<<state[i]<<'z';
         }
    }
    else
    {
        ss<<fixed<<setprecision(0)<<'d';
         for (int i =0; i<4; i++)
         {
            ss<<state[i]<<'z';
        }
    }
   
    ss<<endl;
    cout<<ss.str();
    //convert from string stream to char array
    string str;
    str=ss.str();
    
    //write it to the port
    serial_port.write(str.c_str(),str.length());
}
//Name: WriteCmd
//Function: Write the command to the serial port
//Input: cmd
//Output: None
void WriteCmd(int cmd)
{
    stringstream ss;
        
    string str;
    if (cmd==CMD_START_MOTOR)
    {
        ss<<'t'<<'\n';
    }
    else if (cmd==CMD_STOP_MOTOR)
    {
        ss<<'o'<<'\n';
    }
    else if (cmd==CMD_CALIB)
    {
        ss<<'c'<<'\n';
    }
    
    str=ss.str();
    serial_port.write(str.c_str(),str.length());
}
    
//Name: GetData
//Function: Read the data and parse the input to get the angles.
//Input: None
//Output: None
void GetData(int inputNum)
{
    int count=0;
    int timecount=0;
    //read until timeout or get something in the buffer
    while( serial_port.rdbuf()->in_avail() == 0 &&timecount<10) //add a timeout
    {
        usleep(100) ;
        timecount++;
    }
    //keep reading until it gets the new line
    stringstream ss;
    string str;
    char next_byte;
    serial_port.get(next_byte);
    count=0;
    
    timecount=0;
    while( next_byte!='\n'&&count<inputNum && timecount<200) 
    {
        //reading until it gets a comma
        if (next_byte!=',')
        {
            ss<<next_byte;
        }
        else
        {
            //convert the data to a double variable and store it to an array
            ss>>inputData[count];
            count=count+1;
            ss.clear();
            ss.str("");//reset the stringstream
        }
        serial_port.get(next_byte);
        timecount=timecount+1;   
    }      
}

//Name: GetData
//Function: Read the data and parse the input to get the angles.
//Input: inputNum is the number to read. 
//     : ptData is a pointer to the storage
//Output: None
void GetGainData(int inputNum,double * ptData)
{
    int count=0;
    int timecount=0;
    cout<<"stuck here"<<endl;
    //read until timeout or get something in the buffer
    while( serial_port.rdbuf()->in_avail() == 0 &&timecount<100) //add a timeout
    {
        usleep(100) ;
        timecount++;
        cout<<"timecount"<<timecount;
    }
    //keep reading until it gets the new line
    stringstream ss;
    string str;
    char next_byte;
    serial_port.get(next_byte);
    count=0;
    cout<<"get input1"<<endl;
    timecount=0;
    while( count<inputNum && timecount<200) 
    {
        //reading until it gets a comma
        if (next_byte!=',')
        {
            ss<<next_byte;
        }
        else
        {
            //convert the data to a double variable and store it to an array
            ss>>ptData[count];
            
            cout<<"get input2"<<endl;
            cout << ptData[count]<< endl;
            count=count+1;
            ss.clear();
            ss.str("");//reset the stringstream
        }
        serial_port.get(next_byte);
        timecount=timecount+1;   
    }      
}
void mexFunction(int nlhs,mxArray *plhs[],int nrhs, const mxArray *prhs[])
{
    double *inputGain;
    double* state;
    char* port;
    double *cmd1;
    double *cmd2;
    double *cmd3;
    double *cmd4;
    size_t mrows,ncols;
    size_t buflen;
    
    

            
    //get the command number, which determines what will happen afterwards.
    int cmd = (int)(*(mxGetPr(prhs[0]) ) );
    
    switch(cmd)
    {
        case CMD_OPEN_PORT:
            /*initialize the serial*/
            //input must be a string
            if (!mxIsChar(prhs[1]))
                mexErrMsgIdAndTxt( "MATLAB:libport_ss:inputNotString",
                "Input must be a string.");

            // input must be a row vector
            if (mxGetM(prhs[0])!=1)
              mexErrMsgIdAndTxt( "MATLAB:libport_ss:inputNotVector",
                      "Input must be a row vector.");
            
            // Copy string buffer into port variable
            port = mxArrayToString(prhs[1]);
            
            // Call the setup subroutine
            SetUp(port);
            cout << "Initialize Serial" << endl;
            
            // Free the memory allocated by the mxArrayToString function
            mxFree(port);
            break;
        case CMD_READ:
            //read from serial
            
            //ensure correct number of outputs
            if(nlhs != 4){
                mexErrMsgIdAndTxt("MATLAB:libport_ss:outputIncorrect", 
                        "Expecting 4 output parameters");
            }
            //read data from the serial buffer
            //read four motor speed
            
            GetData(4);
            
            plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
            plhs[1]=mxCreateDoubleMatrix(1,1,mxREAL);
            plhs[2]=mxCreateDoubleMatrix(1,1,mxREAL);
            plhs[3]=mxCreateDoubleMatrix(1,1,mxREAL);
            cmd1 = mxGetPr(plhs[0]);
            cmd2 = mxGetPr(plhs[1]);
            cmd3 = mxGetPr(plhs[2]);
            cmd4 = mxGetPr(plhs[3]);
            *cmd1 = inputData[0];
            *cmd2 = inputData[1];
            *cmd3 = inputData[2];
            *cmd4 = inputData[3];
            //write data to outputs
            // *s_dis=demo.distance;
            //set up output variables
            
            

            break;    
        case CMD_WRITE_CLIMB_ASSIST:
            mrows = mxGetM(prhs[1]);
            ncols = mxGetN(prhs[1]);
            if( !mxIsDouble(prhs[1]) || mxIsComplex(prhs[1]) ||
                !(mrows==CMD_STATES && ncols==1) ) {
                mexErrMsgIdAndTxt( "MATLAB:libport_ss:inputNotCorrect",
                    "Input must be a noncomplex NUM_STATESx1 double array.");
            }
            // extract the data from the arguments (as an array)
            state = mxGetPr(prhs[1]);
            // pass it to this function which will deal with it
            WriteData(state,CMD_WRITE_CLIMB_ASSIST); 
           break;
        case CMD_WRITE_CLIMB:
            mrows = mxGetM(prhs[1]);
            ncols = mxGetN(prhs[1]);
            if( !mxIsDouble(prhs[1]) || mxIsComplex(prhs[1]) ||
                !(mrows==CMD_STATES && ncols==1) ) {
                mexErrMsgIdAndTxt( "MATLAB:libport_ss:inputNotCorrect",
                    "Input must be a noncomplex NUM_STATESx1 double array.");
            }
            // extract the data from the arguments (as an array)
            state = mxGetPr(prhs[1]);
            // pass it to this function which will deal with it
            WriteData(state,CMD_WRITE_CLIMB); 
           break;
        case CMD_WRITE:
            // write the command
            // check that data is correct size
            mrows = mxGetM(prhs[1]);
            ncols = mxGetN(prhs[1]);
            if( !mxIsDouble(prhs[1]) || mxIsComplex(prhs[1]) ||
                !(mrows==4 && ncols==1) ) {
                mexErrMsgIdAndTxt( "MATLAB:libport_ss:inputNotCorrect",
                    "Input must be a noncomplex NUM_STATESx1 double array.");
            }
            // extract the data from the arguments (as an array)
            state = mxGetPr(prhs[1]);
            // pass it to this function which will deal with it
            WriteData(state,CMD_WRITE);
            break;
         
        case CMD_ANG_GAIN:
            mrows = mxGetM(prhs[1]);
            ncols = mxGetN(prhs[1]);
            if( !mxIsDouble(prhs[1]) || mxIsComplex(prhs[1]) ||
                !(mrows==CMD_GAIN_STATES && ncols==1) ) {
                mexErrMsgIdAndTxt( "MATLAB:libport_ss:inputNotCorrect",
                    "Input must be a noncomplex NUM_STATESx1 double array.");
            }
            // extract the data from the arguments (as an array)
            state = mxGetPr(prhs[1]);
            // pass it to this function which will deal with it
            WriteGain(state,CMD_ANG_GAIN);
            break;
        case CMD_POS_GAIN:
            mrows = mxGetM(prhs[1]);
            ncols = mxGetN(prhs[1]);
            if( !mxIsDouble(prhs[1]) || mxIsComplex(prhs[1]) ||
                !(mrows==CMD_GAIN_STATES && ncols==1) ) {
                mexErrMsgIdAndTxt( "MATLAB:libport_ss:inputNotCorrect",
                    "Input must be a noncomplex NUM_STATESx1 double array.");
            }
            // extract the data from the arguments (as an array)
            state = mxGetPr(prhs[1]);
            // pass it to this function which will deal with it
            WriteGain(state,CMD_POS_GAIN);
            break;
 
        case CMD_READ_GAIN:
            if(nlhs != 1){
                mexErrMsgIdAndTxt("MATLAB:libport_ss:outputIncorrect", 
                        "Expecting 4 output parameters");
            }
            plhs[0]=mxCreateDoubleMatrix(1,16,mxREAL);
            inputGain=mxGetPr(plhs[0]);//get the value
            GetGainData(16,inputGain);
             
            break;
        case CMD_CALIB:
            WriteCmd(CMD_CALIB);
            break;
        case CMD_CLOSE_PORT:
            //close the serial
            if (serial_port.IsOpen()==1)
            {
                serial_port.Close();
            }
            break;
        case CMD_START_MOTOR:
            WriteCmd(CMD_START_MOTOR);
            break;
        case CMD_STOP_MOTOR:
            WriteCmd(CMD_STOP_MOTOR);
            break;
    }
    
 
     return;
}