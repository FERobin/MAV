function theta = SubProblem4(h1,h2,k,d )
%SubProblem4 Calculate the SubProblem4
%d=h1*rotk(k,theta)*h2
%h1 is the vector of the plane
%k is the rotation matrix
%d is the distance
%h2 is the initial plane
%theta is the result
c=d-dot(h1,h2)-h1'*cross(k,cross(k,h2));
a=-h1'*cross(k,h2);
b=h1'*cross(k,cross(k,h2));
if c^2>a^2+b^2
    theta=NaN;
elseif c^2==a^2+b^2
    theta=acos(c/sqrt(a^2+b^2))-(pi+atan2(-a,b));
    if theta<0
        theta=theta+2*pi;
    end
else
    theta(1)=acos(-c/sqrt(a^2+b^2))-(pi+atan2(a,b));
    if theta(1)<0
        theta(1)=2*pi+theta(1);
    end
    theta(2)=2*pi-acos(-c/sqrt(a^2+b^2))-(pi+atan2(a,b));
    if theta(2)<0
        theta(2)=2*pi+theta(2);
    end
end

end

