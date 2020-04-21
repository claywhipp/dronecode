
% time
% time = out.throttleout.Time;

%% Linear T
% z = out.throttleout.Data(:,1);
% w = out.throttleout.Data(:,2);
% 
% figure
% plot(time, z, time, w);
% title('Z and w response to throttle');
% xlabel('time (s)');
% ylabel('m (for z) or m/s (for w)');
% legend('Z', 'w');

%% Linear E
% X = out.elevatorout.Data(:,1);
% u = out.elevatorout.Data(:,2);
% theta = out.elevatorout.Data(:,3);
% q = out.elevatorout.Data(:,4);
% 
% figure
% plot(time, X, time, u, time, theta, time, q);
% title('X, u, theta, and q response to elevator');
% xlabel('time (s)');
% ylabel('m or m/s or radians or radians/s');
% legend('X', 'u', 'theta', 'q');

%% Linear A
% Y = out.aileronout.Data(:,1);
% v = out.aileronout.Data(:,2);
% phi = out.aileronout.Data(:,3);
% p = out.aileronout.Data(:,4);
% 
% figure
% plot(time, Y, time, v, time, phi, time, p);
% title('Y, v, phi, and p response to aileron');
% xlabel('time (s)');
% ylabel('m or m/s or radians or radians/s');
% legend('Y', 'v', 'phi', 'p');

%% Linear R
% psi = out.rudderout.Data(:,1);
% r = out.rudderout.Data(:,2);
% 
% figure
% plot(time, psi, time, r);
% title('psi, r response to rudder step');
% xlabel('time (s)');
% ylabel('radians or radians/s');
% legend('psi', 'r');

%% Nonlinear T
% z = out.throttleout1.Data(:,1);
% w = out.throttleout1.Data(:,2);
% 
% figure
% plot(time, z, time, w);
% title('Nonlinear Z and w response to throttle step');
% xlabel('time (s)');
% ylabel('m (for z) or m/s (for w)');
% legend('Z', 'w');

%% Nonlinear E
% X = out.elevatorout1.Data(:,1);
% u = out.elevatorout1.Data(:,2);
% theta = out.elevatorout1.Data(:,3);
% q = out.elevatorout1.Data(:,4);
% 
% figure
% plot(time, X, time, u, time, theta, time, q);
% title('Nonlinear X, u, theta, and q response to elevator step');
% xlabel('time (s)');
% ylabel('m or m/s or radians or radians/s');
% legend('X', 'u', 'theta', 'q');

%% Nonlinear A
% Y = out.aileronout1.Data(:,1);
% v = out.aileronout1.Data(:,2);
% phi = out.aileronout1.Data(:,3);
% p = out.aileronout1.Data(:,4);
% 
% figure
% plot(time, Y, time, v, time, phi, time, p);
% title('Nonlinear Y, v, phi, and p response to aileron step');
% xlabel('time (s)');
% ylabel('m or m/s or radians or radians/s');
% legend('Y', 'v', 'phi', 'p');

%% Nonlinear R
% psi = out.rudderout1.Data(:,1);
% r = out.rudderout1.Data(:,2);
% 
% figure
% plot(time, psi, time, r);
% title('Nonlinear psi, r response to rudder step');
% xlabel('time (s)');
% ylabel('radians or radians/s');
% legend('psi', 'r');


%% Linear Zw actual
% time1 = out.Zwactual.Time;
% Z = out.Zwactual.Data(:,1);
% w = out.Zwactual.Data(:,2);
% 
% figure
% plot(time1, Z, time1, w);
% title('Linear Z and w actual given hover input');
% xlabel('time (s)');
% ylabel('m or m/s');
% legend('Z', 'w');

%% Linear Zw actual
time1 = out.Zwactual.Time;
Z = out.Zwactual1.Data(:,1);
w = out.Zwactual1.Data(:,2);

figure
plot(time1, Z, time1, w);
title('Nonlinear Z and w actual given hover input');
xlabel('time (s)');
ylabel('m or m/s');
legend('Z', 'w');




