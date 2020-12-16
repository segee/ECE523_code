#include <stdio.h>

int my_exp(int,int,int,int);
main()
{
	int x;
	for(x=0;x<=25;x++) printf("%d,%d\n",x,my_exp(488,-x,667,100));
}



/* calculate A*exp(t/tau) using all integer arithmetic              */
/* Tau is expressed as tau_num and tau_den where the time           */
 /* contant is the ratio of tau_num/tau_den                         */
 /* for example, to calculate 488*exp(-3/6.67) call                 */
 /* my_exp(488,-3,667,100)                                          */
 /* it calculates the first 20 terms of the taylor series eapansion */
 /* in such a way that very large and very small numbers are avoided*/
int my_exp( int a, int t, int tau_num, int tau_den)
{
  long temp, sum;
  int i;
  temp=sum=a;
  for(i=1;i<20;i++)
  {
    temp *= t*tau_den;
    temp /= tau_num;
    temp /=i;
    sum +=temp;
  }
  return sum;
}

