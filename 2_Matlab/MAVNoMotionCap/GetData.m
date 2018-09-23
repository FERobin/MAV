function [pos,ang] = GetData(mode)
%GetData toggles between getting data from MotionCap or Optical Flow
if mode %using optical flow
    pos = cellfun(@double,cell(py.serDat.pos()));
%     ang = cellfun(@double,cell(py.serDat.ang()));
%     pos = cell(py.serDat.pos());
%     ang = cell(py.serDat.ang());
%     pause(0.02);
else %using motion cap
    data = listener.trackerData;
    pause(0.02);
    pos = GetPos(data);
    ang = GetAng(data);
end