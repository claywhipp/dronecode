
% I took Chris' lsim and modified it

% close all
s = tf('s');

b = b_T;
c = c_T;
A = [0 1; 0 b];
B = [0; c];
C = [0 1];
D = [0];

T_sys = ss(A,B,C,D);

time_bangbang = time(bangbang_start:bangbang_end-1-delay)-time(bangbang_start);
sim = lsim(T_sys,T_i,time_bangbang);

figure;
plot(w_i);
hold on;
plot(sim);
legend({'actual data','lsim'});