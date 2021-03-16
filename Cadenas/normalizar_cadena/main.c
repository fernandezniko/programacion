#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM     100

char * normalizar_cadena (char *s) ;
int esLetra (char c) ;
char aMayuscula (char c) ;
char aMinuscula (char c) ;

int main()
{
    char cadena[TAM] = "   ,.,´´99hOla tODo    ,,.-'-,BIEn   ,.." ;

    normalizar_cadena(cadena) ;
    puts(cadena) ;

    return 0;
}

///
char * normalizar_cadena (char *s)
{
    char *posi , *escribir ;

    if(*s == '\0')
        return NULL ;

    posi = s ;
    escribir = s ;

    while( *posi )
    {
        while(!esLetra(*posi) && *posi)
            posi++ ;
        if(esLetra(*posi))
        {   *escribir = aMayuscula(*posi) ;
            escribir++ ;
            posi++ ;
        }
        while(esLetra(*posi))
        {
            *escribir = aMinuscula(*posi) ;
            posi ++ ;
            escribir ++ ;
        }
        if(*posi)
        {   *escribir = ' ' ;
            escribir++ ;
        }
    }
    *escribir = '\0' ;

    return s ;
}

int esLetra (char c)
{
    if( (c >= 'a' && c <= 'z') || (c>='A' && c<='Z') )
        return 1 ;
    else
        return 0 ;
}

char aMayuscula (char c)
{
    return c >= 'a' && c <= 'z' ? c += 'A' - 'a' : c ;
}

char aMinuscula (char c)
{
    return c >= 'A' && c <= 'Z' ? c += 'a' - 'A' : c ;
}
