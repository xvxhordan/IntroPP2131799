# Armstrong 
El siguiente codigo encuentra los numeros armstrong los cuales son aquellos que si elevamos al cubo cada uno de sus digitos y los sumamos y el resultado es igual al numero original entonces este es un numero armstrong.

Ejemplo: 153 = 1^3+5^3+3^3

Dentro de la carpeta, se encuentran localizados los 4 archivos de la entrega de la evaluación 1:
- armstrong.c
- omp_armstrong.c
- armstrong.sbatch
- readme.md


## Ejecución del programa:
#### En Guane:
1. gcc -fopenmp omp_armstrong.c -o arms -lm **(Compilar)**
2. ./arms **(Ejecutar)**
3. sbatch armstrong.sbatch  **(ejecutar sbatch)**
#### En local:
1. gcc -fopenmp omp_armstrong.c -o arms -lm **(Compilar)**
2. ./arms **(Ejecutar)**

