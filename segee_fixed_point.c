
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

int16_t segee_fixed_add(int16_t,int16_t);
int16_t segee_fixed_sub(int16_t,int16_t);
void segee_print_fixed(int16_t);
int16_t segee_fixed_multiply(int16_t,int16_t);
int16_t segee_fixed_divide(int16_t,int16_t);
int16_t sin_cos(int which, int16_t theta);
int16_t bring_in_range(int16_t theta);
int16_t segee_fixed_sin(int16_t theta);
int16_t segee_fixed_cos(int16_t theta);

main()
{

	int16_t one=1<<11;
	int16_t two=2<<11;
        int16_t pi=3.14159*2048;
	int16_t theta1;
	double theta2;
	double ans1,ans2;
	FILE *fpsin,*fpcos;

	fpsin=fopen("segeesin.csv","w");

	if(fpsin==NULL) perror("fpsin"),exit(1);
	fpcos=fopen("segeecos.csv","w");
	if(fpcos==NULL) perror("fpcos"),exit(1);

	
	theta1=0x8000; //shortcut to biggest negative number
	theta2=theta1/2048.0;
	while(theta1<0x7fff)
	{
		ans2=segee_fixed_sin(theta1)/2048.0;
		ans1=sin(theta2);
                fprintf(fpsin,"%lf, %lf, %lf, %lf\n",theta2,ans1,ans2,ans1-ans2);
		ans2=segee_fixed_cos(theta1)/2048.0;
                ans1=cos(theta2);
		fprintf(fpcos,"%lf, %lf, %lf, %lf\n",theta2,ans1,ans2,ans1-ans2);

		theta1++;
		theta2=theta1/2048.0;
	}
	fclose(fpsin),fclose(fpcos);

	

}


int16_t segee_fixed_add(int16_t a, int16_t b)
{
	return(a+b);
}
int16_t segee_fixed_sub(int16_t a, int16_t b)
{       
        return(a-b);
}  

int16_t segee_fixed_multiply(int16_t a, int16_t b)
{
	long bruce;

	bruce=((long)a*b)>>11;
	return(bruce);
}

int16_t segee_fixed_divide(int16_t a, int16_t b)
{
	long bruce;

	bruce=(long)a<<11;
	bruce /=b;
	return(bruce);
	}


void segee_print_fixed(int16_t val)
{

	double bruce;

	bruce=(double)val /2048.0;
	printf("%lf",bruce);


}

int16_t bring_in_range(int16_t theta)
{  //sine and cosine are periodic in 2pi
   // bring into the range -pi to pi by
   // adding or subtracting 2pi 
   // theta changes, but the sin(theta) or cos(theta)
   // will be the same
   int16_t pi=(int)(3.1415926*2048);
   int16_t twopi=pi<<1;

   while(theta > pi) theta -= twopi;
   while(theta < -pi) theta += twopi;

   return theta;
}

int16_t sin_cos(int which, int16_t theta)

{
	//best if theta is between -pi/4 and pi/4
	//
	//
	int16_t taylor[8];
	int x;
	taylor[7]=taylor[6]=taylor[4]=taylor[5]=0;
	taylor[0]=1<<11;
	for(x=1;x<8;x++)
	{
	 taylor[x]=segee_fixed_multiply(theta,taylor[x-1]);
	 if(x>1) taylor[x] /=x;
	}

	if(which ==1)
		return taylor[1]-taylor[3]+taylor[5]-taylor[7];
	else   return taylor[0]-taylor[2]+taylor[4]-taylor[6];

}

int16_t segee_fixed_sin(int16_t theta)
{
	int16_t pi=(int)(3.1415926*2048);
	int16_t piover2=pi>>1;
	int16_t piover4=pi>>2;
	int16_t threepiover4=piover2+piover4;

	theta=bring_in_range(theta);

//if between -pi/4 and pi/4 return regular sine
	if(theta >= -piover4 && theta <= piover4) return sin_cos(1,theta);
 //sin(theta)==-cos(theta+pi/2)
 //if theta is between -3pi/2 and -pi/4 add pi/2 and compute -cos
  	if(theta >= -threepiover4 && theta <=-piover4 ) return -sin_cos(0,theta+piover2); 
//sin(theta)==cos(theta-pi/2)
//if theta is between pi/4 and 3pi/4 subtract pi/2 and compute cos
	if(theta >=piover4 && theta <= threepiover4) return sin_cos(0,theta-piover2);
//sin(theta) == -sin(theta +pi)
//if theta is negative at this point add pi
//else subtract pi
//in either case compute -sin
	if(theta <0) theta+=pi;
	else theta-=pi;
	return -sin_cos(1,theta);
}	


int16_t segee_fixed_cos(int16_t theta)
{
        int16_t pi=(int)(3.1415926*2048);
        int16_t piover2=pi>>1;
        int16_t piover4=pi>>2;
        int16_t threepiover4=piover2+piover4;

        theta=bring_in_range(theta);

//if between -pi/4 and pi/4 return regular cosine
        if(theta >= -piover4 && theta <= piover4) return sin_cos(0,theta);
 //cos(theta)==sin(theta+pi/2)
 //if theta is between -3pi/2 and -pi/4 add pi/2 and compute sin
        if(theta >= -threepiover4 && theta <=-piover4 ) return sin_cos(1,theta+piover2);
//cos(theta)==-sin(theta-pi/2)
//if theta is between pi/4 and 3pi/4 subtract pi/2 and compute -sin
        if(theta >=piover4 && theta <= threepiover4) return -sin_cos(1,theta-piover2);
//cos(theta) == -cos(theta +pi)
//if theta is negative at this point add pi
//else subtract pi
//in either case compute -sin
        if(theta <0) theta+=pi;
        else theta-=pi;
        return -sin_cos(0,theta);
}


