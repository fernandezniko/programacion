#include "archivo.h"
#include "pila.h"
#include "menu.h"

int main()
{
    FILE *pfDatosPila ;
    t_pers pers ;
    t_pila pila ;
    char opc ;

    if(!abrirArchivo(&pfDatosPila , "datospila" , "r+b" , CON_MSJ))
        return 2 ;

    crearPila(&pila) ;

    fread(&pers , sizeof(t_pers) , 1 , pfDatosPila) ;

    while(!feof(pfDatosPila))
    {
        if(!pilaLlena(&pila))
            ponerEnPila(&pila , &pers) ;

        fread(&pers , sizeof(t_pers) , 1 , pfDatosPila) ;
    }
    ///verTopePila(&pila , &pers) ;
    ///mostrarPers(&pers) ;
    fclose(pfDatosPila) ;

    do
    {puts("*** MENU PILA ***\n") ;
     opc = menu(" P - CARGAR MAS INFO EN PILA \n S - SACAR DE PILA \n V - VER INFO DEL TOPE PILA \n O - SALIR \n : " , "PSVO") ;
     switch(opc)
     {
         case 'P' :
                   if(!pilaLlena(&pila))
                   { ingresarPers(&pers) ;
                     ponerEnPila(&pila , &pers) ;
                   }
                   else
                     puts(" Pila llena \n No se puede cargar mas info...\n") ;
                     break ;
         case 'S' :
                   if(!pilaVacia(&pila))
                     sacarDePila(&pila , &pers) ;
                   else
                     puts(" Pila vacia \n No se puede sacar nada...\n") ;
                     break ;
         case 'V' :
                  if(!pilaVacia(&pila))
                 {   puts("TOPE PILA\n") ;
                     verTopePila(&pila , &pers) ;
                     mostrarPers(&pers) ;
                 }
                  else
                     puts("Pila vacia\n") ;
                     break ;
         //case 'O' : exit(1) ;
     }
    }while(opc != 'O') ;

    if(pilaVacia(&pila))
        fopen("datospila" ,  "wb") ;
    else
        fopen("datospila" , "r+b") ;

    fseek(pfDatosPila , 0L , SEEK_END) ;

    while(!pilaVacia(&pila))
    {   verTopePila(&pila , &pers) ;
        fwrite(&pers , sizeof(t_pers) , 1 , pfDatosPila) ;
        sacarDePila(&pila , &pers) ;
    }
    ///mostrarArchivo(pfDatosPila) ;

    return 0;
}
