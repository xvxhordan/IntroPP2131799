# Armstrong 
El siguiente codigo encuentra los numeros armstrong los cuales son aquellos que si elevamos al cubo cada uno de sus digitos y los sumamos y el resultado es igual al numero original entonces este es un numero armstrong.

Ejemplo: 153 = 1^3+5^3+3^3

Dentro de la carpeta, se encuentran localizados los 5 archivos de la entrega de la evaluación 1:
- armstrong.c
- omp_armstrong.c
- armstrong.sbatch
- readme.md
- output_armstrong.txt


## Ejecución del programa:
#### En Guane:
1. gcc -fopenmp omp_armstrong.c -o arms -lm **(Compilar)
2. ./arms **(Ejecutar)
2. sbatch armstrong.sbatch  **(ejecutar sbatch)
3. Abrir el archivo output_armstrong.txt    **(ver salida)  
#### En local:
1. gcc -fopenmp omp_armstrong.c -o arms -lm **(Compilar)
2. ./arms **(Ejecutar)

