function MatToLatex(recorddata,name,i,TS)
%MatToLatex this function will print the recorddata and convert it to Latex
%recorddata is the data matrix
%name is the name of the file


h=figure(10);

plot(TS*(1:i),recorddata(3:5,1:i))%,1:i,recorddata(4,1:i),1:i, recorddata(5,1:i));
title('Relative Position');
xlabel('Time (s)');
ylabel('Position (m)');
legend('X', 'Y', 'Z'); 
totalName=['/home/botao/Dropbox/0_Common/18_labreport/3_Mar/Figure/' name '_OF_position.jpg'];
print(h,'-djpeg',totalName);

fileName=['\includegraphics[scale=0.15]{./Figure/' name '_OF_position.jpg}'];
 
expName=['\subsubsection{' num2str(norm(errNorm)) '-Exp-OF-' name '}'];
disp(expName);
disp('\begin{figure}'); 
disp('\centering');
disp(fileName);
caption=['\caption{This is the position of ' name '}'];
disp(caption);
disp('\end{figure}');
 
 
  
end