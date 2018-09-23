function nums = receiveData(s)

serialTO = tic;
serialTOelapsed = toc(serialTO);
flushinput(s); %delete everything
while ~s.BytesAvailable && serialTOelapsed < 0.02
    serialTOelapsed = toc(serialTO);
end
exitFlg=1;

if ~s.BytesAvailable
    nums=[];
else
    str = '';
    while (exitFlg==1)% count < numbersExpecting
        while ~s.BytesAvailable
        end
        c = fread(s, s.BytesAvailable);
        str = [str sprintf('%c',c)];
        
        % look for newline character...
        l = strfind(str, char(10));
        if length(l) > 2
            substrs = strsplit(str,char(10));
            
%             datastr='';
%             k = strfind(substrs,',');
%             for i = length(k):1
%                 if length(k{i}) == numbersExpecting-1
%                     datastr = substrs{i};
%                     break;
%                 end
%             end
%             if length(datastr) > 0
%                 break;
%             end
            LEN=length(substrs);
            if LEN >= 2
                if (isempty(substrs{LEN}))
                    datastr=substrs{LEN-2};
                else
                    datastr=substrs{LEN-1};
                end
            end
            exitFlg=0;
             num_cell = strsplit(datastr,',');
            nums = str2double(num_cell);
            if isnan(nums(end))
                nums = nums(1:end-1);
            end
            break;
        else
            if isempty(l)
                exitFlg=0;
                
            end
            nums=[];
            
        end 
        
    end
   
end
flushinput(s); %delete everything
end