

states = rt_states.signals.values;
t = rt_tout;

% states for FFT 
XNED = states(:,1);
YNED = states(:,2);
z = states(:,3);

p = states(:,4);
q = states(:,5);
r = states(:,6);

udot = states(:,7);
vdot = states(:,8);
wdot = states(:,9);

phi = states(:,10);
theta = states(:,11);
psi = states(:,12);

u = states(:,13);
v = states(:,14);
w = states(:,15);

zintegrated = states(:,16);

% figure
% plot(t, p)
% title('p vs t')
% xlabel('t (s)')
% ylabel('p')



% (3)
Fs = 200; % in Hz
L = 1600; % # of sample points
f = Fs*(0:(L/2))/L;


% p_fft = fft(p);
% P2 = abs(p_fft/L);
% P1 = P2(1:L/2+1);
% P1(2:end-1) = 2*P1(2:end-1);
% 
% q_fft = fft(q);
% Q2 = abs(q_fft/L);
% Q1 = Q2(1:L/2+1);
% Q1(2:end-1) = 2*Q1(2:end-1);
% 
% r_fft = fft(r);
% R2 = abs(r_fft/L);
% R1 = R2(1:L/2+1);
% R1(2:end-1) = 2*R1(2:end-1);
% 
% udot_fft = fft(udot);
% UDOT2 = abs(udot_fft/L);
% UDOT1 = UDOT2(1:L/2+1);
% UDOT1(2:end-1) = 2*UDOT1(2:end-1);
% 
% vdot_fft = fft(vdot);
% VDOT2 = abs(vdot_fft/L);
% VDOT1 = VDOT2(1:L/2+1);
% VDOT1(2:end-1) = 2*VDOT1(2:end-1);
% 
wdot_fft = fft(wdot);
WDOT2 = abs(wdot_fft/L);
WDOT1 = WDOT2(1:L/2+1);
WDOT1(2:end-1) = 2*WDOT1(2:end-1);

% u_fft = fft(u);
% U2 = abs(u_fft/L);
% U1 = U2(1:L/2+1);
% U1(2:end-1) = 2*U1(2:end-1);
% 
% v_fft = fft(v);
% V2 = abs(v_fft/L);
% V1 = V2(1:L/2+1);
% V1(2:end-1) = 2*V1(2:end-1);

z_fft = fft(z);
Z2 = abs(z_fft/L);
Z1 = Z2(1:L/2+1);
Z1(2:end-1) = 2*Z1(2:end-1);

w_fft = fft(w);
W2 = abs(w_fft/L);
W1 = W2(1:L/2+1);
W1(2:end-1) = 2*W1(2:end-1);


% figure
% plot(f, P1)
% title('Spectrum of p vs f')
% xlabel('Hz')
% ylabel('|P(f)|')
% 
% figure
% plot(f, Q1)
% title('Spectrum of q vs f')
% xlabel('Hz')
% ylabel('|Q(f)|')
% 
% figure
% plot(f, R1)
% title('Spectrum of r vs f')
% xlabel('Hz')
% ylabel('|R(f)|')
% 
% figure
% plot(f, UDOT1)
% title('Spectrum of udot vs f')
% xlabel('Hz')
% ylabel('|UDOT(f)|')
% 
% figure
% plot(f, VDOT1)
% title('Spectrum of vdot vs f')
% xlabel('Hz')
% ylabel('|VDOT(f)|')
% 
figure
plot(f, WDOT1)
title('Spectrum of wdot vs f')
xlabel('Hz')
ylabel('|WDOT(f)|')

% figure
% plot(f, U1)
% title('Spectrum of u vs f')
% xlabel('Hz')
% ylabel('|U(f)|')
% 
% figure
% plot(f, V1)
% title('Spectrum of v vs f')
% xlabel('Hz')
% ylabel('|V(f)|')

figure
plot(f, Z1)
title('Spectrum of z vs f')
xlabel('Hz')
ylabel('|Z(f)|')

figure
plot(f, W1)
title('Spectrum of w vs f')
xlabel('Hz')
ylabel('|W(f)|')



% (4)
% low_pass = tf([1],[ 1/100 , 1]);
% 
% P_filtered = P1*low_pass;
% 
% figure
% plot(f,P_filtered);




% (8)
%bode(p); % this will be be a transfer function already because of the low pass filter? 

% nyquist(system); %<-- similar question to bode, is the system p? 







 
  
  

