#include "cola.h"

int ponerEnCola (t_cola *p , const t_info *d)
{
    t_nodo *nue ;
    nue = (t_nodo *)malloc(sizeof(t_nodo)) ;
    if(nue == NULL)
        return 0 ;

    nue->info = *d ;
    if( *p == NULL )
        nue->sig = nue ;
    else
    {    nue->sig = (*p)->sig ;
        (*p)->sig = nue ;
    }
    *p = nue ;

    return 1 ;
}

int sacarDeCola (t_cola *p , t_info *d)
{
    t_nodo *aux ;

    if(*p == NULL)
        return 0 ;

    aux = (*p)->sig ;
    *d = aux->info ;
    if(aux == aux->sig)
       *p = NULL ;
    else
        (*p)->sig = aux->sig ;

    free(aux) ;

    return 1 ;
}

int colaLlena (const t_cola *p)
{
    t_nodo *aux = (t_nodo*) malloc(sizeof(t_nodo)) ;
    free(aux) ;

    return aux == NULL ;
}

int colaVacia (const t_cola *p)
{
    return *p == NULL ;
}

void crearCola (t_cola *p)
{
    *p = NULL ;
}

int verPrimeroCola (const t_cola *p , t_info *d)
{
    if(colaVacia(p))
        return 0 ;

    t_nodo * aux = (*p)->sig ;
    *d = aux->info ;

    return 1 ;
}

void vaciarCola (t_cola *p)
{
    t_nodo *aux  ;

    while( *p )
    {
        aux = (*p)->sig ;
        (*p)->sig = aux->sig ;
        if(aux == aux->sig)
            *p = NULL ;
        free(aux) ;
    }
}
