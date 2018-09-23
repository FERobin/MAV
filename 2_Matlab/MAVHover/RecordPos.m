%Record the data

%% Implementing State Space Control Interface
%  Before running this script we would still need to run 'SetVrpnDevice'
%  first to init the necessary variables for the Motion Capture System
%       NOTE: this script only needs to be run once in a session
%
%
SetVrpnDevice_2Obj;
% updatePIDGains
 
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
runTime = 20; %[s]
total_loops = runTime/TS;

recorddata = zeros(18,100000);

%% Normalize Position
posVals = zeros(3,100000);

for i=1:100000
    data = listener.trackerData;
    pos = GetPos(data);
    posVals(:,i) = pos;
    pause(0.02);
    disp(i);
end
save('2018-3-2-15-18.mat','posVals');
