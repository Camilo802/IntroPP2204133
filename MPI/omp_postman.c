/*
Objetivo:

El algoritmo Postman Sort ordena un conjunto de cartas de manera que un cartero pueda entregarlas de la manera m�s$


     20 de marzo de 2024 19:00:00 p.m.

   Licencia:

    Este c�digo se distribuye bajo la licencia GNU LGPL.



   Autor:
   ChatGPT.
   Modificaci�n de OpenMP:
   20 de marzo de 2024 por Camilo Ben�tez, Universidad Industrial de Santander ybenitezmancipe@gmail.com
   La edici�n de OpenMP introduce paralelizaci�n al c�digo base.

*/


#include <stdio.h>
#include <omp.h> // Incluimos la librería de OpenMP

// Declaración de funciones
void arrange(int, int);

// Variables globales
int array[100], array1[100]; // Arreglos para almacenar los números y la copia ordenada
int i, j, temp, max, count, maxdigits = 0, c = 0; // Variables de control y temporales

int main()
{
    int t1, t2, k, t, n = 1;

    
    for (i = 0; i < count; i++)
    {
        t = array[i]; // Primer elemento en t
        while (t > 0)
        {
            c++;
            t = t / 10; // Encontramos el dígito más significativo (MSB)
        }
        #pragma omp critical // Región crítica para asegurar la correcta actualización de maxdigits
        if (maxdigits < c)
            maxdigits = c; // Número de dígitos de cada número
        c = 0;
    }

    // Cálculo del valor de n (base) para el algoritmo de ordenamiento
    while (--maxdigits)
        n = n * 10;

    // Algoritmo principal de ordenamiento
    #pragma omp parallel for private(i, j, max, t) shared(array, array1)
    for (i = 0; i < count; i++)
    {
        max = array[i] / n; // MSB - Dividir por la base particular
        t = i;
        for (j = i + 1; j < count; j++)
        {
            if (max > (array[j] / n))
            {
                max = array[j] / n; // MSB más grande
                t = j;
            }
        }
        // Intercambio de elementos en ambos arreglos
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }

    // Algoritmo adicional para ordenar elementos con la misma base
    while (n >= 1)
    {
        #pragma omp parallel for private(i, j, t1) shared(array, array1)
        for (i = 0; i < count;i++)
        {
            t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++);
            arrange(i, j); // Llamamos a la función arrange para ordenar
            i = j;
        }
        n = n / 10;
    }

    // Impresión del arreglo ordenado
    printf("\nSorted Array (Postman sort) :");
    for (i = 0; i < count; i++)
        printf("%d ", array1[i]);
    printf("\n");

    return 0;
}

/* Función para ordenar secuencias con la misma base */
void arrange(int k, int n)
{
    for (i = k; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array1[i] > array1[j])
            {
                // Intercambio de elementos en ambos arreglos
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

