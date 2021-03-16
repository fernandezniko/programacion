#include "lista.h"
#include "archivo.h"

int main()
{
    t_lista lista ;
    t_info info ;
    FILE *fp ;
    int nodos , nodosDup;

///    if(!abrirArchivo(&fp , "datosLista" , "rb" , 1))
///        return 2 ;

    crearLista(&lista) ;

    while( ingresarInfo(&info) )
    {
        insertarAlFinal(&lista , &info ) ;
    }
/*
    nodos = contarMostrarYeliminar(&lista , mostrarInfo , fp) ;
    if(nodos)
        printf("La cantidad de nodos son: %d\n" , nodos) ;
    else
        puts("No hay nodos..\n") ;

    mostrarArchivo(fp) ;
*/  mostrarLista(&lista) ;
    puts("ordenada ") ;
    ordenarLista(&lista , compararXlegajo) ;
    mostrarLista(&lista) ;

/*
    nodosDup = eliminarDupListaOrd(&lista , compararXlegajo , acumularImporte) ;

    if(nodosDup)
        printf("La cantidad de nodos duplicados eliminados son: %d\n" , nodosDup) ;
    else
        puts("No hay nodos \n") ;

    mostrarLista(&lista) ;
*/
    return 0;
}
