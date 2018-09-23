N=1000;
dt =0.011;


X=recorddata(3,1:N);
Vx(1) =0;
for i=2:N;
    Vx(i) = (X(i)-X(i-1))/dt;
end

% Pxx=pwelch(Vx(2:N),100);

plot(Vx);

n=0:319;
x=cos(pi/4*N)+randn(size(n));
pxx=pwelch(x);