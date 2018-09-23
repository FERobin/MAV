acc=0.5;
T1=100;
T2=200;
TS=0.01;
result=zeros(6,4000);
trajCount=0;
courseSel=0;
for i=1:4000
    
    [posDesired,velDesired]=GenerateTraj(trajCount,courseSel,acc,T1,T2,TS);
    
    trajCount=trajCount+1;
    if trajCount>=T2
        trajCount=0;
        courseSel=courseSel+1;
    end
    if courseSel==5
        posDesired=[0 0 0];
        velDesired=[0 0 0];
    end
    result(1:3,i)=posDesired;
    result(4:6,i)=velDesired;
end
plot(result(1,1:4000),result(2,1:4000));
plot(result(1,1:4000));