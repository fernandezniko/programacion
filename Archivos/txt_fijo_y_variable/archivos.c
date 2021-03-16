#include "archivos.h"

int abrirArchivo (FILE **fp , const char *nom , const char *modo , int conSinMsj)
{
    *fp = fopen(nom , modo) ;
    if (*fp == NULL)
    {
        if (conSinMsj == CON_MSJ)
            fprintf(stderr , "error abriendo \"%s\" en modo \"%s\" \n" ,nom , modo ) ;
        return 0 ;
    }
    return 1 ;
}

int abrirLosArchivos (FILE **fpE , FILE **txt_fija , FILE **txt_variable )
{
    int retval=0 ;
    if (!abrirArchivo (fpE , ENTRADA , "rb" , CON_MSJ))
        retval = 1 ;
    if (!abrirArchivo (txt_fija , SAL_FIJA , "wt" , CON_MSJ))
        retval += 2 ;
    if (!abrirArchivo (txt_variable , SAL_VAR , "wt" , CON_MSJ))
        retval += 4 ;
    if(retval)
    {
        fprintf(stderr , "El programa se cancelara") ;
        if (*fpE)
            fclose(*fpE) ;
        if (*txt_fija)
            fclose(*txt_fija) ;
        if (txt_variable)
            fclose(*txt_variable) ;
    }
    return retval ;
}
