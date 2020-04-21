
%my_uav
A = [0 1 ;...
     0 0 ];
B = [0; ... 
     1];
C = [1 0]; % theta 
D = [0];

A_bar =  [0    C; ...
         [0;0] A ];
     
B_bar = [D; ...
         B];

Q = diag([10 1 .1]);
R = .1;
     
K = lqr(A_bar, B_bar, Q, R);

Ki = K(1);
Kx = K(2:3);
