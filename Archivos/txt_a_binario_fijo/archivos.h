#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "persona.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CON_MSJ     1
#define SAL_FIJA    "fija.txt"
#define SAL_VAR     "variable.txt"
#define ENTRADA     "datos"

int abrirArchivo (FILE **fp , const char *nom , const char *modo , int conSinMsj) ;
int abrirLosArchivos (FILE **fe , FILE **txt_fija , FILE **txt_variable ) ;


#endif // ARCHIVOS_H_INCLUDED
