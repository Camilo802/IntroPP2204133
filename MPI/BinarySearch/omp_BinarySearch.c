#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 5000  //Se define el tama�o en 5000

void binary_search(int [], int, int, int);
void bubble_sort(int [], int);

int main() {
    int key, i;
    int list[SIZE];

    // Generar elementos aleatorios
    printf("Generating random elements...\n");
    srand(time(NULL)); // Semilla de generaci�n de n�meros aleatorios
    for(i = 0; i < SIZE; i++) {
        list[i] = rand() % 5000; // Genera n�meros aleatorios entre 0 y 5000
    }

    double start_time = omp_get_wtime(); // Guardar el tiempo de inicio

    // Parallelizing bubble sort
    bubble_sort(list, SIZE);

    // Seleccionar una clave aleatoria dentro del rango de la lista
    key = list[rand() % SIZE];

    printf("\n");
    printf("Randomly selected key: %d\n", key);
    binary_search(list, 0, SIZE - 1, key); // Ajuste del l�mite superior del rango

    double end_time = omp_get_wtime(); // Guardar el tiempo de finalizaci�n
    printf("Total execution time: %f seconds\n", end_time - start_time); // Imprimir el tiempo de ejecuci�n

    return 0;
}

void bubble_sort(int list[], int size) {
    int temp, i, j;
    
    #pragma omp parallel for private(i,j,temp) shared(list,size)
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) { // Ajuste del bucle interno para evitar intercambios innecesarios
            if (list[i] > list[j]) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void binary_search(int list[], int lo, int hi, int key) {
    int mid;

    if (lo <= hi) { // Corregido el operador de comparaci�n para incluir el caso en que lo == hi
        mid = lo + (hi - lo) / 2; // Corregido para evitar desbordamientos
        if (list[mid] == key) {
            printf("Key found at index %d\n", mid);
        } else if (list[mid] > key) {
            binary_search(list, lo, mid - 1, key);
        } else {
            binary_search(list, mid + 1, hi, key);
        }
    } else {
        printf("Key not found\n");
    }
}



