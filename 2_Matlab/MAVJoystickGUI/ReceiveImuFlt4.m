function resData=ReceiveImuFlt4(time)


imuCntr = 0;

resData=zeros(1,3);



    packet = ReceivePacket(time);

if ~isempty(packet)
    
    id   = packet(3);
    type = packet(5);
    
    %fprintf('got packet %d %d\n',id,type);
    imuVals2=zeros(1,9);
    if (id == 0 && type == 34) %LL
        imu = ParsePacket(packet);
        fprintf('.');
        
        imuVals2 = [imu.roll imu.pitch imu.yaw imu.wx imu.wy imu.wz imu.ax imu.ay imu.az];
        imuVals2(1:6) = imuVals2(1:6)/pi*180;
      %  disp(imu.t);
        imuCntr = imuCntr + 1;
        
    elseif (id == 0 && type == 1)
        %fprintf('.');
        fprintf('.');
        imui = typecast(packet(6:9),'uint32');
        imuVals2 = double(typecast(packet(10:end-4),'single'));
        imuVals2(1:6) = imuVals2(1:6)/pi*180;
        
    end
%     PlotImuFilt( imuVals2 );
    resData=imuVals2;


end

    
function ret = ReceivePacket(time)
persistent packetId buf2

if isempty(packetId)
  packetId = kBotPacket2API('create');
end

ret = [];

if ~isempty(buf2)
  [packet buf2] =  kBotPacket2API('processBuffer',packetId,buf2);
  if ~isempty(packet)
    ret = packet;
    return;
  end
end

buf = SerialDeviceAPI('read',500,time);
[packet buf2] = kBotPacket2API('processBuffer',packetId,buf);
if ~isempty(packet)
  ret = packet;
end


function PlotImuFilt(imu)
global hx hw ha
global dx dw da
persistent cntr

num = 1000;

if isempty(dw)
  dx   = zeros(3,num);
  dw   = zeros(3,num);
  da   = zeros(3,num);
    
  figure(101); clf(gcf); hold on;
  hx(1) = plot(dx(1,:),'r');
  hx(2) = plot(dx(2,:),'g');
  hx(3) = plot(dx(3,:),'b');
  hold off;
  
  figure(102); clf(gcf); hold on;
  hw(1) = plot(dw(1,:),'r');
  hw(2) = plot(dw(2,:),'g');
  hw(3) = plot(dw(3,:),'b');
  hold off;
  
  
  figure(103); clf(gcf); hold on;
  ha(1) = plot(da(1,:),'r');
  ha(2) = plot(da(2,:),'g');
  ha(3) = plot(da(3,:),'b');
  hold off;
  cntr = 0;
  
end

%update wx2
dx = [dx(:,2:end) imu(1:3)'];

set(hx(1),'ydata',dx(1,:));
set(hx(2),'ydata',dx(2,:));
set(hx(3),'ydata',dx(3,:));

%update wx
dw = [dw(:,2:end) imu(4:6)'];

set(hw(1),'ydata',dw(1,:));
set(hw(2),'ydata',dw(2,:));
set(hw(3),'ydata',dw(3,:));

%update acceleration
da = [da(:,2:end) imu(7:9)'];

set(ha(1),'ydata',da(1,:));
set(ha(2),'ydata',da(2,:));
set(ha(3),'ydata',da(3,:));

cntr = cntr + 1;

if (mod(cntr,2) == 0)
  drawnow;
end