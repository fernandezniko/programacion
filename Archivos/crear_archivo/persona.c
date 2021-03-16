#include "persona.h"

int ingresarEmpleado (t_empleados *p)
{
    puts("finaliza DNI EMPLEADO igual 0 ") ;
    printf("Ingrese dni: ") ;
    scanf("%d" , &p->dni) ;
    if(p->dni == 0)
        return 0;
    printf("Ingrese apellido: ") ;
    fflush(stdin) ;
    gets(p->apellido) ;
    printf("Ingrese nombre: ") ;
    fflush(stdin) ;
    gets(p->nombre) ;
    printf("Ingrese sueldo: ") ;
    scanf("%lf" , &p->sueldo) ;
    puts("") ;
    return 1 ;
}

int ingresarEstudiante (t_estudiantes *p)
{
    puts("finaliza DNI ESTUDIANTE  igual 0 ") ;
    printf("Ingrese dni: ") ;
    scanf("%d" , &p->dni) ;
    if(p->dni == 0)
        return 0;
    printf("Ingrese apellido: ") ;
    fflush(stdin) ;
    gets(p->apellido) ;
    printf("Ingrese nombre: ") ;
    fflush(stdin) ;
    gets(p->nombre) ;
    printf("Ingrese promedio: ") ;
    scanf("%f" , &p->promedio) ;
    puts("") ;
    return 1 ;
}
