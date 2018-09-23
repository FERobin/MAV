KAngGain=[44,42,413,0,0,154,9.8,9.5,479]';

CMD_OPEN_PORT =0;
CMD_READ = 1;
CMD_WRITE = 2;
CMD_CLOSE_PORT = 3;
CMD_START_MOTOR = 4;
CMD_STOP_MOTOR = 5;
CMD_CALIB=9;
CMD_ANG_GAIN=10;
CMD_POS_GAIN=11;
libport_ss(CMD_OPEN_PORT,'/dev/rfcomm0');%open port
libport_ss(CMD_ANG_GAIN,KAngGain);
libport_ss(CMD_CLOSE_PORT);         
