#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pfDatos , *pfError;
    char linea[50] ;
    float importe ;
    long dni ;

    pfError = fopen("error.txt" , "wt") ;
    pfDatos = fopen("datosTxt.txt" , "rt") ;

    if(pfDatos == NULL || pfError == NULL)
    {
        puts("No se pudo acceder") ;
        return 0 ;
    }

    fgets(linea , sizeof(linea) , pfDatos) ;

    while(!feof(pfDatos))
    {
        ///sscanf(linea + 37 , "%f" , &importe) ;
        sscanf(linea , "%ld" , &dni) ;
        if(dni > 10)
        {
            fprintf(pfError , "%s" , linea) ;
        }

        fgets(linea , sizeof(linea) , pfDatos) ;
    }


    return 0;
}
