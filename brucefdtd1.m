mu=12.57e-7;
epsilon=8.85e-12;
size=2000; % length of E and H
ks=200;     % location of electric field source
nsteps=4000;
dz=0.01; % 1 centimeter between points
c=3e8; % speed of light in vacuum
dt=dz/c;  % courant number =1  so c*dt=dz distance in 1 time step = distance
Ez=zeros(1,size);
Hy=Ez;
xe=dz.*(1:size);
xh=dz.*(1.5:(size+0.5));
blank=zeros(1,size);
M=moviein(nsteps);
for t=1:nsteps
% E field loop
Ez(1)=Ez(2);
for k=2:size
if((k<800)|(k>1200)) Ez(k)=Ez(k)+(dt/(epsilon*dz))*(Hy(k-1)-Hy(k));
else Ez(k)=Ez(k)+(dt/(5*epsilon*dz))*(Hy(k-1)-Hy(k));
end
end

% Source
 Ez(ks)= Ez(ks)+sin(0.1*t);  % constant sine wave
%if (t<100)  Ez(ks)=exp(-0.01*(t-20)^2);end  % gaussian pulse
%if (t<2)  Ez(ks)=1; end  %square pulse (pretty freaky)
Hy(size)=Hy(size-1);
for k=1:size-1
Hy(k)=Hy(k)+(dt/(mu*dz))*(Ez(k)-Ez(k+1));
end
%plot3(xe,blank,Ez);hold on;
%plot3(xh,Hy,blank);

%plot3(xe,blank,Ez,xh,Hy,blank);axis([0,60,-2e-3,2e-3,-2,2]);
plot(xe,Ez);axis([1 size*dz -1.5 1.5]);
M(:,t)=getframe ;
hold off;
end
movie(M,100,1000);



 