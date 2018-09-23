function curPos=GetPos(data)
%GetPos this function get the current position of the quadrotor
%data is a structure. it includes the rotation and the position
%curPos is a 3x1 vector.It is the current position.The unit is milimeter
curPosT=[data(1).pos(1) data(1).pos(2) data(1).pos(3)]'*1000;%the unit is milimeter
curPos=diag([1,-1,-1])*[-1 0 0;0 0 1;0 1 0]*curPosT;%transform the position here.
                                   
end