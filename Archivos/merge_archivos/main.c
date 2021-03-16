#include "archivo.h"

int main()
{
    FILE *pfPers1 , *pfPers2 , *pfResultado ;

/*   if(!abrirArchivo(&pfPers1 , "personas1" , "rb" , CON_MSJ))
        return 2 ;
    if(!abrirArchivo(&pfPers2 , "personas2" , "rb" , CON_MSJ))
        return 4 ;
*/
    if(!abrirArchivo(&pfResultado , "interseccion" , "rb" , CON_MSJ))
        return 6 ;

    //apareo_Union(pfPers1 , pfPers1 , pfResultado) ;
    //puts("UNION ok") ;
    //apareo_Interseccion(pfPers1 , pfPers2 , pfResultado) ;
    //puts("INTERSECCION ok") ;
    //apareo_Diferencia(pfPers1 , pfPers2 , pfResultado) ;
    //puts("DIFERENCIA ok") ;
    mostrarArchivo(pfResultado) ;
    puts("") ;

    fclose(pfResultado) ;
    //fclose(pfPers1) ;
    //fclose(pfPers2) ;

    return 0;
}
