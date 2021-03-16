#include <stdio.h>
#include <stdlib.h>

#define FILA  2
#define COLUM  4
#define CO1_FI2 3

void cargar (int m1[][CO1_FI2] , int m2[][COLUM]) ;
void mostrar_2 (int m1[][CO1_FI2] , int m2[][COLUM]) ;
void mostrar_1 (int r[][COLUM]) ;
void producto_matrices (int r[][COLUM] , int m1[][CO1_FI2] , int m2[][COLUM]) ;

int main()
{
    int m1[FILA][CO1_FI2],
        m2[CO1_FI2][COLUM],
        res[FILA][COLUM];

    cargar(m1 , m2) ;
    mostrar_2(m1 , m2) ;
    producto_matrices(res , m1 , m2) ;
    mostrar_1(res) ;

    return 0;
}
///
void cargar (int m1[][CO1_FI2] , int m2[][COLUM])
{
    int fi , co ;
    //puts("Carga matriz 1");
    for(fi=0 ; fi<FILA ; fi++)
        for(co=0 ; co<CO1_FI2; co++)
            m1[fi][co] = rand() % 11 ;
    //puts("Carga matriz 2");
    for(fi=0 ; fi<CO1_FI2 ; fi++)
        for(co=0 ; co<COLUM ; co++)
            m2[fi][co] = rand() % 11 ;
}

void mostrar_2 (int m1[][CO1_FI2] , int m2[][COLUM])
{
    int fi , co ;
    puts("Matriz 1 \n");
    for(fi=0 ; fi<FILA ; fi++)
        {for(co=0 ; co<CO1_FI2; co++)
               printf("%3d " , m1[fi][co] );
                puts("");
        }
    puts("") ;
    puts("Matriz 2 \n");
    for(fi=0 ; fi<CO1_FI2 ; fi++)
        {for(co=0 ; co<COLUM ; co++)
               printf("%3d " , m2[fi][co] ) ;
                puts("");
        }
        puts("");
}

void mostrar_1 (int r[][COLUM])
{
    int fi , co ;
    puts("Matriz resultado \n") ;
    for(fi=0 ; fi<FILA ; fi++)
    {
        for(co=0 ; co<COLUM ; co++)
            printf("%4d " , r[fi][co]);
             puts("") ;
    }
}

void producto_matrices (int r[][COLUM] , int m1[][CO1_FI2] , int m2[][COLUM])
{
    int fi , co , ciclo ;

    for(fi=0 ; fi<FILA ; fi++)
        for(co=0 ; co<COLUM ; co++)
        {
            r[fi][co] = 0 ;
                for(ciclo=0 ; ciclo < CO1_FI2 ; ciclo++)
                    r[fi][co] += m1[fi][ciclo] * m2[ciclo][co] ;
        }
}
