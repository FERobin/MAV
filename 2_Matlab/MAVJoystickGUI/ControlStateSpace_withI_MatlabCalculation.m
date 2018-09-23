%% Implementing State Space Control Interface
%  Before running this script we would still need to run 'SetVrpnDevice'
%  first to init the necessary variables for the Motion Capture System
%       NOTE: this script only needs to be run once in a session
%
%
% updatePIDGains

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%Notice: the get position and get angle direction is different
%%DO NOT COPY THE GETPOS AND GETANG FUNCTION FOR OTHER PROJECT
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Initialization
% state = [x y z dx dy dz roll pitch yaw droll dpitch dyaw ix iy iz iyaw];
t_now=tic;
TS=0.01;
recorddata=zeros(5,10000);
CMD_OPEN_PORT =0;
CMD_READ = 1;
CMD_WRITE = 2;
CMD_CLOSE_PORT = 3;
CMD_START_MOTOR = 4;
CMD_STOP_MOTOR = 5;
CMD_WRITE_CLIMB=12;
CMD_CALIB=9;
CMD_ANG_GAIN=10;
CMD_POS_GAIN=11;
CMD_WRITE_CLIMB_ASSIST=13;

libport_ss(CMD_OPEN_PORT,'/dev/rfcomm0');%open port

%% Ready to fly!
try
    % make sure all of the rotors are off
    if exist('handle','var')==1
        close(CalibrationControl);
        clear handle;
    end
    handle=guihandles(CalibrationControl);
    END=3;
    state=CalState(handle);
    
    %% The Controller
    i=1;
    telapse = TS;
    testTime = TS;t_now = tic;
    while state~=END
        state=CalState(handle);
        %% LOOP
        [posx,posy,posz]=libport_ss(CMD_READ);
        i = i+1;
        
   
        % wait for full TS to normalize sending rate5
        telapse=toc(t_now);
        
        telapse1 = telapse;
        while telapse1 < 0.9732*TS, telapse1 = toc(t_now); end
        t_now = tic;
        drawnow;
        
        recorddata(1,i)=telapse;
        recorddata(2,i)=testTime;
        recorddata(3,i)=posx;
        recorddata(4,i)=posy;
        recorddata(5,i)=posz;
        disp(i);
        axesHandle=handle.axes1;
        plot3(axesHandle,recorddata(3,1:i),recorddata(4,1:i),recorddata(5,1:i));
        
        
    end
    %Convert servo signal to pulse width
    
    %Send it to the controller
    %dataString = TransmitCmd(data);
   
    close(CalibrationControl);
    
    % Turn off motors
 
    
catch err
    disp(['ERROR: ' err.message]);
    disp(err.stack(1,1));
    clear err

end
libport_ss(CMD_CLOSE_PORT);
TOTAL_LENGTH=i;
%% DataAnalysis / Plots
datestr(now,'dd-mm-yyyy HH:MM:SS FFF');
a=datevec(now);
recorData = ['testdata/',num2str(a(1)),'-',num2str(a(2)),'-',num2str(a(3)),'-',num2str(a(4)),'-',num2str(a(5)),'-reading.mat'];
save(recorData,'recorddata');
fileName=[num2str(a(2)),'-',num2str(a(3)),'-',num2str(a(4)),'-',num2str(a(5))];
MatToLatex(recorddata,fileName,TOTAL_LENGTH,TS);
