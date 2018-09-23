function MatToLatex(recorddata,name,KPosGain,KAngGain,TS)
%MatToLatex this function will print the recorddata and convert it to Latex
%recorddata is the data matrix
%name is the name of the file

 
i=4000;

errNorm=[recorddata(3:5,1:i)-recorddata(19:21,1:i)];
h=figure(10);

plot(.01*(1:i),recorddata(3:5,1:i))%,1:i,recorddata(4,1:i),1:i, recorddata(5,1:i));
title('Relative Position');
xlabel('Time (s)');
ylabel('Position (m)');
legend('X', 'Y', 'Z'); 
totalName=['/home/botao/Dropbox/0_Common/18_labreport/3_Mar/Figure/' name '_position.jpg'];
print(h,'-djpeg',totalName);

fileName=['\includegraphics[scale=0.15]{./Figure/' name '_position.jpg}'];
 
expName=['\subsubsection{' num2str(norm(errNorm)) '-Exp-' name '}'];
disp(expName);
disp('\begin{figure}');
disp('\begin{minipage}{0.45\textwidth}');
disp('\centering');
disp(fileName);
caption=['\caption{This is the yaw of ' name '}'];
disp(caption);
disp('\end{minipage}');

 
h=figure(22);
Ts=TS; 
plot(.01*(1:i),recorddata(9:11,1:i)*180/pi)%,1:i,recorddata(7,1:i),1:i, recorddata(8,1:i));
title('Angles');
xlabel('Time (s)');
ylabel('Angle (degrees)');
legend('roll', 'pitch', 'yaw');
 
totalName=['/home/botao/Dropbox/0_Common/18_labreport/3_Mar/Figure/' name '_angle.jpg'];
print(h,'-djpeg',totalName);

fileName=['\includegraphics[scale=0.15]{./Figure/' name '_angle.jpg}'];
disp('\hspace{0.04\textwidth}');
disp('\begin{minipage}{0.45\textwidth}');
disp('\centering');
disp(fileName)
caption=['\caption{This is the input of ' name '}'];
disp(caption);
disp('\end{minipage}');
disp('\end{figure}');
 
% 
% disp('\begin{lstlisting}[language=Mathab]');
% disp('KPosGain=');
% disp(KPosGain');
% disp('\end{lstlisting}');

 

disp('\begin{lstlisting}[language=bash]');
QStr='KPosGain=(['; 
RStr='KAngGain=(['; 
for i=1:8
    QStr=[QStr num2str(KPosGain(i)) ','];
    RStr=[RStr num2str(KAngGain(i)) ','];
end
QStr=[QStr num2str(KPosGain(9)) ']);'];
RStr=[RStr num2str(KAngGain(9)) ']);'];
disp(QStr); 
disp(RStr); 
disp('\end{lstlisting}');

end