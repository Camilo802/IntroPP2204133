
/*
 * Programa C para implementar el algoritmo de clasificaci髇 de cartero#include <stdio.h>
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrange(int, int); // Declaraci贸n de la funci贸n para ordenar subsecuencias
int array[100000], array1[100000]; // Declaraci贸n de los arreglos globales
int i, j, temp, max, count = 100000, maxdigits = 0, c = 0; // Declaraci贸n de variables globales
double start, end; // Declaraci贸n de variables de tiempo
const int MAX_RANGE = 999999; // Declaraci贸n de una constante para el rango m谩ximo de n煤meros aleatorios

int generateRandom(); // Declaraci贸n de la funci贸n para generar n煤meros aleatorios

void main()
{
    struct timespec start, finish; // Declaraci贸n de estructuras para medir el tiempo
    double elapsed; // Variable para almacenar el tiempo transcurrido
    int n = 1; // Inicializaci贸n de la variable n
    int t;     // Declaraci贸n de la variable t

    clock_gettime(CLOCK_MONOTONIC, &start); // Inicio del contador de tiempo

    srand(time(NULL)); // Inicializaci贸n de la semilla para generar n煤meros aleatorios
    for (int i = 0; i < count; i++)
    {
        array1[i] = generateRandom(); // Llenado del arreglo con n煤meros aleatorios
        array[i] = array1[i];
    }

    // C谩lculo del n煤mero m谩ximo de d铆gitos de los n煤meros en el arreglo
    for (i = 0; i < count; i++)
    {
        int t = array[i];
        while (t > 0)
        {
            c++;
            t = t / 10;
        }
        if (maxdigits < c)
            maxdigits = c;
        c = 0;
    }

    // Determinaci贸n del valor de n para el ordenamiento por el algoritmo de Postman
    while (--maxdigits)
        n = n * 10;

    // Ordenamiento inicial por el d铆gito m谩s significativo
    for (i = 0; i < count; i++)
    {
        max = array[i] / n;
        t = i;
        for (j = i + 1; j < count; j++)
        {
            if (max > (array[j] / n))
            {
                max = array[j] / n;
                t = j;
            }
        }
        // Intercambio de elementos en ambos arreglos seg煤n el ordenamiento por d铆gitos
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }

    // Ordenamiento final de las subsecuencias de n煤meros con el mismo d铆gito m谩s significativo
    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            int t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++)
                arrange(i, j); // Llamada a la funci贸n para ordenar subsecuencias
            i = j;
        }
        n = n / 10;
    }

    clock_gettime(CLOCK_MONOTONIC, &finish); // Fin del contador de tiempo
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("El trabajo tom贸 %f segundos\n", elapsed); // Impresi贸n del tiempo transcurrido
}

// Definici贸n de la funci贸n para ordenar subsecuencias
void arrange(int k, int n)
{
    for (i = k; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array1[i] > array1[j])
            {
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

// Definici贸n de la funci贸n para generar n煤meros aleatorios
int generateRandom()
{
    return rand() % MAX_RANGE; // Generaci贸n de un n煤mero aleatorio dentro del rango especificado
}

/*
En el c骴igo original, la capacidad de los arreglos array y array1 estaba limitada a 100 elementos.
En el c骴igo modificado, esta capacidad se aument� significativamente a 100,000 elementos, lo que permite
manejar conjuntos de datos mucho m醩 grandes.

Se agreg� la capacidad de generar n鷐eros aleatorios en lugar de solicitar al usuario que ingrese los datos
manualmente. Esto hace que el c骴igo sea m醩 vers醫il y adecuado para pruebas con diferentes conjuntos de datos.

Se incluy� la medici髇 del tiempo de ejecuci髇 del algoritmo, lo que proporciona informaci髇 valiosa sobre el
rendimiento del programa. Esto permite evaluar la eficiencia del algoritmo de ordenamiento y compararlo con otros
en t閞minos de velocidad de ejecuci髇.
*/

