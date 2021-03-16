#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include "fechas.h"

typedef struct
{
    long dni ;
    char apyn[36] ;
    char sex ;
    t_fecha fec ;
    float importe ;
} t_pers ;

int ingresarPers (t_pers *p) ;
void mostrarPers (t_pers *pers) ;

#endif // PERSONA_H_INCLUDED
