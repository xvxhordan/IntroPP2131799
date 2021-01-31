#!/bin/bash

#SBATCH --partition=normal  # Nombre de la particion
#SBATCH --job-name=mpi_armstrong # Nombre de la tarea a ejecutar
#SBATCH --nodes=2         # Cantidad de nodos a usar
#SBATCH --ntasks=2          # Numero de tareas a ejecutar
#SBATCH --cpus-per-task=4  # Numero de cores asignados a cada tarea
#SBATCH --output=output_mpi_armstrong.txt # Archivo de salida donde se encuentran los resultados de la ejecucion

module load devtools/mpi/openmpi/3.1.4    # Modulo que contiene el software a usar

mpirun -np 2 arms <<< 1000000