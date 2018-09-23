function [posDesired,velDesired]=GenerateTraj(stepCount,courseSel,acc,T1,T2,TS)
%GenerateTraj this function generates a simple square course
%stepCount is the current step count [0,T2] 
%courseSel is the course selection ranges from 0 to 3. 
%acc is the acceleration
%T1 is the acceleration time
%T2 is the deceleartion time
%TS is the sampling time

posDesired=zeros(3,1);
velDesired=zeros(3,1);
if stepCount<=T1%try to plan the trajectory based on a simple constant acceleration trajectory
    if courseSel==0%this is the horizontal x direction
        posDesired(1)=0.5*acc*TS^2*stepCount^2;
        velDesired(1)=acc*TS*T1-acc*TS*(stepCount-T1);
        posDesired(2)=0;
        velDesired(2)=0;
    elseif courseSel==1%this is the horizontal y direction
        posDesired(2)=0.5*acc*TS^2*stepCount^2;
        velDesired(2)=acc*TS*T1-acc*TS*(stepCount-T1);
        posDesired(1)=acc*(T1*TS)^2;
        velDesired(1)=0;
    elseif courseSel==2%this is the third side
        posDesired(1)=acc*(T1*TS)^2-0.5*acc*TS^2*stepCount^2;
        velDesired(1)=-acc*TS*T1+acc*TS*(stepCount-T1);
        posDesired(2)=acc*(T1*TS)^2;
        velDesired(2)=0;
    else%this is the last side
        posDesired(2)=acc*(T1*TS)^2-0.5*acc*TS^2*stepCount^2;
        velDesired(2)=-acc*TS*T1+acc*TS*(stepCount-T1);
        posDesired(1)=0;
        velDesired(1)=0;
    end
elseif stepCount<=T2
    if courseSel==0%this is the first side
        posDesired(1)=-0.5*acc*TS^2*(stepCount-T2)^2+acc*(T1*TS)^2;
        velDesired(1)=acc*TS*T1-acc*TS*(stepCount-T1);
        posDesired(2)=0;
        velDesired(2)=0;
    elseif courseSel==1%this is the second side
        
        posDesired(2)=-0.5*acc*TS^2*(stepCount-T2)^2+acc*(T1*TS)^2;
        velDesired(2)=acc*TS*T1-acc*TS*(stepCount-T1);
        
        posDesired(1)=acc*(T1*TS)^2;
        velDesired(1)=0;
    elseif courseSel==2%this is the third side
        
        posDesired(1)=0.5*acc*TS^2*(stepCount-T2)^2;
        velDesired(1)=-acc*TS*T1+acc*TS*(stepCount-T1);
        
        posDesired(2)=acc*(T1*TS)^2;
        velDesired(2)=0;
    elseif courseSel==3%this is the last side
        posDesired(2)=0.5*acc*TS^2*(stepCount-T2)^2;
        velDesired(2)=-acc*TS*T1+acc*TS*(stepCount-T1);
        
        posDesired(1)=0;
        velDesired(1)=0;
    end
end    
    
end
