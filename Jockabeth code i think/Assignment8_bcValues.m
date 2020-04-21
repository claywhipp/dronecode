
%z,vertical speed (w), Throttle
%bang bang T folder
%motor speed data AND state est data
T=motor_speed_data*[1;-1;1;-1]/4;
E=motor_speed_data*[1;-1;-1;1]/4;
A=motor_speed_data*[1;1;-1;-1]/4;
R=motor_speed_data*[-1;-1;-1;-1]/4;


% w from state est data column 10
Z=state_est_data(2:end,10); %not state z
PHI=[state_est_data(1:end-1,10) T(1:end-1,1)] ; %not state phi
C=PHI\Z; %not constant c

%b=C(1)*200-1; wrong from Bhan's notes 198.9590? 
b=(C(1)-1)/.005; %-0.0410
c=C(2)/.005; % 4.3596e-05


%CLEAR WORKSPACE 


%pitch angle, pitch rate, elevator AKA theta, q, Elevator
%bang bang E folder
%motor speed data AND sensor state data

T=motor_speed_data*[1;-1;1;-1]/4;
E=motor_speed_data*[1;-1;-1;1]/4;
A=motor_speed_data*[1;1;-1;-1]/4;
R=motor_speed_data*[-1;-1;-1;-1]/4;


% q from sensor state data column 7
Z=sensor_state_dataE(2:end,7); %not state z
PHI=[sensor_state_dataE(1:end-1,7) E(1:end-1,1)] ; %not state phi
C=PHI\Z; %not constant c

b=(C(1)-1)/.005; %-0.0981
c=C(2)/.005; % 0.0855

%CLEAR WORKSPACE 


%roll angle, roll rate, aileron; AKA phi,p,A
%bang bang A folder
%motor speed data AND sensor state data

T=motor_speed_data*[1;-1;1;-1]/4;
E=motor_speed_data*[1;-1;-1;1]/4;
A=motor_speed_data*[1;1;-1;-1]/4;
R=motor_speed_data*[-1;-1;-1;-1]/4;


% p from sensor state data column 6
Z=sensor_state_dataA(2:end,6); %not state z
PHI=[sensor_state_dataA(1:end-1,6) A(1:end-1,1)] ; %not state phi
C=PHI\Z; %not constant c

b=(C(1)-1)/.005; %4.8071
c=C(2)/.005; %1.1483


%CLEAR WORKSPACE 


%yaw angle, yaw rate, rudder AKA psi,r,R
%bang bang R folder
%motor speed data AND sensor state data

T=motor_speed_data*[1;-1;1;-1]/4;
E=motor_speed_data*[1;-1;-1;1]/4;
A=motor_speed_data*[1;1;-1;-1]/4;
R=motor_speed_data*[-1;-1;-1;-1]/4;


% r from sensor state data column 8
Z=sensor_state_dataR(2:end,8); %not state z
PHI=[sensor_state_dataR(1:end-1,8) R(1:end-1,1)] ; %not state phi
C=PHI\Z; %not constant c

b=(C(1)-1)/.005; %-0.4499
c=C(2)/.005; %0.0480


