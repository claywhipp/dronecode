% Run Chris's code to create dynamics
state_decoupling    

%HW3 Code - Equations of Motion
% syms u v w p q r phi theta psi XNED YNED ZNED n1 n2 n3 n4 

%% Rotation matrices
% Rtphi = [1 0 0 ; ...
%          0 cos(phi) sin(phi) ; ...
%          0  -sin(phi) cos(phi) ]; 
% 
% Rttheta =  [cos(theta) 0 -sin(theta) ; ...
%             0 1 0 ; ...
%             sin(theta) 0 cos(theta) ]; 
% 
% Rtpsi =  [cos(psi) sin(psi) 0 ; ... 
%           -sin(psi) cos(psi) 0 ; ...
%           0 0 1 ]; 

% %% 4.1 Vdot
% V = [u; v; w];
% 
% m = 0.068; % kg
% g = 9.81 ; % m/s^2
% 
% gvector = [0; 0; m*g];
% 
% % Thrust vector, T = sum(Ti) from i=1 to i=4
% Ct = 0.082; % at 299Hz or 18000 RPM  
% rho = 1.225; % kg/m3
% D = 0.066; %m
% 
% T =  Ct*rho*(n1^2 + n2^2 + n3^2 + n4^2)*D^4; % All propellers contribute positively to thrust
% thrustvector =  [0; 0; -T];
% 
% omega_cross = [0 -r  q; ...
%                r  0 -p; ...
%               -q  p  0];
%                   
% Vdot = 1/m * (-omega_cross*m*V + Rtphi*Rttheta*Rtpsi*gvector + thrustvector);
% 
% udot = Vdot(1);
% vdot = Vdot(2);
% wdot = Vdot(3);
                     
%% 4.2 Omegadot
% omega = [p; q; r];
% cross(omega, m*V);
% 
% Jxx = 0.0000582857; % kg/m^2
% Jyy = 0.0000716914; % kg/m^2
% Jzz = 0.0001; % kg/m^2
% 
% Jmatrix = [Jxx 0 0 ; ...
%            0 Jyy 0 ; ...
%            0 0 Jzz;];
% 
% h = 0.047625; % distance along the x-axis from CoM to center of rotor in meters
% b = 0.047625; % distance along the y-axis from CoM to center of rotor in meters
% 
% Cp = 0.041; % At 18000 RPM
% 
% Cl = Ct*h; % rolling moment
% Cm = Ct*b; % pitching moment
% Cn = Cp/(2*pi); % yawing moment
% 
% Lt =  b*Cl*rho*(n1^2 - n2^2 - n3^2 + n4^2)*D^4; 
% Mt =  b*Cm*rho*(n1^2 + n2^2 - n3^2 - n4^2)*D^4; 
% Nt =  b*Cn*rho*(-n1^2 + n2^2 - n3^2 + n4^2)*D^4; 
% 
% Mtvector = [Lt; Mt; Nt];
% 
% m_p = 0.001; % mass of propeller in kg
% L_p = D; % length (diameter) of propeller in m
% 
% Jp = (1/12)*m_p*L_p^2; % J of propeller in the propeller's frame in kg*m^2
% Jb = Jp + m_p*b^2; % J of propeller in body frame in kg*m^2
% 
% Mgyro = omega_cross*Jb*[0; 0; 2*pi*(n1-n2+n3-n4)];
% 
% Omegadot = inv(Jmatrix)*(-(omega_cross*Jmatrix*omega) + Mtvector + Mgyro);
% 
% pdot = Omegadot(1);
% qdot = Omegadot(2);
% rdot = Omegadot(3);
% 
% % 4.3 
% phidot = p + tan(theta)*(q*sin(phi)+r*cos(phi));
% 
% % 4.4
% thetadot = q*cos(phi) - r*sin(phi);
% 
% % 4.5
% psidot = (q*sin(phi) + r*cos(phi))/cos(theta);
% 
% % 4.6
% XYZNEDdot = Rtpsi.'*Rttheta.'*Rtphi.'*[u; v; w];
% 
% XNEDdot = XYZNEDdot(1);
% YNEDdot = XYZNEDdot(2);
% ZNEDdot = XYZNEDdot(3);
% 
% % 4.7
% h = -ZNED;
% 
% % 4.8
% accvector = (1/m)*thrustvector;
% ax = accvector(1);
% ay = accvector(2); 
% az = accvector(3);
% 
% % Jacobian to linearize the system
% A = jacobian([udot, vdot, wdot, pdot, qdot, rdot, phidot, thetadot, psidot, XNEDdot, YNEDdot, ZNEDdot], ...
%           [u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED]);
% 
% Aeval = eval(subs(A, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
%              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
%          
% B = jacobian([udot, vdot, wdot, pdot, qdot, rdot, phidot, thetadot, psidot, XNEDdot, YNEDdot, ZNEDdot], ...
%              [n1, n2, n3, n4]);
% 
% Beval = eval(subs(B, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
%                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
%          
% C = jacobian([h, ax, ay, az], ...
%              [u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED]);
% 
% Ceval = eval(subs(C, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
%                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
%              
% D = jacobian([h, ax, ay, az], ...
%           [n1, n2, n3, n4]);
% 
% Deval = eval(subs(D, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
%              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
%             
%% Motor mixing matrix
M_motor = [1, 1, 1, -1; ...
           1, 1, -1, 1; ...
           1, -1, -1, -1; ...
           1, -1, 1, 1 ]; % used to go from TEAR to n1,...,n4

M_inv = inv(M_motor); %used to go from n1,...,n4 to TEAR    

%% HW4 code
% 
% % Dynamics
% R = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1; ...
%      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0; ...
%      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0; ...
%      0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0; ...
%      0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0; ...
%      0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0; ...
%      0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0; ...
%      0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0; ...
%      0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0; ...
%      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; ...
%      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0; ...
%      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ];
%      
% A_change = R*A*inv(R);
% B_change = R*Beval;
% C_change = Ceval*inv(R);
% D_change = Deval;
%     
%  
% u_0 = [299; ...
%        299; ...
%        299; ...
%        299];
% 
% % Used to generate decoupled matrices below
% A_new = A_change;
% B_new = B_change*M_motor;
% C_new = C_change;
% D_new = D_change*M_motor;
% 
% A_neweval = eval(subs(A_new, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
%              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
% 
% B_neweval = eval(subs(B_new, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
%              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
% 
% C_neweval = eval(subs(C_new, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
%              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
%          
% D_neweval = eval(subs(D_new, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
%              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));

%% Q and R (covariances for Kalman Filter)
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
  
%% HW7 Code
%% Decoupled A,B,C,D for dynamics

% Zned w decoupled system
% A1 = [0 1; ...
%       0 0];
% B1 = [0; ...
%     -0.067];
% C1 = [1 0];
% D1 = [0];
% 
% % theta, q, Xned, and u decoupled system
% A2 = [0 1 0 0; ...
%       0 0 0 0; ...
%       0 0 0 1; ...
%      -9.81 0 0 0];
% B2 = [0; ...
%       0.1442;
%       0;
%       0];
% C2 = [1 0 0 0; ...
%       0 1 0 0; ...
%       0 0 1 0; ...
%       0 0 0 1];
% D2 = [0; ...
%       0; ...
%       0; ...
%       0]; ...
%       
% % third system  
% A3 = [0 1 0 0; ...
%       0 0 0 0; ...
%       0 0 0 1; ...
%      9.81 0 0 0];
% B3 = [0; ...
%       0.1774; ...
%       0; ...
%       0];  
% C3 = [1 0 0 0; ...
%       0 1 0 0; ...
%       0 0 1 0; ...
%       0 0 0 1];   
% D3 = [0; ...
%       0; ...
%       0; ...
%       0];
% % fourth system   
% A4 = [0 1; ...
%       0 0];
% B4 = [0; ...
%      0.1728];  
% C4 = [1 0; ...
%       0 1]; ...
% D4 = [0;...
%       0];

%% Calculating controller gains K1,...,K4   
Qthrust = diag([1 1]);
Rthrust = 1;  
Qelevator = diag([1 1 1 1]);
Relevator = 1; 
Qaileron = diag([1 1 1 1]);
Raileron = 1; 
Qrudder = diag([1 1]);
Rrudder = 1; 

Kthrust = lqr(Athrust, Bthrust, Qthrust, Rthrust); %-1.0000   -5.3645
Kelevator = lqr(Aelevator, Belevator, Qelevator, Relevator); % -1.0000   -1.5854    7.4240    1.8413
Kaileron = lqr(Aaileron, Baileron, Qaileron, Raileron); % 1.0000    1.5639    7.0916    1.6901
Krudder = lqr(Arudder, Brudder, Qrudder, Rrudder); %1.0000    3.0781

Kelevator = Kelevator(2:4);
Kaileron = Kaileron(2:4);
Krudder = Krudder(2);

%% Adding integral control

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




%% Ethan's code for his Kalman/Wiener filters IS BELOW

%% Load in data for Covariance calculations
load('In_out_data')
syms t
Ts = 0.005;

%% Assert arbitrary power for noises
measurement_noise = 0.025;
process_noise = 0.05;

%% filter cutoff for low pass filter 
omega_c = 2*pi *20; %20 Hz (picked from experimentation, feel free to adjust)

%% Calculating Dynamics for Kalman/Wiener Filters
% Single Integrator state-space model
A_single = [0];
B_single = [1];
C_single = [1];
D_single = [0];

% Double Integrator state-space model
A_double = [0 1; 0 0];
B_double = [0; 1]; 
C_double = [1 0];
D_double = [0];

% Calculating Discrete Dynamics
Ad_single = expm(A_single*t);
Bd_single = int(Ad_single)*B_single;
Ad_double = expm(A_double*t);
Bd_double = int(Ad_double)*B_double;

% Evalute Discrete Dynamics for t = Ts (sampling time)
A_s_single = eval(subs(Ad_single,Ts));
B_s_single = eval(subs(Bd_single,Ts));
A_s_double = eval(subs(Ad_double,Ts));
B_s_double = eval(subs(Bd_double,Ts));


%% Covariance Calculations for Kalman/Wiener Filters
% Calculate Covariances 
q_single = cov(out.In_Out_Data{1}.Values.Data)*10000000000000; % input data
r_single = cov(out.In_Out_Data{2}.Values.Data); % output data

% don't worry about size of Q, the lqe function handle it
q_double = q_single;
r_double = r_single;

% Wiener Filter code
G_single = B_single; % noise input is same as process input
G_double = B_double;


%% LQE Gain for Wiener Filter
% Gain for the Wiener filter
L_single = lqe(A_single, G_single, C_single, q_single, r_single, 0);
L_double = lqe(A_double, G_double, C_double, q_double, r_double, 0);
% 
% [v,lambda] = eig(A_s_single-L_single*C_single)
% [v,lambda] = eig(A_s_double-L_double*C_double)






