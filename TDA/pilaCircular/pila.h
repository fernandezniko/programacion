#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEMORIA 0
#define PILA_VACIA 2

typedef struct
{
    int dni ;
}t_info ;

typedef struct s_nodo
{
    t_info info ;
    struct s_nodo *sig ;
}t_nodo ;

typedef t_nodo * t_pila ;

int ponerEnPila (t_pila *p , const t_info *d) ;
int sacarDePila (t_pila *p , t_info *d) ;

void crearPila (t_pila *p) ;
void vaciarPila (t_pila *p) ;

int pilaLlena (const t_pila *p) ;
int pilaVacia (const t_pila *p) ;

int verTopePila (const t_pila *p , t_info *d) ;

#endif // PILA_H_INCLUDED
