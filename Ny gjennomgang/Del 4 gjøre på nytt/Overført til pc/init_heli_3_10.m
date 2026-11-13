% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;

PORT = 4;

%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]

lambda_1 = -1+10j;
lambda_2 = -1-10j;
Vs0 = 7.5;

L2 = g*(l_c*m_c - 2*l_h*m_p);
L3 = l_h*Vs0;

J_p = 2*m_p*l_p^2;
J_e = m_c*l_c^2 + 2*m_p*l_h^2;
J_l = m_c*l_c^2 + 2*m_p*(l_h^2 + l_p^2);

Kf = -L2/L3;
K1 = Kf/(2*m_p*l_p);
K2 = Kf*l_h/((m_c*l_c^2 + 2*m_p*l_h));
K3 = g*(2*m_p*l_h - m_c*l_c)/(m_c*l_c^2 + 2*m_p*(l_h^2 + l_p^2));

K_pp = (lambda_1*lambda_2)/K1;
K_pd = -(lambda_1 + lambda_2)/K1;


A = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 0 0; -1 0 0 0 0; 0 0 -1 0 0];
B = [0 0; 0 K1; K2 0; 0 0; 0 0];
G = [0 0; 0 0; 0 0; 1 0; 0 1];

qp_max = 1/6;
qpd_max = 3/60;
qed_max = 1/6;
rvs_max = 1;
rvd_max = 1;
gamma_max = 1;
zeta_max = 1;


qp =  1/(qp_max^2);
qpd = 1/(qpd_max^2);
qep = 1/(qed_max^2);
rvs = 1/(rvs_max^2);
rvd = 1/(rvd_max^2);
qgamma = 1/(gamma_max^2);
qzeta = 1/(zeta_max^2);

Q = diag([qp, qpd, qep, qgamma, qzeta]);
R = diag([rvs, rvd]);

[K, S, P] = lqr(A,B,Q,R,0);
F = [0 0; 0 0];




A_kal = [0, 1, 0, 0, 0, 0;
        0, 0, 0, 0, 0, 0;
        0, 0, 0, 1, 0, 0;
        0, 0, 0, 0, 0, 0;
        0, 0, 0, 0, 0, 1;
        K3, 0, 0, 0, 0, 0];

B_kal = [0, 0;
        0, K1;
        0, 0;
        K2, 0;
        0, 0;
        0, 0];

C_kal = [1 0 0 0 0 0;
        0 1 0 0 0 0;
        0 0 1 0 0 0;
        0 0 0 1 0 0;
        0 0 0 0 1 0;
        0 0 0 0 0 1];
    
Obs = obsv(A_kal, C_kal);

rank_obs = rank(Obs);

if rank_obs == size(A_kal, 1)
    disp("Systemet er observerbart")
else
    disp("Systemet er IKKE observerbart")
end

H = ss(A_kal, B_kal, C_kal, zeros(6, 2));
Ts = 0.002;
Hd = c2d(H, Ts);
Ad = Hd.A;
Bd = Hd.B;
Cd = Hd.C;

x_hat0 = [0;
    0;
    0.48;
    0;
    0;
    0];
    
P_hat0 = zeros(6);


Qd = zeros(6);
Qd(1, 1) = 1E34;
Qd(2, 2) = 1E34;
Qd(3, 3) = 1E34;
Qd(4, 4) = 1E34;
Qd(5, 5) = 1E34;
Qd(6, 6) = 1E34;

Qd = Qd*1E-1;

Rd = zeros(6, 6);
X = load("task41_xhat_noie_fligh.mat").ans;
X_meas = X(2:7, :);
Rd = cov(X_meas');
