#include "archivo.h"

int main()
{
    FILE *pfDatosFija , *pfFija ;
    char linea[100] , *aux ;
    t_pers pers ;

    if(!abrirArchivo(&pfFija , "fija.txt" , "rt" , CON_MSJ))
        return 2 ;
    if(!abrirArchivo(&pfDatosFija , "datosFija" , "wb" , CON_MSJ))
        return 4 ;

    while( fgets(linea , sizeof(linea) , pfFija) )
    {
        aux = strchr(linea , '\n') ;
        if(aux == NULL)
        {
           fclose(pfFija) ;
           return 1 ;
        }

        *aux = '\0' ;
        aux -= 9 ;
        sscanf(aux , "%f" , &pers.importe ) ;
        *aux = '\0' ;

        aux -= 8 ;
        sscanf(aux , "%2d%2d%4d" , &pers.fec.d , &pers.fec.m , &pers.fec.a) ;
        *aux = '\0' ;

        aux -= 1 ;
        sscanf(aux , "%c" , &pers.sex) ;
        *aux = '\0' ;

        aux -= 35 ;
        strcpy(pers.apyn , aux) ;
        *aux = '\0' ;

        aux -= 8 ;
        sscanf(aux , "%ld" , &pers.dni) ;
        *aux = '\0' ;

        mostrarPers(&pers) ;
        //fwrite(&pers , sizeof(t_pers) , 1 , pfDatosFija) ;
    }
    //mostrarArchivo(pfDatosFija) ;

    fclose(pfFija) ;
    fclose(pfDatosFija) ;

    return 0;
}
