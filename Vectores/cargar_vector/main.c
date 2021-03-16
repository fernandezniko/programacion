#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 30

int cargar (int *v , int posiIni) ;
void mostrar (int *v , int posiIni) ;
char menu (const char *msj , const char *opc) ;

int main()
{
    int vec[TAM] ,
        cargados=0 ;

    cargados = cargar(vec , cargados) ;
    mostrar(vec , cargados) ;
    //cargados = cargar(vec , cargados) ;
    //mostrar(vec , cargados) ;

    return 0;
}

///
char menu (const char *msj , const char *opc)
{
    char opcion ;
    do
    {
        printf("%s" , msj) ;
        fflush(stdin) ;
        scanf("%c" , &opcion) ;

    }while (!strchr(opc , opcion)) ;

    return opcion ;
}


int cargar (int *v , int posiIni)
{
   v += posiIni ;
   while(posiIni < TAM && toupper( menu("Cargar? (S/N): " , "SNsn") )== 'S')
   {
       printf("Ingrese elemento: ") ;
       fflush(stdin);
       scanf("%d" , v);
       posiIni++ ;
       v++ ;
   }
   return posiIni ;
}


void mostrar (int *v , int posiIni)
{
    int i ;
    for (i=0 ; i<posiIni ; i++)
    {
        printf("%d " , *(v+i)) ;

    }
    puts("");
}
