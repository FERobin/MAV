
function str=Integ2Str(data)
str='';
count=1;
sign=0;
if data<0
    sign=1;
end
data=abs(data);
b=floor(data/1000);
if b~=0
    str(count)=b+'0';
    count=count+1;
end
data=rem(data,1000);
b=floor(data/100);
if count==1
    if b~=0
    str(count)=b+'0';
    count=count+1;
    end
else
    str(count)=b+'0';
    count=count+1;
end
data=rem(data,100);
b=floor(data/10);
if count==1
    if b~=0
    str(count)=b+'0';
    count=count+1;
    end
else
    str(count)=b+'0';
    count=count+1;
end
data=rem(data,10);
b=data;
if count==1
    if b~=0
    str(count)=b+'0';
    count=count+1;
    else
        str(count)='0';
    end
else
    str(count)=b+'0';
    count=count+1;
end
if sign==1
    str=['-' str];
end
end