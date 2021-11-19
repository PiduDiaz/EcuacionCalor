# Ecuación Del Calor #

# Descripción
Con el presente programa se pretende resolver la ecuación unidimensional  del calor utilizando los métodos de Euler Explícito e Implícitos.

# Descarga 

Para la instalación se pueden descargar los archivos o clonar el repositorio con el siguiente comando.

```
git clone https://github.com/PiduDiaz/EcuacionCalor.git

```
# Requerimientos 

 * Compilador de lenguaje C
 * Make
 * LAPACK
 * Valgrind (opcional)

# Instalacion

Luego de descargados los archivos se puede, caso de no tener las librerias de LAPACK, se pueden descargar ejecutando el comando:

```
make Download

```
A continuación, ejecuntado `make` o `make all` se compilara el programa y se podra ejecutar con el comando `./heat`.


# Funcionamiento

Cuando se ejecuta el programa le pedirá al usuario que ingrese por teclado que método de Euler desea utilizar. Luego preguntará por un tiempo final para el problema y la discretización temporal, luego por las condiciones de frontera y por último el valor de alfa o difusividad térmica. 

Al finalizar la ejecución el programa mostrara en pantalla algunos resultados y habra creado un archivo llamado Datos.txt que contendran los valores de todas las iteraciones.

# Bandera -restart

Adicionalmente el programa cuenta con una bandera que se ejecuta de la siguiente forma `./heat -r`. Esta bandera hace que al llegar a la iteración número 25 le pregunta al usuario si desea reiniciar a la iteración 20, si responde que sí, el programa continuará las iteraciones faltantes desde el último punto guardado (iteración 20) (Los datos se guardan cada 10 iteraciones en un archivo llamado restart.dat).


# Hoja de ruta 
Se tienen las siguientes ideas para próximas versiones:

* Que el usuario pueda modificar la discretización espacial del problema.
* Que la bandera `-r ` realice el reinicio en algun momento solicitado por el usuario.
* Añadirle más funcionalidades con nuevas banderas.

# Estado del proyecto 

Paralizo por deberes.


