function [a,y]=stamp_in_voltage_source(ain,yin,plusnode,minusnode,row,voltage)
a=ain;
y=yin;
if plusnode ~=0 
    a(row,plusnode)= a(row,plusnode)+1;
    a(plusnode,row)=a(plusnode,row)+1;
end
if(minusnode ~=0) 
    a(row,minusnode)=a(row,minusnode)-1;
    a(minusnode,row) =a(minusnode,row)-1;
end
y(row)=voltage;
end

