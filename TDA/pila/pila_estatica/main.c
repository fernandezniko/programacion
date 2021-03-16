#include "pila.h"

int main()
{
    t_pila pila ;
    t_info info ;

    crearPila(&pila) ;

    while(!pilaLlena(&pila) && ingresarInfo(&info))
        ponerEnPila(&pila , &info) ;

    if(verTopePila(&pila,&info))
        mostrarInfo(&info) ;

    return 0;
}
