#include "pila.h"

void crearPila (t_pila *p)
{
    *p = NULL ;
}


int ponerEnPila (t_pila *p , const t_info *d)
{
    t_nodo *nue = (t_nodo *)malloc(sizeof(t_nodo)) ;
    if(nue == NULL)
        return SIN_MEMORIA ;

    if(*p == NULL)
    {
        nue->sig = nue ;
        (*p) = nue ;
    }
    else
    {
       nue->sig = (*p)->sig ;
       (*p)->sig = nue ;
    }
    nue->info = *d ;

    return 1 ;
}

int sacarDePila (t_pila *p , t_info *d)
{
    t_nodo *aux ;
    if(*p == NULL)
        return PILA_VACIA ;

    aux = (*p)->sig ;
    if(aux == aux->sig)
    {
        *p = NULL ;

    }
    else
    {
        (*p)->sig = aux->sig ;

    }
    *d = aux->info ;
    free(aux) ;

    return 1 ;
}

int pilaLlena (const t_pila *p)
{
    t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo)) ;
    free(aux) ;
    return aux == NULL ;
}

int pilaVacia (const t_pila *p)
{
    return *p == NULL ;
}

int verTopePila (const t_pila *p , t_info *d)
{
    if(*p == NULL)
        return PILA_VACIA ;
    *d = (*p)->sig->info ;

    return 1 ;
}

void vaciarPila (t_pila *p)
{
    t_nodo *aux ;
    while(*p)
    {
        aux = (*p)->sig ;
        (*p)->sig = aux->sig ;
        if(aux == aux->sig)
            *p = NULL ;

        free(aux) ;
    }
}
