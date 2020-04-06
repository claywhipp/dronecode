    
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

Omegadot = inv(Jmatrix)*(-(omega_cross*Jmatrix*omega) + Mtvector + Mgyro);

pdot = Omegadot(1);
qdot = Omegadot(2);
rdot = Omegadot(3);

% 4.3 
phidot = p + tan(theta)*(q*sin(phi)+r*cos(phi));

% 4.4
thetadot = q*cos(phi) - r*sin(phi);

% 4.5
psidot =  (q*sin(phi) + r*cos(phi))/cos(theta);

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

% A,B,C,D for dynamics
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
     -9.81 0 0 0];

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
      0 1; ...
      0 0; ...
      0 0];
   
D4 = [0;
      0;
      0; ...
      0];
  
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

q1_noise = 0.0101; %cov(wdot);
r1_noise = 0.0166; %cov(z);
Q1 = q1_noise;
R1 = r1_noise;
N1 = 0;

L1 = lqe(A1_cont, G1, C1_cont, Q1, R1, N1);
  
% HW7 Code

% Calculating controller weight K         
Q1 = [1 0;...
      0 1];
  
R1 = 1;

K1 = lqr(A1, B1, Q1, R1);

% Actuator dynamics
V = 5; % measured battery voltage
V0 = 5; % actual battery voltage

tau1 = 30e-3; % delay time of actuator 
tau2 = 0.04; % time constant so that bandwidth is 10 Hz. Make sure I calculated this correctly 








