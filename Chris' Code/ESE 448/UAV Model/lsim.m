% close all
s = tf('s');

bstar=b*1;
% bstar=0;
A = [0 1; 0 bstar];
B = [0; c];

C = [0 1];
D = [0];

T_sys = ss(A,B,C,D);

sim = lsim(T_sys,(T(bang_bang_start:bang_bang_end-1)-T_trim),time(bang_bang_start:bang_bang_end-1)-time(bang_bang_start));

figure;
plot(w(bang_bang_start+delay:bang_bang_end+delay-1));
hold on;
plot(sim);
legend({'actual data','lsim'});