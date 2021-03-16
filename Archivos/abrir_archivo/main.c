#include "archivo.h"
#include "persona.h"

int main()
{
    t_pers persona ;
    FILE *fp ;
    char archi[] = "niko" ;

    if ( !abrirArchivo(&fp , "datospila" , "wb" , CON_MSJ) )
        return 1 ;

    while (ingresarPers(&persona))
        fwrite(&persona , sizeof(t_pers) , 1 , fp) ;



    //mostrarArchivo(fp) ;

    fclose(fp) ;

    return 0;
}
