 % run Chris' file
state_decoupling

%% Motor mixing matrix
M_motor = [1, 1, 1, -1; ...
           1, 1, -1, 1; ...
           1, -1, -1, -1; ...
           1, -1, 1, 1 ]; % converts from TEAR to n1,...,n4

M_inv = inv(M_motor); %converts from n1,...,n4 to TEAR    
  
%% Q and R for Kalman/Wiener filters
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
  
% A,B,C,D matrices for wiener filter
A1_wiener = [0 1 ; ...
             0 0];
B1_wiener = [0; ... 
             1];
C1_wiener = [1 0];
D1_wiener = [0];

A1_cont = A1_wiener;
B1_cont = B1_wiener;
C1_cont = C1_wiener;
D1_cont = B1_wiener;

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
  
%% Q and R for controller gains K1,...,K4   
Qthrust = diag([1 1]);
Rthrust = 1;  
Qelevator = diag([1 1 1 1]);
Relevator = 1; 
Qaileron = diag([1 1 1 1]);
Raileron = 1;  
Qrudder = diag([1 1]);
Rrudder = 1;  

%% Controller gains K for TEAR
Kthrust = lqr(Athrust, Bthrust, Qthrust, Rthrust);
Kelevator = lqr(Aelevator, Belevator, Qelevator, Relevator);
Kaileron = lqr(Aaileron, Baileron, Qaileron, Raileron); 
Krudder = lqr(Arudder, Brudder, Qrudder, Rrudder); 


% integral control attempt
% A1_bar = [0      C1; ...
%          [0;0]   A1 ];
% B1_bar = [D1; ...
%          B1];
% K1 = lqr(A1_bar, B1_bar, Q1, R1);
% Ki1 = K1(1);
% Kx1 = K1(2:3);

% A2_bar = [[0 0; 0 0]                   C2; ...
%            [0 0; 0 0; 0 0; 0 0]         A2 ];
% B2_bar = [D2; ...
%           B2];
% K2 = lqr(A2_bar, B2_bar, Q2, R2);
% Ki2 = K1(1:2);
% Kx2 = K1(3:6);

%% Actuator dynamics
V = 5; % measured battery voltage
V0 = 5; % actual battery voltage

syms tau2
tau2 = eval(max(solve(1/sqrt((tau2*2*pi*10)^2+1^2) == 1/sqrt(2), tau2)));
tau1 = 30e-3; % delay time of actuator 










