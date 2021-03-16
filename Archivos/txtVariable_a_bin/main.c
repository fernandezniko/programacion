#include "archivo.h"

int main()
{
    FILE *pfDatosVar , *pfVar ;
    t_pers pers ;
    char linea[100] , *aux ;
    int registros = 0 ;

    if(!abrirArchivo(&pfVar , "variable.txt" , "rt" , CON_MSJ))
        return 2 ;
    if(!abrirArchivo(&pfDatosVar , "datosVariable" , "wb" , CON_MSJ))
        return 4 ;

    while( fgets(linea , sizeof(linea) , pfVar) )
    {
        aux = strchr(linea , '\n') ;
        if(aux == NULL)
        {
            fclose(pfVar) ;
            return 1 ;
        }
        registros ++ ;

        *aux = '\0' ;
        aux = strrchr(linea , '|') ;
        sscanf(aux + 1 , "%f" , &pers.importe) ;
        *aux = '\0' ;

        aux = strrchr(linea , '|') ;
        sscanf(aux + 1 ,"%d/%d/%d" , &pers.fec.d , &pers.fec.m , &pers.fec.a) ;
        *aux = '\0' ;

        aux = strrchr(linea , '|') ;
        sscanf(aux + 1 , "%c" , &pers.sex) ;
        *aux = '\0' ;

        aux = strrchr(linea , '|') ;
        strcpy(pers.apyn , aux+1) ;
        *aux = '\0' ;

        sscanf(linea , "%ld" , &pers.dni) ;

        mostrarPers(&pers) ;
    }

    printf("Se leyeron %d registros\n" , registros) ;

    fclose(pfDatosVar) ;
    fclose(pfVar) ;

    return 0;
}
