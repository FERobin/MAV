function nums = receiveDataNew(s)

serialTO = tic;
serialTOelapsed = toc(serialTO);
%flushinput(s); %delete everything
while ~s.BytesAvailable && serialTOelapsed < 0.005
    serialTOelapsed = toc(serialTO);
end
exitFlg=1;

if ~s.BytesAvailable
    nums=[inf inf inf inf]';
   
else
    str = '';
    while (exitFlg==1)% count < numbersExpecting
%         while ~s.BytesAvailable
%         end

        
       
        l = strfind(str, char(10));
        while isempty(l)
            while ~s.BytesAvailable
            end
            c=fread(s,s.BytesAvailable);
            str=[str sprintf('%c', c)];
            l = strfind(str, char(10));
        end
%   
        
        % look for newline character...
        l = strfind(str, char(10));
       
        if isempty(l)
            nums=[inf inf inf inf]';
        
           break;
        else 
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
                    datastr=substrs{LEN-1};
                else
                    datastr=substrs{LEN};
                end
            end
            exitFlg=0;
           
            
            num_cell = strsplit(datastr,',');
            nums = str2double(num_cell);
            disp(nums);
            if isnan(nums(end))
                
                nums = nums(1:end-1);
            end
            break;
        end 
        
    end
    
end
flushinput(s); %delete everything
end