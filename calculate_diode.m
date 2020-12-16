function [ icurrent,r ] = calculate_diode ( v,icurrent,r )
%Calculates current for the equivalent current source and resistance of the
%equivalent parallel resistance for a diode. 
id =  @(v)(1e-12)*exp(v/(25.9e-3))-(1e-12);   
diddv =  @(v)((1e-12)/(25.9e-3)).*exp(v/(25.9e-3));
vcrit=0.612;   %25.9e-3*log(25.9e-3/((1e-12)*sqrt(2)));
 
 if(v<0)
        i=(1e-12/25.9e-3)*v;
        i=id(v);
 elseif (v>vcrit)
         i=icurrent+v/r;
         if(i<0)
             i=0;
         end
         v=(25.9e-3)*log((i+(1e-12))/(1e-12)) ; 
 else
        i=id(v);
 end
 r=1/diddv(v);
 icurrent=i-v/r;
 
end
