function [xStates] = translateX(time,xFinal)
% gives expected x, xdot, xdotdot for a given time during longitudal
% motion
% input: time, final x distance
% output: expected position, velocity, and acceleration in x

%% parameters
vxMax = 1;      % craft max velocity (m/s)
axMax = 1.5;    % craft max acceleration (m/s^2)

if xFinal < 0   % allow backwards motion
    axMax = -axMax;
    vxMax = -vxMax;
end

%% calculate turning points
tAccel = vxMax/axMax;
xAccel = 0.5*axMax*tAccel^2;
if 2*abs(xAccel)>abs(xFinal)
    xAccel = xFinal/2;
    tAccel = sqrt(2*xAccel/axMax);    
end
xTravel = xFinal - 2*xAccel;
vTravel = axMax*tAccel;
tTravel = xTravel/vTravel;
tStop = 2*tAccel + tTravel;

%% accel phase
if time<tAccel
    ax = axMax;
    vx = ax*time;
    x = 0.5*ax*time^2;        
end

%% steady phase
if time>=tAccel && time<(tAccel+tTravel)
    ax = 0;
    vx = vTravel;
    x = vx*(time-tAccel) + xAccel;
end

%% decel phase
if time>=(tAccel+tTravel) && time<tStop
    ax = -axMax;
    vx = vTravel + ax*(time-tAccel-tTravel);
    x = xAccel + xTravel + vTravel*(time-tAccel-tTravel) + 0.5*ax*(time-tAccel-tTravel)^2;
end

%% hold steady
if time >= tStop
    ax = 0;
    vx = 0;
    x = xFinal;
end

xStates = [x,vx,ax];

end