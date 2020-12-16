function [ a,y ] = stamp_in_diode( a,y,i_flat,j_pointy,current,r )
%Stamps in a linearized diode with a current source and a resistor in
%parallel.
% current flows from i to j
 
 [a,y]=stamp_in_current_source(a,y,j_pointy,i_flat,current);
 [a,y]=stamp_in_resistor(a,y,i_flat,j_pointy,r);
end
