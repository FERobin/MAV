%% Implementing State Space Control Interface
%  Before running this script we would still need to run 'SetVrpnDevice'
%  first to init the necessary variables for the Motion Capture System
%       NOTE: this script only needs to be run once in a session
%
%
SetVrpnDevice_2Obj;
% updatePIDGains

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%Notice: the get position and get angle direction is different
%%DO NOT COPY THE GETPOS AND GETANG FUNCTION FOR OTHER PROJECT
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Initialization
% state = [x y z dx dy dz roll pitch yaw droll dpitch dyaw ix iy iz iyaw];
posDesired = [0 0 0.25];
velDesired = [0 0 0];
angDesired = [0 0 0];
angvelDesired = [0 0 0];
iPosDesired = [0 0 0];
iYawDesired = 0;
desired = [posDesired velDesired angDesired angvelDesired iPosDesired iYawDesired]';
TAKEOFF_CMD = 't';
OFF_CMD = 'o';
DATA_CMD = 'd';

channel_select = [1];
numServos = length(channel_select);

% Generate LQR Gain Matrix%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
load DFA_PARAMS.mat

%DFA.B(10,5:8) = zeros(1,4);

numStates = 16;
A = [DFA.A zeros(12,4);
    eye(3) zeros(3,13);
    zeros(1,8) 1 zeros(1,7)];
B = [DFA.B; zeros(4,DFA.N)];

% Q = diag([.1 .1 5 0.005 0.005 1 0.01 0.01 10 0.01 0.01 0.1 0.01 0.01 1 1]);
% R = eye(DFA.N);
% K = lqr(A,B,Q,R);

A(4,8)=-9.81;
A(5,7)=9.81;


B(6,:)=-3.4247*ones(4,1);
B(10,:)=104.1667*[1 -1 -1 1];
B(11,:)=104.1667*[1 1 -1 -1];
B(12,:)=6.4267*[1 -1 1 -1];
%           X       Y    Z     u      v    w      Roll   Pitch  Yaw     p     q      r
Q=diag([0.001,0.001,5,0.001,0.001,0.5,0.001,0.001,0.01,0.001,0.001,0.1,0.001,0.001,0.1,0.1]);
R = eye(DFA.N);
K = lqr(A,B,Q,R);
K(1:4,1:2)=zeros(4,2);
K(1:4,13:14)=zeros(4,2);
K(1:4,4)=0.025*[-1 -1 1  1];
K(1:4,5)=0.025*[1  -1 -1 1];
K(1:4,7)=0.148*[1 -1 -1  1];
K(1:4,8)=0.148*[1  1 -1 -1];
K(1:4,10)=0.030*[1 -1 -1  1];
K(1:4,11)=0.030*[1  1 -1 -1];

K=zeros(4,16);
% Q=diag([0.001,0.001,5,0.001,0.001,0.5,0.001,0.001,0.01,0.001,0.001,0.1,0.002,0.001,0.1,0.1]);
% R = eye(DFA.N);
% K = lqr(A,B,Q,R);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Conversion variables:
mg = 0.073*9.81;

MAX_DUTY = 500;
MIN_DUTY = 275;
HOVER_DUTY = 350;
OFF_DUTY = 250;


% Serial port
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

% 
% this is the gain for hover with no extra sensor
% KPosGain=[0.5*1.1,0.5*0.75,20.34,...%Kpx, Kpy, Kpz
%           0.08*0.9,0.08,8.17,...%Kix, Kiy, Kiz
%           0.35*1.1,0.35*0.75,7.49]';
%  
% 
% % KPosGain=[0.0,0.0,20.34,...%Kpx, Kpy, Kpz
% %           0.0,0.0,8.17,...%Kix, Kiy, Kiz
% %           0.0,0.0,7.49]';
% 
% KAngGain=[120,120,20.80,...%Kproll, Kppitch, Kp yaw
%           0.0,0.0,5.06,...%Ki roll, Ki pitch, Ki yaw
%           30,30,20.49]';%Kd roo, Kd pitch, Kd yaw



% KPosGain=[0,0,25.34,...%Kpx, Kpy, Kpz
%           0,0,8.17,...%Kix, Kiy, Kiz
%           0,0,7.49]';
%       

KPosGain=[0.385,.385,15.55,...%Kpx, Kpy, Kpz
    .2,0.2,20.0,...%Kix, Kiy, Kiz
    0.37,0.37,5]';
% KPosGain=[0.0,0.0,20.34,...%Kpx, Kpy, Kpz
%           0.0,0.0,8.17,...%Kix, Kiy, Kiz
%           0.0,0.0,7.49]';

% KAngGain=[120.0,125.0,20.80,...%Kproll, Kppitch, Kp yaw
%           0.0,0.3,5.06,...%Ki roll, Ki pitch, Ki yaw
%           30.0,30.0,20.49]';%Kd roo, Kd pitch, Kd yaw
      
KAngGain=[110.0,70.0,20.80,...%Kproll, Kppitch, Kp yaw
          0.0,0,5.06,...%Ki roll, Ki pitch, Ki yaw
          25.0,25.0,20.49]';%Kd roo, Kd pitch, Kd yaw
     


% KPosGain=[0.26,0.26,16.34,...%Kpx, Kpy, Kpz
%           0.1,0.1,2.17,...%Kix, Kiy, Kiz
%           0.25,0.25,7.49]';
% 

libport_ss(CMD_OPEN_PORT,'/dev/rfcomm0');%open port

pause(0.5);
libport_ss(CMD_ANG_GAIN,KAngGain);
pause(0.5);
libport_ss(CMD_POS_GAIN,KPosGain);
pause(0.5);
libport_ss(CMD_CALIB);
% KPosGain=[0.23,0.23,8,0.1,0.1,3,0.2,0.2,4]';
% libport_ss(CMD_POS_GAIN,KPosGain);
pause(2) % may be necessary to initialize the connection
tempPos=zeros(3,100);
tempAng=zeros(3,100);
for i=1:100
    data = listener.trackerData;
    pause(0.02);
    tempPos(1:3,i) = GetPos(data);
    tempAng(1:3,i)=GetAng(data);
end
disp('covariance');
disp([cov(tempPos(1,1:100));cov(tempPos(2,1:100));cov(tempPos(3,1:100))]);

%Test Settings
TS = 0.01; % [s]
runTime = 40; %[s]
total_loops = runTime/TS;

recorddata = zeros(18,100000);

%% Normalize Position
posVals = zeros(3,5);

for i=1:5
    data = listener.trackerData;
    pos = GetPos(data);
    posVals(:,i) = pos;
    pause(0.02);
end
pos0 = mean(posVals,2)./1000; %convert mm --> ma
prevPos = zeros(3,1);
prevAng = zeros(3,1);
iPos = zeros(3,1);
iYaw = 0;

stepCount=0;
T2=100;
T1=50;
acc=-2;
state=0;
mgVec=[323 327 327 329]';%this is the trim value
%mgVec=[319 319 319 319]';
%% Ready to fly!
try
    % make sure all of the rotors are off
    libport_ss(CMD_STOP_MOTOR);
    pause(2)
    
    disp('Everything is ready. PRESS START ON THE GUI');
    
    % Start the motors
    libport_ss(CMD_START_MOTOR);
    pause(0.5);
    
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
        %% LOOP
        state=CalState(handle);
        
        nowtest = t_now;
 
        if state==1
            %% Take Measurements from the motion capture
 
            % determine the relative position
            
            if stepCount<=T2
                if stepCount<=T1
                    posDesired=[0 0 0.5*acc*TS^2*stepCount^2];
                    velDesired=[0 0 stepCount*acc*TS];
                    
                elseif stepCount<=T2
                    posDesired=[0 0 -0.5*acc*TS^2*(stepCount-T2)^2+acc*(T1*TS)^2];
                    velDesired=[0 0 acc*TS*T1-acc*TS*(stepCount-T1)];
                    endgit 
            elseif stepCount<=3000
                posDesired=[0 0 acc*(TS*T1)^2];%0.5 meters
                velDesired=[0 0 0];
                
            else
                posDesired=[0 0 -0.1];
                velDesired=[0 0 0];
            end
            
            
            stepCount=stepCount+1;
        
        elseif state==2
            
            if stepCount<=T2
                if st                input_signal=[341;340;338;338];
                libport_ss(CMD_WRITE,input_signal);%in this case, the quadrotor will rely on the motion ccapture to provide the position
 
                    posDesired=[0 0 0.5*acc*TS^2*stepCount^2];
                    velDesired=[0 0 stepCount*acc*TS];
                    
                elseif stepCount<=T2
                    posDesired=[0 0 -0.5*acc*TS^2*(stepCount-T2)^2+acc*(T1*TS)^2];
                    velDesired=[0 0 acc*TS*T1-acc*TS*(stepCount-T1)];
                end
            elseif stepCount<=3000
                posDesired=[0 0 acc*(TS*T1)^2];
                velDesired=[0 0 0];
                
            else
                posDesired=[0 0 -0.1];
                velDesired=[0 0 0];
            end
            
            
            stepCount=stepCount+1;
        elseif state == 5
            if posDesired(3) < 0
                posDesired(3) = posDesired(3) + 0.0025;
                velDesired=[0 0 0];
            else
                state = 3;
            end
        end
        if state==1||state==2||state==5
            data=listener.trackerData;
            posRes = GetPos(data)./1000; %convert back to m from mm
            pos = posRes - pos0;
            
            % calculate the integral of position term (only x and y will be
            % used)
            iPos = iPos + pos*TS;
            
            % calculate the position derivative
            
         
            % determine the angles and filter the readings
            angRes = GetAng(data);
%             for j=1:3
%                 if abs(prevAng(j)-angRes(j))>1
%                     angRes(1:3)=prevAng(1:3);
%                     break;
%                 end
%             end
            ang=angRes;
            if i==1
                prevAng=ang;
                prevPos=pos;
            end
            %calculate the angle derivative
            dAng = (ang-prevAng)/TS;
            dPos = (pos-prevPos)/TS;
            % calculate the integral of yaw
            iYaw = iYaw + ang(3)*TS;
            
            % Update the previous position and angle
            prevPos = pos;
            prevAng = ang;
            
            % compile all of the readings (integral terms for x,y,z,yaw
            quadstate = [pos; dPos; ang; dAng; iPos; iYaw];
            
            % Update the desired
            iPosDesired = iPosDesired + posDesired*TS;
            iYawDesired = iYawDesired + angDesired(3)*TS;
            desired = [posDesired velDesired angDesired angvelDesired iPosDesired iYawDesired]';
            
            %calculate      the state error
            errstate = desired - quadstate;
            
            % send it to the controller
            
            % Calculate the input for the state error using the gains
            input_signal = K*errstate;
            
            %We will only send tilt angles 1 not 2 and 4:
            %input_signal = [input_signal(1:4); input_signal(6); input_signal(8) ]; %for transmitting
            input_signal = [input_signal(1:4)];
            
            %convert motor signal to pulse width:
            for k = 1:4
              
                %                 input_signal(k) = (MAX_DUTY-MIN_DUTY)*(0.248*input_signal(k)-0.1111)+MIN_DUTY;
                input_signal(k) = 62.59*input_signal(k);
                input_signal(k) = input_signal(k) + mgVec(k);%add the trim value
                %apply Sawhituration:
                if (input_signal(k) >= 500)
                    input_signal(k) = 500;
                elseif (input_signal(k) <= MIN_DUTY)
                    input_signal(k) = MIN_DUTY;
                end
            end
            i = i+1;
            
            
            if state==1||state==5
%                   input_signal=[0;0;330;0];
                  %input_signal=[339;340;333;333];
                  %libport_ss(CMD_WRITE,input_signal);%in this case, the quadrotor will rely on the motion ccapture to provide the position

                  libport_ss(CMD_WRITE_CLIMB_ASSIST,errstate(1:3));%in this case, the quadrotor will rely on the motion ccapture to provide the position
           
            elseif  state==2
                %this is the code for autonomous hover with tof sensor
                errstate(1)=0;
                errstate(2)=0;
                errstate(3)=desired(3);
                 libport_ss(CMD_WRITE_CLIMB,errstate(1:3)); %in this case, the quadrotor will rely on its own optical flow reading
                disp('OFFFFFFFFFFFF');
            
            end
%             [optx,opty,optz]=libport_ss(CMD_READ);
%              libport_ss(CMD_WRITE,[250;250;300;250]);
%             libport_ss(CMD_WRITE_CLIMB_ASSIST,errstate(1:3));
            recorddata(1,i)=telapse;
            recorddata(2,i)=testTime;
            recorddata(3:18,i)=quadstate;
            recorddata(19:34,i) = desired;
            recorddata(35:38,i)=input_signal;
%             recorddata(39:41,i)=[optx;opty;optz];
            disp(i);
        
        end
        %Convert servo signal to pulse width
        
        %Send it to the controller
        %dataString = TransmitCmd(data);

        
        TOTAL_LENGTH=i;
        
        
        % wait for full TS to normalize sending rate5
        telapse=toc(t_now);
       
        telapse1 = telapse;
        while telapse1 < 0.9732*TS, telapse1 = toc(t_now); end
        t_now = tic;
        drawnow;
        testTime = toc(nowtest);
 
    end
    
    TOTAL_LENGTH=i;
        
    close(CalibrationControl);
    
    % Turn off motors
    for i = 1:50
        libport_ss(CMD_STOP_MOTOR);
        pause(TS);
    end
    end
    
catch err
    disp(['ERROR: ' err.message]);
    disp(err.stack(1,1));
    clear err
    for i = 1:50
        libport_ss(CMD_STOP_MOTOR);
        pause(TS);
    end
end

libport_ss(CMD_CLOSE_PORT);
i=TOTAL_LENGTH;
%% DataAnalysis / Plots

figure(1);
subplot(121)
plot(0.01*(1:i),recorddata(1,1:i));
title('Time for MATLAB computations');
subplot(122);
plot(.01*(1:i),recorddata(2,1:i));
%                 input_signal=[341;340;338;338];
%                 libport_ss(CMD_WRITE,input_signal);%in this case, the quadrotor will rely on the motion ccapture to provide the position

title('Time for full control loop');

figure(2)
subplot(121);
plot(.01*(1:i),recorddata(19:21,1:i))%,1:i,recorddata(4,1:i),1:i, recorddata(5,1:i));
title('Relative Position');
xlabel('Time (s)');
ylabel('Position (m)');
legend('X', 'Y', 'Z');
subplot(122);
plot(.01*(1:i),recorddata(9:11,1:i)*180/pi)%,1:i,recorddata(7,1:i),1:i, recorddata(8,1:i));
title('Angles');
xlabel('Time (s)');

ylabel('Angle (degrees)');
legend('roll', 'pitch', 'yaw');

figure(222)
plot(.01*(1:i),recorddata(9,1:i)*180/pi)%,1:i,recorddata(7,1:i),1:i, recorddata(8,1:i));
title('roll)');
xlabel('Time (s)');

ylabel('roll (degrees)');

figure(333)
plot(.01*(1:i),recorddata(9,1:i)*180/pi,'r-')%,1:i,recorddata(7,1:i),1:i, recorddata(8,1:i));
hold on;
plot(.01*(1:i),60*recorddata(7,1:i),'b-')%,1:i,recorddata(7,1:i),1:i, recorddata(8,1:i));
title('roll)');
xlabel('Time (s)');

ylabel('roll (degrees)');

% figure(3)
% plot(1:i,recorddata(9:11,1:i))%,1:i,recorddata(4,1:i),1:i, recorddata(5,1:i));
% title('Relative Position');
% legend('X', 'Y', 'Z');

% figure(3)
% plot(1:i,recorddata(15:18,1:i))%,1:i,recorddata(4,1:i),1:i, recorddata(5,1:i));
% title('Motor Commands');
% legend('1','2','3','4');%,'5','6');

% figure(4)
% subplot(211);
% plot(1:i,recorddata(35:38,1:i))
% title('DC Motor Command Signal')
% legend('Channel 1', 'Channel 2', 'Channel 3', 'Channel 4');

% subplot(212);
% plot(1:i,recorddata(39:39,1:i))
% title('Servo Motor Command Signal')
% legend('Channel 1', 'Channel 4');
figure(444)
plot(recorddata(3, 1:i), recorddata(4, 1:i))
figure(4); 
i=total_loops;
plot(0.01*(1:i),recorddata(3,1:i)); 

datestr(now,'dd-mm-yyyy HH:MM:SS FFF');
a=datevec(now);
recorData = ['testdata/',num2str(a(1)),'-',num2str(a(2)),'-',num2str(a(3)),'-',num2str(a(4)),'-',num2str(a(5)),'.mat'];
save(recorData,'recorddata','DFA','R','Q','K','KPosGain','KAngGain');

fileName=[num2str(a(2)),'-',num2str(a(3)),'-',num2str(a(4)),'-',num2str(a(5))];
MatToLatex(recorddata,fileName,KPosGain,KAngGain,TS);
disp('x error');
disp(norm(recorddata(3,1:i)));
disp('y error');
disp(norm(recorddata(4,1:i)));
disp('yaw error');
disp(norm(recorddata(11,1:i)));
