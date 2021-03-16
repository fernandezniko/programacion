#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eliminar (char *donde , const char *que) ;

int main()
{
    char txt[] = "Algo que se me ocurrió",
         carac[] = "aeiou" ;

    puts(txt) ;
    printf("Los caracteres eliminados son: %d\n" , eliminar(txt , carac)) ;
    puts(txt) ;

    return 0;
}

int eliminar (char *donde , const char *que)
{
    int eliminados=0 ;
    char *dest=donde ,*pri=donde;

    while(*que)
    {
        while(*donde)
        {
            if(*donde==*que)
            {     ///falta ver si el que le sigue ahi que borrar tambien
                  donde++ ;
                  eliminados++ ;
            }

            *dest = *donde ;
            dest++ ;
            donde++ ;

        }
        *dest='\0' ;
        que++ ;

        donde = pri ;
        dest = pri ;

    }

    return eliminados ;
}
