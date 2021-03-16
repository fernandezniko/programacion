#include <stdio.h>
#include <stdlib.h>

#define FI1     2
#define CO1FI2  3
#define CO2     4

void  multiplicar (int m1[][CO1FI2] , int m2[][CO2] , int r[][CO2]) ;
void  mostrarMat (int m[][CO2]) ;

int main()
{
    int m1[FI1][CO1FI2] = {{8,9,9} , {1,7,5}} ,
        m2[CO1FI2][CO2] = {{5,10,1,0} , {7,7,5,8} , {6,7,3,7}} ,
        res[FI1][CO2] ;

    multiplicar(m1 , m2 , res) ;
    mostrarMat(res) ;

    return 0;
}


void  mostrarMat (int m[][CO2])
{
    int fi , co ;

    for(fi=0 ; fi<FI1 ; fi++)
        {for(co=0 ; co<CO2 ; co++)
            printf("%03d\t" , m[fi][co]) ;
            puts("\n") ;
        }

}
void  multiplicar (int m1[][CO1FI2] , int m2[][CO2] , int r[][CO2])
{
    int fi , co , ciclo;

    for(fi=0 ; fi<FI1 ; fi++)
        for(co=0 ; co<CO2 ; co++)
    {
        r[fi][co] = 0 ;

        for(ciclo=0 ; ciclo < CO1FI2 ; ciclo++)
            r[fi][co] += m1[fi][ciclo] * m2[ciclo][co] ;
    }
}
