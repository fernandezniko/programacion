#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM_APELLIDO    30
#define TAM_NOMBRE      30

typedef struct
{
    int dni ;
    char apellido[TAM_APELLIDO] ,
         nombre[TAM_NOMBRE] ;
    float promedio;
}t_estudiantes ;

typedef struct
{
    int dni ;
    char apellido[TAM_APELLIDO] ,
         nombre[TAM_NOMBRE] ;
    double sueldo ;
}t_empleados ;

int ingresarEmpleado (t_empleados *p) ;
int ingresarEstudiante (t_estudiantes *p) ;

#endif // PERSONA_H_INCLUDED
