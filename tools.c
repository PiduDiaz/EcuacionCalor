// reservar matriz
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <lapacke.h>
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

double *multiplicationMV(double **A,double *vector, int size_array){

  int i,j;
  double *result;
  result = (double*) malloc(sizeof(double)*size_array);

  for(i=0;i<size_array;i++){
    result[i]=0;
  }

  for(i=0;i<size_array;i++){

    for(j=0;j<size_array;j++){
      result[i] +=A[i][j]*vector[j];
    }

  }
  return result;

}


/*Function for solving a linear system*/
/*La funcion recibe las matrices como arreglos unidimensionales*/
void solveSistema(double *a,double *b, int N ){


  int *ipiv = (int*) malloc(sizeof(int)*(N*N));
  lapack_int n=N,nrhs=1,lda=N,  ldb=1,info;

  info = LAPACKE_dgesv(LAPACK_ROW_MAJOR,n,nrhs,a,lda,ipiv,b,ldb);


  free(ipiv);

  return;
}
