#include "archivo.h"
#include "persona.h"

int main()
{
    FILE *fpEstudiantes,
         *fpEmpleados ;
    t_empleados emp ;
    t_estudiantes est ;


    if(!abrirArchivo(&fpEmpleados , "empleados" , "r+b" , CON_MSJ))
        return 1 ;
    if(!abrirArchivo(&fpEstudiantes , "estudiantes" , "rb" , CON_MSJ))
        return 1 ;

    fread(&est , sizeof(t_estudiantes) , 1 , fpEstudiantes) ;
    fread(&emp , sizeof(t_empleados) , 1 , fpEmpleados) ;

    if( feof(fpEmpleados) )
        puts("No hay empleados \n") ;

    while( !feof(fpEstudiantes)  )
    {
        if(est.promedio > 7 && compararXdni(&emp , &est)==0)
        {
            emp.sueldo *= 1.0728 ;
            fseek(fpEmpleados , -1L*sizeof(t_empleados) , SEEK_CUR) ;
            fwrite(&emp , sizeof(t_empleados) , 1 , fpEmpleados) ;
            //rewind(fpEmpleados) ;
            fseek(fpEmpleados , 0L , SEEK_CUR) ;
            fread(&est , sizeof(t_estudiantes) , 1 , fpEstudiantes) ;
            fread(&emp , sizeof(t_empleados) , 1 , fpEmpleados) ;

        }
        else if(est.promedio > 7 && compararXdni(&emp , &est))
            {
                fread(&emp , sizeof(t_empleados) , 1 , fpEmpleados) ;
            }
            else
                {
                 fread(&est , sizeof(t_estudiantes) , 1 , fpEstudiantes) ;
                }

            if(feof(fpEmpleados) && !feof(fpEstudiantes))
              {  rewind(fpEmpleados) ;//fseek(fpEmpleados , 0L , SEEK_SET) ;
                 fread(&emp , sizeof(t_empleados) , 1 , fpEmpleados) ;
                 fread(&est , sizeof(t_estudiantes) , 1 , fpEstudiantes) ;
              }
    }

    //mostrarArchivoEmpleados(fpEmpleados) ;
    fclose(fpEstudiantes) ;
    fclose(fpEmpleados) ;

    return 0;
}
