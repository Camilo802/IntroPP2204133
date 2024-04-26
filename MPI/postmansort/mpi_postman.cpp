#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"

// Prototipo de la función para ordenar subsecuencias
void arrange(int, int);

// Declaración de variables globales
int array[100000], array1[100000];
int i, j, temp, max, count = 100000, maxdigits = 0, c = 0;
double start, end;
const int MAX_RANGE = 999999; // Constante para el rango máximo de números aleatorios

// Prototipo de la función para generar números aleatorios
int generateRandom();

int main(int argc, char *argv[]) {
    struct timespec start, finish;
    double elapsed;
    int n = 1;
    int t;
    int rank, size;

    // Inicialización de MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Si es el proceso 0, se realiza la inicialización y generación de números aleatorios
    if (rank == 0) {
        // Inicio del contador de tiempo
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Inicialización de la semilla para generar números aleatorios
        srand(time(NULL));
        // Generación de números aleatorios y copia a ambos arreglos
        for (i = 0; i < count; i++) {
            array1[i] = generateRandom();
            array[i] = array1[i];
        }

        // Cálculo del número máximo de dígitos de los números en el arreglo
        for (i = 0; i < count; i++) {
            int t = array[i];
            while (t > 0) {
                c++;
                t = t / 10;
            }
            if (maxdigits < c)
                maxdigits = c;
            c = 0;
        }

        // Determinación del valor de n para el ordenamiento
        while (--maxdigits)
            n = n * 10;
    }

    // Se envía el valor de n y los arreglos a todos los procesos MPI
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(array, count, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(array1, count, MPI_INT, 0, MPI_COMM_WORLD);

    // Cada proceso MPI realiza parte del ordenamiento inicial
    for (i = rank; i < count; i += size) {
        max = array[i] / n;
        t = i;
        for (j = i + 1; j < count; j++) {
            if (max > (array[j] / n)) {
                max = array[j] / n;
                t = j;
            }
        }
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }

    // Ordenamiento final de las subsecuencias de números con el mismo dígito más significativo
    while (n >= 1) {
        for (i = rank; i < count;) {
            int t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++)
                arrange(i, j); // Llamada a la función para ordenar subsecuencias
            i = j;
        }
        n = n / 10;
    }

    // Barrera de sincronización MPI
    MPI_Barrier(MPI_COMM_WORLD);
    
    // Si es el proceso 0, se calcula y muestra el tiempo transcurrido
    if (rank == 0) {
        // Fin del contador de tiempo
        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        printf("El trabajo tomó %f segundos\n", elapsed);
    }

    // Finalización de MPI
    MPI_Finalize();
    return 0;
}

// Definición de la función para ordenar subsecuencias
void arrange(int k, int n) {
    for (i = k; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (array1[i] > array1[j]) {
                temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                temp = (array[i] % 10);
                array[i] = (array[j] % 10);
                array[j] = temp;
            }
        }
    }
}

// Definición de la función para generar números aleatorios
int generateRandom() {
    return rand() % MAX_RANGE;
}

