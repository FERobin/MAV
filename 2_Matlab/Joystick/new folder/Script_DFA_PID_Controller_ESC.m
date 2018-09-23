clear all; close all;
clc; format long
%% Define all the parameters

Tfinal = 5;   %seconds
Tstep = 1e-2; %seconds; this should match sampling rate

% Array Parameters
N = 4; %number of modules
m = [.18265; .18265; .18265; .18265]; % module mass in kg; .13655 for module and .0461 for battery. Previous code used .25
g = 9.806;% acceleration of gravity in m/s^2; previous code used 9.81
mg = m.*g;
m_total = sum(m);

%% Initial Conditions in Meters

x0 = 0;         %Initial x-displacement
y0 = 0;         %Initial y-displacement
z0 = 0;         %Initial z-displacement

x0dot = 0;      %Initial x velocity
y0dot = 0;      %Initial y velocity
z0dot = 0;      %Initial z velocity
Init_vel = [x0dot; y0dot; z0dot];

gamma0 = 0;     %Initial roll angle
beta0  = 0;     %Initial pitch angle
alpha0 = 0;     %Initial yaw angle

gamma0dot = 0;
beta0dot  = 0;
alpha0dot = 0;

f0 = mg;     %Previously was 0
u0 = f0-mg;

poly_order = 1;
%% Rotational Parameters and Desired Parameters

psi_dot = [gamma0dot; beta0dot; alpha0dot];

% Rotation Matrix from Equation 27
T = [1, sin(gamma0)*tan(beta0), cos(gamma0)*tan(beta0);  ...
     0,       cos(gamma0),           -sin(gamma0);       ...
     0, sin(gamma0)*sec(beta0), cos(gamma0)*sec(beta0)];

omega = T\psi_dot;  %Equation 25
p0 = omega(1);
q0 = omega(2);
r0 = omega(3);

% Mass Moments of Inertia of the Whole Array (not of a single module)
Ix = .004738;
Iy = .01077;
Iz = .01487;

Ixy = Ix-Iy;
Izx = Iz-Ix;
Iyz = Iy-Iz;

%Moment Arms
vect_xi = [ -.154;     .154;      0;      0];  %Previously 0.7 & -0.7
vect_yi = [     0;        0;   .087;  -.087];  %Previously 0.5 & -0.5 and signs were switched
ci      = [-.01235; -.01235; .01235; .01235];  %sign depends on propeller CW or CCW   %.01235

% P-Matrix
P = [ones(N,1), vect_yi, -vect_xi, ci]; %Was previously ones, -vect_xi, vect_yi, ci

% Q-Matrix
Q = pinv(P');  %Moore-Penrose pseudoinverse

%Desired States
x_desired = 0.1;
y_desired = 0.1;
z_desired = 0.25;     %meters
alpha_desired = 0.1;    % radians

%% Noise

% ACTIVATE ALL SENSOR NOISES
SENS_NOISE01 = 1;  % 0/1 for off/on of all sensor noises

%Noises are in DEGREES, need to convert to radians
IR_mean = 0;
Gyromean = 0;
ThreeD_mean = 0;
Accelmean = 0;

sx = (3*10^-4)/1000;
sy = (3*10^-4)/1000;
sz = (5.8*10^-3)/1000; %5.8*10^-3 OR 0.58%
xyz_noise = [sx; sy; sz];

sxdot = (3*10^-2)*(pi/180);
sydot = (3*10^-2)*(pi/180);
szdot = (3*10^-2)*(pi/180);

salpha = (2*10^-4)*(pi/180);
sbeta  = (2*10^-4)*(pi/180);
sgamma = (2*10^-4)*(pi/180);

sbetadot  = (5.4*10^-4)*(pi/180);
sgammadot = (5.4*10^-4)*(pi/180);
salphadot = (5.7*10^-4)*(pi/180);

%% PID Gains
%first commented values represent good values with noise, second are from
%the tests in the flight lab

%Proportional Gains
Kp_alpha = 50;     %190  %500
Kp_beta  = 8;      %80  %80
Kp_gamma = 15;      %80  %150

Kp_x     = .1;     %0.6   %1
Kp_y     = .15;     %0.6   %1.5
Kp_z     = 200;     %270  %200

%Integral Gains
Ki_alpha = 0; %120*(180/pi);       %0  %120*(180/pi)
Ki_beta  =  0; %30*(180/pi);       %0   %30*(180/pi)
Ki_gamma =  0; %40*(180/pi);       %0   %40*(180/pi)

Ki_x     = 0; %1;       %0     %1
Ki_y     = 0; %1;       %0     %1
Ki_z     = 200;       %2   %200

%Derivative Gains
Kd_alpha = 60;     %120   %60*(180/pi)
Kd_beta  = 30;      %20 %30*(180/pi)
Kd_gamma = 30;      %20   %30*(180/pi)

Kd_x     = 0.008;     %.25   %0.08
Kd_y     = 0.002;     %.25   %0.02
Kd_z     = 100;      %140   %100

%% Simulation
joymex2('open',0);
SimOut = sim('DFA_PID_Controller_ESC');
