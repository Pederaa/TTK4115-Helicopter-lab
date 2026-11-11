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

Kf = -L2/L3;
K1 = Kf/(2*m_p*l_p);
K2 = Kf*l_h/(m_c*l_c^2 + 2*m_p*l_h^2);

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














