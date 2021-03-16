#include <stdio.h>

int main()
{
    /*    printf("El tamaño de short (entero corto), es: %d\n", sizeof(short));
        printf("El tamaño de int (entero), es: %d\n", sizeof(int));
        printf("El tamaño de long (entero largo), es: %d\n", sizeof(long));
    */

    /*
    int j, k;
    int *ptr;

    j = 1;
    k = 2;
    ptr = &k;
    printf("\n");
    printf("j tiene el valor: %d y esta alojado en: %p\n", j, (void *)&j);
    printf("k tiene el valor: %d y esta alojado en: %p\n", k, (void *)&k);
    printf("ptr tiene el valor: %p y esta alojado en: %p\n", ptr, (void *)&ptr);
    printf("El valor del entero al que apunta ptr es: %d\n", *ptr);
    */


    int mi_arreglo[] = {1,23,17,4,-5,100};
    int *ptr;

    int i;
    ptr = &mi_arreglo[0]; //ptr = mi_arreglo /* apuntamos nuestro puntero al primer elemento del arreglo*/
    printf("\n\n");
    for (i = 0; i < 6; i++)
    {
        printf("mi_arreglo[%d] = %d ", i, mi_arreglo[i]); /*<-- A */
        printf("ptr + %d = %d\n",i, *(ptr + i)); /*<-- B */
        //printf ("ptr + %d = %d\n", i, *ptr++);
        //printf("ptr + %d = %d\n", i, *(++ptr));
    }


    return 0 ;
}
