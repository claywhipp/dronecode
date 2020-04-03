
% Equations of Motion

% 4.1 Vdot

syms u v w p q r phi theta psi XNED YNED ZNED n1 n2 n3 n4 
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
         
         
         

% % Linear and Nonlinear states and outputs that should be nonzero given throttle input
% t_out = out.linstates.Time(:,1);
% w_lin = out.linstates.Data(:,3);
% ZNED_lin = out.linstates.Data(:,12);
% h_lin = out.linoutputs.Data(:,1);
% az_lin = out.linoutputs.Data(:,4);
% 
% w_nonlin = out.nonlinstates.Data(:,3);
% ZNED_nonlin = out.nonlinstates.Data(:,12);
% 
% plot(t_out, w_lin, t_out, ZNED_lin, t_out, az_lin);
% xlabel('t (s)');
% title('Linear ZNED, w, and z given throttle input');
% legend('linear w','linear ZNED', 'linear a_z');



% % % Linear and Nonlinear states and outputs that should be nonzero given elevator input
% t_out = out.linstates.Time(:,1);
% u_lin = out.linstates.Data(:,1);
% q_lin = out.linstates.Data(:,5);
% theta_lin = out.linstates.Data(:,8);
% XNED_lin = out.linstates.Data(:,10);
% ax_lin = out.linoutputs.Data(:,2);    
% 
% figure
% plot(t_out, u_lin, t_out, q_lin, t_out, theta_lin, t_out, XNED_lin);
% xlabel('t (s)');
% title('Linear u, q, theta, XNED given elevator input');
% legend('u','q','theta','XNED');



% % Linear and Nonlinear states and outputs that should be nonzero given aileron input
% t_out = out.linstates.Time(:,1);
% v_lin = out.linstates.Data(:,2);
% p_lin = out.linstates.Data(:,4);
% phi_lin = out.linstates.Data(:,7);
% YNED_lin = out.linstates.Data(:,11);
% 
% figure
% plot(t_out, v_lin, t_out, p_lin, t_out, phi_lin, t_out, YNED_lin );
% xlabel('t (s)');
% title('Linear v, p, phi, and YNED vs time given aileron input');
% legend('v','p','phi','YNED');
         

% % % Linear and nonlinear states and outputs that should be nonzero given rudder input
% t_out = out.linstates.Time(:,1);
% r_lin = out.linstates.Data(:,6);
% psi_lin = out.linstates.Data(:,9);
% 
% plot(t_out, r_lin, t_out, psi_lin);
% xlabel('t (s)');
% title('Linear r, psi vs time given rudder input');
% legend('r','psi');
         






