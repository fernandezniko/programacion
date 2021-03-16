#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM_COLA 10
#define ingresarInfo    ingresarPers
#define mostrarInfo     mostrarPers

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"


typedef t_pers  tInfo ;


typedef struct
{
    tInfo cola[TAM_COLA];
    int   pri,
          ult,
          cargados;
}tCola ;

void crearCola (tCola *p) ;
void vaciarCola (tCola *p) ;
int colaLlena (const tCola *p) ;
int colaVacia (const tCola *p) ;
int ponerEnCola (tCola *p , const tInfo *d) ;
int sacarDeCola (tCola *p , tInfo *d) ;
int verPrimeroCola (const tCola *p , tInfo *d) ;

#endif // COLA_H_INCLUDED
