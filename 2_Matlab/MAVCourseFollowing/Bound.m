function res=Bound(input,upbound,bottombound)
%Bound this function bounds the input value
%input is a value
%upbound is the upper bound of the value
%bottombound is the bottom bound of the value
if input>=upbound
    res=upbound;
elseif input<=bottombound
    res=bottombound;
else
    res=input;
end
end
