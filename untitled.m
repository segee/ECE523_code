clear;
clc
k=2*pi;% spatial propagation constant
w=10;% angular frequency
E=20*sqrt(2); % electric field amplitude
H=20*sqrt(2); % magnetic field amplitude
x=0:0.01:3; % space representative point
Z=zeros(size(x));
for i=1:501
t=i*0.01;
Ey=E*cos(w*x).*exp(-0.5*x);
Hz=H*cos(w*x-pi/4).*exp(-0.5*x);
end
figure(1)
plot3(x,Ey,Z,'b');
hold on;
plot3(x,Z,Hz,'b');
grid on;
axis([0,2,-20,20,-20,20])
xlabel('x axis'); ylabel('electric field'); zlabel('magnetic field');
set(gcf,'color','w')
hold off
