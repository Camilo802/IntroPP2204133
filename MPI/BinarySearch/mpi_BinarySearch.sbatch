#!/bin/bash
#SBATCH --job-name=MPI_BinarySearch
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=8
#SBATCH --output=output_mpi_BinarySearch.txt%j.out
#SBATCH --error=error_mpi_BinarySearch.err%j.err

# Cargar módulos de gcc y mpi
module load devtools/gcc/6.2.0
module load devtools/mpi/openmpi/3.1.4

# Compilar el archivo mpi_BinarySearch.c
mpicc mpi_BinarySearch.c -o mpi_BinarySearch

# Ejecutar el programa
mpiexec -np 2 ./mpi_BinarySearch