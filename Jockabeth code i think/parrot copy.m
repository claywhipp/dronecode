open_system('parrot_TEAR')
load_system('parrot_TEAR');
hilite_system('parrot_TEAR/Flight_Control_System');
Parrot_FlightInterface;

M=[1 1 1 1;
    1 1 -1 -1;
    1 -1 -1 1;
    -1 1 -1 1;];

%plot(rt_ax.time(:,1),rt_ax.signals.values(:,1);
 
%cov(rt_az.signals.values(:,1))
q1=19.0085;
%cov(rt_z.signals.values(:,1))
r1=.0731;


%cov(rt_ay.signals.values(:,1))
q2=5.761;
%cov(y.data);
r2=4.9726e+03;



%cov(rt_ax.signals.values(:,1));
q3=15.4224;
%cov(x.data)
r3=7.7884e+03;



%cov(rt_p.signals.values(:,1))
q4=1.4190;
%cov(rt_ay.signals.values(:,1)/cov(rt_az.signals.values(:,1)));
r4=.0160;



%cov(rt_q.signals.values(:,1))
q5=6.1085;
%cov(theta.Data);
r5=3.0877;





