#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "persona.h"

#define ingresarInfo    ingresarPers
#define mostrarInfo     mostrarPers

typedef t_pers  t_info ;

typedef struct s_nodo
{
    t_info info ;
    struct s_nodo *sig ;
}t_nodo ;

typedef t_nodo*     t_pila ;

void crearPila(t_pila *p) ;
void vaciarPila(t_pila *p) ;
int pilaLlena(const t_pila *p) ;
int pilaVacia(const t_pila *p) ;
int ponerEnPila(t_pila *p , const t_info *d) ;
int sacarDePila(t_pila *p , t_info *d) ;
int verTopePila(const t_pila *p , t_info *d) ;

#endif // PILA_H_INCLUDED
