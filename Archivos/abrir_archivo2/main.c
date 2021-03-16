#include "archivo.h"
#include "persona.h"

int main()
{
    t_pers persona ;
    FILE *fp ;
/*    char archi[] = "niko" ;

    if ( !abrirArchivo(&fp , archi , "rb" , CON_MSJ) )
        return 1 ;

    while (ingresarPers(&persona))
        fwrite(&persona , sizeof(t_pers) , 1 , fp) ;



    mostrarArchivo(fp) ;

    fclose(fp) ;
*/
    ///crearArchivo() ;
    t_pers reg ;
    if (!abrirArchivo(&fp , ENTRADA , "rb" , CON_MSJ))
    {
        return 1 ;
    }
/*
    fread(&reg , sizeof(t_pers) , 1 , fp) ;
    while(!feof(fp))
    {
        if (reg.sex == 'F')
        {
            reg.importe *= 1.15 ;

            fseek(fp , -1L*sizeof(t_pers) , SEEK_CUR) ;
            fwrite(&reg , sizeof(t_pers) , 1 , fp) ;
            fseek(fp , 0L , SEEK_CUR) ;
        }

        fread(&reg , sizeof(t_pers) , 1 , fp) ;

    }

    fclose(fp) ;
*/
    mostrarArchivo(fp) ;
    printf("Cantidad de registros: %d\n" , cantidadRegistros(fp)) ;

    return 0;
}
