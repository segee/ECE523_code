mu=12.57e-7;
epsilon=8.85e-12;
size=500; % length of E and H
ks=100;     % location of electric field source
nsteps=1000;
dz=0.01; % 1 centimeter between points
c=3e8; % speed of light in vacuum
dt=dz/c;  % courant number =1  so c*dt=dz distance in 1 time step = distance
Ez=zeros(1,size);
Hy=Ez;
M=moviein(nsteps);
for t=1:nsteps
% E field loop
for k=2:size
Ez(k)=Ez(k)+(dt/(epsilon*dz))*(Hy(k-1)-Hy(k));
end
% Source
%Ez(ks)=0.1*sin(0.1*t);
if (t<100) 
    Ez(ks)=exp(-0.01*(t-20)^2)
end
for k=1:size-1
Hy(k)=Hy(k)+(dt/(mu*dz))*(Ez(k)-Ez(k+1));
end
bruce=t
plot(Ez);axis([1 size -1.5 1.5]);
M(:,t)=getframe ;
end
movie(M,100,100);



 