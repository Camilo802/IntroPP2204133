
Conversación abierta. 1 mensaje leído. 

Ir al contenido
Uso de Gmail con lectores de pantalla
17 de 3.655
Evaluación 1 (25%) C/C++ Procesamiento Memoria Compartida (Individual)
Recibidos

CARLOS JAIME BARRIOS HERNANDEZ
Adjuntos
18 mar 2024, 4:19 (hace 1 día)
para Carlos, SC3, SC3

Estimado Estudiante,

Se le anexa el código a realizar de acuerdo a las indicaciones que estan en el sitio: http://wiki.sc3.uis.edu.co/index.php/Introducci%C3%B3n_a_la_programaci%C3%B3n_paralela#Evaluaci.C3.B3n_1_.2825.25.29_C.2FC.2B.2B_Procesamiento_Memoria_Compartida_.28Individual.29%3A 

Tenga en cuenta que el código esta realizado en C y debe tener en cuenta, ademas de las indicaciones dadas en el sitio, los siguientes aspectos:

Debe usar bastantes datos (en el ejemplo de base, que puede encontrar en: https://www.sanfoundry.com/c-program-postman-sort-algorithm/ esta dado para usar pocos números. Use al menos 50 elementos (puede generar una porción de código que generé los datos aleatoriamente o que lea un archivo con los números por ejemplo).

Postman Sort Algorithm in C - Sanfoundry
This C Program implements Postman Sort Algorithm. Here is source code of the C Program implements Postman Sort Algorithm. The C program is successfully compiled and run on a Linux system. The program output is also shown below. /* * C Program to Implement Postman Sort Algorithm */#include <stdio.h> void arrange(int,int);int array[100], array1[100];int i, j, temp, max, ... Read more
www.sanfoundry.com


Si al compilar sale un warning debe indicar por que sale ese warning y dar o la opción de eleminarlo o lo resuelve en el código.
Puede realizar mejoras al código.
Recuerde que debe correrlo en GUANE-1 y dar las indicaciones de ejecución. Sin embargo, puede probarlo previamente en su equipo en local.
Puede usar cuaquier compilador, desde GCC hasta los otros que estan disponibles en la plataforma.
Tenga en cuenta que es una entrega individual.



Evaluación 1 (25%) C/C++ Procesamiento Memoria Compartida (Individual):
Fecha Limite de Entrega: Viernes 22 de Marzo de 2024 hasta las 9:59 (GMT - 5, Bogotá Time)

En esta primera entrega, dividida en cinco partes, tiene como objetivo evaluar las competencias adquiridas en torno a la transformación de códigos que se encuentran implementados en C/C++ para su ejecución paralela usando OpenMP. Cada uno de los estudiantes recibirá un correo electrónico personalizado que contendrá la descripción y encabezado del código recibido (en inglés principalmente), junto con el código respectivo (en .c). Este código se encuentra debidamente documentado y licenciado para su uso bajo una licencia GPL .

Este taller esta diseñado para hacerlo en 2 horas, sin embargo, tienen toda la semana para realizarlo y la entrega es hasta las 9:59 a.m. del dia viernes 22 de marzo. Recuerden que esto es la primera nota que se subirá al sistema.

La metodología para realizar la evaluación y la entrega es la siguiente:

Cree o reactive una cuenta existente en Github (puede usar cualquier nombre o pseudonimo), sin embargo tenga en cuenta que el github que usted cree es parte de sus evidencias de presentación profesional, que incluso se referencian hoy en dia en hojas de vida.
Debe vincularse a Supercomputación y Cálculo Científico de la Universidad Industrial de Santander (SC3UIS) (https://github.com/orgs/SC3UIS/teams) y dentro de SC3UIS, unirse al equipo beginners-hpc https://github.com/orgs/SC3UIS/teams/beginners-hpc
Una vez asociados, deberán crear un repositorio (carpeta) de la siguiente manera: IntroPP<Código de Estudiante>, asi, si por ejemplo su código de estudiante es 941108, el repositorio será IntroPP941108.
Dentro de ese repositorio crear un repositorio adicional que se llame OpenMP
Es recomendable por cada nuevo repositorio que genere, crear un README explicando que contiene allí.
Y en ese repositorio deberán subir los archivos relacionados con la entrega, que básicamente son (5) cinco:
Archivo con el código original en C o C++
Archivo con el nuevo código en OpenMP (que llamaran omp_<nombre_codigo_fuente_original>.c (Si el código fuente que recibieron por ejemplo se llama transform3.c, el código nuevo que subirán allí se llamara omp_transform3.c). Como es obvio el código fuente que recibirán es en C o C++.
Archivo sbatch para la corrida en GUANE-1 (BONUS). Igual si su código se llama omp_transform el sbatch se llamara transform.sbatch.
Archivo Readme, en no mas de diez lineas deben explicar con sus palabras y en español que hace el código, deben muestrar las opciones de compilación y de corrida (pueden realizar la compilación en gcc o icc). En ese archivo deben colocar como se ejecuta en local (en sus maquinas) y como se ejecuta en GUANE-1.
Archivo de salida que llamarán output_<nombre_codigo_openmp>.txt, entonces si su código se llama omp_transform.c su archivo de salida se llamara output_transform.txt
Para el código recibido, deben realizar una versión en OpenMP de acuerdo a los fundamentos vistos en clase y los que consulten en la bibliografía relacionada. El nuevo código que realicen lo deben igualmente documentar, manteniendo el estilo de la documentación, por ejemplo:
/*

  Purpose:

    TRANSFORM is an example of a transformation of an EDP using some parameters for Intro PP Students.

  Example:

    31 May 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2003

  Author:
  George 
  OpenMP Modification:
  27 July 2020 by Levy Rincon, Universidad Industrial de Santander levy.rincon@correouis.edu.co                   
  This OpenMP Modification makes a parallelization of the original Code...  
*/
(Tengan en cuenta solo deben adicionar una sección de su modificaciones, explicando brevemente que es lo que hace, puede hacerlo en inglés (recomendado) o en español)

Nota importante: usted puede realizar modificaciones al código recibido originalmente, por supuesto debe explicar esas modificaciones y por qué las hace de acuerdo a la versión original. Puede subir el archivo original dado, pero no olvide colocar en los comentarios el autor y de donde fue seleccionado.

3. Como se dijo inicialmente y por eso se insiste, deben documentar en el cuerpo de su código fuente las variaciones que ustedes hagan. Pueden hacerlo en español (pero se recomienda tratar de hacerlo en inglés).

4. Los mismos (5) cinco archivos igualmente MAS EL ARCHIVO EJECUTABLE, con las mismas condiciones deben ser colocados dentro de su carpeta personal en la plataforma de SC3UIS y su cuenta asociada a GUANE-1 (ver el punto 1.), en otras palabras, cree una carpeta llamada OpenMP. En total son seis archivos en su repositorio en GUANE-1.

5. Finalmente deben enviar la dirección del enlace donde podrá verse su entrega al correo del profesor con copia a la cuenta de soporte de SC3UIS sc3.soporte(-@-)uis.edu.co hasta la fecha y hora limite escrita en el encabezado. En el cuerpo del correo deben colocar su código de estudiante, nombre completo y las indicaciones para acceder a su espacio en Github.

Es posible que encuentren soluciones de los problemas dados ya implementadas en OpenMP (de hecho, todos los problemas tienen ya solución paralela), por lo que pueden usarla como guía (no solo se limiten a copiar y pegar), entender lo que hace ya paralelizado y deben enviar SU SOLUCIÓN con las condiciones dadas. Aleatoriamente se preguntará de manera aleatoria acerca de los desarrollos en la sesión del martes 1 de diciembre. Por lo que una explicación del código y las decisiones tomadas debe tenerse lista.

NOTA IMPORTANTE: NO DUDE EN COMUNICARSE CON NOSOTROS (sc3.operaciones(-@-)uis.edu.co , sc3.soporte(-@-)uis.edu.co con copia a la cuenta del profesor) por email, si tiene problemas de acceso y ejecución relacionadas con la plataforma únicamente. Para preguntas relacionadas con el desarrollo de la entrega o sobre el curso, solamente a la cuenta de email del profesor.

Recomendaciones:

Si usa chatGPT o alguna de las aplicaciones de IA, debe indicarlo y lo importante es que usted entienda que fué lo que hizo y por qué. En la primera sesión posterior a la evaluación, se realizará una sustentación oral de su solución de manera aleatoria que modificaría la nota.
Lea cuidadosamente el texto dado para que efectivamente responda lo que se le esta diciendo que haga.
Puede haber un bonus si usa las máquinas EXA. (SMExa o EXADell).
Cordialmente,

Carlos J. BARRIOS HERNADEZ.




________________________________________________

Carlos Jaime Barrios Hernández, PhD.

Associate Professor 

Informatics and Systems Engineering School

Universidad Industrial de Santander

Bucaramanga, Colombia

https://orcid.org/0000-0002-3227-8651



 1 archivo adjunto
•  Analizado por Gmail
carlos jaime. Pulsa el tabulador para insertarlo.
/* 
 * C Program to Implement Postman Sort Algorithm
 */
#include <stdio.h>
 
void arrange(int,int);
int array[100], array1[100];
int i, j, temp, max, count, maxdigits = 0, c = 0;
 
void main()
{
    int t1, t2, k, t, n = 1;
 
    printf("Enter size of array :");
    scanf("%d", &count);
    printf("Enter elements into array :");
    for (i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
        array1[i] = array[i];            
    }
    for (i = 0; i < count; i++)
    {
        t = array[i];        /*first element in t */
        while(t > 0)
        {
            c++;
            t = t / 10;        /* Find MSB */
        }
        if (maxdigits < c) 
            maxdigits = c;   /* number of digits of a each number */
        c = 0;
    }
    while(--maxdigits) 
        n = n * 10;      
 
    for (i = 0; i < count; i++)
    {
        max = array[i] / n;        /* MSB - Dividnng by perticular base */
        t = i;
        for (j = i + 1; j < count;j++)    
        {
            if (max > (array[j] / n))
            {
                max = array[j] / n;   /* greatest MSB */
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
    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++);
                arrange(i, j);
            i = j;
        }
        n = n / 10;
    }
    printf("\nSorted Array (Postman sort) :");    
    for (i = 0; i < count; i++)
        printf("%d ", array1[i]);
    printf("\n");
}
 
/* Function to arrange the of sequence having same base */
void arrange(int k,int n)
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
PostmanSort.c
Mostrando PostmanSort.c.
