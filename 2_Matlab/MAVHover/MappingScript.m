%This script will map the PID controller with the LQR controller.


syms x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 x15 x16 real;
syms x1d x2d x3d x4d x5d x6d x7d x8d x9d x10d x11d x12d x13d x14d x15d x16d;


syms k1 k2 k3 k4 k5 k6 k7 k8 k9 k10 k11 k12 k13 k14 k15 k16 real;

kGain=[k1;k2;k3;k4;k5;k6;k7;k8;k9;k10;k11;k12;k13;k14;k15;k16];
errstate=[x1d-x1;x2d-x2;x3d-x3;x4d-x4;x5d-x5;x6d-x6;x7d-x7;x8d-x8;x9d-x9;...
          x10d-x10;x11d-x11;x12d-x12;x13d-x13;x14d-x14;x15d-x15;x16d-x16];
GRAVITY=1;
accx=kGain(1)*errstate(1)+kGain(2)*errstate(4)+kGain(3)*errstate(13);
accy=(kGain(4)*errstate(2)+kGain(5)*errstate(5)+kGain(6)*errstate(14));
alphaDes=(-accy)/GRAVITY;
betaDes=(accx)/GRAVITY;
T=kGain(7)*errstate(3)+kGain(8)*errstate(6)+kGain(9)*errstate(15);
               
errAng=[alphaDes-x7;betaDes-x8;errstate(9)];
tau1=kGain(10)*errAng(1)-kGain(11)*x10;
tau2=kGain(12)*errAng(2)-kGain(13)*x11;
tau3=kGain(14)*errAng(3)-kGain(15)*x12+kGain(16)*errstate(16);
cmd=[0.0024  0.0024  0.0389 -0.0730;...
    -0.0024  0.0024 -0.0389 -0.0730;...
    -0.0024 -0.0024  0.0389 -0.0730;...
     0.0024 -0.0024 -0.0389 -0.0730]*[tau1;tau2;tau3;T];
disp(simplify(cmd(1)));
disp(vpa(cmd(1),3));
disp(vpa(cmd(2),3));
disp(vpa(cmd(3),3));
disp(vpa(cmd(4),3));

% load DFA_PARAMS.mat
% 
% %DFA.B(10,5:8) = zeros(1,4);
% 
% numStates = 16;
% A = [DFA.A zeros(12,4); 
%     eye(3) zeros(3,13); 
%     zeros(1,8) 1 zeros(1,7)];
% B = [DFA.B; zeros(4,DFA.N)];


%gain for the new esc
% Q=diag([0.1,0.1,5,0.01,0.01,1,0.05,0.1,1,0.01,0.01,1,0.1,0.1,10,10]);
% R = eye(4);
% K = lqr(A,B,Q,R);  
%  
PIDK=zeros(1,16);

PIDK(12)=K(1,8)/0.0024;
PIDK(1)=-K(1,1)/0.0024/PIDK(12);
PIDK(2)=-K(1,4)/0.0024/PIDK(12);
PIDK(3)=-K(1,13)/0.0024/PIDK(12);

PIDK(10)=-K(2,7)/0.0024;
PIDK(6)=-K(2,14)/0.0024/PIDK(10);
PIDK(5)=-K(2,5)/0.0024/PIDK(10);
PIDK(4)=-K(2,2)/0.0024/PIDK(10);


PIDK(7)=-K(1,3)/0.073;
PIDK(8)=-K(1,6)/0.073;
PIDK(9)=-K(1,15)/0.073;


PIDK(11)=-K(2,10)/0.0024;
PIDK(13)=K(1,11)/0.0024; 
PIDK(14)=-K(2,9)/0.0389;
PIDK(15)=-K(2,12)/0.0389;
PIDK(16)=K(1,16)/0.0389;

disp(PIDK);