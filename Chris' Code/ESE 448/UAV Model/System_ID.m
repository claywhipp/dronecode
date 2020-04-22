

%% Bang-Bang Throttle
%load in data
load('systemID_data_zip/bang_bang_T/motor_speed_dataT.mat');
load('systemID_data_zip/bang_bang_T/sensor_dataT.mat');
load('systemID_data_zip/bang_bang_T/sensor_state_dataT.mat');
load('systemID_data_zip/bang_bang_T/state_est_dataT.mat');

MotorMix = [...%T  E  A  R
                1  1  1 -1 ;... %n1  T+ E+ A+ R-
                1  1 -1  1 ;... %n2  T+ E+ A- R+
                1 -1 -1 -1 ;... %n3  T+ E- A- R-
                1 -1  1  1 ;... %n4  T+ E- A+ R+
]';

%correct negative motor speeds
motor_correction = diag([1 -1 1 -1]);
motor_speed_data = motor_speed_data*motor_correction;

% get Throttle
TEAR = motor_speed_data/MotorMix;
T = TEAR(:,1);

% T = motor_speed_data*[ 1; -1;  1; -1]/4;
% E = motor_speed_data*[ 1; -1; -1;  1]/4;
% A = motor_speed_data*[ 1;  1; -1; -1]/4;
% R = motor_speed_data*[-1; -1; -1; -1]/4;

%get states
z  = state_est_data(:,4);
w  = state_est_data(:,10);
% az = sensor_data(:,3);

%correct data
bang_bang_start = 200;  %start of bang bang
bang_bang_end = 400;    %end of bang bang
T_trim = 303;           %trim offset
delay = 7;              %time delay from actuator
w = detrend(w);         %correct for w offset from pre bang bang dynamics


%create system to solve using backwards euler
% wdot = b*w + c*T
% w(i+1) = wdot*dT + w(i)
% w(i+1) = [w(i) T(i)]*[(1+b*dT); c*dT];
phi = [w(bang_bang_start+delay:bang_bang_end-1+delay), (T(bang_bang_start:bang_bang_end-1)-T_trim)];
W   = [w(bang_bang_start+1+delay:bang_bang_end+delay)];
%solve for system parameters
C = phi\W;
b = (C(1)-1)/dT; %damping term on w
c = C(2)/dT;     %more accurate coefficient for Throttle
%%%% check that delay correction is accurate
% figure;
% plotyy(1:length(W),phi(:,1),1:length(W),phi(:,2));


%% Throttle Chirp (Actuator Dynamics)

%load in data
% load('log_chirp_data/log_chirp_1Hz.mat');
% load('log_chirp_data/log_chirp_5Hz.mat');
% load('log_chirp_data/log_chirp_10Hz.mat');
% load('log_chirp_data/log_chirp_20Hz.mat');
load('log_chirp_data/log_chirp_50Hz.mat');

motor_speed_data = motor_speed_data*motor_correction;

% get Throttle
TEAR = motor_speed_data/MotorMix;
T_trim = 301.5;
T_cmd = TEAR(:,1)-T_trim;


% T_act = (b*w-az)/c;








%% Elevator Bang-Bang




