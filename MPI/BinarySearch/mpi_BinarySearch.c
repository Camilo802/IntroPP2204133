#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h> // Incluir la biblioteca de MPI

#define SIZE 5000  // Define el tamaño "SIZE" en 5000
void binary_search(int [], int, int, int);
void bubble_sort(int [], int);

int main(int argc, char *argv[])
{
    int rank, size;
    int key, i;
    int list[SIZE];
    int local_list[SIZE];
    int local_size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Si no hay suficientes procesos, salir
    if (size < 2) {
        if (rank == 0) {
            printf("Este programa debe ejecutarse con al menos dos procesos.\n");
        }
        MPI_Finalize();
        return 1;
    }

    // Generar números aleatorios y dividir la lista entre los procesos
    srand(time(NULL));
    if (rank == 0) {
        printf("Generated list:\n");
        for(i = 0; i < SIZE; i++)
        {
            list[i] = rand() % 5000; // Números aleatorios entre 0 y 5000
            printf("%d ", list[i]);
        }
    }

    MPI_Bcast(list, SIZE, MPI_INT, 0, MPI_COMM_WORLD);

    local_size = SIZE / size;
    MPI_Scatter(list, local_size, MPI_INT, local_list, local_size, MPI_INT, 0, MPI_COMM_WORLD);

    double start_time = MPI_Wtime(); // Obtener el tiempo de inicio

    bubble_sort(local_list, local_size);
    
    int global_sorted_list[SIZE];
    MPI_Gather(local_list, local_size, MPI_INT, global_sorted_list, local_size, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("\n\nSorted list:\n");
        for(i = 0; i < SIZE; i++)
        {
            printf("%d ", global_sorted_list[i]);
        }
        
        key = global_sorted_list[rand() % SIZE]; // Escoger aleatoriamente una clave de la lista ordenada
        printf("\n\nAutomatically chosen key: %d\n", key);
        binary_search(global_sorted_list, 0, SIZE - 1, key);

        double end_time = MPI_Wtime(); // Obtener el tiempo de finalización
        printf("\nTime taken: %f seconds\n", end_time - start_time); // Imprimir el tiempo de ejecución
    }

    MPI_Finalize();

    return 0;
}

void bubble_sort(int list[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void binary_search(int list[], int lo, int hi, int key)
{
    int mid;

    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    mid = (lo + hi) / 2;
    if (list[mid] == key)
    {
        printf("Key found at index %d\n", mid);
    }
    else if (list[mid] > key)
    {
        binary_search(list, lo, mid - 1, key);
    }
    else if (list[mid] < key)
    {
        binary_search(list, mid + 1, hi, key);
    }
}