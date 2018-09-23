//use the following command
//mex  libport.cpp SerialPort.cpp SerialStream.cc SerialStreamBuf.cc PosixSignalDispatcher.cpp -lpthread

#include <SerialStream.h>
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
double zDes=0.0;
double rollDes=0.0;
double pitchDes=0.0;
double yawDes=0.0;
double inputData[6]={0,0,0,0,0,0};

const int CMD_START=4;
const int CMD_STOP=5;
//Name: SetUp
//Function: Set up the serial port. Including the port number and the baud rate
//Input: None
//Output: None
void SetUp(void)
{
    //
    // Open the serial port.
    //

    serial_port.Open( "/dev/ttyUSB1") ;
   
    //
    // Set the baud rate of the serial port.
    //
    serial_port.SetBaudRate( SerialStreamBuf::BAUD_115200) ;
  
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

//Name: WriteData
//Function: Write the data in a special format to the serial port
//Input: posx is the position in x direction (mm)
//       posy is the position in y direction (mm)
//       posz is the position in z direction (mm)
//       roll is the roll angle (radius)
//       pitch is the pitch angle (radius)
//       yaw is the yaw angle (radius)
//Output: None
void WriteData(double posx,double posy,double posz,double roll,double pitch,double yaw)
{
    stringstream ss;
    
    //formate the input. Begin with d
    ss<<fixed<<setprecision(3)<<'d'<<posx<<'z'<<posy<<'z'<<posz<<'z'<<roll<<'z'<<pitch<<'z'<<yaw<<'z'<<endl;
    string str;
    str=ss.str();
    //convert from string stram to char array
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
    if (cmd==CMD_START)
    {
        ss<<'t'<<'\n';
        str=ss.str();
        serial_port.write(str.c_str(),str.length());
    }
    else if (cmd==CMD_STOP)
    {
        ss<<'o'<<'\n';
        str=ss.str();
        serial_port.write(str.c_str(),str.length());
    }
}
    
//Name: GetData
//Function: Read the data and parse the input to get the angles.
//Input: None
//Output: None
void GetData(void)
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
    
    int totalcount=0;
    while(timecount<10&& next_byte!='\n'&&count<6 ) 
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
       
        
    } 
     
}


void mexFunction(int nlhs,mxArray *plhs[],int nrhs, const mxArray *prhs[])
{
    double posx=0.0;
    double posy=0.0;
    double posz=0.0;
    double roll=0.0;
    double pitch=0.0;
    double yaw=0.0;
    
    //get the command number, which determines what will happen afterwards.
    int cmd=(int)(*(mxGetPr(prhs[0])));
    
    if (nrhs==7)
    {
        //get input position and angles
         posx=(*(mxGetPr(prhs[1])));
         posy=(*(mxGetPr(prhs[2])));
         posz=(*(mxGetPr(prhs[3])));
         roll=(*(mxGetPr(prhs[4])));
         pitch=(*(mxGetPr(prhs[5])));
         yaw=(*(mxGetPr(prhs[6])));
    }
    if (cmd==0)
    {
        //initialize the serial
           SetUp();

          cout << "Initialize Serial" << endl;
    
       
    }
    else if (cmd==1)
    {
        //read from serial
        GetData();
        
    }
    else if (cmd==2)
    {
        //write the command
        WriteData(posx,posy,posz,roll,pitch,yaw);
    }
    else if (cmd==3)
    {
        //close the serial
        if (serial_port.IsOpen()==1)
        {
            serial_port.Close();
        }
    }
    else if (cmd==CMD_START)
    {
        WriteCmd(CMD_START);
    }
    else if (cmd==CMD_STOP)
    {
        WriteCmd(CMD_STOP);
    }
    if (nlhs==3)
    {
         
     
        plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
        plhs[1]=mxCreateDoubleMatrix(1,1,mxREAL);

        plhs[2]=mxCreateDoubleMatrix(1,1,mxREAL); 
         double *pdesZ=mxGetPr(plhs[0]);
         double *pdesRoll=mxGetPr(plhs[1]);
         double *pdesPitch=mxGetPr(plhs[2]); 

         *pdesZ=inputData[0];
         *pdesRoll=inputData[1];
         *pdesPitch=inputData[2]; 
    }
    if (nlhs==4)
    {
        plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
        plhs[1]=mxCreateDoubleMatrix(1,1,mxREAL);

        plhs[2]=mxCreateDoubleMatrix(1,1,mxREAL);
        plhs[3]=mxCreateDoubleMatrix(1,1,mxREAL);
         double *pdesZ=mxGetPr(plhs[0]);
         double *pdesRoll=mxGetPr(plhs[1]);
         double *pdesPitch=mxGetPr(plhs[2]);
         double *pdesYaw=mxGetPr(plhs[3]);

         *pdesZ=inputData[0];
         *pdesRoll=inputData[1];
         *pdesPitch=inputData[2];
         *pdesYaw=inputData[3];
    }
    if (nlhs==6)
    {
        plhs[0]=mxCreateDoubleMatrix(1,1,mxREAL);
        plhs[1]=mxCreateDoubleMatrix(1,1,mxREAL);

        plhs[2]=mxCreateDoubleMatrix(1,1,mxREAL);
        plhs[3]=mxCreateDoubleMatrix(1,1,mxREAL);
        plhs[4]=mxCreateDoubleMatrix(1,1,mxREAL);
        plhs[5]=mxCreateDoubleMatrix(1,1,mxREAL);
         double *pwmCmd1=mxGetPr(plhs[0]);
         double *pwmCmd2=mxGetPr(plhs[1]);
         double *pwmCmd3=mxGetPr(plhs[2]);
         double *pwmCmd4=mxGetPr(plhs[3]);
         double *pwmCmd5=mxGetPr(plhs[4]);
         double *pwmCmd6=mxGetPr(plhs[5]);
         *pwmCmd1=inputData[0];
         *pwmCmd2=inputData[1];
         *pwmCmd3=inputData[2];
         *pwmCmd4=inputData[3];
         *pwmCmd5=inputData[4];
         *pwmCmd6=inputData[5];
    }
   // *s_dis=demo.distance;
     return;
}