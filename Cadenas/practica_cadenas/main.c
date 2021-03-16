#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * compactar_cadena (char* cad) ;
char * eliminar_sub (char *donde , const char *que) ;

int main()
{
    char cadena[50] ;
    char cadena2[50] ;

    puts("ingrese cadena: ") ;
    fflush(stdin) ;
    gets(cadena) ;
    puts("ingrese sub-cadena: ") ;
    fflush(stdin) ;
    gets(cadena2) ;
    //puts(cadena) ;
/*    puts("cadena compactada") ;
    compactar_cadena(cadena) ;
    puts(cadena) ;
*/  eliminar_sub(cadena , cadena2) ;
    puts(cadena) ;

    return 0;
}

///
char * compactar_cadena (char* cad)
{
    char *aux , letra ;
    int veces=0 ;
    aux = cad ;

    while(*aux)
    {
        letra = *aux ;

        while(letra == *aux)
        {
            veces++ ;
            aux++ ;
        }
        if(veces < 4)
        {
            while(veces)
             { *cad=letra ;
               cad++ ;
               veces-- ;
             }
            veces=0 ;

        }
        else
        {   *cad = '\\' ;
            cad++ ;
            cad = itoa(veces,cad,10) ;
            if(veces - 10 >= 0 )
                cad++ ;
            cad++ ;
            *cad = letra ;
            cad++ ;
            veces=0 ;
        }
    }

    *cad = '\0' ;

    return cad ;
}

char * eliminar_sub (char *donde , const char *que)
{
    char *dev = donde ,
         *dest = donde ,
         *d ;
    const char *q ;
    while( *donde )
    {
        d = donde ;
        q = que ;
        while( *d == *q && *q )
        {
            d++ ;
            q++ ;
        }
        if(*q == '\0')
            donde = d ;
        *dest = *donde ;
        dest ++ ;
        donde ++ ;
    }
    *dest = '\0' ;

    return dev ;
}
