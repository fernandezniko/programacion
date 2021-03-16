#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CON_MSJ 1

int abrirArchivo (FILE **pf , const char *nom , const char *modo , int conSinMsj) ;
void mostrarArchivo (FILE *pf) ;

#endif // ARCHIVO_H_INCLUDED
