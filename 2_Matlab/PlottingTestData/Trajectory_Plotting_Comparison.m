%x y z are from the first three columns of data3.csv
%data3.csv has optical flow data

%recorddata 3,4,5 are x y z from motion capture
%motion cap data in 2018-5-1-11-38.mat

close all
figure(1),hold on
len = 700;
mult = 0.5;
plot3(smooth(x(300:300+floor(len * mult)),20),smooth(y(300:300+floor(len * mult)),20), smooth(-z(300:300+floor(len * mult)),20),'b')
title('Optical Flow vs Motion Capture Trajectories')
xlabel('x');ylabel('y')
plot3(recorddata(3,1:len),recorddata(4,1:len), -recorddata(5,1:len),'r')
legend('Optical Flow','Motion Cap')