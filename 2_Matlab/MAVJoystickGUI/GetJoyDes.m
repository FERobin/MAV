function desPos=GetJoyDes(prevPos,TS,joyCmd)
%GetJoyDes this function get the joystick position
%prevPos is a 6x1 vector
%TS is the sampling time
%joyCmd is the joystick reading

x=prevPos(1:2);
y=prevPos(3:4);
z=prevPos(5:6);

 
A=[0 1;0 -2];
B=[0;1];
desPos=zeros(6,1);

desPos(1:2)=x+TS*(A*x+B*joyCmd(1)/32768);
desPos(3:4)=y+TS*(A*y+B*joyCmd(2)/32768);%the direction is opposite

desPos(5:6)=z+TS*(A*z+B*joyCmd(4)/1e5);%the direction is opposite
velVec=[desPos(2);desPos(4)];
velNorm=norm(velVec);
if velNorm>=0.2
    desPos(2)=desPos(2)*0.2/velNorm;
    desPos(4)=desPos(4)*0.2/velNorm;
end
%put some limit on the x position
if desPos(1)>1
    desPos(1)=1;
    desPos(2)=0;
elseif desPos(1)<-1
    desPos(1)=-1;
    desPos(2)=0;
end

%put some limit on the y position
if desPos(3)>1
    desPos(3)=1;
    desPos(4)=0;
elseif desPos(3)<-1
    desPos(3)=-1;
    desPos(4)=0;
end

%put some limit on the z position
if desPos(5)>0
    desPos(5)=0;
    desPos(6)=0;
elseif desPos(5)<-0.6
    desPos(5)=-0.6;
    desPos(6)=0;
end

 

end