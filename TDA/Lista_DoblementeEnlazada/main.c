#include "lista.h"

int main()
{
    t_lista lista ;
    t_info info ;

    crearLista(&lista) ;

    while(ingresarInfo(&info))
    {
        insertarAlFinal(&lista , &info) ;
    }
    mostrarLista(&lista) ;
/*
    printf("\ningreso dni a buscar: ") ;
    scanf("%ld" , &info.dni) ;

    if(buscarEnListaOrdenada(&lista , &info , compararXdni))
    {
        puts("esta! , info -> ") ;
        mostrarInfo(&info) ;
    }
    else
        puts("no esta gato \n") ;
*/
/*    printf("\ningreso dni a eliminar: ") ;
    scanf("%ld" , &info.dni) ;
    eliminarListarOrdenada(&lista , &info , compararXdni) ;

    mostrarLista(&lista) ;
*/  ordenarLista(&lista , compararXdni) ;
    puts("LISTA ORDENADO") ;
    mostrarLista(&lista) ;

    return 0;
}
