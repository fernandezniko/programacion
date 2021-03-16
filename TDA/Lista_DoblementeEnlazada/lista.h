#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define DUPLICADO 0
#define SIN_MEMORIA 0

typedef t_pers  t_info ;
#define ingresarInfo    ingresarPers
#define mostrarInfo     mostrarPers

/*
typedef struct
{
    int dni ;
}t_info ;
*/
typedef struct s_nodo
{
    t_info info ;
    struct s_nodo *sig,
                  *ant ;
}t_nodo ;

typedef t_nodo *    t_lista ;

void crearLista (t_lista *p) ;

int listaLlena (const t_lista *p) ;
int listaVacia (const t_lista *p) ;

int insertarAlFinal (t_lista *p , const t_info *d) ;
int insertarAlInicio (t_lista *p , const t_info *d) ;
int insertarEnOrden (t_lista *p , const t_info *d , int(*comparar)(const t_info * , const t_info *)) ;

int eliminarListaOrdenada (t_lista *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2)) ;

int buscarEnListaOrdenada (const t_lista *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2)) ;

void ordenarLista (t_lista *p , int(*comparar)(const t_info *d1 , const t_info *d2)) ;

void mostrarLista (const t_lista *p) ;
int compararXdni (const t_info *d1 , const t_info *d2) ;
void acumular (t_info *d1 , t_info *d2) ;

#endif // LISTA_H_INCLUDED
