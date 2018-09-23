%% Implementing State Space Control Interface
%  Before running this script we would still need to run 'SetVrpnDevice'
%  first to init the necessary variables for the Motion Capture System
%       NOTE: this script only needs to be run once in a session


if exist('handle','var')
    close(CalibrationControl);
    clear handle;
end
handle=guihandles(CalibrationControl);
pause('on');
pause;
[state,mode]=CalState(handle);
if mode && ~state
    disp('1')
else
    disp('0')
    SetVrpnDevice_2Obj;
end

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

channel_select = 1;
numServos = length(channel_select);

% Generate LQR Gain Matrix%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
load DFA_PARAMS.mat

numStates = 16;
A = [DFA.A zeros(12,4);
    eye(3) zeros(3,13);
    zeros(1,8) 1 zeros(1,7)];
B = [DFA.B; zeros(4,DFA.N)];

A(4,8)=-9.81;
A(5,7)=9.81;

B(6,:)=-3.4247*ones(4,1);
B(10,:)=104.1667*[1 -1 -1 1];
B(11,:)=104.1667*[1 1 -1 -1];
B(12,:)=6.4267*[1 -1 1 -1];
%           X       Y    Z     u      v    w      Roll   Pitch  Yaw     p     q      r
Q=diag([0.001,0.001,5,0.001,0.001,0.5,0.001,0.001,0.01,0.001,0.001,0.1,0.001,0.001,0.1,0.1]);
R = eye(DFA.N);
K=zeros(4,16);

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

KPosGain=[0.385,.385,15.55,...%Kpx, Kpy, Kpz
    .2,0.2,20.0,...%Kix, Kiy, Kiz
    0.37,0.37,5]';

KAngGain=[110.0,70.0,20.80,...%Kproll, Kppitch, Kp yaw
          0.0,0,5.06,...%Ki roll, Ki pitch, Ki yaw
          25.0,25.0,20.49]';%Kd roo, Kd pitch, Kd yaw

libport_ss(CMD_OPEN_PORT,'/dev/ttyUSB0');%'/dev/rfcomm0');%open port

pause(0.5);
libport_ss(CMD_ANG_GAIN,KAngGain);
pause(0.5);
libport_ss(CMD_POS_GAIN,KPosGain);
pause(0.5);
libport_ss(CMD_CALIB);
pause(2) % may be necessary to initialize the connection
tempPos=zeros(3,100);
tempAng=zeros(3,100);
% [own_path,~,~] = fileparts(mfilename('fullpath'));
% module_path = fullfile(own_path, '..');
% python_path = py.sys.path;
% if count(python_path,module_path)==0
%     insert(python_path,int32(0),module_path);
% end
% checkPath %Add Python Module to Python Search Path
disp('FLAG')
for i=1:100
    [position,angle] = GetData(mode);
    tempPos(1:3,i) = position;
    tempAng(1:3,i) = angle;
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
    [position,angle] = GetData(mode);
    posVals(:,i) = position;
end
pos0 = mean(posVals,2)./1000; %convert mm --> m
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
%% Ready to fly!
try
    % make sure all of the rotors are off
    libport_ss(CMD_STOP_MOTOR);
    pause(2)

    disp('Everything is ready. PRESS START ON THE GUI');

    % Start the motors
    libport_ss(CMD_START_MOTOR);
    pause(0.5);

    handle=guihandles(CalibrationControl);
    END=3;
    [state,mode]=CalState(handle);

    %% The Controller
    i=1;
    telapse = TS;
    testTime = TS;t_now = tic;
    while state~=END
        %% LOOP
        [state,mode]=CalState(handle);

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
                end
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
                input_signal=[341;340;338;338];
                libport_ss(CMD_WRITE,input_signal);%in this case, the quadrotor will rely on the motion ccapture to provide the position
                if stepCount<=T1
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
            [position,angle] = GetData(mode);
            posRes = position./1000; %convert back to m from mm
            pos = posRes - pos0;

            % calculate the integral of position term (only x and y will be
            % used)
            iPos = iPos + pos*TS;

            % calculate the position derivative
            dPos = (pos-prevPos)/TS;

            % determine the angles and filter the readings
            angRes = GetAng(data);

            ang=angRes;
            if i==1
                prevAng=ang;
                prevPos=pos;
            end
            % calculate the angle derivative
            dAng = (ang-prevAng)/TS;

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

            % calculate the state error
            errstate = desired - quadstate;

            % send it to the controller

            % Calculate the input for the state error using the gains
            input_signal = K*errstate;

            %We will only send tilt angles 1 not 2 and 4:
            input_signal = input_signal(1:4);

            %convert motor signal to pulse width:
            for k = 1:4

                %input_signal(k) = (MAX_DUTY-MIN_DUTY)*(0.248*input_signal(k)-0.1111)+MIN_DUTY;
                input_signal(k) = 62.59*input_signal(k);
                input_signal(k) = input_signal(k) + mgVec(k);%add the trim value
                %apply Saturation:
                if (input_signal(k) >= 500)
                    input_signal(k) = 500;
                elseif (input_signal(k) <= MIN_DUTY)
                    input_signal(k) = MIN_DUTY;
                end
            end
            i = i+1;


            if state==1||state==5
                  libport_ss(CMD_WRITE_CLIMB_ASSIST,errstate(1:3));%in this case, the quadrotor will rely on the motion ccapture to provide the position

            elseif  state==2
                %this is the code for autonomous hover with tof sensor
                errstate(1)=0;
                errstate(2)=0;
                errstate(3)=desired(3);
                libport_ss(CMD_WRITE_CLIMB,errstate(1:3)); %in this case, the quadrotor will rely on its own optical flow reading
                disp('OFFFFFFFFFFFF');

            end
            recorddata(1,i)=telapse;
            recorddata(2,i)=testTime;
            recorddata(3:18,i)=quadstate;
            recorddata(19:34,i) = desired;
            recorddata(35:38,i)=input_signal;
            disp(i);

        end

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
