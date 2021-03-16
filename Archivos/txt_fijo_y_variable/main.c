#include "archivos.h"

int main()
{
    int retVal=0 ;

    FILE *fpEnt ,
         *fpTxtFijo ,
         *fpTxtVar ;

    t_pers pers ;

    retVal = abrirLosArchivos(&fpEnt , &fpTxtFijo , &fpTxtVar) ;
    if (retVal)
        return retVal ;

    fread(&pers , sizeof(t_pers) , 1 , fpEnt) ;
    while(!feof(fpEnt))
    {
        ///LONG FIJA
        fprintf(fpTxtFijo , "%08Ld%-*s%c%02d%02d%04d%09.2f\n" , pers.dni , sizeof(pers.apyn)-1 , pers.apyn , pers.sex , pers.fec.d , pers.fec.m , pers.fec.a , pers.importe) ;

        ///LONG VARIABLE
        fprintf(fpTxtVar , "%ld|%s|%c|%d/%d/%d|%.2f\n" , pers.dni , pers.apyn , pers.sex , pers.fec.d , pers.fec.m , pers.fec.a , pers.importe) ;

        fread(&pers , sizeof(t_pers) , 1 , fpEnt) ;
    }

    fclose(fpEnt) ;
    fclose(fpTxtVar) ;
    fclose(fpTxtFijo) ;

    return 0;
}
