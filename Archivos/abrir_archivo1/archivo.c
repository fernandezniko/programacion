#include "archivo.h"

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

void mostrarArchivo (FILE *p)
{
    t_pers pers;

    fread(&pers , sizeof(t_pers) , 1 , p) ;

    while( !feof(p) )
    {
        printf("DNI : %ld\n" , pers.dni) ;

        printf("Apellido(s), Nombre(s): %s\n" , pers.apyn ) ;

        printf("Sexo (M/F): %c\n" , pers.sex);

        printf("Fecha (dd/mm/aaa): %d/%d/%d\n" , pers.fec.d , pers.fec.m , pers.fec.a ) ;

        printf("Importe: %.2f\n" , pers.importe ) ;

        puts("") ;

        fread(&pers , sizeof(t_pers) , 1 , p) ;
    }

}

void crearArchivo (void)
{
    FILE *fp ;
    t_pers vec[] = { {11111111 , "Fernandez, Niko", 'M' , {{22},{02},{1960}} , 11115.5},
                     {22222222 , "Cyc, Juan", 'M' , {{9},{04},{2010}} , 10519.8},
                     {33333333 , "Fernandez, Juan" , 'M' , {{27},{8},{1985}} , 29500.99} } ;

    fp = fopen(NOMBRE , "wb") ;

    if (fp)
    {
        fwrite(vec , sizeof(vec) , 1 , fp) ;
        fclose(fp) ;
    }

}
