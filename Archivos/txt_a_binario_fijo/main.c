#include "archivos.h"

#define ARCHI "fija.txt"
#define TAM_DNI 8
#define TAM_APYN 35
#define TAM_SEX 1
#define TAM_FECHA 8
#define TAM_IMPORTE 9
#define TAM_REG     TAM_DNI+TAM_DNI+TAM_SEX+TAM_FECHA+TAM_IMPORTE

int main()
{
    FILE *fpFija ;
    char linea[100],
         *aux ;
    t_pers pers ;
    if(!abrirArchivo(&fpFija , ARCHI , "rt" , 1))
        return 1 ;

    while ( fgets(linea , sizeof(linea) , fpFija) )
    {
        aux = strchr(linea , '\n') ;
        if( (aux) == NULL )
        {
            fprintf(stderr , "Error linea larga") ;
            fclose(fpFija) ;
            return 2 ;
        }
        *aux = '\0' ;
        ///validar
        /* importe */
        aux -= TAM_IMPORTE ;
        sscanf(aux , "%f" , &pers.importe) ;
        *aux = '\0' ;
        /* fecha */
        aux -= TAM_FECHA ;
        sscanf(aux , "%2d%2d%4d" , &pers.fec.d , &pers.fec.m , &pers.fec.a) ;
        *aux = '\0' ;
        /* sexo */
        aux -= TAM_SEX ;
        sscanf(aux , "%c" , &pers.sex) ;
        *aux = '\0' ;
        /* apyn */
        aux -= TAM_APYN ;
        strcpy(pers.apyn , aux) ;
        *aux = '\0' ;
        /* dni */
        aux -= TAM_DNI ;
        sscanf(aux , "%ld" , &pers.dni) ;
        *aux = '\0' ;

        mostrarPers(&pers) ;
    }
    fclose(fpFija) ;

    return 0;
}
