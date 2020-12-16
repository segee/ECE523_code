delta_omega = 0.000005;
length=500000;
vin=1;
r=100;
c=1;

l=1;

ain=zeros(3,3);
y=zeros(3,1);
cvolt=zeros(1,length);

freq=cvolt;
cvolt(1)=1;

[ain,y]=stamp_in_resistor(ain,y,1,2,r);
[ain,y]=stamp_in_voltage_source(ain,y,1,0,3,vin);

%%% so far we have a voltage from node 1 to ground and 
%% a resistor from 1 to 1.  We will stamp in L and c

for x=2:length
    freq(x)=freq(x-1)+delta_omega;
    impc=1/(j*freq(x)*c);
    impl=j*freq(x)*l;
    
    [a,y]=stamp_in_resistor(ain,y,2,0,impc);
     [a,y]=stamp_in_resistor(a,y,2,0,impl);
     answer=inv(a)*y;
    
    cvolt(x)=answer(2);
    
end
plot(freq,abs(cvolt))
