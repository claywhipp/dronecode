

% zw system

syms b c

% state est data best data to use? 

M_motor = [1, 1, 1, -1; ...
           1, 1, -1, 1; ...
           1, -1, -1, -1; ...
           1, -1, 1, 1 ]; % used to go from TEAR to n1,...,n4
       
M_inv = inv(M_motor); %used to go from n1,...,n4 to TEAR

% motor_speed_data1 = motor_speed_data(1,:);
motor_speed_data_tran = motor_speed_data(1,:)';

TEAR_tran = M_inv*motor_speed_data_tran;

TEAR = TEAR_tran';

wmatrix = [state_est_data(1:800,10) TEAR(1:800,1)]; % could also use sensor_state_dataT
winv = inv(wmatrix);

[b c] = xuinv*state_est_data(2:801,10);
