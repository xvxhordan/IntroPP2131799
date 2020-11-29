/*

  Purpose:

    Identify Armstrong numbers form 1 to 1000.

  Example:

    February 26 2020 08:07:29 (UTC/GMT +8 hours)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    November 29 2020

  Author:

  OpenMP Modification:
  29 November 2020 by Hordan Navarro, Universidad Industrial de Santander hordan.navarro@correouis.edu.co
  This OpenMP Modification makes a parallelization of the original Code...
*/

#include <stdio.h>
#include <omp.h>

void main(){
   int num,temp,r,sum;

	printf("Armstrong numbers in given range are: ");

    /*Se definieron dos variables para calcular el tiempo de ejecucion*/
    double start, end;
    start = omp_get_wtime();

    /* Se uso la directiva ordered para ejecutarlo como si fuera secuencial pero usando varios hilos */
    #pragma omp parallel for ordered
    for(num=1;num<=1000;num++){
        temp = num;
        sum = 0;
        /* Se remplazo el ciclo while por un ciclo for para poder paralelizarlo*/
   		#pragma omp ordered
        for(temp = num; temp != 0; temp = temp/10){
            r=temp % 10;
            sum=sum+(r*r*r);
        }
        // if num is equal to result, the number is an Armstrong number
        if(sum==num){
           printf("%d ", num);
        }
    }
printf("\n");
end = omp_get_wtime();
printf("Tiempo de ejecicion = %f\n",end-start);
}

