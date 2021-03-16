#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

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

typedef struct
{
    t_nodo *pri,
           *ult ;

}t_cola ;

void crearCola(t_cola *p) ;
void vaciarCola(t_cola *p) ;
int colaLlena(const t_cola *p) ;
int colaVacia(const t_cola *p) ;
int ponerEnCola(t_cola *p , const t_info *d) ;
int sacarDeCola(t_cola *p ,t_info *d) ;
int verPrimeroCola(const t_cola *p , t_info *d) ;

#endif // COLA_H_INCLUDED
