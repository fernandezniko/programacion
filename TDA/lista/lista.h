#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define CLA_DUPLICADA   2
#define EliminarTodos 7

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

typedef t_nodo *    t_lista ;

void crearLista (t_lista *p) ;
int listaLlena (const t_lista *p) ;
int listaVacia (const t_lista *p) ;

int insertarAlComienzo (t_lista *p , const t_info *d) ;
int insertarAlFinal (t_lista *p , const t_info *d)  ;
int insertarEnOrden (t_lista *p , const t_info *d , int(*comparar)(const t_info * , const t_info *) , void(*acumular)(t_info *, const t_info *)) ;

void ordenarLista (t_lista *p , int(*comparar)(const t_info * , const t_info *)) ;

int contarMostrarYeliminar (t_lista *p , void(*mostrar)(const t_info *) , FILE *fp) ;

int buscarYrecuperarListaNoOrd (const t_lista *p , t_info *d , int(*comparar)(const t_info * , const t_info *)) ;
int buscarRecuperarListaNoOrdYeliminar (t_lista *p , t_info *d , int(*comparar)(const t_info * , const t_info *)) ;
int buscarYrecuperarListaOrd (const t_lista *p , t_info *d , int(*comparar)(const t_info * , const t_info *)) ;
int buscarRecuperarListaOrdYeliminar (t_lista *p , t_info *d , int(*comparar)(const t_info * , const t_info *)) ;

int eliminarTodosDupListaNoOrd (t_lista *p , int(*comparar)(const t_info * , const t_info *) , void(*acumular)(t_info * , const t_info *) , int elimTodos) ;
int eliminarDupListaNoOrd (t_lista *p , int(*comparar)(const t_info * , const t_info *) , void(*acumular)(t_info * , const t_info *) ) ;
int eliminarTodosDupListaOrd (t_lista *p , int(*comparar)(const t_info *, const t_info *) , void(*acumular)(t_info * , const t_info *) , int elimTodos) ;
int eliminarDupListaOrd (t_lista *p , int(*comparar)(const t_info *, const t_info *) , void(*acumular)(t_info* , const t_info *) ) ;

void mostrarLista(t_lista *p) ;
void recorreerLista (t_lista *p , void(*grabar)(t_info *d1)) ;
int eliminarDeLista (t_lista *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2)) ;

void mostrar_info (const t_info *d) ;
int compararXdni (const t_info *d1 , const t_info *d2) ;
int compararXlegajo (const t_info *d1 , const t_info *d2) ;
void acumularImporte (t_info *d1 , const t_info *d2) ;
void grabarLista (t_info *d) ;

#endif // LISTA_H_INCLUDED
