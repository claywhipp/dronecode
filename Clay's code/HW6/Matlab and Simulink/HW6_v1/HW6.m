
syms t

%A,B,C,D matrices
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

A1_eval = eval(subs(A1_sampled, t));
B1_eval = eval(subs(B1_sampled, t));
C1_eval = C1_sampled;
D1_eval = D1_sampled;     


A2 = @(t) [0];
B2 = @(t) [1];
    
A2_sampled = @(t) expm(A2*t);
B2_sampled = @(t) int(expm(A2*t))*B2;

C2_sampled = [1];
D2_sampled = [0];

t = 0.005;

A2_eval = eval(subs(A2_sampled, t));
B2_eval = eval(subs(B2_sampled, t));
C2_eval = C2_sampled;
D2_eval = D2_sampled;  

% Q and R
q1_noise = 0.0101; %cov(wdot);
r1_noise = 0.0166; %cov(z);

q2_noise = 1; %cov(udot) = 0.5636;
r2_noise = 100; %cov(u) = 0.3250;

q3_noise = 1; %cov(vdot);
r3_noise = 100; %cov(v);

q4_noise = 0.0001; %cov(p);
r4_noise = 0.01; %cov(phi);

q5_noise = 0.001; %cov(q);
r5_noise = 0.0001; %cov(theta);

% Plotting data

%zw Kalman filter
t_out = rt_tout;
z = rt_states.signals.values(:,1);
w = rt_states.signals.values(:,2);
wdot = rt_states.signals.values(:,10);
zkalman = rt_zkalman.signals.values;
wkalman = rt_wkalman.signals.values;

figure
plot(t_out, z, t_out, zkalman);
title('z raw and kalman')
xlabel('Time (s)')
ylabel('z')
legend('altitude sensor', 'kalman');

figure
plot(t_out, w, t_out, wkalman);
title('w raw and kalman')
xlabel('Time (s)')
ylabel('w')
legend('raw', 'kalman');

% u kalman filter
u = rt_states.signals.values(:,4);
ukalman = rt_ukalman.signals.values;

figure
plot(t_out, u, t_out, ukalman);
title('u raw and kalman')
xlabel('Time (s)')
ylabel('u')
legend('raw sensor', 'kalman');

% v kalman filter
v = rt_states.signals.values(:,5);
vkalman = rt_vkalman.signals.values;

figure
plot(t_out, v, t_out, vkalman);
title('v raw and kalman')
xlabel('Time (s)')
ylabel('v')
legend('raw sensor', 'kalman');

%phi kalman filter
phi = rt_states.signals.values(:,6);
phikalman = rt_phikalman.signals.values;

figure
plot(t_out, phi, t_out, phikalman);
title('phi raw and kalman')
xlabel('Time (s)')
ylabel('phi')
legend('raw sensor', 'kalman');

% theta kalman filter
theta = rt_states.signals.values(:,7);
thetakalman = rt_thetakalman.signals.values;

figure
plot(t_out, theta, t_out, thetakalman);
title('theta kalman')
xlabel('Time (s)')
ylabel('theta')
legend('raw sensor', 'kalman');

possiblezero1 = rt_possiblezero1.signals.values;

figure
plot(t_out, possiblezero1);
title('possible zero 1')
xlabel('Time (s)')

possiblezero2 = rt_possiblezero2.signals.values;

figure
plot(t_out, possiblezero2);
title('possible zero 2')
xlabel('Time (s)')

booleanoutput = rt_booleanoutput.signals.values;

figure
plot(t_out, booleanoutput);
title('boolean output')
xlabel('Time (s)')

checksign = rt_checksign.signals.values;

figure
plot(t_out, checksign);
title('check sign')
xlabel('Time (s)')



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% Wiener filter 

% z, w
A1_cont = A1;
B1_cont = B1;
C1_cont = C1;
D1_cont = B1;

G1 = [0; ...
      1]; % G associated with process noise w, which comes from w, not z 
          % since w is the input
Q1 = q1_noise;
R1 = r1_noise;
N1 = 0;

L1 = lqe(A1_cont, G1, C1_cont, Q1, R1, N1);

% u
A2_cont = [0];
B2_cont = [1];
C2_cont = [1];
D2_cont = [0];

G2 = B2_cont;
Q2 = q2_noise;
R2 = r2_noise;
N2 = 0;

L2 = lqe(A2_cont, G2, C2_cont, Q2, R2, N2);

% v

Q3 = q3_noise;
R3 = r3_noise;
N3 = 0;

L3 = lqe(A2_cont, G2, C2_cont, Q3, R3, N3);


% phi

Q4 = q4_noise;
R4 = r4_noise;
N4 = 0;

L4 = lqe(A2_cont, G2, C2_cont, Q4, R4, N4);


% theta

Q5 = q5_noise;
R5 = r5_noise;
N5 = 0;

L5 = lqe(A2_cont, G2, C2_cont, Q5, R5, N5);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% zw 
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









