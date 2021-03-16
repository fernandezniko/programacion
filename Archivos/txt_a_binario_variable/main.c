#include "archivos.h"

#define arch "variable.txt"

int main()
{
    FILE *fpVariable ;
    char linea[100],
         *aux ;
    t_pers pers ;
    if(!abrirArchivo(&fpVariable , arch , "rt" , CON_MSJ))
        return 1 ;

    while ( fgets(linea , sizeof(linea) , fpVariable) )
    {
        aux = strchr(linea , '\n') ;
        if ( (aux)== NULL )
        {
            fprintf(stderr , "Error-lina de texto muy larga \n") ;
            fclose(fpVariable) ;
            return 2 ;
        }
        *aux = '\0' ;
        ///validar lina
        /*   importe   */
        aux = strrchr(linea , '|') ;
        sscanf(aux+1 , "%f" , &pers.importe) ;
        *aux = '\0' ;
        /*   fecha   */
        aux = strrchr(linea , '|') ;
        sscanf(aux+1 , "%d/%d/%d" , &pers.fec.d , &pers.fec.m , &pers.fec.a) ;
        *aux = '\0' ;
        /*   sexo   */
        aux = strrchr(linea , '|') ;
        sscanf(aux+1 , "%c" , &pers.sex) ;
        *aux = '\0' ;
        /*   apyn   */
        aux = strrchr(linea , '|') ;
        strcpy(pers.apyn , aux+1) ;
        *aux = '\0' ;
        /*   dni   */
        sscanf(linea , "%ld" , &pers.dni) ;

        mostrarPers(&pers);
        }
    fclose(fpVariable) ;

    return 0;
}
