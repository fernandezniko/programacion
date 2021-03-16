#include "cola.h"

void crearCola (t_cola *p)
{
    p->pri = 0 ;
    p->ult = -1 ;
    p->cargados = 0 ;

}

void vaciarCola (t_cola *p)
{
    p->cargados = 0 ;
    p->pri = 0 ;
    p->ult = -1 ;
}

int colaLlena (const t_cola *p)
{
    return p->cargados == TAM_COLA ;
}

int colaVacia (const t_cola *p)
{
    return p->cargados == 0 ;
}

int ponerEnCola (t_cola *p , const t_info *d)
{
    if(p->cargados == TAM_COLA)
        return 0 ;

    p->ult++ ;
    if(p->ult == TAM_COLA)
        p->ult = 0 ;
    p->cola[p->ult] = *d ;
    p->cargados++ ;

    return 1 ;
}

int sacarDeCola (t_cola *p , t_info *d)
{
    if(p->cargados == 0)
        return 0 ;

    *d = p->cola[p->pri] ;
    p->pri++ ;
    if(p->pri == TAM_COLA)
        p->pri = 0;
    p->cargados -- ;

    return 1 ;
}

int verPrimeroCola (const t_cola *p , t_info *d)
{
    if(p->cargados == 0)
        return 0 ;
    *d = p->cola[p->pri] ;

    return 1 ;
}

/*
void crearCola(t_cola *p)
{
    p->cargados = 0 ;
    p->pri = 0 ;
    p->ult = -1 ;
}

void vaciarCola(t_cola *p)
{
    p->cargados = 0 ;
    p->pri = 0 ;
    p->ult = -1 ;
}

int colaLlena(const t_cola *p)
{
    return p->cargados == TAM_COLA ;
}

int colaVacia(const t_cola *p)
{
    return p->cargados == 0 ;
}

int verPrimeroCola(const t_cola *p , t_info *d)
{
    if(p->cargados == 0)
        return 0 ;
    *d = p->cola[p->pri] ;
    return 1 ;
}

int ponerEnCola(t_cola *p , const t_info *d)
{
    if(p->cargados == TAM_COLA)
        return 0 ;
    p->cargados ++ ;
    p->ult ++ ;
    if(p->ult == TAM_COLA)
        p->ult = 0 ;
    p->cola[p->ult] = *d ;

    return 1 ;
}

int sacarDeCola(t_cola *p , t_info *d)
{
    if(p->cargados == 0)
        return 0 ;

    p->cargados -- ;
    *d = p->cola[p->pri] ;
    p->pri ++ ;
    if(p->pri == TAM_COLA)
        p->pri = 0 ;

    return 1 ;
}
*/
