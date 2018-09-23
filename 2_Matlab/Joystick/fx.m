clear all;
close all;
 
A=[0 1;0 -2];
B=[0;1];
x=zeros(2,500);
y=zeros(2,500);
z=zeros(2,500);
joymex2('open',0);
joyCmd=zeros(500,4);
Ts=0.02;
for i=2:500
    a=joymex2('query',0);
    %[ax(i);ay(i); ayaw(i); az(i)]=-A(2,1)*[ax(i-1);ay(i-1);ayaw(i-1);az(i-1)]...
    %-A(2,2)*[ax(i-1);ay(i-1);ayaw(i-1);az(i-1)]+a.axes';
    %[vx(i);vy(i);vyaw(i);vz(i)]=
    joyCmd(i,1)=a.axes(1);
    joyCmd(i,2)=a.axes(2);
    joyCmd(i,3)=a.axes(3);
    joyCmd(i,4)=a.axes(4);
    x(:,i+1)=x(:,i)+Ts*(A*x(:,i)+B*joyCmd(i,1)/10^4);
    y(:,i+1)=x(:,i)+Ts*(A*y(:,i)+B*joyCmd(i,2)/10^4);
     
    z(:,i+1)=z(:,i)+Ts*(A*z(:,i)+B*joyCmd(i,4)/2^14);
    if z(1,i+1)<0
        z(1,i+1)=0;
        z(2,i+1)=0;
    end
    pause(Ts);
    disp(i);
end

%A(2,1)
a.axes
subplot(2,2,1);
 hold on;

plot(1:500,x(1,1:500),'r');%axis([0,500,-32768,32768]);
plot(1:500,x(2,1:500),'r');%axis([0,500,-32768,32768]);
plot(1:500,joyCmd(1:500,1)/10^4,'g');%axis([0,500,-32768,32768])
subplot(2,2,2);


hold on;
plot(1:500,y(1,1:500),'r');%axis([0,500,-32768,32768]);
plot(1:500,y(2,1:500),'r');%axis([0,500,-32768,32768]);
plot(1:500,joyCmd(1:500,2)/10^4,'b');
subplot(2,2,3);
hold on;
plot(1:500,z(1,1:500),'r');%axis([0,500,-32768,32768]);

plot(1:500,z(2,1:500),'r');%axis([0,500,-32768,32768]);
plot(1:500,joyCmd(1:500/2^14,4),'k');
subplot(2,2,4) 
hold on;
plot(1:500,double(joyCmd(1:500,3))/2^14,'m');