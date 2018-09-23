clear all;
close all;
load 2018-3-2-15-21-opticalflow.mat;
dataInput=unnamed1;
LENGTH=length(dataInput);
%let us assume the update rate is 100Hz
posx=zeros(LENGTH,1);
posy=zeros(LENGTH,1);
for i=2:LENGTH
    posx(i)=posx(i-1)+dataInput(i,1)*dataInput(i,3);
    posy(i)=posy(i-1)+dataInput(i,2)*dataInput(i,3);
end

figure(1);
plot(posx,posy);

vx=zeros(LENGTH,1);
vy=zeros(LENGTH,1);
posx=zeros(LENGTH,1);
posy=zeros(LENGTH,1);
for i=2:LENGTH
    vx(i)=.7*vx(i-1)+0.3*dataInput(i,1)*dataInput(i,3);
    vy(i)=0.7*vy(i-1)+.3*dataInput(i,2)*dataInput(i,3);
    posx(i)=posx(i-1)+vx(i);
    posy(i)=posy(i-1)+vy(i);
end

figure(2);
plot(posx,posy);
