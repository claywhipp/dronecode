
s = tf('s');

A = [0 1; 0 b];
B = [0; c]

C = [0 1];
D = [0];

T_sys = ss(A,B,C,D);

lsim(T_sys,(T(bang_bang_start:bang_bang_end-1)-T_trim),[5 6]);
