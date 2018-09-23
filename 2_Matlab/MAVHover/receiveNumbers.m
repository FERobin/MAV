function str = receiveNumbers(s, numbersExpecting)

count = 0;
serialTO = tic;
serialTOelapsed = toc(serialTO);
while ~s.BytesAvailable && serialTOelapsed < 2
    serialTOelapsed = toc(serialTO);
end
if ~s.BytesAvailable
    str=' something went wrong';
else
    str = '';
    while count < numbersExpecting
        while ~s.BytesAvailable
        end
        c = fread(s, s.BytesAvailable);
        str = [str sprintf('%c',c)];
        k = strfind(str, ' ');
        count = length(k);
    end
end

end