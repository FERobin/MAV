%% Generating Data
clear all, close all
%Testing pseudo random coordinates from drone
n = 1000; dec = 0.01;
x = zeros(n,1);y = zeros(n,1);z = zeros(n,1);
for i = 1:n
    coord = cellfun(@double,(cell(py.coord.get_coord3(i))));
    x(i) = coord(1);
    y(i) = coord(2);
    z(i) = coord(3);
end
%% Plotting
% plot course
figure()
pos = animatedline('LineWidth',2);
% set(gca,'XLim',[0 10],'YLim',[0 10],'ZLim',[0 10]);
% view(-45,25);
hold on;
title('Sample Course')
xlabel('x')
ylabel('y')
zlabel('z')
for j=1:n
    addpoints(pos,x(j),y(j),z(j));
    head = scatter3(x(j),y(j),z(j),'filled','MarkerFaceColor','r','MarkerEdgeColor','r');
    drawnow
    pause(0.01);
    delete(head);
end
