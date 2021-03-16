#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CON_MSJ 1
#define NOMBRE "nikooo"
#define ENTRADA "datos"

int abrirArchivo (FILE **pf , const char *nom , const char *modo , int conSinMsj) ;
void mostrarArchivo (FILE *pf) ;
void crearArchivo (void) ;
int cantidadRegistros (FILE *fp) ;
void apareo_Union (FILE *pfA , FILE *pfB , FILE *pfRes) ;
void apareo_Interseccion (FILE *pfA , FILE *pfB , FILE *pfRes) ;
void apareo_Diferencia (FILE *pfA , FILE *pfB , FILE *pfRes) ;
int cmpXdni (const t_pers * , const t_pers *) ;

#endif // ARCHIVO_H_INCLUDED
