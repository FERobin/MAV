function [ y1,y2,y3,y4 ] = getjoy( )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
a=joymex2('query',0);

y1=double(a.axes(1));
y2=double(a.axes(2));
y3=double(a.axes(3));
y4=double(a.axes(4));

end

