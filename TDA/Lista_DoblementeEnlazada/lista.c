#include "lista.h"

void crearLista (t_lista *p)
{
    *p = NULL ;
}

int listaVacia (const t_lista *p)
{
    return (*p) == NULL ;
}

int listaLlena(const t_lista *p)
{
    t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo)) ;
    free(aux) ;
    return aux == NULL ;
}

int insertarEnOrden (t_lista *p , const t_info *d , int(*comparar)(const t_info * , const t_info *))
{
    t_nodo *actual , *ant , *sig , *nuevo;

    actual = *p ;

    if(actual)
    {
        while(actual->sig && comparar(d , &actual->info) > 0)
            actual = actual->sig ;

        while(actual->ant && comparar(d , &actual->info) < 0)
            actual = actual->ant ;


        if(comparar(d , &actual->info) == 0)
            return DUPLICADO ;
    }

    if(actual)
    {
        if(comparar(d , &actual->info) > 0)
        {
            ant = actual ;
            sig = ant->sig ;
        }
        else
        {
            ant = actual->ant ;
            sig = actual ;
        }
    }
    else
    {
        ant = NULL ;
        sig = NULL ;
    }

    nuevo = (t_nodo *)malloc(sizeof(t_nodo)) ;
    if(nuevo == NULL)
        return SIN_MEMORIA ;

    nuevo->info = *d ;
    nuevo->ant = ant ;
    nuevo->sig = sig ;

    if(ant)
        ant->sig = nuevo ;
    if(sig)
        sig->ant = nuevo ;

    (*p) = nuevo ;

    return 1 ;

}

int insertarAlFinal(t_lista *p , const t_info *d)
{
    t_nodo *actual = *p , *nue;

    if(listaLlena(p))
        return 0 ;

    nue = (t_nodo *)malloc(sizeof(t_nodo)) ;
    if(nue == NULL)
        return 0 ;
    nue->info = *d ;

    if(actual)
    {
        while(actual->sig)
            actual = actual->sig ;

        nue->sig = NULL ;
        nue->ant = actual ;
        actual->sig = nue ;
    }
    else
    {
        nue->sig = NULL ;
        nue->ant = NULL ;
    }

    (*p) = nue ;

    return 1 ;
}

int insertarAlInicio (t_lista *p , const t_info *d)
{
    t_nodo *actual = *p , *nue ;

    if(listaLlena(p))
        return 0 ;

    nue = (t_nodo *)malloc(sizeof(t_nodo)) ;
    if(nue == NULL)
        return SIN_MEMORIA ;

    nue->info = *d ;

    if(actual)
    {
        while(actual->ant)
            actual = actual->ant ;

        nue->sig = actual ;
        nue->ant = actual->ant ;
        actual->ant = nue ;
    }
    else
    {
        nue->sig = NULL ;
        nue->ant = NULL ;
    }
    (*p) = nue ;

    return 1 ;
}

void mostrarLista (const t_lista *p)
{
    t_nodo *actual = *p ;

    if(listaVacia(p))
        return ;

    while( actual->ant )
    {
        actual = actual->ant ;
    }

    while(actual)
    {
        mostrarPers(&actual->info) ;
        actual = actual->sig ;
    }
    //mostrarPers(&actual->info) ;
}

int buscarEnListaOrdenada (const t_lista *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2))
{
    t_nodo *actual = *p ;

    if(listaVacia(p))
        return 0 ;

    while(actual->sig && comparar(d , &actual->info) > 0)
        actual = actual->sig ;

    while(actual->ant && comparar(d , &actual->info) < 0)
        actual = actual->ant ;

    if(comparar(d ,&actual->info) == 0)
            *d = actual->info ;
    else
        return 0 ;

    return 1 ;
}

int eliminarListaOrdenada (t_lista *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2))
{
    t_nodo *actual=*p , *aux ;

    if(listaVacia(p))
        return 0 ;

    while(actual->sig && comparar(&actual->info , d) > 0)
        actual = actual->ant ;

    while(actual->ant && comparar(&actual->info , d) < 0)
        actual = actual->sig ;

    if(comparar(&actual->info , d) == 0)
    {
        aux = actual ;

        if(aux->ant)
            aux->ant->sig = aux->sig ;
        if(aux->sig)
            aux->sig->ant = aux->ant ;

        *d = aux->info ;
        free(aux) ;

        return 1 ;
    }

    return 0 ;
}
 /*
void ordenarLista (t_lista *p , int(*comparar)(const t_info *d1 , const t_info *d2)) ///INTERCAMBIANDO LA INFORMACION
{
    t_nodo *actual = *p ;
    int marca = 1 ;
    t_info info ;
    t_lista *q ;

    if(listaVacia(p))
        return ;

    while(actual->ant)
        actual = actual->ant ;

    while(marca)
    {
        marca = 0 ;
        q = &actual ;

        while((*q)->sig)
        {
            if(comparar(&(*q)->info , &(*q)->sig->info) > 0)
            {
                marca = 1 ;
                info = (*q)->info ;
                (*q)->info = (*q)->sig->info ;
                (*q)->sig->info = info ;

            }

            q = &(*q)->sig ;
        }
    }

}
 */
void ordenarLista (t_lista *p , int(*comparar)(const t_info *d1 , const t_info *d2))
{
    t_lista *q , *principio;
    t_nodo *actual = *p , *ant , *sig , *aux , *sigsig;
    int marca = 1 ;

    while(actual->ant)
        actual = actual->ant ;

    principio = &actual ;

    while(marca)
    {
        marca = 0 ;

        q = principio ;

        while((*q)->sig)
        {
            if(comparar(&(*q)->info , &(*q)->sig->info) > 0)
            {
                marca = 1 ;
                aux = *q ;
                (*q) = aux->sig ;
                ant = aux->ant ;
                sig = aux->sig ;
                sigsig = sig->sig ;

                sig->ant = ant ;
                sig->sig = aux ;

                aux->ant = sig ;
                aux->sig = sigsig ;

                if(ant)
                    ant->sig = sig ;
                if(sigsig)
                    sigsig->ant = aux ;
            }

             q = &(*q)->sig ;
        }
    }

}

int compararXdni (const t_info *d1 , const t_info *d2)
{
    if(d1->dni > d2->dni)
        return 1 ;
    if (d1->dni < d2->dni)
        return -1 ;
    return 0 ;
}

