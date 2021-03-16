#include "arbol.h"

int compararXdni (const t_info *d1 , const t_info *d2)
{
    if(d1->dni > d2->dni)
        return 1 ;
    if(d1->dni < d2->dni)
        return -1 ;
    return 0 ;
}

void visitar (const t_info *d)
{
    printf("%ld\t" , d->dni) ;
}

void crearArbol (t_arbol *p)
{
    *p = NULL ;
}

void preOrden (const t_arbol *p)
{
    if(*p)
    {
        visitar(&(*p)->info) ;
        preOrden(&(*p)->izq) ;
        preOrden(&(*p)->der) ;
    }
}

void postOrden (const t_arbol *p)
{
    if(*p)
    {
        postOrden(&(*p)->izq) ;
        postOrden(&(*p)->der) ;
        visitar(&(*p)->info) ;
    }
}

void enOrden(const t_arbol *p)
{
    if(*p)
    {
        enOrden(&(*p)->izq) ;
        visitar(&(*p)->info) ;
        enOrden(&(*p)->der) ;
    }
}

int altura(const t_arbol *p)
{
    if(*p)
    {
        int hi = altura(&(*p)->izq) ,
            hd = altura(&(*p)->der) ;

        return hi >= hd ? hi + 1 : hd + 1 ;
    }
    return 0 ;
}

int contarNodos(const t_arbol *p)
{
    if(*p)
        return contarNodos(&(*p)->izq) + contarNodos(&(*p)->der) + 1 ;

    return 0 ;
}

int contarNodosHastaNivel (const t_arbol *p , int nivel)
{
    if(*p)
    {
        if(nivel == 1)  ///nivel == 0 , return 0 ;1050
            return 1 ;

        return contarNodosHastaNivel(&(*p)->izq , nivel - 1) + contarNodosHastaNivel(&(*p)->der , nivel - 1) + 1 ;
    }
    return 0 ;
}

int contarNodosHojas(const t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq == NULL && (*p)->der == NULL)
            return 1 ;

        return contarNodosHojas(&(*p)->izq) +
                contarNodosHojas(&(*p)->der) ;
    }
    return 0 ;
}

int ponerEnArbol(t_arbol *p , const t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2))
{
    while(*p)
    {
        int cmp = comparar(&(*p)->info , d) ;
        if(cmp == 0)
            return CLA_DUP ;
        if(cmp > 0)
            p = &(*p)->izq ;
        else
            p = &(*p)->der ;
    }
    *p = (t_nodo *)malloc(sizeof(t_nodo)) ;
    if(*p == NULL)
        return SIN_MEMORIA ;

    (*p)->info = *d ;
    (*p)->izq = NULL ;
    (*p)->der = NULL ;

    return TODO_BIEN ;
}

int ponerEnArbolRecursiva(t_arbol *p , const t_info *d , int(*comparar)(const t_info *d , const t_info *d2))
{
    int cmp ;

    if(*p == NULL)
    {
        *p = (t_nodo*)malloc(sizeof(t_nodo)) ;
        if(*p == NULL)
            return SIN_MEMORIA ;
        (*p)->info = *d ;
        (*p)->der = NULL ;
        (*p)->izq = NULL ;

        return 1 ;
    }

    cmp = comparar(d , &(*p)->info) ;
    if(cmp == 0)
        return 0 ;
    if(cmp > 0)
        return ponerEnArbol(&(*p)->der , d , comparar) ;
    else
        return ponerEnArbol(&(*p)->izq , d , comparar) ;

}

int esCompleto (const t_arbol *p)
{
    int h = altura(p) ;
    int cant = contarNodos(p) ;
    int cantSiEsCompleto = pow(2 , h) - 1 ;

    return cantSiEsCompleto == cant ;
}

int esBalanceado (const t_arbol *p)
{
    int h = altura(p) ;
    int cant = contarNodosHastaNivel(p , h - 1) ;
    int cantSiEsBalanceado = pow(2 , h-1) - 1 ;

    return cantSiEsBalanceado == cant ;

}

int esAvl (const t_arbol *p)
{
    if(*p)
    {
        if(abs(altura(&(*p)->izq) - altura(&(*p)->der)) > 1)
            return 0 ;

        return esAvl(&(*p)->izq) && esAvl(&(*p)->der) ;
    }

    return 1 ;
}

void eliminarArbol (t_arbol *p)
{
    if(*p)
    {
        eliminarArbol(&(*p)->izq) ;
        eliminarArbol(&(*p)->der) ;
        free(*p) ;
        *p = NULL ;
    }
}

int eliminarArbloYcontar(t_arbol *p)
{
    if(*p)
    {
        int cant = eliminarArbloYcontar(&(*p)->izq) + eliminarArbloYcontar(&(*p)->der) ;

        free(*p) ;
        *p = NULL ;

        return cant + 1 ;
    }
    return 0 ;
}

void podarArbolHastaNivel (t_arbol *p , int nivel)
{
    if(*p)
    {
        if(nivel == 1)
        {
            eliminarArbol(&(*p)->izq) ;
            eliminarArbol(&(*p)->der) ;
        }
        podarArbolHastaNivel(&(*p)->izq , nivel-1) ;
        podarArbolHastaNivel(&(*p)->der , nivel-1) ;
    }

}

int podarArbolHastaNivelyContar (t_arbol *p , int nivel)
{
    if(*p)
    {
        if(nivel == 1)
        {
            return eliminarArbloYcontar(&(*p)->izq) + eliminarArbloYcontar(&(*p)->der) ;
        }
        return podarArbolHastaNivelyContar(&(*p)->izq , nivel -1) +
               podarArbolHastaNivelyContar(&(*p)->der , nivel -1) ;
    }
    return 0 ;
}


int buscarEnArbolBin (const t_arbol *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2))
{
    int cmp ;
    while (*p && (cmp = comparar(d , &(*p)->info)) != 0)
    {
        if(cmp > 0 )
            p = &(*p)->der ;
        else
            p = &(*p)->izq ;
    }
    if(*p == NULL)
        return 0 ;

    *d = (*p)->info ;

    return 1 ;
}

int buscarEnArbloBinRecursiva (const t_arbol *p , t_info *d , int(*comparar)(const t_info *d1 , const t_info *d2))
{
    int cmp ;

    if(*p == NULL)
        return 0 ;

    cmp = comparar(d , &(*p)->info) ;
    if(cmp == 0)
    {
        *d = (*p)->info ;
        return 1 ;
    }

    if(cmp > 0)
        return buscarEnArbloBinRecursiva(&(*p)->der , d , comparar) ;
    else
        return buscarEnArbloBinRecursiva(&(*p)->izq , d , comparar) ;

}

int contarNodosSoloIzq (const t_arbol *p)
{
    if(*p)
    {

        return contarNodosSoloIzq(&(*p)->izq)  + 1 ;
    }
    return 0 ;
}

void mostrarSoloHijoIzq (const t_arbol *p)
{
    if(*p)
    {
        if( ((*p)->izq != NULL) && ((*p)->der == NULL) )
            visitar(&(*p)->info) ;

        mostrarSoloHijoIzq(&(*p)->izq) ;
        mostrarSoloHijoIzq(&(*p)->der) ;
    }
}

void mostrarNodosHojas (const t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq == NULL && (*p)->der == NULL)
            visitar(&(*p)->info) ;
        mostrarNodosHojas(&(*p)->izq) ;
        mostrarNodosHojas(&(*p)->der) ;
    }
}

void mostrarNodosNoHojas (const t_arbol *p)
{
    if(*p)
    {
        if((*p)->izq || (*p)->der)
            visitar(&(*p)->info) ;
        mostrarNodosNoHojas(&(*p)->izq) ;
        mostrarNodosNoHojas(&(*p)->der) ;
    }
}

int mostrarContarHastaNivel (const t_arbol *p , int nivel)
{
    if(*p)
    {
        if(nivel == 1)
        {
            visitar(&(*p)->info) ;
            return 1 ;
        }
        visitar(&(*p)->info) ;
        return     mostrarContarHastaNivel(&(*p)->izq , nivel-1) +
                   mostrarContarHastaNivel(&(*p)->der , nivel-1) + 1 ;
    }
    return 0 ;
}

void EliminarArbol2 (t_arbol *p)
{
    if(*p)
    {
        EliminarArbol2(&(*p)->izq) ;
        EliminarArbol2(&(*p)->der) ;
        free(*p) ;
        *p = NULL ;
    }
}

void podarArbolHastaNivel2(t_arbol *p , int nivel)
{
    if(*p)
    {
        if(nivel == 1)
        {
            EliminarArbol2(&(*p)->izq) ;
            EliminarArbol2(&(*p)->der) ;
        }

        podarArbolHastaNivel2(&(*p)->izq , nivel-1) ;
        podarArbolHastaNivel2(&(*p)->der , nivel-1) ;

    }

}
