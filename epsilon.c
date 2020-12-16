#include <stdio.h>



#define epsilon(ARG) ARG=4.0;ARG/=3;ARG-=1;ARG*=3;ARG-=1;



main()

{

        float f;

        double d;

        long double ld;

        __float128 q;



        epsilon(f);

        epsilon(d);

        epsilon(ld);

        epsilon(q);
        epsilon(hello);

        printf("f is %e \nd is %le \nld is %Le\n",f,d,ld);

        ld=q; //I don't know how to print a __float128

        printf("q is %Le\n",ld);

}


