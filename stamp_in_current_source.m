function [a,y]=stamp_in_current_source(ain,yin,plusnode,minusnode,current)
a=ain;
y=yin;
if plusnode ~=0 
    y(plusnode)=  y(plusnode)+current;

end
if(minusnode ~=0) 
    y(minusnode)=y(minusnode)-current;
end
end
