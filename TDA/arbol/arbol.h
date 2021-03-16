#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "persona.h"

#define ingresarInfo    ingresarPers
#define CLA_DUP     0
#define SIN_MEMORIA 2
#define TODO_BIEN 1

typedef t_pers  t_info ;

typedef struct s_nodo
{
    t_info info ;
    struct s_nodo *izq ,
                  *der ;
}t_nodo ;

typedef t_nodo *    t_arbol ;

void crearArbol (t_arbol *p) ;

void preOrden (const t_arbol *p) ;
void postOrden (const t_arbol *p) ;
void enOrden (const t_arbol *p) ;

void mostrarSoloHijoIzq (const t_arbol *p) ;
void mostrarNodosHojas (const t_arbol *p) ;
void mostrarNodosNoHojas (const t_arbol *p) ;


int altura (const t_arbol *p) ;

int contarNodos (const t_arbol *p) ;
int contarNodosHastaNivel (const t_arbol *p , int nivel) ;
int contarNodosSoloIzq (const t_arbol *p) ;
int contarNodosHojas(const t_arbol *p) ;

int ponerEnArbol (t_arbol *p , const t_info *d , int(*comparar)(const t_info * , const t_info *)) ;
int ponerEnArbolRecursiva(t_arbol *p , const t_info *d , int(*comparar)(const t_info *d , const t_info *d2)) ;


int esCompleto (const t_arbol *p) ;
int esAvl (const t_arbol *p) ;
int esBalanceado (const t_arbol *p) ;

void eliminarArbol (t_arbol *p) ;
int eliminarArbloYcontar (t_arbol *p) ;
void podarArbolHastaNivel (t_arbol *p , int nivel) ;
int podarArbolHastaNivelyContar (t_arbol *p , int nivel) ;

int buscarEnArbolBin (const t_arbol *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2)) ;
int buscarEnArbloBinRecursiva (const t_arbol *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2)) ;

int mostrarContarHastaNivel (const t_arbol *p , int nivel) ;
void EliminarArbol2 (t_arbol *p) ;

void podarArbolHastaNivel2(t_arbol *p , int nivel) ;

int compararXdni (const t_info *d1 , const t_info *d2) ;
void visitar (const t_info *d) ;

#endif // ARBOL_H_INCLUDED
