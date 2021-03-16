#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

#define CON_MSJ 1
#define NOMBRE "nikooo"
#define ENTRADA "datos"

int abrirArchivo (FILE **pf , const char *nom , const char *modo , int conSinMsj) ;
void mostrarArchivo (FILE *pf) ;
void crearArchivo (void) ;
int cantidadRegistros (FILE *fp) ;

#endif // ARCHIVO_H_INCLUDED
