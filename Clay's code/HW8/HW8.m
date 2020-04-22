 % % state est data best data to use? 
%% Motor matrix
M_motor = [1, 1, 1, -1; ...
           1, 1, -1, 1; ...
           1, -1, -1, -1; ...
           1, -1, 1, 1 ]; % used to go from TEAR to n1,...,n4      
M_inv = inv(M_motor); %used to go from n1,...,n4 to TEAR


%% (1)
% % Load in data
% load('systemID_data_zip\bang_bang_T\state_est_dataT.mat')
% load('systemID_data_zip\bang_bang_T\motor_speed_dataT.mat')
% 
% 
% % Converting from n1,...,n4 to TEAR
% motor_speed_data_corrected = motor_speed_data*diag([1 -1 1 -1]);
% motor_speed_data_tran = motor_speed_data_corrected'; 
% TEAR_tran = M_inv*motor_speed_data_tran;
% TEAR = TEAR_tran';
% 
% % Constants
% matrixsize = size(state_est_data);
% datasize = matrixsize(1);
% dT = 0.005;
% 
% % Detrending w
% time = state_est_data(:,1);
% w = state_est_data(:,10);
% w_corrected = detrend(w);
% %figure
% %plot(time, w, time, w_corrected);
% %legend('w', 'w detrended');
% 
% % Correcting T using T_trim (Chris' idea) 
% T = TEAR(:,1);
% T_trim = 301.45; % taken from sample point 450 of throttle data. Idea came
%                  % from Chris Bonney, shouts out to him!!!!!
% T_corrected = T - T_trim;
% 
% %figure
% %plot(T_corrected);
% 
% % Correcting delay
% n = 801;
% sampletime = [1:n];
% delay = 9; % in sample points, from plot below
% %figure
% %plotyy(sampletime, T_corrected, sampletime, w_corrected);
% %legend('Throttle', 'w');
% 
% % Bang band start and end times
% bangbang_start = 200; % units are sample points 
% bangbang_end = 400; 
% 
% % Throttle (z, w)
% w_i = w_corrected(bangbang_start+delay:bangbang_end-1);
% w_iplus1 = w_corrected(bangbang_start+1+delay:bangbang_end);
% T_i = T_corrected(bangbang_start:bangbang_end-1-delay);
% Phi_T= [w_i T_i]; % could also use sensor_state_dataT
% Phi_T_inv = pinv(Phi_T);
% 
% bc_T = Phi_T_inv*(w_iplus1 - w_i)/dT;
% b_T = bc_T(1); % 0.1741
% c_T = bc_T(2); % -0.0427
% 
% % Elevator (theta, q)
% q_i = state_est_data(bangbang_start+delay:bangbang_end-1,12);
% q_iplus1 = state_est_data(bangbang_start+1+delay:bangbang_end,12);
% E_i = TEAR(bangbang_start:bangbang_end-1-delay,2);
% Phi_E= [q_i E_i]; % could also use sensor_state_dataT
% Phi_E_inv = pinv(Phi_E);
% bc_E = Phi_E_inv*(q_iplus1 - q_i)/dT;
% b_E = bc_E(1); % -0.0981
% c_E = bc_E(2); % 4.8964
% 
% % Aileron (phi, p)
% p_i = state_est_data(1:datasize-1,11);
% p_iplus1 = state_est_data(2:datasize,11);
% A_i = TEAR(1:datasize-1,3);
% Phi_A= [p_i A_i]; % could also use sensor_state_dataT
% Phi_A_inv = pinv(Phi_A);
% bc_A = Phi_A_inv*(p_iplus1 - p_i)/dT;
% b_A = bc_A(1); % 4.8073
% c_A = bc_A(2); % 65.7956
% 
% % Rudder (psi, r)
% r_i = state_est_data(1:datasize-1,13);
% r_iplus1 = state_est_data(2:datasize,13);
% R_i = TEAR(1:datasize-1,4);
% Phi_R= [r_i R_i]; % could also use sensor_state_dataT
% Phi_R_inv = pinv(Phi_R);
% bc_R = Phi_R_inv*(r_iplus1 - r_i)/dT;
% b_R = bc_R(1); % -0.4500
% c_R = bc_R(2); % 2.7482

%% (2) Finding motor transfer function
load('systemID_data_zip\chirp_motor1\state_est_data1.mat')
load('systemID_data_zip\chirp_motor1\chirp_data1.mat')
load('log_chirp_data\log_chirp_50Hz.mat')




% constants
b = 0.1741; % b_T
c = -0.0427; % c_T
deltaT = 0.005;
chirp_start = 2000;
chirp_end = 4000;
delay = 9;

%figure
%plot(chirp_data(:,1));
%figure
%plot(time, motor_speed_data);

bcinv = pinv([b c]);

% Detrending w
time = state_est_data(:,1);
w = state_est_data(:,10);
w_length = size(w);
w_corrected = detrend(w);
w_transp = w_corrected';
% figure
% plot(w_corrected);
% legend('w detrended');

% Equation is [w_i; T_i] = [b c]^-1*(w_i+1 - w_i)/deltaT
w_i = w_transp(chirp_start:chirp_end-1-delay); % when is the chirp signal
w_iplus1 = w_transp(chirp_start+1:chirp_end-delay); %todo: add az
wT_transp = bcinv*(w_iplus1 - w_i)/deltaT;
wT = wT_transp';
T = wT(:,2);
% plot(T);

% Adding EAR to T
TEAR = [T zeros(1991,3)];

% Converting from TEAR to n1,...,n4
TEAR_tran = TEAR';
motorspeeds_tran = M_motor*TEAR_tran;
motorspeeds = motorspeeds_tran'; % n_a
motorspeed1 = motorspeeds(:,1);
chirp_transp = chirp_data(chirp_start+delay: chirp_end-1); % n_c
chirp = chirp_transp';

% more constants
signalarea = size(chirp);
signallength = signalarea(1); %1992

% figures
figure
plotyy((1:signallength), motorspeed1, (1:signallength), chirp);
legend('n_a', 'n_c');

n_a = motorspeed1;
n_c = chirp;

dT = 0.005;

n_a = double(n_a);
n_c = double(n_c);

obj=iddata(n_a, n_c, dT);

sys=tfest(obj,1);



