// calcular Q

#include <math.h>
#include "tools.h"

//---------------------------------------------------------------------------------------------------------------
float CalQ(float a, float b){
    float a1 , b1 , c1;

    a1 = cos(PI*b);
    b1 =sin(2*PI*a);
    c1= a1*b1;

    return c1;
}