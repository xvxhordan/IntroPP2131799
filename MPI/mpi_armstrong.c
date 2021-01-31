#include "mpi.h"
#include <stdio.h>

/*
  Purpose:
    Identify Armstrong numbers in a certain range.
  Example:
    February 26 2020 08:07:29 (UTC/GMT +8 hours)
  Licensing:
    This code is distributed under the GNU LGPL license.
  Modified:
    January 30 2021
  Author:
  MPI Modification:
  30 January 2021 by Hordan Navarro, Universidad Industrial de Santander hordan.navarro@correouis.edu.co
  This MPI Modification makes a parallelization of the original Code...
*/

void calcularArmstrong(int a, int b){
	int num,temp,r,sum;
	for(num=a;num<=b;num++){
		temp = num;
		sum = 0;
		for(temp = num; temp != 0; temp = temp/10){
			r=temp % 10;
			sum=sum+(r*r*r);
		}
		if(sum==num){
			printf("%d ", num);
		}
	}
}

int main(int argc, char** argv){
	double start, end;
	int num;
	int enno;
	int cantidadCiclos[]={0,0,0,0};
	int idTarea, numeroTareas; /*Variables a usar mpi*/
	MPI_Init(&argc, &argv); /*Inicializamos mpi*/
	MPI_Comm_size(MPI_COMM_WORLD, &numeroTareas); /*Obtener numero de procesos*/
	MPI_Comm_rank(MPI_COMM_WORLD, &idTarea); /*Obtener rango*/

	/*Tiempo de inicio*/
	MPI_Barrier(MPI_COMM_WORLD);
	start = MPI_Wtime();

	if(idTarea == 0){
		printf("Input ending number of range : ");
		scanf("%d",&enno);
		printf("Armstrong numbers in given range are: ");

		for (num = 0; num < numeroTareas; ++num){
			if((num+1)== numeroTareas){ /*Ultimo*/
				cantidadCiclos[num]=enno;
			}else{
				cantidadCiclos[num]=enno/numeroTareas;
			}
		}

		calcularArmstrong(1,cantidadCiclos[0]);
		for (num = 1; num < numeroTareas; ++num){
			MPI_Send(&cantidadCiclos,4,MPI_INT,num,0,MPI_COMM_WORLD); /*Envia a cada proceso*/
		}
	}else{
		MPI_Recv(&cantidadCiclos,4,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		calcularArmstrong(cantidadCiclos[idTarea-1]+1,cantidadCiclos[idTarea]);
	}

	/*Tiempo final*/
  printf("\n");
	MPI_Barrier(MPI_COMM_WORLD);
	end = MPI_Wtime();
	if(idTarea == 0){
		printf("Tiempo de ejecicion en segundos = %f\n",end-start);
	}
	printf("\n");
}