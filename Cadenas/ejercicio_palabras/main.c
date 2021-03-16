#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define esSeparador( x ) ( (x) == ' ' || (x) == '\t' )
#define esFintexto( x ) ( (x) == '.' || (x) == '\0' )

char * proxpal (const char *s) ;
char * finpalabra (const char *s) ;


int main()
{
    char texto[] = { "      Hola que tal         Hola holas holassssss" },
         *pripal,
         *finpal,
         *sigpal;

    size_t tampal , long1 , longmayor;
    int veces=0 , palabras=0 ;

    pripal = proxpal(texto) ;
    finpal = finpalabra (pripal) ;
    tampal = (size_t) (finpal - pripal) ;

    if (tampal == 0)
    {   printf("No hay texto") ;
        return 0 ;
    }

    printf("La primer palabra es: \"%.*s\"\n" , tampal , pripal) ;
    palabras += 1 ;
    sigpal = proxpal(finpal) ;
    finpal = finpalabra(sigpal) ;
    long1 = tampal ;
    longmayor = tampal ;

    while (sigpal != finpal)
    {
        palabras++ ;
        if (tampal == (size_t)(finpal - sigpal) && strnicmp(pripal , sigpal , tampal)==0 )
            veces++ ;
        if (long1 < (size_t)(finpal - sigpal))
            {longmayor = (size_t)(finpal - sigpal) ;
             long1 = longmayor ;
            }
        sigpal = proxpal(finpal) ;
        finpal = finpalabra(sigpal) ;

    }

    printf("Se repite %d veces \n" , veces) ;
    printf("La cantidad de palabras son: %d \n" , palabras) ;
    printf("Longitud palabra mas larga: %d \n" , longmayor) ;

    return 0;
}


char * proxpal (const char * s)
{
    while (esSeparador(*s))
        s++ ;

    return (char *) s ;
}

char * finpalabra (const char *s)
{
    while (!esSeparador(*s) && !esFintexto(*s))
        s++ ;

    return (char *) s ;
}


