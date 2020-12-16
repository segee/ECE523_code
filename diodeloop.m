% set up aorig and yorig (everything but the diode)
% first guess zero volts i=0 r=1/(1e-12/25.9e-3)

i=0
r=1/(1e-12/25.9e-3);
diodevoltage=zeros(10);
diodecurrent=zeros(10);


for x =2:10
    [a,y]=stamp_in_diode(aorig,yorig,0,2,i,r);
    inv(a)*y;
    diodevoltage(x)=-ans(2);
    [i,r]=calculate_diode(diodevoltage(x),i,r);
    diodecurrent(x)=i+diodevoltage(x)/r;
end
figure(1);
plot(1:10,diodecurrent);
figure(2);
plot(1:10,diodevoltage);

    