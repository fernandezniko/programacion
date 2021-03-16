#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define TAM 5
#define ingresarInfo    ingresarPers
#define mostrarInfo     mostrarPers

#include <stdio.h>
#include <stdlib.h>

#include "persona.h"

typedef t_pers t_info ;

typedef struct
{
    t_info vecPila[TAM] ;
    int tope ;
}t_pila ;

void crearPila (t_pila *p) ;
void vaciarPila (t_pila *p) ;
int ponerEnPila (t_pila *p , const t_info *d) ;
int sacarDePila (t_pila *p, t_info *d) ;
int verTopePila (const t_pila *p, t_info *d) ;
int pilaLlena (const t_pila *p) ;
int pilaVacia (const t_pila *p) ;

#endif // PILA_H_INCLUDED
