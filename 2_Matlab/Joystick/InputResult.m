%this is testing the second order system

A=[0 1;0 -3];

B=[0;1];

LENGTH=1000;
x=zeros(2,LENGTH);

Ts=0.01;

u=zeros(1,LENGTH);
u(1:500)=1;

for i=1:LENGTH-1
    x(:,i+1)=x(:,i)+Ts*(A*x(:,i)+B*u(:,i));
end
figure(1);
plot(x(1,1:LENGTH));

figure(2);
plot(x(2,1:LENGTH));


