
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

%% forward Y
Y = 1;
for i = 400:599
    [x(i,:),y(i,:),z(i,:),yaw(i,:)] = nav(t(i),4,'translateY',Y,[1,0,0],[0,0,0],[1,0,0],[0,0,0]);
end

%% backward X
X = -1;
for i = 600:799
    [x(i,:),y(i,:),z(i,:),yaw(i,:)] = nav(t(i),6,'translateX',X,[1,0,0],[1,0,0],[1,0,0],[0,0,0]);
end

%% backward Y
Y = -1;
for i = 800:999
    [x(i,:),y(i,:),z(i,:),yaw(i,:)] = nav(t(i),8,'translateY',Y,[0,0,0],[1,0,0],[1,0,0],[0,0,0]);
end

%% landing
Z = -1;
for i = 1000:1199
    [x(i,:),y(i,:),z(i,:),yaw(i,:)] = nav(t(i),10,'altitude',Z,[0,0,0],[0,0,0],[1,0,0],[0,0,0]);
end


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