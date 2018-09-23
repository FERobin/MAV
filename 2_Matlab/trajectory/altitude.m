function [zStates] = altitude(time,zFinal)
% gives expected z, zdot, zdotdot for a given time during altitude change
% input: time, final height relative to starting height
% output: expected position, velocity, and acceleration in z

%% parameters
vzMax = 1;      % craft max velocity (m/s)
azMax = 1.5;    % craft max acceleration (m/s^2)

if zFinal < 0   % allow negative motion
    azMax = -azMax;
    vzMax = -vzMax;
end

%% calculate turning points
tAccel = vzMax/azMax;
zAccel = 0.5*azMax*tAccel^2;
if 2*abs(zAccel)>abs(zFinal)
    zAccel = zFinal/2;
    tAccel = sqrt(2*zAccel/azMax);    
end
zTravel = zFinal - 2*zAccel;
vTravel = azMax*tAccel;
tTravel = zTravel/vTravel;
tStop = 2*tAccel + tTravel;

%% accel phase
if time<tAccel
    az = azMax;
    vz = az*time;
    z = 0.5*az*time^2;        
end

%% steady phase
if time>=tAccel && time<(tAccel+tTravel)
    az = 0;
    vz = vTravel;
    z = vz*(time-tAccel) + zAccel;
end

%% decel phase
if time>=(tAccel+tTravel) && time<tStop
    az = -azMax;
    vz = vTravel + az*(time-tAccel-tTravel);
    z = zAccel + zTravel + vTravel*(time-tAccel-tTravel) + 0.5*az*(time-tAccel-tTravel)^2;
end

%% hold steady
if time >= tStop
    az = 0;
    vz = 0;
    z = zFinal;
end

zStates = [z,vz,az];

end