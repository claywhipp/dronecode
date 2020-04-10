%% Define Constants
%Thrust coefficients
T_3 = 1.066e-9;
T_2 = 1.468e-6;

%Yaw Coefficient
Y_2 = 8.890e-9;

%Torque Distance
d = .047625;

%Mass
m = .068;

%Gravity
g = 9.81;

%Inertia in Prop Frame
I_p = 3.49e-7;

%Motor Mixing Matrix
M = [1, 1,    1, -1;
     1, 1,   -1,  1;
     1, -1,  -1, -1;
     1, -1,   1,  1];
 
%Actuator time constants
tau1 = 30/1000;
tau2 = 1/10;
 
    %  u v w p q r x y z phi theta psi <-Before Transform
 R = [ 0 0 0 0 0 0 0 0 1 0   0     0; %z
       0 0 1 0 0 0 0 0 0 0   0     0; %w
       0 0 0 0 0 0 0 0 0 0   1     0; %theta
       0 0 0 0 1 0 0 0 0 0   0     0; %q
       0 0 0 0 0 0 0 0 0 1   0     0; %phi
       0 0 0 1 0 0 0 0 0 0   0     0; %p
       0 0 0 0 0 0 0 0 0 0   0     1; %psi
       0 0 0 0 0 1 0 0 0 0   0     0; %r
       0 0 0 0 0 0 1 0 0 0   0     0; %x
       1 0 0 0 0 0 0 0 0 0   0     0; %u
       0 0 0 0 0 0 0 1 0 0   0     0; %y
       0 1 0 0 0 0 0 0 0 0   0     0]; %v       
%% Set operating point to linearize about:
u=0;
v=0;
w=0;

p=0;
q=0;
r=0;

x=0;
y=0;
z=0;

phi=0;
theta=0;
psi=0;

n1 = 305;
n2 = 305;
n3 = 305;
n4 = 305;

%% Calculate Matrix A
%Velocity Jacobians
u_j = [q-r, 0, 0, 0, u, -u, 0, 0, 0, 0, -g*cos(theta), 0];
v_j = [0, r-p, 0, -v, 0, v, 0, 0, 0, 0, -g*sin(psi)*sin(theta), g*cos(psi)*cos(theta)];
w_j = [0, 0, p-q, w, -w, 0, 0, 0, 0, 0, -g*cos(psi)*sin(theta),-g*sin(psi)*cos(theta)];

%Angular Velocity Jacobians
p_j = [r-q, 0, 0, 0, -u, u, 0, 0, 0, 0, 0, 0];
q_j = [0, p-r, 0, v, 0, -v, 0, 0, 0, 0, 0, 0];
r_j = [0, 0, q-p, -w, w, 0, 0, 0, 0, 0, 0, 0];

%Position Jacobians
x_j = [cos(theta)*cos(psi), -cos(theta)*sin(psi), sin(theta), 0, 0, 0, 0, 0, 0, 0, -u*sin(theta)*cos(psi) + v*sin(theta)*sin(psi), w*cos(theta)];
y_j = [sin(phi)*sin(theta)*cos(psi)+cos(phi)*sin(psi), cos(phi)*cos(psi) - sin(phi)*sin(theta)*sin(psi), -sin(phi)*cos(theta), 0, 0, 0, 0, 0, 0, u*(cos(phi)*sin(theta)*cos(psi) - sin(phi)*sin(psi)) + v*(-sin(phi)*cos(psi) - cos(phi)*sin(theta)*sin(psi)) + w*(-cos(phi)*cos(theta)), u*(sin(phi)*cos(theta)*cos(psi)) + v*(-sin(phi)*cos(theta)*sin(phi)) + w*(sin(phi)*sin(theta)), u*(-sin(phi)*sin(theta)*sin(psi)) + v*(-cos(phi)*sin(psi) - sin(phi)*sin(theta)*cos(psi))];
z_j = [sin(phi)*sin(psi)-cos(phi)*sin(theta)*cos(psi), cos(phi)*sin(theta)*sin(psi) + sin(phi)*cos(psi), cos(phi)*cos(theta), 0, 0, 0, 0, 0, 0, u*(cos(phi)*sin(psi) + sin(phi)*sin(theta)*cos(psi)) + v*(-sin(phi)*sin(theta)*sin(psi) + cos(phi)*cos(psi)) + w*(-sin(phi)*cos(theta)), u*(-cos(phi)*cos(theta)*cos(psi)) + v*(cos(phi)*cos(theta)*sin(psi)) + w*(-cos(phi)*sin(theta)), u*(sin(phi)*cos(psi) + cos(phi)*sin(theta)*sin(psi)) + v*(cos(phi)*sin(theta)*cos(psi) - sin(phi)*sin(psi))];

%Angle Jacobians
phi_j   = [0, 0, 0, 1, sin(phi)*tan(theta), cos(phi)*tan(theta), 0, 0, 0, tan(theta)*(q*cos(phi)-r*sin(phi)), sec(theta)^2*(q*sin(phi)+r*cos(phi)), 0];
theta_j = [0, 0, 0, 0, cos(phi), -sin(phi), 0, 0, 0, -q*sin(phi)-r*cos(phi), 0, 0];
psi_j   = [0, 0, 0, 0, sin(phi)/cos(theta), cos(phi)/cos(theta), 0, 0, 0, (q*cos(phi)-r*sin(phi)/cos(theta)), sec(theta)*tan(theta)*(q*sin(phi)+r*cos(phi)), 0];

%Assemble A
A = [u_j ; v_j ; w_j ; p_j ; q_j ; r_j ; x_j ; y_j ; z_j ; phi_j ; theta_j ; psi_j];

%% Calculate Matrix B
%Velocity Jacobians
u_j = zeros(1,5);
v_j = zeros(1,5);
%w_j = [(-3*T_3*n1^2 - 2*T_2*n1)/m, (-3*T_3*n2^2 - 2*T_2*n2)/m, (-3*T_3*n3^2 - 2*T_2*n3)/m, (-3*T_3*n4^2 - 2*T_2*n4)/m, 9.8]; 
w_j = [(-T_3*n1^2 - T_2*n1)/m, (-T_3*n2^2 - T_2*n2)/m, (-T_3*n3^2 - T_2*n3)/m, (-T_3*n4^2 - T_2*n4)/m, 9.81]; 

%Angular Velocity Jacobians
p_j = [3*d*T_3*n1^2 + 2*d*T_2*n1, 3*d*T_3*n1^2 + 2*d*T_2*n1, -3*d*T_3*n1^2 - 2*d*T_2*n1, -3*d*T_3*n1^2 - 2*d*T_2*n1, 0];
q_j = [3*d*T_3*n1^2 + 2*d*T_2*n1, -3*d*T_3*n1^2 - 2*d*T_2*n1, -3*d*T_3*n1^2 - 2*d*T_2*n1, 3*d*T_3*n1^2 + 2*d*T_2*n1, 0];
r_j = [-2*Y_2*n1, 2*Y_2*n1, -2*Y_2*n1, 2*Y_2*n1, 0];

%Position Jacobians
x_j = [0, 0, 0, 0, 0];
y_j = [0, 0, 0, 0, 0];
z_j = [0, 0, 0, 0, 0];

%Angle Jacobians
phi_j   = [0, 0, 0, 0, 0];
theta_j = [0, 0, 0, 0, 0];
psi_j   = [0, 0, 0, 0, 0];

%Assemble A
B = [u_j ; v_j ; w_j ; p_j ; q_j ; r_j ; x_j ; y_j ; z_j ; phi_j ; theta_j ; psi_j];

%% Calculate Matrix C

h_j = [0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0];
ax_j = zeros(1,12);
ay_j = zeros(1,12);
az_j = zeros(1,12);

C = [h_j ; ax_j ; ay_j ; az_j];

%% Calculate Matrix D
h_j = zeros(1,5);
ax_j = zeros(1,5);
ay_j = zeros(1,5);
az_j = w_j;

D = [h_j ; ax_j ; ay_j ; az_j];


%% Apply Similarity Transform to Rearrange States
A_R = R*A*inv(R);
B_R = R*B(:,1:4)*M;
C_R = C*inv(R);
D_R = D(:,1:4)*M;

%% Decouple Dynamics
A_zsys = A_R(1:2, 1:2);
B_zsys = B_R(1:2, 1);
C_zsys = C_R(1:2,1:2);
D_zsys = D_R(3:4,1);

A_thetasys = A_R(3:4, 3:4);
B_thetasys = B_R(3:4, 3);
C_thetasys = [1,0;0,0];
D_thetasys = zeros(2,1);

A_phisys = A_R(5:6, 5:6);
B_phisys = B_R(5:6, 2);
C_phisys = [1,0;0,0];
D_phisys = D_thetasys;

A_psisys = A_R(7:8, 7:8);
B_psisys = B_R(7:8, 4);
C_psisys = [1,0;0,0];
D_psisys = D_thetasys;




%% LQR Controller
Q_R = diag([1,2,1,2,1,2,1,2,.1,1,.1,1]);
R_R = diag([.5,1,1,3]);

K_R = lqr(A_R, B_R, Q_R, R_R);

Q = diag([1,3]);
R = diag([1]);

K_psi = lqr(A_psisys, B_psisys, Q, R);
K_phi = lqr(A_phisys, B_phisys, Q, R);
K_theta = lqr(A_thetasys, B_thetasys, Q, R);
K_z = lqr(A_zsys, B_zsys, Q, R);
%% Sim Output

figure;
hold on;
plot(out.simout.time, out.simout.signals.values(:,1))
plot(out.simout.time, out.simout.signals.values(:,2))
legend("X", "Y", "Location", 'best');
title("Velocities");
hold off;

figure;
hold on;
plot(out.simout.time, out.simout.signals.values(:,3))
plot(out.simout.time, out.simout.signals.values(:,4))
plot(out.simout.time, out.simout.signals.values(:,5))
legend("X", "Y", "Z", "Location", 'best');
title("Accelerations");
hold off;

figure;
hold on;
plot(out.simout.time, out.simout.signals.values(:,6))
plot(out.simout.time, out.simout.signals.values(:,7))
plot(out.simout.time, out.simout.signals.values(:,8))
legend("\phi", "\theta", "\psi", "Location", 'best');
title("Angular Velocities");
hold off;

figure;
hold on;
plot(out.simout.time, out.simout.signals.values(:,9))
title("Altitude");
hold off;


