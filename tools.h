// tools
#ifndef FUNCIONES
#define FUNCIONES

float multiplicar (float a, float b);

float linsolve (float A, float x);

int validar(char x);

float CalQ(float a, float b);

double **alloc_2D_double(int nrows, int ncolumns);


#endif


#ifndef EULER
#define EULER 2.71828182845904523536
#endif



#ifndef PI
#define PI 3.14159265358979323846
#endif

#ifndef _MATRIX_VECTOR_
#define _MATRIX_VECTOR_
double *multiplicationMV(double **A, double *vector, int size_array);

#endif // _MATRIX_VECTOR_

#ifndef _SOLVER_SYSTEM_
#define _SOLVER_SYSTEM_

void solveSistema(double *a, double *b, int N);

#endif // _SOLVER_SYSTEM_
