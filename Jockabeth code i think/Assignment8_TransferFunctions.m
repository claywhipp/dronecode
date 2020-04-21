%Assignment 8 transfer functions
%use bc values and chirp data

az=sensor_state_data(201:402,5); %during chirp
w=state_est_data(201:402,10); %during chirp
%b value for throttle is -0.0410
%c value for throttle is 4.3596e-05
b=-0.0410; %calculations from part 1
c=4.3596e-05; %calculations from part 1

T=(az-b*w)./c;