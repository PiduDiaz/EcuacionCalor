// reservar matriz
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tools.h"

//-----------------------------------------------------------------------------------------------------------------
double **alloc_2D_double(int nrows, int ncolumns) //credito de esta funcion a quien corresponda.
{
  int i;
	double **arreglo=NULL;
	arreglo = (double**)malloc(nrows*sizeof(double*));
	for (i=0; i<nrows; i++){
		arreglo[i] = (double*)malloc(ncolumns*sizeof(double) );
		if (arreglo[i] == NULL){
			perror("ERROR. There is not enough memory");
			exit(EXIT_FAILURE);
		}
	}
	return arreglo;

}


//---------------------------------------------------------------------------------------------------------------
float CalQ(float a, float b){
    float a1 , b1 , c1;

    a1 = cos(PI*b);
    b1 =sin(2*PI*a);
    c1= a1*b1;

    return c1;
}


