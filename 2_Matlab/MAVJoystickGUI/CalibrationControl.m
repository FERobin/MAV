function varargout = CalibrationControl(varargin)
% CALIBRATIONCONTROL MATLAB code for CalibrationControl.fig
%      CALIBRATIONCONTROL, by itself, creates a new CALIBRATIONCONTROL or raises the existing
%      singleton*.
%
%      H = CALIBRATIONCONTROL returns the handle to a new CALIBRATIONCONTROL or the handle to
%      the existing singleton*.
%
%      CALIBRATIONCONTROL('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CALIBRATIONCONTROL.M with the given input arguments.
%
%      CALIBRATIONCONTROL('Property','Value',...) creates a new CALIBRATIONCONTROL or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before CalibrationControl_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to CalibrationControl_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help CalibrationControl

% Last Modified by GUIDE v2.5 20-Oct-2017 23:03:14

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @CalibrationControl_OpeningFcn, ...
                   'gui_OutputFcn',  @CalibrationControl_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before CalibrationControl is made visible.
function CalibrationControl_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to CalibrationControl (see VARARGIN)

% Choose default command line output for CalibrationControl
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes CalibrationControl wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = CalibrationControl_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
str=get(hObject,'String');
if strcmp(str,'Start')
    set(hObject,'String','Move');
elseif strcmp(str,'Move')
    set(hObject, 'String', 'Land');
elseif strcmp(str,'Land')
    set(hObject,'String','Stop');
elseif strcmp(str,'Stop')
    set(hObject,'String','Exit');
end


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%Off % Don't mess around, just turn it off
set(hObject,'String','Exit');


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
str=get(hObject,'String');
if strcmp(str,'Calibration')
    set(hObject,'String','Start calibration');
elseif strcmp(str,'Start calibration')
    set(hObject, 'String', 'Calibration');
end
