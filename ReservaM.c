// reservar matriz
#include <stdlib.h>
#include "tools.h"

//-----------------------------------------------------------------------------------------------------------------
double **alloc_2D_double(int nrows, int ncolumns)
{
  int i;

  double **array = (double **)malloc(nrows*sizeof(double *));
  if (array==NULL)
    return NULL;
  array[0] = (double *)malloc(nrows*ncolumns*sizeof(double));
  if (array[0]==NULL)
     return NULL;

  for (i = 1; i < nrows; ++i)
    array[i] = array[0] + i * ncolumns;

  return array;

}
//--------------------------------------------------------------------------------------------------------------------
void double_2D_array_free(double **array)
{
  /*Frees the memory previously allocated by alloc_2D_double*/
  free(array[0]);
  free(array);
}
