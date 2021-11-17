#include <stdio.h>
#include <stdlib.h>


int iteracion ; //numero de iteraciones 
int valor;  // valor de la iteracion 10,20,21,22
int deltax;  // valor de delta de x
int deltay; // valor de delta de y


int restart(int iteracion, int deltax, int deltay);// agregen las variables que falten


int main (){
	int iteraciones = restart(25,0.001,0.01); //estos valores son los que da el problema ahi le pueden cambiar y agregar las variables que hagan falta
	
	printf("Los valores de la iteracion 10, la iteracion 20, 21...,22: d%\n",iteraciones);
	
	return 0;
	
}


int restart(int iteracion, int deltax, int deltay){// aqui va el codigo del metodo de euler implicito
	int veces = iteracion/10 //como estamos en C la division devuelve un entero
	int valores[veces++5]={10,20,21,22,23,24,25}; //Los indices de los resultados que se debe imprimir
	printf("Los valores de deltax, deltat, el valor de las respectiva iteraciones: d%\n", iteraciones[valores]);
	}
	return 0;
}
	
	
	
	

