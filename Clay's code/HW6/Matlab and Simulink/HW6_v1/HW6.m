%% Initialize
close all
load('RSdata.mat');
%% A1_kalman,B1_kalman,C1_kalman,D1_kalman 
syms t
A1 = [0 1 ; ...
      0 0];
B1 = [0; ... 
      1];
  
C1 = [1 0];

D1 = [0];
    
A1_sampled = expm(A1*t);
B1_sampled = int(expm(A1*t))*B1;

C1_sampled = C1; % only output z because z is the only state we can measure out of z and w
D1_sampled = D1;

t = 0.005;

A1_kalman = eval(subs(A1_sampled, t));
B1_kalman = eval(subs(B1_sampled, t));
C1_kalman = C1_sampled;
D1_kalman = D1_sampled;     

%% A2_kalman,B2_kalman,C2_kalman,D2_kalman 
syms t
A2 = @(t) [0];
B2 = @(t) [1];
    
A2_sampled = @(t) expm(A2*t);
B2_sampled = @(t) int(expm(A2*t))*B2;

C2_sampled = [1];
D2_sampled = [0];

t = 0.005;

A2_kalman = eval(subs(A2_sampled, t));
B2_kalman = eval(subs(B2_sampled, t));
C2_kalman = C2_sampled;
D2_kalman = D2_sampled;  

%% Q and R
q1_noise = 1; %cov(wdot) = 0.0101;
r1_noise = 100; %cov(z) = 0.0166;

q2_noise = 1; %cov(udot) = 0.5636;
r2_noise = 100; %cov(u) = 0.3250;

q3_noise = 1; %cov(vdot);
r3_noise = 100; %cov(v);

q4_noise = 1; %cov(p);
r4_noise = 100; %cov(phi);

q5_noise = 1; %cov(q);
r5_noise = 100; %cov(theta);

%% Plotting Z,w Kalman
t_out = rt_tout;
Z = rt_states.signals.values(:,1);
w = rt_states.signals.values(:,2);
zkalman = rt_zkalman.signals.values;
wkalman = rt_wkalman.signals.values;

az = rt_states.signals.values(:,11);
azbias = az - (-9.4351);

Z2int = rt_states.signals.values(:,3);

figure
plot(t_out, Z, t_out, zkalman);
title('Z raw and kalman')
xlabel('Time (s)')
ylabel('z')
legend('altitude sensor', 'kalman');

figure
plot(t_out, w, t_out, wkalman);
title('w raw and kalman')
xlabel('Time (s)')
ylabel('w')
legend('raw', 'kalman');

figure
title('azbias')
plot(t_out,azbias);
legend('azbias');

%% Plotting u Kalman
% u = rt_states.signals.values(:,4);
% ukalman = rt_ukalman.signals.values;
% ax = rt_states.signals.values(:,8);
% 
% figure
% plot(t_out, u, t_out, ukalman);
% title('u raw and kalman')
% xlabel('Time (s)')
% ylabel('u')
% legend('raw sensor', 'kalman');
% 
% figure
% plot(t_out,ax);
% legend('ax');

%% Plotting v Kalman
% v = rt_states.signals.values(:,5);
% vkalman = rt_vkalman.signals.values;
% ay = rt_states.signals.values(:,9);
% 
% figure
% plot(t_out, v, t_out, vkalman);
% title('v raw and kalman')
% xlabel('Time (s)')
% ylabel('v')
% legend('v raw sensor', 'v kalman');
% 
% figure
% plot(t_out,ay);
% legend('ay');


%% Plotting phi Kalman
phi = rt_states.signals.values(:,6);
phikalman = rt_phikalman.signals.values;
p = rt_states.signals.values(:,13);

figure
plot(t_out, phi, t_out, phikalman, t_out, p);
title('phi kalman')
xlabel('Time (s)')
ylabel('phi')
legend('phi integrated', 'phi kalman', 'p');

%% Plotting theta Kalman
theta = rt_states.signals.values(:,7);
thetakalman = rt_thetakalman.signals.values;
q = rt_states.signals.values(:,14);

figure
plot(t_out, theta, t_out, thetakalman, t_out, q);
title('theta kalman')
xlabel('Time (s)')
legend('integrated', 'kalman', 'q');



%% Checking for zeros 
% possiblezero1 = rt_possiblezero1.signals.values;
% 
% figure
% plot(t_out, possiblezero1);
% title('possible zero 1')
% xlabel('Time (s)')
% 
% possiblezero2 = rt_possiblezero2.signals.values;
% 
% figure
% plot(t_out, possiblezero2);
% title('possible zero 2')
% xlabel('Time (s)')
% 
% booleanoutput = rt_booleanoutput.signals.values;
% 
% figure
% plot(t_out, booleanoutput);
% title('boolean output')
% xlabel('Time (s)')
% 
% booleanoutput1 = rt_booleanoutput1.signals.values;
% 
% figure
% plot(t_out, booleanoutput1,'o');
% title('boolean output 1')
% xlabel('Time (s)')
% 
% checksign = rt_checksign.signals.values;
% 
% figure
% plot(t_out, checksign);
% title('check sign')
% xlabel('Time (s)')
% 
%% Wiener filter 
% 
% % z, w
% A1_cont = A1;
% B1_cont = B1;
% C1_cont = C1;
% D1_cont = B1;
% 
% G1 = [0; ...
%       1]; % G associated with process noise w, which comes from w, not z 
%           % since w is the input
% Q1 = q1_noise;
% R1 = r1_noise;
% N1 = 0;
% 
% L1 = lqe(A1_cont, G1, C1_cont, Q1, R1, N1);
% 
% % u
% A2_cont = [0];
% B2_cont = [1];
% C2_cont = [1];
% D2_cont = [0];
% 
% G2 = B2_cont;
% Q2 = q2_noise;
% R2 = r2_noise;
% N2 = 0;
% 
% L2 = lqe(A2_cont, G2, C2_cont, Q2, R2, N2);
% 
% % v
% 
% Q3 = q3_noise;
% R3 = r3_noise;
% N3 = 0;
% 
% L3 = lqe(A2_cont, G2, C2_cont, Q3, R3, N3);
% 
% 
% % phi
% 
% Q4 = q4_noise;
% R4 = r4_noise;
% N4 = 0;
% 
% L4 = lqe(A2_cont, G2, C2_cont, Q4, R4, N4);
% 
% 
% % theta
% 
% Q5 = q5_noise;
% R5 = r5_noise;
% N5 = 0;
% 
% L5 = lqe(A2_cont, G2, C2_cont, Q5, R5, N5);
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% wiener plots 
% zwiener = rt_zwiener.signals.values;
% wwiener = rt_wwiener.signals.values;
% t_z = rt_zwiener.time;
% t_w = rt_wwiener.time;
% 
% t_out = rt_tout;
% 
% figure
% plot(t_z, zwiener, t_out, z, t_out, zintegrated);
% title('z wiener and raw')
% xlabel('Time (s)')
% ylabel('z')
% legend('wiener','altitude sensor', 'double integrated');
% 
% figure
% plot(t_w, wwiener, t_out, w);
% title('w wiener and raw')
% xlabel('Time (s)')
% ylabel('w')
% legend('wiener','raw');


% % u
% uwiener = rt_uwiener.signals.values;
% t_u = rt_uwiener.time;
% 
% t_out = rt_tout;
% 
% figure
% plot(t_u, uwiener, t_out, u);
% title('u wiener and raw')
% xlabel('Time (s)')
% ylabel('u')
% legend('wiener','altitude sensor');


% % v
% vwiener = rt_vwiener.signals.values;
% t_v = rt_vwiener.time;
% 
% t_out = rt_tout;
% 
% figure
% plot(t_v, vwiener, t_out, v);
% title('v wiener and raw')
% xlabel('Time (s)')
% ylabel('v')
% legend('wiener','altitude sensor');


% % phi
% phiwiener = rt_phiwiener.signals.values;
% t_phi = rt_phiwiener.time;
% 
% t_out = rt_tout;
% 
% figure
% plot(t_phi, phiwiener, t_out, phi);
% title('phi wiener and raw')
% xlabel('Time (s)')
% ylabel('phi')
% legend('wiener','altitude sensor');

% % theta
% thetawiener = rt_thetawiener.signals.values;
% t_theta = rt_thetawiener.time;
% 
% t_out = rt_tout;
% 
% figure
% plot(t_theta, thetawiener, t_out, theta);
% title('theta wiener and raw')
% xlabel('Time (s)')
% ylabel('theta')
% legend('wiener','altitude sensor');









