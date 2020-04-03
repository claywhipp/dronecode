
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
 
u_0 = [299; ...
       299; ...
       299; ...
       299];

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

% A,B,C,D for dynamics and controller
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
  
  
%%% System 1

% (1)
% [ZNED, w] = meshgrid(-10:5:10, -10:5:10);
% 
% ZNEDdot = w; 
% wdot = zeros(5);
% 
% figure
% quiver(ZNEDdot, wdot,'LineWidth', 3);
% xlabel('ZNED');
% ylabel('w');
% title('ZNEDdot and wdot Phase-Portrait');

% (2)
% [V1, eigval1] = eig(A1);

% % (3)
% Unstable since eigenvalues are 0 which are not strictly in the left-half
% plane

% % (4)
% A1_exp = expm(A1);
% A1_mode1 = A1_exp(:,1);
% A1_mode2 = A1_exp(:,2);

% % (5)
% W1 = [B1 A1*B1];

% W does have full row rank so controllable

% (6)

% M1 = [C1;...
%     C1*A1];

% M does have full column rank so observable 


%%% System 2

% % (1)
% 
% [theta, q] = meshgrid(-10:5:10, -10:5:10);
% 
% thetadot = w; 
% qdot = zeros(5);
% 
% figure
% quiver(thetadot, qdot,'LineWidth', 3);
% xlabel('thetadot');
% ylabel('qdot');
% title('ZNEDdot vs wdot Phase-Portrait');

% (2)

% [V2, D2] = eig(A2);

% % (3)

% Unstable since eigenvalues are all 0 which are not strictly in the left-half
% plane

% % (4)

% A2_exp = expm(A2);
% A2_mode1 = A2_exp(:,1);
% A2_mode2 = A2_exp(:,2);
% A2_mode3 = A2_exp(:,3);
% A2_mode4 = A2_exp(:,4);


% % (5)
% 
% W2 = [B2 A2*B2];

% W doesn't have full row rank so not controllable

% (6)

% M = [C2;...
%     C2*A2];

% M does have full column rank so is the system is observable 



%%% System 3

% % (1)
% 
% [phi, p] = meshgrid(-10:5:10, -10:5:10);
% 
% phidot = p; 
% pdot = zeros(5);
% 
% figure
% quiver(phidot, pdot,'LineWidth', 3);
% xlabel('phidot');
% ylabel('pdot');
% title('Phidot vs pdot Phase-Portrait');

% (2)

% [V3, D3] = eig(A3);

% % (3)

% Unstable since eigenvalues are all 0 which are not strictly in the left-half
% plane

% % (4)

% A3_exp = expm(A3);
% A3_mode1 = A3_exp(:,1);
% A3_mode2 = A3_exp(:,2);
% A3_mode3 = A3_exp(:,3);
% A3_mode4 = A3_exp(:,4);


% % (5)
% 
% W = [B3 A3*B3];

% W doesn't have full row rank so not controllable

% (6)

% M = [C3;...
%     C3*A3];

% M does have full column rank so is the system is observable 
    



%%% System 4

% % (1)
% 
% [psi, r] = meshgrid(-10:5:10, -10:5:10);
% 
% psidot = r; 
% rdot = zeros(5);
% 
% figure
% quiver(psidot, rdot,'LineWidth', 3);
% xlabel('psidot');
% ylabel('rdot');
% title('Psidot vs rdot Phase-Portrait');

% (2)

% [V4, D4] = eig(A4);

% % (3)

% Unstable since eigenvalues are all 0 which are not strictly in the left-half
% plane

% % (4)

% A4_exp = expm(A4);
% A3_mode1 = A3_exp(:,1);
% A3_mode2 = A3_exp(:,2);


% % (5)
% 
% W4 = [B4 A4*B4];

% W does have full row rank so controllable

% (6)

% M4 = [C4;...
%     C4*A4];


% M does have full column rank so is the system is observable 





% Linear and Nonlinear states and outputs that should be nonzero given throttle input
% t_out = out.decoupstates1.Time(:,1);
% ZNED_decoup = out.decoupstates1.Data(:,1);
% w_decoup = out.decoupstates1.Data(:,2);
% 
% plot(t_out, ZNED_decoup, t_out, w_decoup);
% xlabel('t (s)');
% title('Decoupled linear ZNED and w given throttle input');
% legend('decoup ZNED', 'decoup w');





