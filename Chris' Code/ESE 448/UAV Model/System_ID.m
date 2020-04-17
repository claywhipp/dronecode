



load('systemID_data_zip/bang_bang_T/motor_speed_dataT.mat');
load('systemID_data_zip/bang_bang_T/sensor_dataT.mat');
load('systemID_data_zip/bang_bang_T/sensor_state_dataT.mat');
load('systemID_data_zip/bang_bang_T/state_est_dataT.mat');
% 
% close all
% figure;
% plot(motor_speed_data(:,1));
% hold on
% for i=2:size(motor_speed_data,2)
%     plot(motor_speed_data(:,i));
% end
% legend({'n1','n2','n3','n4'});
% figure;
% plot(sensor_data(:,1));
% hold on
% for i=2:size(sensor_data,2)
%     plot(sensor_data(:,i));
% end
% figure;
% plot(state_est_data(:,1));
% hold on
% for i=2:size(state_est_data,2)
%     plot(state_est_data(:,i));
% end
% figure;
% plot(y_fil(:,1));
% hold on
% for i=2:size(y_fil,2)
%     plot(y_fil(:,i));
% end

MotorMix = [...%T  E  A  R
                1  1  1 -1 ;... %n1  T+ E+ A+ R-
                1  1 -1  1 ;... %n2  T+ E+ A- R+
                1 -1 -1 -1 ;... %n3  T+ E- A- R-
                1 -1  1  1 ;... %n4  T+ E- A+ R+
];

T = motor_speed_data*[ 1; -1;  1; -1]/4;
E = motor_speed_data*[ 1; -1; -1;  1]/4;
A = motor_speed_data*[ 1;  1; -1; -1]/4;
R = motor_speed_data*[-1; -1; -1; -1]/4;

z  = state_est_data(:,4);
w  = state_est_data(:,10);
% az = sensor_data(:,3);


phi = [w(1:end-1), T(1:end-1)];
W   = [w(2:end)];

% wdot = b*w + c*T
% wdot =~ (w(i+1)-w(i))/dT
% 
% w(i+1) = wdot*dT + w(i)
% w(i+1) = (b*w(i) + c*T)*dT + w(i)
% w(i+1) = (1 + b*dT)*w(i) + c*T*dT
% 
% w(i+1) = [w(i) T(i)]*[(1+b*dT); c*dT];

C = phi\W;

% Zdot = 1*w
% Wdot = b*w + c*T;

dT = 1/200;

b = (C(1)-1)/dT;
c = C(2)/dT;