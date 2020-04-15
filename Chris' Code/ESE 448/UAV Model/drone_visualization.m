function drone_visualization(T)

%% /// IMPORTANT ///
%T is array that hold states
%ZED is pointing downwards
%MAKE A MATLAB FUNCTION BLOCK IN SIMULINK
%PASS IN THE NED STATES AND EULER ANGLES
%ADJUST THE STATES AS NECESSARY
%the drone is .18 meters by .18 meters

%the simulation will run MUCH slower while running the visualization
%you can comment out the function block to run the simulation quicker

%% constants
d = .18/2;
c1 = [d; d; 0]; %motor coordinates compared to center of drone
c2 = [d; -d; 0];
c3 = -c1;
c4 = -c2;

    %% adjust indices to get [X; Y; Z] and phi, theta, psi
    XYZ =  [T(1); ...
            T(2); ...
           -T(3)];
    phi =   T(7);
    theta = T(8);
    psi =   T(9);
    %%Defining rotation matrices
    Rx = [1 0 0; 0 cos(theta) sin(theta); 0 -sin(theta) cos(theta)];
    Ry = [cos(phi) 0 -sin(phi); 0 1 0; sin(phi) 0 cos(phi)];
    Rz = [cos(psi) sin(psi) 0; -sin(psi) cos(psi) 0; 0 0 1];
    b1 = Rz*Ry*Rx*c1;
    b2 = Rz*Ry*Rx*c2;
    b3 = Rz*Ry*Rx*c3;
    b4 = Rz*Ry*Rx*c4;
    m1 = XYZ + b1;
    m2 = XYZ + b2;
    m3 = XYZ + b3;
    m4 = XYZ + b4;
    P1 = [m1 m3];
    P2 = [m2 m4];
    P3 = [m1 m2];
    P4 = [m3 m4];

    %%displaying the drone
    plot3(P1(1,:),P1(2,:),P1(3,:),'k-', 'linewidth', 2);
    axis([-3 3 -3 3 -0 3]);
    xlabel('X Axis [Meters]')
    ylabel('Y Axis [Meters]')
    zlabel('Height [Meters]')
    hold on;
    grid on;
    plot3(P2(1,:),P2(2,:),P2(3,:),'k-', 'linewidth', 2);
    plot3(P3(1,:),P3(2,:),P3(3,:),'ob', 'linewidth', 1);
    plot3(P4(1,:),P4(2,:),P4(3,:),'ok', 'linewidth', 1);
    hold off
end