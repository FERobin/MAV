function [zStates] = hover(time,zHover)
% gives expected z, zdot, zdotdot while hovering
% input: height
% output: expected position, velocity, and acceleration in z

zPos = zHover;
zVel = 0;
zAcc = 0;
zStates = [zPos,zVel,zAcc];
end