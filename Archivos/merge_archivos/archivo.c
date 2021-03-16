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
    t_pers vec[] = { {11111111, "Fernandez, Niko", 'M', {1/2/2010}, 5.5},
                     {22222222, "Cyc, Juan", 'F', {3/4/2011}, 10.5},
                     {33333333, "Gallardo, Marcelo" , 'M' , {5/12/2012} , 100.99} } ;

    fp = fopen(ENTRADA , "wb") ;

    if (fp)
    {
        fwrite(vec , sizeof(vec) , 1 , fp) ;
        fclose(fp) ;
    }

}

int cantidadRegistros (FILE *fp)
{
    long posActual = ftell(fp) ;
    int cantregistros ;

    fseek(fp , 0L , SEEK_END) ;
    cantregistros = ftell(fp) / sizeof(t_pers) ;
    fseek(fp , posActual , SEEK_SET) ;

    return cantregistros ;
}

void apareo_Union (FILE *pfA , FILE *pfB , FILE *pfRes)
{
    t_pers persA , persB , perRes ;
    int comp ;

    fread(&persA , sizeof(t_pers) , 1 ,pfA) ;
    fread(&persB , sizeof(t_pers) , 1 , pfB) ;

    while(!feof(pfA) && !feof(pfB))
    {
        comp = cmpXdni(&persA , &persB) ;
        if(comp < 0) ///el de A no esta en B
        {
            perRes = persA ;
            fwrite(&perRes , sizeof(t_pers) , 1 , pfRes) ;
            fread(&persA , sizeof(t_pers) , 1 , pfA) ;
        }
        if(comp == 0)
        {
            perRes = persB ;
            fwrite(&perRes , sizeof(t_pers) , 1 ,pfRes) ;
            fread(&persA , sizeof(t_pers) , 1 ,pfA) ;
            fread(&persB , sizeof(t_pers) , 1 , pfB) ;
        }
        if(comp > 0)
        {
            perRes = persB ;
            fwrite(&perRes , sizeof(t_pers) , 1 , pfRes) ;
            fread(&persB , sizeof(t_pers) , 1 , pfB) ;
        }
    }
    while(!feof(pfA))
    {
        perRes = persA ;
        fwrite(&perRes , sizeof(t_pers) , 1 , pfRes) ;
        fread(&persA , sizeof(t_pers) , 1 , pfA) ;
    }
    while(!feof(pfB))
    {
        perRes = persB ;
        fwrite(&perRes , sizeof(t_pers) , 1 , pfRes) ;
        fread(&persB , sizeof(t_pers) , 1 , pfB) ;

    }

}


void apareo_Interseccion (FILE *pfA , FILE *pfB , FILE *pfRes)
{
    t_pers persA , persB , persRes ;
    int comp ;

    fread(&persA , sizeof(t_pers) , 1 , pfA) ;
    fread(&persB , sizeof(t_pers) , 1 , pfB) ;

    while(!feof(pfA) && !feof(pfB))
    {
        comp = cmpXdni(&persA , &persB) ;
        if(comp == 0)
        {
            persRes = persB ;
            fwrite(&persRes , sizeof(t_pers) , 1 , pfRes) ;
            fread(&persA , sizeof(t_pers) , 1 , pfA) ;
            fread(&persB , sizeof(t_pers) , 1 , pfB) ;
        }
        if(comp < 0)
        {
            fread(&persA , sizeof(t_pers) , 1 ,pfA) ;
        }
        if(comp > 0)
        {
            fread(&persB , sizeof(t_pers) , 1 ,pfB) ;
        }
    }
}

void apareo_Diferencia (FILE *pfA , FILE *pfB , FILE *pfRes)
{
    t_pers persA , persB , persRes ;
    int comp ;

    fread(&persA , sizeof(t_pers) , 1 , pfA) ;
    fread(&persB , sizeof(t_pers) , 1 , pfB) ;

    while(!feof(pfA) && !feof(pfB))
    {
        comp = cmpXdni(&persA , &persB) ;
        if(comp < 0) ///el de A no esta en B
        {
            persRes = persA ;
            fwrite(&persRes , sizeof(t_pers) , 1 , pfRes) ;
            fread(&persA , sizeof(t_pers) , 1 , pfA) ;
        }
        if(comp == 0)
        {
            persRes = persB ;
            fread(&persA , sizeof(t_pers) , 1 ,pfA) ;
            fread(&persB , sizeof(t_pers) , 1 , pfB) ;
        }
        if(comp > 0)
        {
            fread(&persB , sizeof(t_pers) , 1 , pfB) ;
        }
    }
    while(!feof(pfA))
    {
        persRes = persA ;
        fwrite(&persRes , sizeof(t_pers) , 1 , pfRes) ;
        fread(&persA , sizeof(t_pers) , 1 , pfA) ;
    }
}


int cmpXdni (const t_pers *d1 , const t_pers *d2)
{
    if(d1->dni > d2->dni)
        return 1 ;
    if(d1->dni < d2->dni)
        return -1 ;
    return 0 ;
}
