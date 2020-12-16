#include <stdio.h>
#include <math.h>

int p707(int);


main()
{
  int x;
  double d;

  for(x=0;x<1000;x++) printf("%d,%d,%d,%lf\n",x,p707(x),(int)(x/sqrt(2.0)),x/sqrt(2.0));

}

/* 1/sqrt(2) is 0.7071 is 0.5 + 0.125 + etc */
/* the binary fraction is 0.1011 0101 0000 0100 this calculates the first 8 terms*/
/* (probably more than necessary)  */
int p707(int val)
{ 
    int half,eighth,sixteenth,sixty4th,one28th;

    half=val>>1;
    eighth=half>>2;
    sixteenth=eighth>>1;
    sixty4th=sixteenth>>2;
    one28th=sixty4th>>2;// originally rounded up
    return half+eighth+sixteenth+sixty4th+one28th;
}

