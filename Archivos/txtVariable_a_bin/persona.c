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

void mostrarPers (t_pers *pers)
{



        printf("DNI : %ld\n" , pers->dni) ;

        printf("Apellido(s), Nombre(s): %s\n" , pers->apyn ) ;

        printf("Sexo (M/F): %c\n" , pers->sex);

        printf("Fecha (dd/mm/aaa): %d/%d/%d\n" , pers->fec.d , pers->fec.m , pers->fec.a ) ;

        printf("Importe: %.2f\n" , pers->importe ) ;

        puts("") ;



}
