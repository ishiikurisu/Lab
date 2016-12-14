function varargout = message_ui(varargin)
% MESSAGE_UI M-file for message_ui.fig
%      MESSAGE_UI, by itself, creates a new MESSAGE_UI or raises the existing
%      singleton*.
%
%      H = MESSAGE_UI returns the handle to a new MESSAGE_UI or the handle to
%      the existing singleton*.
%
%      MESSAGE_UI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MESSAGE_UI.M with the given input arguments.
%
%      MESSAGE_UI('Property','Value',...) creates a new MESSAGE_UI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before message_ui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to message_ui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help message_ui

% Last Modified by GUIDE v2.5 14-Dec-2016 09:36:54

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @message_ui_OpeningFcn, ...
                   'gui_OutputFcn',  @message_ui_OutputFcn, ...
                   'gui_LayoutFcn',  [ ], ...
                   'gui_Callback',   @pushbuttonOk_Callback);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before message_ui is made visible.
function message_ui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to message_ui (see VARARGIN)

% Choose default command line output for message_ui
handles.running = true;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes message_ui wait for user response (see UIRESUME)
uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = message_ui_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
varargout{1} = handles.output;
close(handles.figure1);

function editMessage_Callback(hObject, eventdata, handles)
% hObject    handle to editMessage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editMessage as text
%        str2double(get(hObject,'String')) returns contents of editMessage as a double


% --- Executes during object creation, after setting all properties.
function editMessage_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editMessage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), ...
                   get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbuttonOk.
function pushbuttonOk_Callback(hObject, eventdata, handles)
% hObject    handle to pushbuttonOk (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = get(handles.editMessage, 'String');
handles.running = false;
guidata(hObject, handles);
uiresume(handles.figure1);
