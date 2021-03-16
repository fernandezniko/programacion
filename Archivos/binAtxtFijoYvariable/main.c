#include "archivo.h"

int main()
{
    FILE *pfDatos , *pfFija , *pfVar ;
    t_pers pers ;

    if(!abrirArchivo(&pfDatos , "datos" , "rb" , CON_MSJ))
        return 2 ;

    if(!abrirArchivo(&pfFija , "fija.txt" , "wt" , CON_MSJ))
        return 4 ;

    if(!abrirArchivo(&pfVar , "variable.txt" , "wt" , CON_MSJ))
        return 6 ;

    fread(&pers , sizeof(t_pers) , 1 , pfDatos) ;

    while(!feof(pfDatos))
    {
        ///FIJA
        fprintf(pfFija , "%08ld%-35s%c%02d%02d%04d%09.2f\n" , pers.dni , pers.apyn , pers.sex , pers.fec.d , pers.fec.m , pers.fec.a , pers.importe) ;

        ///VARIABLE
        fprintf(pfVar , "%ld|%s|%c|%d/%d/%d|%.2f\n" , pers.dni , pers.apyn , pers.sex , pers.fec.d , pers.fec.m , pers.fec.a , pers.importe) ;

        fread(&pers , sizeof(t_pers) , 1 , pfDatos) ;

    }

    fclose(pfFija) ;
    fclose(pfVar) ;
    fclose(pfDatos) ;

    return 0;
}
