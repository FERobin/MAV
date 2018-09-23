function state=CalState(handle)
%CalState get the calibration state
%handle is the handle for the gui
%state is the current state

str=get(handle.pushbutton1,'String');
str2 = get(handle.pushbutton3,'String');
str3=get(handle.pushbutton4,'String');
if strcmp(str,'Start')
    state=0;
elseif strcmp(str,'Move')
    state=1;
elseif strcmp(str,'Land')
    state=2;
elseif strcmp(str,'Stop')
    state=3;
elseif strcmp(str,'Exit')
    state=4;
end

if strcmp(str2,'Exit')
    state=3;    
end
if strcmp(str3,'Soft Landing')
    state=5;
end
end