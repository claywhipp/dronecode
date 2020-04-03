%% Example Transfer Functions
% Dr. Sankalp K. Bhan
s = tf('s');


%% First Order Filters
% Example of a low pass filter
% H = tau/(s+tau)
low_pass = @(tau) tf([1],[ 1/tau , 1]);


% Example of a low pass filter
% H = tau/(s+tau)
high_pass = @(tau) tf([1 0],[ 1 , tau]);


taus = logspace(-3,3,10)';

figure('Units', 'Inches','Position',[1 1 8 8])
subplot(132)
for i = 1 : length(taus)
    tau = taus(i);
    bode(low_pass(tau)); hold all
end
title('low pass');

subplot(133)
bode(high_pass(tau))
for i = 1 : length(taus)
    tau = taus(i);
    bode(high_pass(tau)); hold all
end
title('high pass');

subplot(131)
for i = 1 : length(taus)
    j = length(taus)+1-i;
    semilogy([0, 1], [taus(j), taus(j)]); hold all;
end
legend({num2str(round(taus,2))}, 'FontSize',14)
title({'Frequency Responses for Filters' ,'\tau shown in legend'},'FontSize',18)





figure('Units', 'Inches','Position',[1 1 8 8])
subplot(132)
for i = 1 : length(taus)
    tau = taus(i);
    [H1,W1] = freqresp(low_pass(tau));
    plot(squeeze(real(H1)),squeeze(imag(H1))); hold all
end
title('low pass');
axis([-2 2 -2 2]);

subplot(133)
bode(high_pass(tau))
for i = 1 : length(taus)
    tau = taus(i);
    [H2,W2] = freqresp(high_pass(tau));
    plot(squeeze(real(H2)),squeeze(imag(H2))); hold all
end
title('high pass');
axis([-2 2 -2 2]);

subplot(131)
for i = 1 : length(taus)
    j = length(taus)+1-i;
    semilogy([0, 1], [taus(j), taus(j)]); hold all;
    
end
legend({num2str(round(taus,2))}, 'FontSize',14)
title({'Frequency Responses for Filters' ,'\tau shown in legend'},'FontSize',18)

 