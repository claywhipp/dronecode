
%z,vertical speed (w), Throttle
%bang bang T folder
%motor speed data AND state est data
T=motor_speed_data*[1;-1;1;-1]/4;
E=motor_speed_data*[1;-1;-1;1]/4;
A=motor_speed_data*[1;1;-1;-1]/4;
R=motor_speed_data*[-1;-1;-1;-1]/4;


% w from state est data column 9
Z=state_est_data(2:end,10); %not state z
PHI=[state_est_data(1:end-1,10) T(1:end-1,1)] ; %not state phi
C=phi\w; %not constant c

%b=C(1)*200-1; wrong from Bhan's notes 198.9590? 
b=(C(1)-1)/.005; %-0.0410
%b=C(1)/.005-1; %same thing as above
c=C(2)*200; % 4.3596e-05




%pitch angle, pitch rate, elevator AKA theta, q, Elevator
%bang bang T folder
%motor speed data AND state est data

T=motor_speed_data*[1;-1;1;-1]/4;
E=motor_speed_data*[1;-1;-1;1]/4;
A=motor_speed_data*[1;1;-1;-1]/4;
R=motor_speed_data*[-1;-1;-1;-1]/4;


