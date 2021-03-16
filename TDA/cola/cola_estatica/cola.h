#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM_COLA 10
#define ingresarInfo    ingresarPers
#define mostrarInfo     mostrarPers

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"


typedef t_pers  t_info ;


typedef struct
{
    t_info cola[TAM_COLA];
    int   pri,
          ult,
          cargados;
}t_cola ;

void crearCola (t_cola *p) ;
void vaciarCola (t_cola *p) ;
int colaLlena (const t_cola *p) ;
int colaVacia (const t_cola *p) ;
int ponerEnCola (t_cola *p , const t_info *d) ;
int sacarDeCola (t_cola *p , t_info *d) ;
int verPrimeroCola (const t_cola *p , t_info *d) ;

#endif // COLA_H_INCLUDED
