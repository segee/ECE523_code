#include <stdio.h>
#include <math.h>
#include <stdint.h>

struct float_fields
{
	unsigned int mantissa:23;
	unsigned int exponent:8;
	unsigned int sign:1;
};

struct double_fields
{
	unsigned long int mantissa:52;
	unsigned long int exponent:11;
	unsigned int sign:1;
};
union float_union
{
	float f;
	uint32_t i;
	struct float_fields field;
};
union double_union
{
	double d;
	uint64_t i;
	struct double_fields field;
};
int main()
{ union float_union try_float;
  union double_union try_double;

  
  
  
  
  try_float.f=2.0;
  try_double.d=2.0;

   try_float.field.exponent=0x82;
   try_float.field.mantissa=1<<22;
   try_float.field.sign=0;

  try_double.field.sign=0;
  try_double.field.exponent=0x400;
  try_double.field.mantissa=(unsigned long)205887<<35;



  printf("float %f sign %x exponent %x mantissa %x\n",try_float.f,try_float.field.sign,try_float.field.exponent,try_float.field.mantissa);
  printf("As an integer %x\n",try_float.i);
  printf("float %20.20lf sign %x exponent %x mantissa %lx\n",try_double.d,try_double.field.sign,try_double.field.exponent,(long)try_double.field.mantissa);
  printf("as an integer %lx\n",try_double.i);

  try_float.field.exponent++;
  try_float.field.mantissa++;
  try_double.field.exponent++;
  try_double.field.mantissa++;

  printf("float %.25f sign %x exponent %x mantissa %x\n",try_float.f,try_float.field.sign,try_float.field.exponent,try_float.field.mantissa);

  printf("As an integer %x\n",try_float.i);
  printf("float %.25lf sign %x exponent %x mantissa %lx\n",try_double.d,try_double.field.sign,try_double.field.exponent,(long)try_double.field.mantissa);
  printf("as an integer %lx\n",try_double.i);
}



