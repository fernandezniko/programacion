#include "pila.h"

void crearPila(t_pila *p)
{
    p->tope = 0 ;
}

void vaciarPila(t_pila *p)
{
    p->tope = 0 ;
}

int pilaLlena(const t_pila *p)
{
    return p->tope == TAM ;
}

int pilaVacia(const t_pila *p)
{
    return p->tope == 0 ;
}

int verTopePila(const t_pila *p , t_info *d)
{
    if(p->tope == 0)
        return 0 ;

    *d = p->vecPila[p->tope-1] ;

    return 1 ;
}

int ponerEnPila(t_pila *p , const t_info *d)
{
   if(p->tope == TAM)
        return 0 ;

   p->vecPila[p->tope] = *d ;
   p->tope ++ ;

   return 1 ;
}

int sacarDePila(t_pila *p , t_info *d)
{
    if(p->tope == 0)
        return 0 ;

    p->tope -- ;
    *d = p->vecPila[p->tope] ;


    return 1 ;
}


















/*
void crearPila(t_pila *p)
{
    p->tope = 0 ;
}

int vaciarPila(t_pila *p)
{
    p->tope = 0 ;
}

int pilaLlena(const t_pila *p)
{
    return p->tope == TAM ;
}

int pilaVacia(const t_pila *p)
{
    return p->tope == 0 ;
}

int verTopePila(const t_pila *p , t_info *d)
{
    if(p->tope == 0)
        return 0 ;
    *d = p->vecPila[p->tope-1] ;
    return 1 ;
}

int ponerEnPila(t_pila *p , const t_info *d)
{
    if(p->tope == TAM)
        return 0 ;
    p->vecPila[p->tope] = *d ;
    p->tope ++ ;

    return 1 ;
}

int sacarDePila(t_pila *p , t_info *d)
{
    if(p->tope == 0)
        return 0 ;

    *d = p->vecPila[p->tope-1] ;
    p->tope -- ;
    return 1 ;
}
*/
