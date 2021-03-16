#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * invertir_cadena (char *s1) ;
void intercambiar (char *c1 , char *c2) ;

int main()
{
    char cad[] = "hola" ;

    printf("cadena original: ") ;
    puts(cad) ;
    printf("cadena invertida: " ) ;
    invertir_cadena(cad) ;
    puts(cad) ;

    return 0;
}
///
void intercambiar(char *c1 , char *c2)
{
    char aux ;
    aux = *c1 ;
    *c1 = *c2 ;
    *c2 = aux ;

}
char * invertir_cadena (char *s1)
{
    char *pri , *fin ;
    pri = s1 ;
    fin = s1 + strlen(s1) -1  ;

    while(pri < fin)
    {
       intercambiar(pri , fin) ;
       pri ++ ;
       fin -- ;
    }
    return s1 ;
}
