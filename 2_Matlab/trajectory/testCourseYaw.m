
%% initial settings
tStep = 0.01;
t = 0:tStep:12-tStep;
x = zeros(1200,3);
y = zeros(1200,3);
z = zeros(1200,3);
yaw = zeros(1200,3);

%% takeoff
Z = 1;
for i = 1:199
    [x(i,:),y(i,:),z(i,:),yaw(i,:)] = nav(t(i),0,'altitude',Z,[0,0,0],[0,0,0],[0,0,0],[0,0,0]);
end

%% forward X
X = 1;
for i = 200:399
    [x(i,:),y(i,:),z(i,:),yaw(i,:)] = nav(t(i),2,'translateX',X,[0,0,0],[0,0,0],[1,0,0],[0,0,0]);
end

%% turn left 90deg
YAW = -pi/2;
for i = 400:599
    [x(i,:),y(i,:),z(i,:),yaw(i,:)] = nav(t(i),4,'changeYaw',YAW,[1,0,0],[0,0,0],[1,0,0],[0,0,0]);
end

% test
% figure()
% plot(t,yaw(:,1))

% translating forward in X again should move the craft forward, but this
% will plot it as continuing to move to the side. these functions are all 
% from the frame of reference of the craft. not sure how to plot that 
% movement accurately for demonstration

%% plot course
figure()
pos = animatedline('LineWidth',2);
set(gca,'XLim',[0 1],'YLim',[0 1],'ZLim',[0 1]);
view(-45,25);
hold on;
title('Sample Course')
xlabel('x')
ylabel('y')
zlabel('z')
for j=1:1199
    addpoints(pos,x(j,1),y(j,1),z(j,1));
    head = scatter3(x(j,1),y(j,1),z(j,1),'filled','MarkerFaceColor','r','MarkerEdgeColor','r');
    drawnow
    %pause(0.01);
    delete(head);
end