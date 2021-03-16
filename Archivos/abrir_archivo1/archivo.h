#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CON_MSJ 1
#define NOMBRE "datos"

int abrirArchivo (FILE **pf , const char *nom , const char *modo , int conSinMsj) ;
void mostrarArchivo (FILE *pf) ;
void crearArchivo (void) ;

#endif // ARCHIVO_H_INCLUDED
