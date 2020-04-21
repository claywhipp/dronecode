%(1)
%% Motor matrix
% state est data best data to use? 
M_motor = [1, 1, 1, -1; ...
           1, 1, -1, 1; ...
           1, -1, -1, -1; ...
           1, -1, 1, 1 ]; % used to go from TEAR to n1,...,n4      
M_inv = inv(M_motor); %used to go from n1,...,n4 to TEAR

%% Converting from n1,...,n4 to TEAR
motor_speed_data_corrected = motor_speed_data*diag([1 -1 1 -1]);
motor_speed_data_tran = motor_speed_data_corrected'; 
TEAR_tran = M_inv*motor_speed_data_tran;
TEAR = TEAR_tran';

%% Calculating bc for T, E, A, and R systems
matrixsize = size(state_est_data);
datasize = matrixsize(1);
dT = 0.005;
%% Detrending w
time = state_est_data(:,1);
w = state_est_data(:,10);
w_corrected = detrend(w);
% figure
% plot(time, w, time, w_corrected);
% legend('w', 'w detrended');

%% Correcting T using T_trim (Chris' idea) 
T = TEAR(:,1);
T_trim = 301.45; % taken from sample point 450 of throttle data. Idea came
                 % from Chris Bonney, shouts out to him!!!!!
T_corrected = T - T_trim;

% figure
% plot(T_corrected);

%% Correcting delay
n = 801;
sampletime = [1:n];
delay = 9; % in sample points, from plot below
% figure
% plotyy(sampletime, T_corrected, sampletime, w_corrected);
% legend('Throttle', 'w');

%% Bang band start and end times
bangbang_start = 200; % units are sample points 
bangbang_end = 400; 

%% Throttle (z, w)
w_i = state_est_data(bangbang_start+delay:bangbang_end-1,10);
w_iplus1 = state_est_data(bangbang_start+1+delay:bangbang_end,10);
T_i = TEAR(bangbang_start:bangbang_end-1-delay,1);
Phi_T= [w_i T_i]; % could also use sensor_state_dataT
Phi_T_inv = pinv(Phi_T);
bc_T = Phi_T_inv*(w_iplus1 - w_i)/dT;
b_T = bc_T(1); % 3.0768
c_T = bc_T(2); % 0.0018

%% Elevator (theta, q)
q_i = state_est_data(bangbang_start+delay:bangbang_end-1,12);
q_iplus1 = state_est_data(bangbang_start+1+delay:bangbang_end,12);
E_i = TEAR(bangbang_start:bangbang_end-1-delay,2);
Phi_E= [q_i E_i]; % could also use sensor_state_dataT
Phi_E_inv = pinv(Phi_E);
bc_E = Phi_E_inv*(q_iplus1 - q_i)/dT;
b_E = bc_E(1); % -0.0981
c_E = bc_E(2); % 4.8964

%% Aileron (phi, p)
p_i = state_est_data(1:datasize-1,11);
p_iplus1 = state_est_data(2:datasize,11);
A_i = TEAR(1:datasize-1,3);
Phi_A= [p_i A_i]; % could also use sensor_state_dataT
Phi_A_inv = pinv(Phi_A);
bc_A = Phi_A_inv*(p_iplus1 - p_i)/dT;
b_A = bc_A(1); % 4.8073
c_A = bc_A(2); % 65.7956

%% Rudder (psi, r)
r_i = state_est_data(1:datasize-1,13);
r_iplus1 = state_est_data(2:datasize,13);
R_i = TEAR(1:datasize-1,4);
Phi_R= [r_i R_i]; % could also use sensor_state_dataT
Phi_R_inv = pinv(Phi_R);
bc_R = Phi_R_inv*(r_iplus1 - r_i)/dT;
b_R = bc_R(1); % -0.4500
c_R = bc_R(2); % 2.7482


%% (2) Finding motor transfer function

% input is chirp data
% output is motor speeds? 
% wdot = b*w + c*T
% wdot = [b c][w; T]
% [w; T] = [b c]^-1*wdot
b = 3.0768; % b_T
c = 0.0018; % c_T


