function [yStates] = translateY(time,yFinal)
% gives expected y, ydot, ydotdot for a given time during lateral motion
% input: time, final y distance
% output: expected position, velocity, and acceleration in y

%% parameters
vyMax = 1;      % craft max velocity (m/s)
ayMax = 1.5;    % craft max acceleration (m/s^2)

if yFinal < 0   % allow backwards motion
    ayMax = -ayMax;
    vyMax = -vyMax;
end
%% calculate turning points
tAccel = vyMax/ayMax;
yAccel = 0.5*ayMax*tAccel^2;
if 2*abs(yAccel)>abs(yFinal)
    yAccel = yFinal/2;
    tAccel = sqrt(2*yAccel/ayMax);    
end
yTravel = yFinal - 2*yAccel;
vTravel = ayMax*tAccel;
tTravel = yTravel/vTravel;
tStop = 2*tAccel + tTravel;

%% accel phase
if time<tAccel
    ay = ayMax;
    vy = ay*time;
    y = 0.5*ay*time^2;        
end

%% steady phase
if time>=tAccel && time<(tAccel+tTravel)
    ay = 0;
    vy = vTravel;
    y = vy*(time-tAccel) + yAccel;
end

%% decel phase
if time>=(tAccel+tTravel) && time<tStop
    ay = -ayMax;
    vy = vTravel + ay*(time-tAccel-tTravel);
    y = yAccel + yTravel + vTravel*(time-tAccel-tTravel) + 0.5*ay*(time-tAccel-tTravel)^2;
end

%% hold steady
if time >= tStop
    ay = 0;
    vy = 0;
    y = yFinal;
end

yStates = [y,vy,ay];

end