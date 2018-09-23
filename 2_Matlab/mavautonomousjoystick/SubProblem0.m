function theta=SubProblem0(p,q)
%SubProblem0 Calculate the subproblem 0. The input are two vectors, the
%output is the theta. There always exists one solution for theta
%P,Q are two vectors
%theta is the result.(rad)
theta=2*atan(norm(p-q)/norm(p+q));
while theta<-pi
    theta=theta+2*pi;
end
while theta>pi
    theta=theta-2*pi;
end
end

