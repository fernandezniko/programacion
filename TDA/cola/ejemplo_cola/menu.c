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

    return opcion ;
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

char mostrarOpciones (tCola *p)
{
    char letra ;
    if(!colaLlena(p))
    {
        puts("la cola no esta llena\n") ;
        letra = menu("elija una opcion \n --------------\n\n P - Poner en cola \n V - Ver primero \n S - Sacar primero \n 0 - Para terminar \n\n:" , "PVS0") ;

    }
    if(colaVacia(p))
    {
        puts("cola vacia") ;
        letra = menu("elija una opcion \n --------------\n\n P - Poner en cola \n 0 - Para terminar \n\n:" , "P0") ;
    }
    if(colaLlena(p))
    {
        puts("cola llena") ;
        letra = menu("elija una opcion \n --------------\n\n  V - Ver primero \n S - Sacar primero \n 0 - Para terminar \n\n:" , "P0") ;
    }
    puts("") ;
    return toupper(letra) ;
}
