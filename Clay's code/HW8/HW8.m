

% zw system
% x_1 = Zned, x_2 = w, u = T

% x_2 k = b*x_2 k-1 + c*u_k-1 
% w_k = b*w_k-1 + c*T_k-1
% w_k = [w_k-1 T_k-1]*[b; c]
% z = [w_k-1 T_k-1]^-1 * w_k

syms b c

% use a_z to find throttle vector? 
% state est data best data to use? 
[b; c] = [state_est_data(1:800,10) T_k-1]^-1*state_est_data(2:801,10);
