#include "archivo.h"

int abrirArchivo (FILE **fp , const char *nom , const char *modo , int conSinMsj)
{
    *fp = fopen(nom , modo) ;
    if (*fp == NULL)
    {
        if (conSinMsj == CON_MSJ)
            fprintf(stderr , "error abriendo \"%s\" en modo \"%s\" \n" ,nom , modo ) ;
        return 0 ;
    }
    return 1 ;
}

void mostrarArchivoEmpleados (FILE *p)
{
    t_empleados emp;

    fread(&emp , sizeof(t_empleados) , 1 , p) ;

    while( !feof(p) )
    {
        printf("DNI : %d\n" , emp.dni) ;

        printf("Apellido(s): %s\n" , emp.apellido ) ;

        printf("Nombre(s): %s\n" , emp.nombre) ;

        printf("Sueldo: %.2lf\n" , emp.sueldo ) ;

        puts("") ;

        fread(&emp , sizeof(t_empleados) , 1 , p) ;
    }

}

void mostrarArchivoEstudiantes (FILE *p)
{
    t_estudiantes est;

    fread(&est , sizeof(t_estudiantes) , 1 , p) ;

    while( !feof(p) )
    {
        printf("DNI : %d\n" , est.dni) ;

        printf("Apellido(s): %s\n" , est.apellido ) ;

        printf("Nombre(s): %s\n" , est.nombre) ;

        printf("Promedio: %.2f\n" , est.promedio ) ;

        puts("") ;

        fread(&est , sizeof(t_estudiantes) , 1 , p) ;
    }

}

int compararXdni (t_empleados *p1 , t_estudiantes *p2)
{
    if(p1->dni > p2->dni)
        return 1 ;
    if(p1->dni < p2->dni)
        return -1 ;
    return 0 ;
}
