%this function will tune the PID for the quadrotor


% Serial port
CMD_OPEN_PORT =0;
CMD_READ = 1;
CMD_WRITE = 2;
CMD_CLOSE_PORT = 3;
CMD_START_MOTOR = 4;
CMD_STOP_MOTOR = 5;
CMD_CALIB=9;

libport_ss(CMD_OPEN_PORT,'/dev/rfcomm0');%open port
libport_ss(CMD_CALIB);
libport_ss(CMD_CLOSE_PORT);     




KAngGain=[40,36,132,0,0,75,6,6,28];


% port = '/dev/ttyUSB2'; %change this to where the serial port is connected
port = '/dev/ttyUSB0';
s = serial(port,'BaudRate', 57600);
s.OutputBufferSize = 1024;
s.InputBufferSize = 100000;
try
    fopen(s);
catch eConnErr
    throwAsCaller(eConnErr);
end

pause(1.5) % may be necessary to initialize the connection

 
%Write row by row 
dataString = sprintf('a%0.3fz',KAngGain);

fwrite(s,[dataString '\n']);

disp(['K']);
disp(['Matlab SAYS: ' sprintf('%0.4f, ', KAngGain)]); 


fclose(s);
delete(s);
