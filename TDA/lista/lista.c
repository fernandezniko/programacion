#include "lista.h"

void crearLista (t_lista *p)
{
    *p = NULL ;
}

int listaLlena (const t_lista *p)
{
    t_nodo *aux = (t_nodo *)malloc(sizeof(t_nodo)) ;
    free(aux) ;
    return aux == NULL ;
}

int insertarAlComienzo (t_lista *p , const t_info *d)
{
    t_nodo *nue = (t_nodo *)malloc(sizeof(t_nodo)) ;
    if(nue == NULL)
        return 0 ;
    nue->info = *d ;
    nue->sig = *p ;
    *p = nue ;

    return 1;
}

int insertarAlFinal (t_lista *p , const t_info *d)
{
    while( *p )
        p = &(*p)->sig ;
    *p = (t_nodo *)malloc(sizeof(t_nodo)) ;
    if(*p == NULL)
        return 0 ;

    (*p)->info = *d ;
    (*p)->sig = NULL ;

    return 1 ;
}

int insertarEnOrden (t_lista *p , const t_info *d , int(*comparar)(const t_info * , const t_info *) , void(*acumular)(t_info *, const t_info *))
{
    t_nodo *nue ;

    while( *p && comparar(&(*p)->info , d) < 0 )
        p = &(*p)->sig ;
    if (*p && comparar(&(*p)->info , d) == 0)
    {
        acumular(&(*p)->info , d) ;
        return CLA_DUPLICADA ;
    }
    nue = (t_nodo *)malloc(sizeof(t_nodo)) ;
    if(nue == NULL)
        return 0 ;

    nue->info = *d ;
    nue->sig = *p ;
    *p = nue ;

    return 1 ;
}

void ordenarLista (t_lista *p , int(*comparar)(const t_info * , const t_info *))
{
    t_lista *q ;
    t_nodo *aux ;
    int marca = 1 ;

    if(*p)
    {
        while(marca)
        {
            marca = 0 ;
            q=p ;
            while((*q)->sig)
            {
                if(comparar(&(*q)->info , &(*q)->sig->info) > 0)
                {
                    marca = 1 ;
                    aux = *q ;
                    (*q) = aux->sig ;
                    aux->sig = (*q)->sig ;
                    (*q)->sig = aux ;
                }
                q = &(*q)->sig ;
            }
        }
    }
}

int contarMostrarYeliminar(t_lista *p , void(*mostrar)(const t_info *) , FILE *fp)
{
    t_nodo *aux ;
    int cont=0 ;

    while(*p)
    {
        aux = *p ;
        *p = aux->sig ;
        cont ++ ;
        mostrar(&aux->info) ;
        fwrite(&aux->info , sizeof(t_info),1,fp) ;
        free(aux) ;
    }
    return cont ;
}

int buscarYrecuperarListaNoOrd (const t_lista *p , t_info *d , int(*comparar)(const t_info * , const t_info *))
{
    while(*p && comparar(d , &(*p)->info) != 0)
        p = &(*p)->sig ;

    if(*p == NULL)
        return 0 ;
    *d = (*p)->info ;

    return 1 ;
}

int buscarRecuperarListaNoOrdYeliminar (t_lista *p , t_info *d , int(*comparar)(const t_info * , const t_info *))
{
    t_nodo *aux ;

    while(*p && comparar(d , &(*p)->info) != 0)
        p = &(*p)->sig ;

    if(*p == NULL)
        return 0 ;

    aux = *p ;
    *p = aux->sig ;
    *d = aux->info ;
    free(aux) ;

    return 1 ;
}

int buscarYrecuperarListaOrd (const t_lista *p , t_info *d , int(*comparar)(const t_info * , const t_info *))
{
    while(*p && comparar(d , &(*p)->info) > 0)
        p = &(*p)->sig ;

    if(*p || comparar(d , &(*p)->info) != 0)
        return 0 ;

    *d = (*p)->info ;

    return 1 ;
}

int buscarRecuperarListaOrdYeliminar (t_lista *p , t_info *d , int(*comparar)(const t_info * , const t_info *))
{
    t_nodo *aux ;

    while(*p && comparar(d , &(*p)->info))
        p = &(*p)->sig ;

    if(*p || comparar(d , &(*p)->info) != 0)
        return 0 ;

    aux = *p ;
    *d = aux->info ;
    *p = aux->sig ;
    free(aux) ;

    return 1 ;
}

int eliminarDupListaOrd(t_lista *p , int(*comparar)(const t_info * , const t_info *) , void(*acumular)(t_info * , const t_info *) )
{
    t_nodo *aux ;
    int cantot=0 , cantdup ;

    while( *p )
    {
        cantdup = 0 ;

        while( (*p)->sig && comparar(&(*p)->info , &(*p)->sig->info ) == 0 )
            {
                cantdup++ ;
                aux = (*p)->sig ;
                (*p)->sig = aux->sig ;
                if(acumular)
                    acumular(&(*p)->info , &aux->info) ;
                free(aux) ;
            }

            p = &(*p)->sig ;
            cantot += cantdup ;
    }
    return cantot ;
}

int eliminarTodosDupListaOrd(t_lista *p , int(*comparar)(const t_info * , const t_info *) , void(*acumular)(t_info * , const t_info *) , int elimTodos)
{
    t_nodo *aux ;
    int cantdup , cantot=0 ;

    while(*p)
    {
        cantdup = 0 ;
        while((*p)->sig && comparar(&(*p)->info , &(*p)->sig->info ) == 0)
        {
            cantdup ++ ;
            aux = (*p)->sig ;
            (*p)->sig = aux->sig ;
            if(acumular)
                acumular(&(*p)->info , &aux->info) ;
            free(aux) ;
        }
        if(cantdup && elimTodos == EliminarTodos)
        {
            cantdup ++ ;
            aux = *p ;
            *p = aux->sig ;
            free(aux) ;
        }
        else
            p = &(*p)->sig ;

        cantot += cantdup ;

    }

    return cantot ;
}

int eliminarDupListaNoOrd(t_lista *p , int(*comparar)(const t_info * , const t_info * ), void(*acumular)(t_info * , const t_info *))
{
    t_lista *q ;
    t_nodo *aux ;
    int cantot=0 , cantdup ;

    while( *p )
    {
        q = &(*p)->sig ;
        cantdup = 0 ;

        while(*q)
        {
            if(comparar(&(*p)->info , &(*q)->info) == 0)
            {
                cantdup ++ ;
                aux = *q ;
                *q = aux->sig ;
                if(acumular)
                    acumular(&(*p)->info , &(*q)->info) ;
                free(aux) ;
            }
            else
                q = &(*q)->sig ;
        }
        p = &(*p)->sig ;
        cantot += cantdup ;
    }

    return cantot ;
}

int eliminarTodosDupListaNoOrd(t_lista *p , int(*comparar)(const t_info * , const t_info *) , void(*acumular)(t_info * , const t_info *) , int elimTodos)
{
    t_lista *q ;
    t_nodo *aux ;
    int cantot=0 , cantdup ;

    while( *p )
    {
        q = &(*p)->sig ;
        cantdup = 0 ;

        while(*q)
        {
            if(comparar(&(*p)->info , &(*q)->info) == 0)
            {
                cantdup ++ ;
                aux = *q ;
                *q = aux->sig ;
                if(acumular)
                    acumular(&(*p)->info , &(*q)->info) ;
                free(aux) ;
            }
            else
                q = &(*q)->sig ;
        }
        if(cantdup && elimTodos == EliminarTodos)
        {
            aux = *p ;
            *p = aux->sig ;
            free(aux) ;
            cantdup++ ;
        }
        else
            p = &(*p)->sig ;

        cantot += cantdup ;
    }

    return cantot ;
}

void mostrar_info (const t_info *d)
{

    printf("DNI : %ld\n", d->dni) ;

    printf("Apellido(s), Nombre(s): %s\n", d->apyn ) ;

    printf("Sexo (M/F): %c\n", d->sex);

    printf("Fecha (dd/mm/aaa): %d/%d/%d\n", d->fec.d, d->fec.m, d->fec.a ) ;

    printf("Importe: %.2f\n", d->importe ) ;

    printf("Legajo: %d\n" , d->legajo) ;

    puts("") ;
}

void mostrarLista(t_lista *p)
{
    t_info info ;
    while(*p)
    {
        info = (*p)->info ;
        ///mostrarInfo(&info) ;
        mostrar_info(&info) ;
        p = &(*p)->sig ;
    }
}

int compararXdni (const t_info *d1 , const t_info *d2)
{
    if(d1->dni > d2->dni)
        return 1 ;
    if(d1->dni < d2->dni)
        return -1 ;
    return 0 ;
}

int compararXlegajo (const t_info *d1 , const t_info *d2)
{
    if(d1->legajo > d2->legajo)
        return 1 ;
    if (d1->legajo < d2->legajo)
        return -1 ;
    return 0 ;
}

void acumularImporte (t_info *d1 , const t_info *d2)
{
    d1->importe += d2->importe ;
}

void recorreerLista (t_lista *p , void(*grabar)(t_info *d1))
{
    while(*p)
    {
        grabar(&(*p)->info) ;
        p = &(*p)->sig ;
    }
}

int eliminarDeLista (t_lista *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2))
{
    t_nodo *aux ;
    while(*p && comparar(d , &(*p)->info)!=0)
        p = &(*p)->sig ;

    if(*p == NULL || comparar(d , &(*p)->info)<0)
        return 0 ;

    aux = (*p) ;
    (*p) = aux->sig ;
    *d = aux->info ;
    free(aux) ;

    return 1 ;
}
