%this script will calibrate the sensor
  
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

