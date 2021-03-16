#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int d,
        m,
        a ;
}t_fecha ;

typedef struct
{
    long dni ;
    char apyn[36] ;
    char sex ;
    t_fecha fec ;
    float importe ;

}t_pers ;

void crearArchivoBin (void) ;
void crearArchivoTxt (void) ;
void mostrarArch (FILE *pf) ;

int main()
{
    FILE *pfDatos ;

    pfDatos = fopen("datosBin" , "rb") ;
    if(pfDatos == NULL)
    {
        printf("no existe ") ;
        return 0;
    }

    ///crearArchivoTxt() ;
    ///crearArchivoBin() ;
    mostrarArch(pfDatos) ;

    return 0;
}

void crearArchivoBin (void)
{
    FILE *fp ;
    t_pers vec[] = { {11111111 , "Fernandez, Niko", 'M' , {22,02,1960} , 11115.5},
                     {22222222 , "Cyc, Juan", 'M' , {9,04,2010} , 10519.8},
                     {33333333 , "Fernandez, Juan" , 'M' , {27,8,1985} , 29500.99} } ;

    fp = fopen("datosBin" , "wb") ;

    if (fp)
    {
        fwrite(vec , sizeof(vec) , 1 , fp) ;
        fclose(fp) ;
    }

}

void crearArchivoTxt (void)
{
    FILE *fp ;
    char vec[] = { "11111111|Fernandez, Niko|M|22/02/1960|11115.5 \n"
                   "22222222|Cyc, Juan|M|9/04/2010|10519.8 \n"
                   "33333333|Fernandez, Juan|M|27/8/1985|29500.99 \n" } ;

    fp = fopen("datosTxt.txt" , "wt") ;

    if (fp)
    {
        fprintf(fp , "%s" , vec) ;

        fclose(fp) ;
    }

}

void mostrarArch (FILE *pf)
{
    t_pers pers;

    fread(&pers , sizeof(t_pers) , 1 , pf) ;

    while( !feof(pf) )
    {
        printf("DNI : %ld\n" , pers.dni) ;

        printf("Apellido(s), Nombre(s): %s\n" , pers.apyn ) ;

        printf("Sexo (M/F): %c\n" , pers.sex);

        printf("Fecha (dd/mm/aaa): %d/%d/%d\n" , pers.fec.d , pers.fec.m , pers.fec.a ) ;

        printf("Importe: %.2f\n" , pers.importe ) ;

        puts("") ;

        fread(&pers , sizeof(t_pers) , 1 , pf) ;
    }
}
