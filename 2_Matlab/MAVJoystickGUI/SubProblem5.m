function [alpha beta gamma]=SubProblem5(R,h1,h2,h3)
%SubProblem5 Calculate the subproblem5 
%R=rotk(h1,alpha)rotk(h2,beta)rotk(h3,gamma)
%R is the rotation matrix
%h1 is the first axis
%h2 is the second axis
%h3 is the third axis
beta=SubProblem4(h1,h3,h2,h1'*R*h3);
alpha(1)=SubProblem1(rotk(h2,beta(1))*h3,R*h3,h1);
gamma(1)=SubProblem1(h2,rotk(h2,-beta(1))*rotk(h1,-alpha(1))*R*h2,h3);
alpha(2)=SubProblem1(rotk(h2,beta(2))*h3,R*h3,h1);
gamma(2)=SubProblem1(h2,rotk(h2,-beta(2))*rotk(h1,-alpha(2))*R*h2,h3);

end