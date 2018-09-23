s = serial('COM6');
set(s,'BaudRate',38400);
fopen(s);
fprintf(s,'*IDN?');
out = fscanf(s)
fclose(s);
delete(s);
clear s; 