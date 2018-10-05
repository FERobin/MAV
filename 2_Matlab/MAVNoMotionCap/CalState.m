function [state,mode]=CalState(handle)
%CalState get the calibration state
%handle is the handle for the gui
%state is the current state
%Edited by Phil Kwon 9/30/18
str=get(handle.pushbutton1,'String');
str2 = get(handle.pushbutton3,'String');
str3=get(handle.pushbutton4,'String');
str4 = get(handle.togglebutton2,'String');
if strcmp(str4,'Motion Capture') %Motion capture str4 should be editted out. Or you can make mode always=1 by editing out lines 10-12
    mode = 0; %Takeoff using motion cap
else
    mode = 1; %Takeoff using optical flow
end
if strcmp(str,'Start')   % Is it starting up and calibrating or is it in hover. The str should properly reflect it's actions
    state=0;
elseif strcmp(str,'Move')  %Might want to clarify move into move in a pattern.
    if mode
        state=2;
    else
        state=1;
    end
elseif strcmp(str,'Land')  % What type of landing is this? Emergency landing
    state=2;
elseif strcmp(str,'Stop') % Is this the emergency kill switch that stops the drone?
    state=3;
elseif strcmp(str,'Exit') % Exit the screen/window I assume
    state=4;
end

if strcmp(str2,'Exit') % Exit the screen/window I assume
    state=3;    
end
if strcmp(str3,'Soft Landing')
    state=5;
end

end
