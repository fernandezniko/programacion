#include "pila.h"

int main()
{
    t_pila pila ;
    t_info info ;
    int x ;

    crearPila(&pila) ;

    puts("x: ") ;
    scanf("%d" , &x) ;


    while(x)
    {
        printf("Ingrese dni: " ) ;
        scanf("%d" , &info.dni) ;

        ponerEnPila(&pila , &info) ;

        puts("x: ") ;
        scanf("%d" , &x) ;
    }

    verTopePila(&pila , &info) ;
    printf("%d" , info.dni) ;

    return 0;
}
