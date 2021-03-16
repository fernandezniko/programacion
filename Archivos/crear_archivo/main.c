#include "persona.h"
#include "archivo.h"

int main()
{
    FILE *fpest ,
         *fpemp ;
    t_estudiantes est ;
    t_empleados emp ;

    if(!abrirArchivo(&fpemp , "empleados" , "rb" , CON_MSJ))
        return 1;
    if(!abrirArchivo(&fpest , "estudiantes" , "rb" , CON_MSJ))
        return 1;
/*
    while(ingresarEstudiante(&est))// && ingresarEmpleado(&emp))
       fwrite(&est , sizeof(t_estudiantes) , 1 , fpest) ;

    while(ingresarEmpleado(&emp))
        fwrite(&emp , sizeof(t_empleados) , 1 , fpemp) ;

*/
    mostrarArchivoEmpleados(fpemp) ;
    mostrarArchivoEstudiantes(fpest) ;

    fclose(fpest) ;
    fclose(fpemp) ;

    return 0;
}
