#include "arbol.h"

int main()
{
    t_arbol arbol ;
    t_info info ;
    int nodos , alt ;

    crearArbol(&arbol) ;
    puts("CARGA ARBOL") ;

    while(ingresarInfo(&info))
    {
        if(ponerEnArbolRecursiva(&arbol , &info , compararXdni) == 0)
         {
            puts("duplicado gato");
            return 0;
         }
    }
/*
    puts("PRE ORDEN") ;
    preOrden(&arbol) ;
    puts("") ;
    puts("POST ORDEN") ;
    postOrden(&arbol) ;
    puts("") ;
    puts("EN ORDEN") ;
    enOrden(&arbol) ;
    puts("") ;

    printf("Nodos: %d \n" , contarNodos(&arbol)) ;
    //alt = altura(&arbol) ;
    printf("Altura: %d \n" , altura(&arbol)) ;

    if(esCompleto(&arbol))
        puts("Es completo") ;
    else
        puts("No es completo") ;
    if(esBalanceado(&arbol))
        puts("Es balanceado") ;
    if(esAvl(&arbol))
        puts("Es avl") ;

    nodos = contarNodosHastaNivel(&arbol , 2) ;
    printf("Nodos hasta nivel 2: %d\n" , nodos) ;
    //eliminarArbol(&arbol) ;
    //enOrden(&arbol) ;

    printf("nodos: %d\n" , contarNodos(&arbol)) ;

    puts("\nIngrese nodo a buscar: ") ;
    ingresarInfo(&info) ;
    if( buscarEnArbolBin(&arbol , &info ,compararXdni) )
        printf("Esta! info -> DNI: %ld\tLEGAJO: %d" , info.dni , info.legajo) ;
    else
        puts("No esta!") ;

    //puts("En orden \n") ;
    //enOrden(&arbol) ;
    //puts("\nDESPUES DE PODAR\n\n") ;

    //printf("nodos eliminados: %d\n\n" , podarArbolHastaNivelyContar(&arbol , 2)) ;
    //enOrden(&arbol) ;
    puts("") ;
    printf("solo izq: %d" , contarNodosSoloIzq(&arbol)) ;
    mostrarSoloHijoIzq(&arbol) ;
    puts("") ;
    puts("---NODOS HOJAS---\n") ;
    mostrarNodosHojas(&arbol) ;
    puts("") ;
    puts("---NODOS NO HOJAS---\n") ;
    mostrarNodosNoHojas(&arbol) ;
    puts("") ;
    printf("nodos eliminados: %d\n" , eliminarArbloYcontar(&arbol)) ;

    printf("nodos mostrados: %d" , mostrarContarHastaNivel(&arbol , 3) ) ;

    //EliminarArbol2(&arbol) ;
    //preOrden(&arbol) ;
    //podarArbolHastaNivel2(&arbol , 2) ;
    //enOrden(&arbol) ;

    printf("nodos elim: %d" , eliminarArbloYcontar(&arbol)) ;
*/

    printf("nodos hojas: %d" , contarNodosHojas(&arbol)) ;

    return 0;
}
