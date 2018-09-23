function [yawStates] = changeYaw(time,yawFinal)
% gives expected yaw, yawdot, yawdotdot for a given time during turning
% motion
% input: time, final yaw angle
% output: expected angular position, velocity, and acceleration

%% parameters
vYawMax = pi;      % craft max velocity (rad/s)
aYawMax = pi;    % craft max acceleration (rad/s^2)

if yawFinal < 0   % allow backwards motion
    aYawMax = -aYawMax;
    vYawMax = -vYawMax;
end

%% calculate turning points
tAccel = vYawMax/aYawMax;
yawAccel = 0.5*aYawMax*tAccel^2;
if 2*abs(yawAccel)>abs(yawFinal)
    yawAccel = yawFinal/2;
    tAccel = sqrt(2*yawAccel/aYawMax);    
end
yawTravel = yawFinal - 2*yawAccel;
vTravel = aYawMax*tAccel;
tTravel = yawTravel/vTravel;
tStop = 2*tAccel + tTravel;

%% accel phase
if time<tAccel
    ayaw = aYawMax;
    vyaw = ayaw*time;
    yaw = 0.5*ayaw*time^2;        
end

%% steady phase
if time>=tAccel && time<(tAccel+tTravel)
    ayaw = 0;
    vyaw = vTravel;
    yaw = vyaw*(time-tAccel) + yawAccel;
end

%% decel phase
if time>=(tAccel+tTravel) && time<tStop
    ayaw = -aYawMax;
    vyaw = vTravel + ayaw*(time-tAccel-tTravel);
    yaw = yawAccel + yawTravel + vTravel*(time-tAccel-tTravel) + 0.5*ayaw*(time-tAccel-tTravel)^2;
end

%% hold steady
if time >= tStop
    ayaw = 0;
    vyaw = 0;
    yaw = yawFinal;
end

yawStates = [yaw,vyaw,ayaw];

end