#include "persona.h"

int ingresarPers(t_pers *p)
{
    printf("DNI(0=terminar): ") ;
    fflush(stdin) ;
    scanf("%ld", &p->dni ) ;
    if (p->dni == 0)
        return 0 ;
    printf("Apellido(s), Nombre(s): ") ;
    fflush(stdin) ;
    gets(p->apyn) ;
    printf("Sexo (M/F): ");
    fflush(stdin) ;
    scanf("%c", &p->sex) ;
    printf("Fecha (dd/mm/aaa): ") ;
    fflush(stdin) ;
    scanf("%d/%d/%d", &p->fec.d, &p->fec.m, &p->fec.a) ;
    printf("Importe: ") ;
    fflush(stdin) ;
    scanf("%f", &p->importe) ;
    printf("Legajo: ") ;
    fflush(stdin) ;
    scanf("%d" , &p->legajo) ;
    puts("") ;

    return 1 ;
}

void mostrarPers ( const t_pers *pers )
{
    puts("------------------------") ;
    puts("Informacion \n") ;
    printf("DNI : %ld\n", pers->dni) ;
    puts("------------------------") ;
    printf("Apellido(s), Nombre(s): %s\n", pers->apyn ) ;
    puts("------------------------") ;
    printf("Sexo (M/F): %c\n", pers->sex);
    puts("------------------------") ;
    printf("Fecha (dd/mm/aaa): %d/%d/%d\n", pers->fec.d, pers->fec.m, pers->fec.a ) ;
    puts("------------------------") ;
    printf("Importe: %.2f\n", pers->importe ) ;
    puts("------------------------") ;
    printf("Legajo: %d\n" , pers->legajo) ;
    puts("") ;

}
