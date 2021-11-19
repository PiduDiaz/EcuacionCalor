//main
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <lapacke.h>
#include "tools.h"


double **alloc_2D_double(int nrows, int ncolumns);

int main(int argc, char *argv[]){

    int eleccion , ban ,opcion;
    int i , j , k, n;
    double tiempof , dt , ipaso, alfa, I1, I2, lol;

    double dx = 0.01;

    ban=0;

    while ((opcion = getopt (argc, argv, "r")) != -1)
{
    switch (opcion)
      {

      case 'r':
        ban = 1;
        break;

        // en caso de error getopt devuelve el caracter ?
      case '?':
        printf ("Opcion desconocida");
        return 1;}
}

    printf("\nEliga el metodo de euler que quiere utilizar (1 = explicito ; 2 = implicito) \n");
    scanf("%d",&eleccion);


    printf("Introduzca el tiempo final \n");
    scanf("%lf",&tiempof);

    printf("Introduzca el tamano del paso temporal (Ejem: 0.1) \n");
    scanf("%lf",&dt);

    printf("Introduzca la primera condicion de frontera \n");
    scanf("%lf",&I1);

    printf("Introduzca la segunda condicion de frontera \n");
    scanf("%lf",&I2);

    printf("Introduzca el valor de alfa \n");
    scanf("%lf",&alfa);

    // constante lamda
    double lambda;
    lambda = (alfa * dt)/(0.0001);

   // numero de iteraciones

    lol= tiempof/dt;

    n= (int) lol;

    printf("Numero de iteraciones: %d \n",n);

    //matriz de datos
    double **M;

    M = alloc_2D_double(n,101);

    //condiciones iniciales frontera
    for(i=0;i<n;i++){
        M[i][0]=I1;
        M[i][100]=I2;
    }
    //condiciones iniciales (Las filas seran con respecto al tiempo y las columnas respecto a la posicion)
    for(i=1;i<100;i++){
        ipaso=i*0.01;
        M[0][i]=exp(ipaso);
    }

    //euler explicito-------------------------------------------------------------------------------
    if(eleccion==1){
    double  T1 , T2 ,Ope, jpaso ,iipaso;

    //Se calcula la temperatura en del i-esimo paso de tiempo en la posicion j-esima
    for(i=1;i<n;i++){
        for(j=1;j<100;j++){

            T1= M[i-1][j-1]-(2*M[i-1][j])+M[i-1][j+1];
            T2 = dt * CalQ(j*0.01,i*dt);

            Ope = (lambda*T1)+ T2 + M[i-1][j];
            M[i][j]= Ope;
        }//for(j=1;j<99;j++)

        //condicion para saber si es una iteracion multiplo de 10
       /* if(i%10==0){
            FILE *restart= fopen("restart.dat","a");
            for(k=0;k<101;k++){
                fprintf(restart,"%.2f,",M[i][k]);
            }
            fprintf(restart,"%.2f,%.2f,%.2f \n",dt,dx,lambda);
            fclose(restart);
        } */

    }//for(i=1;i<n;i++)

    //Registro de datos para gráficar: Creación de archivo

    FILE *datos= fopen("datos1.txt","w");
    for (i=0;i<n;i++){
        iipaso = i*dt;
        for (j=0;j<101;j++){
            jpaso = j*0.01;
            fprintf(datos,"%.4f,%.4f,%.4f\n",jpaso,iipaso,M[i][j]);
        }
    }
    fclose(datos);

    
    }//explicito


    //euler implicito------------------------------------------------------------------------------------
    if(eleccion==2){
        double con1, con2;
        double  jpaso ,iipaso;

        
        con1 = lambda*I1;
        con2 = lambda*I2;

        for(i=1;i<n;i++){
            double **A;
            double *B, *C;
            double gu;

            //creacion de matriz dinamica
            A=alloc_2D_double(99,99);
            B=(double*)malloc((99*99)*sizeof(double));
            C=(double*)malloc(99*sizeof(double));

            printf("\nvuelta %.d \n",i);

            if ( A==NULL ){
                printf("Allocation error");
                exit(1);
            }
            if ( B==NULL ){
                printf("Allocation error");
                exit(1);
            }
            if ( C==NULL ){
                printf("Allocation error");
                exit(1);
            }

            //frontera del arreglo C

            C[0]=M[i-1][1]+(dt*CalQ(0.01,i*dt))+con1;
            C[98]=M[i-1][99]+(dt*CalQ(0.99,i*dt))+con2;

            

            //se llena el arreglo C
            for(j=1;j<98;j++){
                C[j]= M[i-1][j]+(dt*CalQ(i*0.01,i*dt));
            }

            //se llena el arreglo A
            double lambda2;
            lambda2 = 1 + (2*lambda);
            for(j=0;j<99;j++){
                for(k=0;k<99;k++){
                    if(j==k){
                        A[j][k]=lambda2;
                    }
                    if (j-k==-1){
                        A[j][k]=-1*lambda;
                    }
                    if (j-k==1){
                        A[j][k]=-1*lambda;
                    }

                }

            }

            for(k=0;k<99;k++){
                for(j=0;j<99;j++){
                    B[k*99+j]=A[k][j];
                }
            }



            for(int p=0;p<9801;p++){
                B[p]=p/100;
            }
            //se llama a la funcion solve

            solveSistema(B,C,99);
            printf("se uso la funcion \n");



            //se ingresa los resultados a la matriz M
            for(j=1;j<100;j++){
                M[i][j]=C[j-1];
            }

            free(C);
            free(B);
            for (k=0;k<99;k++){
                free(A[k]);
            }
            free(A);

        }//(i=1;i<n;i++)

        FILE *datos= fopen("datos2.txt","w");
        for (i=0;i<n;i++){
            iipaso = i*dt;
            for (j=0;j<101;j++){
                jpaso = j*0.01;
                fprintf(datos,"%.4f,%.4f,%.4f\n",jpaso,iipaso,M[i][j]);
            }
        }
        fclose(datos);
    }//(eleccion==2)   
    



    printf("Los resultados de la ultima iteracion fueron los siguientes \n");
    printf("Con x=0.01: %.2f \n",M[n-1][1]);
    printf("Con x=0.2: %.2f \n",M[n-1][20]);
    printf("Con x=0.4: %.2f \n",M[n-1][40]);
    printf("Con x=0.6: %.2f \n",M[n-1][60]);
    printf("Con x=0.8: %.2f \n",M[n-1][80]);

    system("pause");

    for (i=0;i<n;i++){
    free(M[i]);
    }
    free(M);
    return 0;
    }
