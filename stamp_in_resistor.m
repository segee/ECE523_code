function [a,y] =stamp_in_resistor(ain,yin,row,col,rvalue)
a=ain;
y=yin;
if row ~=0
    a(row,row)=a(row,row)+1/rvalue;
end
if col ~=0
    a(col,col) = a(col,col)+1/rvalue;
end
if row*col ~=0
    a(row,col) = a(row,col)-1/rvalue;
    a(col,row) = a(col,row)-1/rvalue;
end
end