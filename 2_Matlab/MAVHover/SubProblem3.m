function theta = SubProblem3(p,q,k,d)
%SubProblem3 Calculate the SubProblem3
%p,q two vectors
%k the rotation matrix
%d the distance
PPrime=p-dot(p,k).*k;
QPrime=q-dot(q,k).*k;
PSqrNorm=norm(PPrime)^2;
QSqrNorm=norm(QPrime)^2;
Test=d^2-(dot(p,k)-dot(q,k))^2;
if Test>=0
    DPrime=sqrt(d^2-(dot(p,k)-dot(q,k))^2);
    cosres=(PSqrNorm+QSqrNorm-DPrime^2)/(2*norm(PPrime)*norm(QPrime));
    if cosres<1
        phi(1)=acos((PSqrNorm+QSqrNorm-DPrime^2)/(2*norm(PPrime)*norm(QPrime)));
        
        ThetaRes=SubProblem1(PPrime/norm(PPrime),QPrime/norm(QPrime),k);
        theta(1)=ThetaRes-phi(1);
        theta(2)=ThetaRes+phi(1);
    elseif cosres==1
        phi(1)=acos((PSqrNorm+QSqrNorm-DPrime^2)/(2*norm(PPrime)*norm(QPrime)));
        phi(2)=phi(1);
        ThetaRes=SubProblem1(PPrime/norm(PPrime),QPrime/norm(QPrime),k);
        theta(1)=ThetaRes-phi(1);
     else
        theta(1)=NaN;
        
    end
    
else
    theta=NaN;
end


end

