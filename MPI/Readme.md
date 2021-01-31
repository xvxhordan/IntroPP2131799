# Armstrong 
El siguiente codigo encuentra los numeros armstrong los cuales son aquellos que si elevamos al cubo cada uno de sus digitos y los sumamos y el resultado es igual al numero original entonces este es un numero armstrong.

Ejemplo: 153 = 1^3+5^3+3^3

Dentro de la carpeta, se encuentran localizados los 4 archivos de la entrega de la evaluación 1:
- arms (ejecutable)
- armstrong.c
- mpi_armstrong.c
- armstrong.sbatch
- readme.md
- ouput_mpi_armstrong.txt


## Ejecución del programa:
#### En Guane:
1. module load devtools/mpi/openmpi/3.1.4
2. mpicc -lm mpi_armstrong.c -o arms **(Compilar)**
3. ./arms **(Ejecutar)**
4. sbatch armstrong.sbatch  **(ejecutar sbatch)**
5. Abrir el archivo output_armstrong.txt **(ver salida)**
