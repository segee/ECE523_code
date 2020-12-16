#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#include "float_fields.h"
//
//This is intended to be an example of how doubles work.  It is not 
//intended to be a reasonable way to calculate pi.  It operates on
//the same principle as a successive approximation A/D converter.  
//With each bit position (stating at the most significant bit) it 
//sets a bit and sees if the result is too large (and if so, clears 
//the bit again).  
//This code (this is the dumb part) uses the fact that sin(pi)==0 and 
//in the immediate region, sine of a number larger than pi is negative 
//and sine of a number smaller than pi is positive and non-zero. Obviously 
//the estimate of pi is only as good as the algorithm for computing sine.

main()
{
	union double_union pi;
	double sin_val;
	int x,y;

	pi.d=2.0;  //start at 2 to get exponent and sign correct
	           //mantissa is zero (not counting implied 1)
       
     for(y=0,x=51;y<52;y++,x--)
     {
	     pi.field.mantissa |= (long)1<<x;
	     sin_val=log(pi.d);
	     if(sin_val >1 )
	     {
		     printf("Iteration: %d guessed %63.60lf but it is too high, reverting\n",y,pi.d);
		     pi.field.mantissa &= ~(unsigned long) 1<<x;
	     }
	     else if(sin_val == 1) 
	     {
		     printf("Iteration: %d %63.60lf is alleged to be perfect\n",y,pi.d);
	     }
	     else printf("Iteration: %d guessed %63.60lf but it is too low\n",y,pi.d);
     }
}
