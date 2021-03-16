#include "cola_estatica.h"
#include "menu.h"
#include "archivo.h"

int main()
{
    char opcion ;
    int sigue = 1 ;
    FILE *fpDatos ;
    tCola cola ;
    tInfo info ;

    crearCola(&cola) ;
    if(abrirArchivo(&fpDatos , "datos" , "rb" , CON_MSJ))
    {
        fread(&info , sizeof(tInfo) , 1 , fpDatos) ;
        while(!feof(fpDatos) && sigue)
        {
            if(!ponerEnCola(&cola , &info))
            {
                puts("cola llena\n sigue adelante") ;
                sigue=0 ;
            }
            else
                fread(&info , sizeof(tInfo) , 1 ,fpDatos);
        }
        fclose(fpDatos) ;
    }
    do
    {
        opcion = mostrarOpciones(&cola) ;
        switch(opcion)
        {
        case 'V':verPrimeroCola(&cola , &info) ;
                mostrarInfo(&info) ;
                break ;
        case 'S':sacarDeCola(&cola , &info) ;
                mostrarInfo(&info) ;
                break ;
        case 'P':ingresarInfo(&info) ;
                ponerEnCola(&cola , &info) ;
        }
    }while(opcion!='0') ;

    if(abrirArchivo(&fpDatos , "datos" , "wb" , CON_MSJ))
    {
        while(!colaVacia(&cola) && sacarDeCola(&cola , &info))
        {
            fwrite(&info , sizeof(tInfo) , 1 , fpDatos) ;
            mostrarInfo(&info) ;
        }
        fclose(fpDatos) ;
    }
    else
        puts("error") ;

    return 0;
}
