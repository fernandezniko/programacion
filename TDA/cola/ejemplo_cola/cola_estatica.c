#include "cola_estatica.h"

void crearCola (tCola *p)
{
    p->pri = 0 ;
    p->ult = -1 ;
    p->cargados = 0 ;

}

void vaciarCola (tCola *p)
{
    p->cargados = 0 ;
    p->pri = 0 ;
    p->ult = -1 ;
}

int colaLlena (const tCola *p)
{
    return p->cargados == TAM_COLA ;
}

int colaVacia (const tCola *p)
{
    return p->cargados == 0 ;
}

int ponerEnCola (tCola *p , const tInfo *d)
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

int sacarDeCola (tCola *p , tInfo *d)
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

int verPrimeroCola (const tCola *p , tInfo *d)
{
    if(p->cargados == 0)
        return 0 ;
    *d = p->cola[p->pri] ;

    return 1 ;
}
