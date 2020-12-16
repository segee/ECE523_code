delta_t=0.0005;
length=5000000;
vin=1;
r=100;
c=1;
initial_vc=0;
l=1;
initial_il=0;
a=zeros(4,4);
y=zeros(4,1);
cvolt=zeros(1,length);
lcurrent=cvolt;
time=cvolt;
cvolt(1)=initial_vc;
lcurrent(1)=initial_il;
[a,y]=stamp_in_resistor(a,y,1,2,r);
[a,y]=stamp_in_voltage_source(a,y,1,0,3,vin);
[a,y]=stamp_in_voltage_source(a,y,2,0,4,initial_vc);
[a,y]=stamp_in_current_source(a,y,0,2,initial_il);
inv_a=inv(a);
%%% so far we have a voltage from node 1 to ground and 
%% a resistor from 1 to 1.  We will stamp in L and c

for x=2:length
    y(4)=cvolt(x-1);
    y(2)=-lcurrent(x-1);
    answer=inv_a*y;
    cvolt(x)=cvolt(x-1)+(1/c)*answer(4)*delta_t;
    lcurrent(x)=lcurrent(x-1) + (1/l)*answer(2)*delta_t;
    time(x)=time(x-1) +delta_t;
end
plot(time,cvolt,time,lcurrent)
