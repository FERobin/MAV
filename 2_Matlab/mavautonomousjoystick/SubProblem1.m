function theta = SubProblem1(p,q,k)
%SubProblem1 Calculate the SubProblem1
%p,q are two vectors
%k is a unit vector around which two vectors rotate
%theta is the result. There is always one result
PPrime=p-dot(p,k).*k;
QPrime=q-dot(q,k).*k;
theta=SubProblem0(PPrime,QPrime);
if cross(PPrime,QPrime)'*k<0
    theta=2*pi-theta;
end
while theta<-pi
    theta=theta+2*pi;
end
while theta>pi
    theta=theta-2*pi;
end
end

