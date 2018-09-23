function [theta1 theta2]= SubProblem2( p,q,k1,k2 )
%SubProblem2 Calculate the SubProblem2
%q=rotk(k1,theta1)rotk(k2,theta2)p
%p,q are two vectors;
%k1 k2 are two rotation axis
%theta might be a 1x2 vector, a value or not exist.if not exist, theta will
%be NaN
Coeff=[1 -dot(k1,k2);-dot(k1,k2) 1]*[dot(k1,q);dot(k2,p)];
r=(norm(p)^2-(Coeff(1)^2+Coeff(2)^2+2*Coeff(1)*Coeff(2)*dot(k1,k2)))/(norm(cross(k1,k2))^2);
num=norm(p)^2-(Coeff(1)^2+Coeff(2)^2+2*Coeff(1)*Coeff(2)*dot(k1,k2));
if num>0
    r1=sqrt(r);
    r2=-sqrt(r);
elseif num==0
    r1=0;
    r2=0;
else
    r1=NaN;
    r2=NaN;
end

if isnan(r1)
    theta1=NaN;
    theta2=NaN;
else
    z1=Coeff(1)*k1+Coeff(2)*k2+r1*cross(k1,k2);
    z2=Coeff(1)*k1+Coeff(2)*k2+r2*cross(k1,k2);
    if abs(r1-r2)>1e-5
        theta1(1)=-SubProblem1(q,z1,k1);
        theta2(1)=SubProblem1(p,z1,k2);
        theta1(2)=-SubProblem1(q,z2,k1);
        theta2(2)=SubProblem1(p,z2,k2);
    else
        theta1(1)=-SubProblem1(q,z1,k1);
        theta2(1)=SubProblem1(p,z1,k2);
    end
end
end

