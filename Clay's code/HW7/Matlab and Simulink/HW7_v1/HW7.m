    
% HW3 Code

% Equations of Motion
syms u v w p q r phi theta psi XNED YNED ZNED n1 n2 n3 n4 

% 4.1 Vdot
V = [u; v; w];

%Rotation matrices in the x, y, and z directions 
Rtphi = [1 0 0 ; ...
         0 cos(phi) sin(phi) ; ...
         0  -sin(phi) cos(phi) ]; 

Rttheta =  [cos(theta) 0 -sin(theta) ; ...
            0 1 0 ; ...
            sin(theta) 0 cos(theta) ]; 

Rtpsi =  [cos(psi) sin(psi) 0 ; ... 
          -sin(psi) cos(psi) 0 ; ...
          0 0 1 ]; 

% 4.1 Vdot
m = 0.068; % kg
g = 9.81 ; % m/s^2

gvector = [0; 0; m*g];

% Thrust vector, T = sum(Ti) from i=1 to i=4
Ct = 0.082; % at 299Hz or 18000 RPM  
rho = 1.225; % kg/m3
D = 0.066; %m

T =  Ct*rho*(n1^2 + n2^2 + n3^2 + n4^2)*D^4; % All propellers contribute positively to thrust
thrustvector =  [0; 0; -T];


omega_cross = [0 -r q; ...
               r  0 -p; ...
               -q p 0];
% Vdot                    
Vdot = 1/m * (omega_cross*m*V + Rtphi*Rttheta*Rtpsi*gvector + thrustvector);

udot = Vdot(1);
vdot = Vdot(2);
wdot = Vdot(3);
                     
% 4.2 Omegadot
omega = [p; q; r];

Jxx = 0.0000582857; % kg/m^2
Jyy = 0.0000716914; % kg/m^2
Jzz = 0.0001; % kg/m^2

Jmatrix = [Jxx 0 0 ; ...
           0 Jyy 0 ; ...
           0 0 Jzz;];

h = 0.047625; % distance along the x-axis from CoM to center of rotor in meters
b = 0.047625; % distance along the y-axis from CoM to center of rotor in meters

Cp = 0.041; % At 18000 RPM

Cl = Ct*h; % rolling moment
Cm = Ct*b; % pitching moment
Cn = Cp/(2*pi); % yawing moment

Lt =  b*Cl*rho*(n1^2 - n2^2 - n3^2 + n4^2)*D^4; 
Mt =  b*Cm*rho*(n1^2 + n2^2 - n3^2 - n4^2)*D^4; 
Nt =  b*Cn*rho*(-n1^2 + n2^2 - n3^2 + n4^2)*D^4; 

Mtvector = [Lt; Mt; Nt];

m_p = 0.001; % mass of propeller in kg
L_p = D; % length (diameter) of propeller in m

Jp = (1/12)*m_p*L_p^2; % J of propeller in the propeller's frame in kg*m^2
Jb = Jp + m_p*b^2; % J of propeller in body frame in kg*m^2

Mgyro = omega_cross*Jb*[0; 0; 2*pi*(n1-n2+n3-n4)];

% Omegaodot
Omegadot = inv(Jmatrix)*(-(omega_cross*Jmatrix*omega) + Mtvector + Mgyro);

pdot = Omegadot(1);
qdot = Omegadot(2);
rdot = Omegadot(3);

% 4.3 
phidot = p + tan(theta)*(q*sin(phi)+r*cos(phi));

% 4.4
thetadot = q*cos(phi) - r*sin(phi);

% 4.5
psidot = (q*sin(phi) + r*cos(phi))/cos(theta);

% 4.6
XYZNEDdot = Rtpsi.'*Rttheta.'*Rtphi.'*[u; v; w];

XNEDdot = XYZNEDdot(1);
YNEDdot = XYZNEDdot(2);
ZNEDdot = XYZNEDdot(3);

% 4.7
h = -ZNED;

% 4.8
accvector = (1/m)*thrustvector;
ax = accvector(1);
ay = accvector(2); 
az = accvector(3);

% Jacobian to linearize the system
A = jacobian([udot, vdot, wdot, pdot, qdot, rdot, phidot, thetadot, psidot, XNEDdot, YNEDdot, ZNEDdot], ...
          [u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED]);

Aeval = eval(subs(A, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
         
B = jacobian([udot, vdot, wdot, pdot, qdot, rdot, phidot, thetadot, psidot, XNEDdot, YNEDdot, ZNEDdot], ...
             [n1, n2, n3, n4]);

Beval = eval(subs(B, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
         
C = jacobian([h, ax, ay, az], ...
             [u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED]);

Ceval = eval(subs(C, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
             
D = jacobian([h, ax, ay, az], ...
          [n1, n2, n3, n4]);

Deval = eval(subs(D, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
            
% Motor mixing matrix
M_motor = [1, 1, 1, -1; ...
           1, 1, -1, 1; ...
           1, -1, -1, -1; ...
           1, -1, 1, 1 ];
      
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% HW4 code

% Dynamics
R = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1; ...
     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0; ...
     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0; ...
     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0; ...
     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0; ...
     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0; ...
     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0; ...
     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0; ...
     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0; ...
     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; ...
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0; ...
     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ];
     
A_change = R*A*inv(R);
B_change = R*Beval;
C_change = Ceval*inv(R);
D_change = Deval;

M_motor = [1, 1, 1, -1; ...
           1, 1, -1, 1; ...
           1, -1, -1, -1; ...
           1, -1, 1, 1 ];
       
M_inv = inv(M_motor);
 
u_0 = [299; ...
       299; ...
       299; ...
       299];

% Used to generate decoupled matrices below
A_new = A_change;
B_new = B_change*M_motor;
C_new = C_change;
D_new = D_change*M_motor;

A_neweval = eval(subs(A_new, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));

B_neweval = eval(subs(B_new, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));

C_neweval = eval(subs(C_new, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));
         
D_neweval = eval(subs(D_new, {u, v, w, p, q, r, phi, theta, psi, XNED, YNED, ZNED, n1, n2, n3, n4}, ...
             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 299, 299, 299, 299}));

% Decoupled A,B,C,D for dynamics

% Zned w decoupled system
A1 = [0 1; ...
      0 0];
B1 = [0; ...
    -0.067];
C1 = [1 0;...
      0 1;...
     -1 0 ; ...
      0 0]; 
D1 = [0;
      0;
      0; ...
     -0.0067];

% theta, q, Xned, and u decoupled system
A2 = [0 1 0 0; ...
      0 0 0 0; ...
      0 0 0 1; ...
     -9.81 0 0 0];
A2_twostates = [0 1; ...
                0 0];
B2 = [0; ...
      0.1442;
      0;
      0];
C2 = [1 0 0 0; ...
      0 1 0 0; ...
      0 0 1 0; ...
      0 0 0 1];
D2 = [0; ...
      0; ...
      0; ...
      0];
A3 = [0 1 0 0; ...
      0 0 0 0; ...
      0 0 0 1; ...
     9.81 0 0 0];
B3 = [0; ...
      0.1774; ...
      0; ...
      0];  
C3 = [1 0 0 0; ...
      0 1 0 0; ...
      0 0 1 0; ...
      0 0 0 1];   
D3 = [0; ...
      0; ...
      0; ...
      0];
  
A4 = [0 1; ...
      0 0];
B4 = [0; ...
     0.1728];  
C4 = [1 0; ...
      0 1]; ...
D4 = [0;...
      0];
  
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
  
% HW7 Code

% Calculating controller gains K1,...,K4 using Q and R weights      
Q1 = [1 0;...
      0 1];
R1 = 0.0001;  
  
Q2 = [1 0 0 0;...
      0 1 0 0;...
      0 0 1 0;...
      0 0 0 1];
R2 = 0.0001;  

Q3 = [1 0 0 0;...
      0 1 0 0;...
      0 0 1 0;...
      0 0 0 1];
R3 = 0.0001;  
  
Q4 = [1 0;...
      0 1];
R4 = 0.0001;  

K1 = lqr(A1, B1, Q1, R1); %K1 = [-100.0000 -113.9521]
K2 = lqr(A2, B2, Q2, R2); %K2 = [635.7988  137.1798 -100.0000 -151.5330]
K3 = lqr(A3, B3, Q3, R3); %K3 = [619.2955  130.3147  100.0000  150.4188]
K4 = lqr(A4, B4, Q4, R4); %K4 = [100.0000  105.6286]


% Actuator dynamics
V = 5; % measured battery voltage
V0 = 5; % actual battery voltage

syms tau2
tau2 = eval(max(solve(1/sqrt((tau2*2*pi*10)^2+1^2) == 1/sqrt(2), tau2)));
tau1 = 30e-3; % delay time of actuator 








