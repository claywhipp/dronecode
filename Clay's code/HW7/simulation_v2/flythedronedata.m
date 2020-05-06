
t_out = rt_tout;
motorspeeds = rt_motorspeeds.signals.values(1, 1:4, 1:1446);

error1 = rt_error1.signals.values;

plot(t_out, error1(:,1), t_out, error1(:,2));