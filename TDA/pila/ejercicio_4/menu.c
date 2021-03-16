#include "menu.h"

char menu (const char *msj , const char *opc)
{
    char opcion ;

    do
    {
        printf("%s" , msj) ;
        fflush(stdin) ;
        scanf("%c" , &opcion) ;

    } while (!strchr(opc , toupper(opcion))) ;

    return toupper(opcion) ;
}

char menu2 (const char *msj , const char *opc)
{
    char opcion ;

    printf("%s" , msj) ;
    fflush(stdin) ;
    scanf("%c" , &opcion) ;

    while ( !strchr(opc , opcion) )
    {
        puts("Error opcion - Ingrese Nuevamente") ;
        printf("%s" , msj) ;
        fflush(stdin) ;
        scanf("%c" , &opcion) ;

    }

    return opcion ;
}
