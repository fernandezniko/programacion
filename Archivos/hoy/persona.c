#include "persona.h"

int ingresarPers(t_pers *p)
{
    printf("DNI(0=terminar): ") ;
    fflush(stdin) ;
    scanf("%ld" , &p->dni ) ;
    if (p->dni == 0)
        return 0 ;
    printf("Apellido(s), Nombre(s): ") ;
    fflush(stdin) ;
    gets(p->apyn) ;
    printf("Sexo (M/F): ");
    fflush(stdin) ;
    scanf("%c" , &p->sex) ;
    printf("Fecha (dd/mm/aaa): ") ;
    fflush(stdin) ;
    scanf("%d/%d/%d" , &p->fec.d , &p->fec.m , &p->fec.a) ;
    printf("Importe: ") ;
    fflush(stdin) ;
    scanf("%f" , &p->importe) ;

    return 1 ;
}
