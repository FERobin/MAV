function [ theta1,theta2 ] = subproblem2_zj( k1,k2,p,q )

k1=k1/norm(k1);
k2=k2/norm(k2);
p=p/norm(p);
q=q/norm(q);


if k1==k2
    theta1=subproblem1(k1,p,q);
    theta2=theta1;
    disp('One Solution')
end

a_b=([1 -dot(k1,k2);-dot(k1,k2)  1]*[dot(q,k1) ; dot(p,k2)])/(1-dot(k1,k2)^2)


if (norm(p)^2<(a_b(1))^2-(a_b(2))^2-2*a_b(1)*a_b(2)*dot(k1,k2))
    disp('No Solution')
    return
end
 
r1=sqrt(  ((norm(p))^2-(a_b(1))^2-(a_b(2))^2-2*a_b(1)*a_b(2)*dot(k1,k2)          )/(norm(hat(k1)*k2))^2            );
r2=-sqrt(  ((norm(p))^2-(a_b(1))^2-(a_b(2))^2-2*a_b(1)*a_b(2)*dot(k1,k2)          )/(norm(hat(k1)*k2))^2           );

z1=a_b(1)*k1+a_b(2)*k2+r1.*(hat(k1)*k2);
z2=a_b(1)*k1+a_b(2)*k2+r2.*(hat(k1)*k2);

theta2_1=subproblem1(k2,p,z1);
theta2_2=subproblem1(k2,p,z2);
theta1_1=-subproblem1(k1,q,z1);
theta1_2=-subproblem1(k1,q,z2);

theta1=[theta1_1    theta1_2];
theta2=[theta2_1    theta2_2];
disp('theta1=');
 disp(theta1);
 disp('theta2=');

end

