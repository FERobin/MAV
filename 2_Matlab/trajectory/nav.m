function [x, y, z, yaw] = nav(time,timeStart,operation,dist,xPrev,yPrev,zPrev,yawPrev)
% wrapper function for trajectory creation
% Inputs: current time, starting time of current operation, desired flight
% operation, desired distance for flight operation, previous position
% Outputs: x, y, z, and yaw expected position, velocity, and acceleration as
% row vectors

x = [0,0,0];
y = [0,0,0];
z = [0,0,0];
yaw = [0,0,0];

% time for each operation starts from zero
timeOp = time-timeStart;

switch(operation)
    case 'altitude'
        x = [xPrev(1),0,0];
        y = [yPrev(1),0,0];
        z = altitude(timeOp,dist);
        z(1) = z(1)+zPrev(1);
        yaw = [yawPrev(1),0,0];
    case 'hover'
        x = [xPrev(1),0,0];
        y = [yPrev(1),0,0];
        z = hover(timeOp,dist);
        yaw = [yawPrev(1),0,0];
    case 'translateX'
        x = translateX(timeOp,dist);
        x(1) = x(1)+xPrev(1);
        y = [yPrev(1),0,0];
        z = hover(timeOp,zPrev(1));
        yaw = [yawPrev(1),0,0];
    case 'translateY'
        x = [xPrev(1),0,0];
        y = translateY(timeOp,dist);
        y(1) = y(1)+yPrev(1);
        z = hover(timeOp,zPrev(1));        
        yaw = [yawPrev(1),0,0];
    case 'changeYaw'
        x = [xPrev(1),0,0];
        y = [yPrev(1),0,0];
        z = hover(timeOp,zPrev(1));
        yaw = changeYaw(timeOp,dist);
end


end