
/*
 * Programa C para implementar el algoritmo de clasificaci�n de cartero#include <stdio.h>
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrange(int, int); // Declaración de la función para ordenar subsecuencias
int array[100000], array1[100000]; // Declaración de los arreglos globales
int i, j, temp, max, count = 100000, maxdigits = 0, c = 0; // Declaración de variables globales
double start, end; // Declaración de variables de tiempo
const int MAX_RANGE = 999999; // Declaración de una constante para el rango máximo de números aleatorios

int generateRandom(); // Declaración de la función para generar números aleatorios

void main()
{
    struct timespec start, finish; // Declaración de estructuras para medir el tiempo
    double elapsed; // Variable para almacenar el tiempo transcurrido
    int n = 1; // Inicialización de la variable n
    int t;     // Declaración de la variable t

    clock_gettime(CLOCK_MONOTONIC, &start); // Inicio del contador de tiempo

    srand(time(NULL)); // Inicialización de la semilla para generar números aleatorios
    for (int i = 0; i < count; i++)
    {
        array1[i] = generateRandom(); // Llenado del arreglo con números aleatorios
        array[i] = array1[i];
    }

    // Cálculo del número máximo de dígitos de los números en el arreglo
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

    // Determinación del valor de n para el ordenamiento por el algoritmo de Postman
    while (--maxdigits)
        n = n * 10;

    // Ordenamiento inicial por el dígito más significativo
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
        // Intercambio de elementos en ambos arreglos según el ordenamiento por dígitos
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }

    // Ordenamiento final de las subsecuencias de números con el mismo dígito más significativo
    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            int t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++)
                arrange(i, j); // Llamada a la función para ordenar subsecuencias
            i = j;
        }
        n = n / 10;
    }

    clock_gettime(CLOCK_MONOTONIC, &finish); // Fin del contador de tiempo
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("El trabajo tomó %f segundos\n", elapsed); // Impresión del tiempo transcurrido
}

// Definición de la función para ordenar subsecuencias
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

// Definición de la función para generar números aleatorios
int generateRandom()
{
    return rand() % MAX_RANGE; // Generación de un número aleatorio dentro del rango especificado
}

/*
En el c�digo original, la capacidad de los arreglos array y array1 estaba limitada a 100 elementos.
En el c�digo modificado, esta capacidad se aument� significativamente a 100,000 elementos, lo que permite
manejar conjuntos de datos mucho m�s grandes.

Se agreg� la capacidad de generar n�meros aleatorios en lugar de solicitar al usuario que ingrese los datos
manualmente. Esto hace que el c�digo sea m�s vers�til y adecuado para pruebas con diferentes conjuntos de datos.

Se incluy� la medici�n del tiempo de ejecuci�n del algoritmo, lo que proporciona informaci�n valiosa sobre el
rendimiento del programa. Esto permite evaluar la eficiencia del algoritmo de ordenamiento y compararlo con otros
en t�rminos de velocidad de ejecuci�n.
*/

