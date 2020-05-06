 % % state est data best data to use? 
%% Motor matrix
M_motor = [1, 1, 1, -1; ...
           1, 1, -1, 1; ...
           1, -1, -1, -1; ...
           1, -1, 1, 1 ]; % used to go from TEAR to n1,...,n4      
M_inv = inv(M_motor); %used to go from n1,...,n4 to TEAR


%% (1)
% Load in data

load('systemID_data_zip\bang_bang_T\state_est_dataT.mat')
load('systemID_data_zip\bang_bang_T\motor_speed_dataT.mat')
load('systemID_data_zip\bang_bang_T\sensor_dataT.mat')

% load('systemID_data_zip\bang_bang_E\state_est_dataE.mat')
% load('systemID_data_zip\bang_bang_E\motor_speed_dataE.mat')
% load('systemID_data_zip\bang_bang_E\sensor_dataE.mat')

% load('systemID_data_zip\bang_bang_A\state_est_dataA.mat')
% load('systemID_data_zip\bang_bang_A\motor_speed_dataA.mat')
% load('systemID_data_zip\bang_bang_A\sensor_dataA.mat')

% load('systemID_data_zip\bang_bang_R\state_est_dataR.mat')
% load('systemID_data_zip\bang_bang_R\motor_speed_dataR.mat')
% load('systemID_data_zip\bang_bang_R\sensor_dataR.mat')

% Constants
matrixsize = size(state_est_data);
datasize = matrixsize(1);
dT = 0.005;
delay = 9; % in sample points, from plot of T vs w
n = 801;
sampletime = (1:n);
bangbang_start = 200; % units are sample points 
bangbang_end = 400; 


% Converting from n1,...,n4 to TEAR
motor_speed_data_corrected = motor_speed_data*diag([1 -1 1 -1]);
motor_speed_data_tran = motor_speed_data_corrected'; 
TEAR_tran = M_inv*motor_speed_data_tran;
TEAR = TEAR_tran';

time = state_est_data(:,1);

% T
T = TEAR(:,1);
T_trim = 303; % this was tweaked until the actual w matched the w_sim found using our b and c values
T_corrected = T - T_trim;

% w
w = state_est_data(:,10);
w_corrected = detrend(w);

% az
az = sensor_data(:,3);
az_corrected = detrend(az);

% Throttle (z, w)
w_i = w_corrected(bangbang_start+delay:bangbang_end-1);
w_iplus1 = w_corrected(bangbang_start+1+delay:bangbang_end);
az_i = az_corrected(bangbang_start+delay:bangbang_end-1);
T_i = T_corrected(bangbang_start:bangbang_end-1-delay);

Phi_T= [w_i T_i]; % could also use sensor_state_dataT
Phi_T_inv = pinv(Phi_T);

anotherc = pinv(T_i)*w_i;
bc_T = Phi_T_inv*(w_iplus1 - w_i)/dT;
% bc_T = Phi_T_inv*az_i;
b_T = bc_T(1); % 0.4972
c_T = bc_T(2); % -0.0411

% Elevator (theta, q)
q = state_est_data(:,12);
q_corrected = detrend(q);
E = TEAR(:,2);

q_i = q_corrected(bangbang_start+delay:bangbang_end-1);
q_iplus1 = q_corrected(bangbang_start+1+delay:bangbang_end);
E_i = E(bangbang_start:bangbang_end-1-delay);
Phi_E= [q_i E_i];
Phi_E_inv = pinv(Phi_E);
bc_E = Phi_E_inv*(q_iplus1 - q_i)/dT;
b_E = bc_E(1);
c_E = bc_E(2);

% Aileron (phi, p)
p = state_est_data(:,11);
p_corrected = detrend(p);
A = TEAR(:,3);

p_i = p_corrected(bangbang_start+delay:bangbang_end-1);
p_iplus1 = p_corrected(bangbang_start+1+delay:bangbang_end);
A_i = A(bangbang_start:bangbang_end-1-delay);
Phi_A= [p_i A_i];
Phi_A_inv = pinv(Phi_A);
bc_A = Phi_A_inv*(p_iplus1 - pi)/dT;
b_A = bc_A(1);
c_A = bc_A(2);

% Rudder (psi, r)
r = state_est_data(:,13);
r_corrected = detrend(r);
R = TEAR(:,4);

r_i = r_corrected(bangbang_start+delay:bangbang_end-1);
r_iplus1 = r_corrected(bangbang_start+1+delay:bangbang_end);
R_i = R(bangbang_start:bangbang_end-1-delay);
Phi_R= [r_i R_i];
Phi_R_inv = pinv(Phi_R);
bc_R = Phi_R_inv*(r_iplus1 - r_i)/dT;
b_R = bc_R(1);
c_R = bc_R(2);

% figures

% figure
% plot(time, w, time, w_corrected);
% legend('w', 'w detrended');

%figure
%plot(T_corrected);

% figure
% plotyy((1:191), T_i,(1:191), w_i);
% figure
% plotyy((1:191), T_i, (1:191), az_i);

%% (2) Finding motor transfer function
% load('log_chirp_data\log_chirp_50Hz.mat')
% 
% % constants
% b = 0.4972; % b_T
% c = -0.0411; % c_T
% deltaT = 0.005;
% chirp_start = 2000;
% chirp_end = 4000;
% delay = 9;
% 
% % Detrending w
% w = state_est_data(:,10);
% w_corrected = detrend(w);
% w_transp = w_corrected';
% w_iplus1 = w_corrected(chirp_start+1:chirp_end);
% w_i = w_corrected(chirp_start:chirp_end-1-delay);
% 
% 
% % Equation I'm using is az = b*w + T*c
% % Solve for T = (az-b*w)/c
% time = state_est_data(:,1);
% time_i = time(chirp_start:chirp_end-1-delay);
% 
% bcinv = pinv([b c]);
% az = sensor_data(:,3);
% az_corrected = detrend(az);
% az_i = az_corrected(chirp_start:chirp_end-1-delay);
% 
% T_i = (az_i-b*w_i)/c;
% 
% 
% % az_i_transp = az_i';
% % wT_transp = bcinv*az_i_transp;
% % %wT_transp = bcinv*(w_iplus1-w_i)/deltaT;
% % wT = wT_transp';
% % T = wT(:,2);
% 
% 
% % Adding EAR to T
% zero_row_size = size(T_i);
% zero_row_size = zero_row_size(1);
% TEAR = [T_i zeros(zero_row_size,3)];
% 
% % Converting from TEAR to n1,...,n4
% TEAR_tran = TEAR';
% motorspeeds_tran = M_motor*TEAR_tran;
% motorspeeds = motorspeeds_tran'; 
% n1 = motorspeeds(:,1); % n_a
% 
% chirp_transp = chirp_data(chirp_start+delay: chirp_end-1); 
% chirp = chirp_transp'; % n_c
% 
% % converting to double
% n_a = T_i;
% n_c = chirp;
% n_a = double(n_a);
% n_c = double(n_c);
% 
% % Obtaining bode plot
% obj=iddata(n_a, n_c, deltaT);
% sys=tfest(obj,1);
% figure
% bode(sys);
% 
% % figures
% 
% figure
% plot(time_i, T_i, time_i, chirp);
% xlabel('time (s)');
% ylabel('Amplitude (Hz)');
% title('Commanded motor speed (chirp signal) and actual motor speed over time');
% legend('n_a', 'n_c');
% 
% 
% % figure
% % plot(w_corrected);
% % legend('w detrended');
% 
% %figure
% %plotyy((1:signallength), motorspeed1, (1:signallength), chirp);
% %legend('n_a', 'n_c');
% 
% %figure
% %plot(chirp_data(:,1));
% %figure
% %plot(time, motor_speed_data);
