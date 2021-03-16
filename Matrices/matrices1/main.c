#include <stdio.h>
#include <stdlib.h>
#define FILAS 4
#define COLUMNAS 4
#define TAM 4

void cargarMat (int m [][TAM]) ;
void mostrarMat (int m [][TAM]) ;
void trasponer (int m [][TAM]) ;
void trasponer_fila_medio (int m[][TAM]) ;
int suma (int tope) ;
int suma_diagp_sup (int m [][TAM]) ;
int suma_diags_sup (int m [][TAM]) ;
int suma_diagp_sup_incluida (int m [][TAM]) ;
int suma_diags_sup_incluida (int m [][TAM]) ;
int suma_diagp_inf (int m [][TAM]) ;
int suma_diags_inf (int m [][TAM]) ;
int trazaDiagPrincipal (int m [][TAM]) ;
int trazaDiagSecundaria (int m [][TAM]) ;
int esMatrizIdentidad (int m [][TAM]) ;
int esMatrizSimetrica (int m [][TAM]) ;
int esMatrizSimetricaDiagonal (int m[][TAM]) ;
int esMatrizDiagonal (int m [][TAM]) ;
void mostrarViborita (int m [][TAM]) ;

int main()
{
    int m[TAM][TAM] ;
    int a ;
    int m2[TAM][TAM] = { {1,8,3,0},{9,5,0,3},{4,0,5,8},{0,4,9,1} } ;
    int m3[TAM][TAM] = { {2,1,0,0},{1,4,0,0},{0,0,4,1},{0,0,1,2} } ;
//    a = suma(5) ;
//    printf("%d" , a) ;

    cargarMat(m) ;
    mostrarMat(m) ;
/*    trasponer(m) ;
    puts("");
    mostrarMat(m) ;
    puts("");
    printf("Suma elementos diagonal principal superior: %d\n" , suma_diagp_sup(m)) ;
    printf("Suma elementos diagonal principal superior incluida: %d\n" , suma_diagp_sup_incluida(m)) ;
    printf("Suma elementos diagonal principal inferior: %d\n" , suma_diagp_inf(m)) ;
    printf("Suma elementos diagonal secundaria superior: %d\n" , suma_diags_sup(m)) ;
    printf("Suma elementos diagonal secundaria superior incluida: %d\n" , suma_diags_sup_incluida(m)) ;
    printf("Suma elementos diagonal secundaria inferior: %d\n" , suma_diags_inf(m)) ;
    printf("Traza Principal (suma elementos de la diag principal): %d\n" , trazaDiagPrincipal(m) ) ;
    printf("Traza Secundaria (suma elementos de la diag secundaria): %d\n" , trazaDiagSecundaria(m) ) ;
*//*
    puts("matriz 2 \n") ;
    mostrarMat(m2) ;
    puts("") ;
    if(esMatrizIdentidad(m2))
        puts("es matriz identidad \n") ;
    else
        puts("no es matriz identidad \n") ;

    puts("matriz 3 \n") ;
    mostrarMat(m3) ;
    puts("") ;
    if(esMatrizSimetrica(m3))
        puts("es matriz simetrica \n") ;
    else
        puts("no es matriz simetrica \n") ;

    puts("matriz 2 \n") ;
    mostrarMat(m2) ;
    puts("") ;
    if(esMatrizDiagonal(m2))
        puts("es matriz diagonal \n") ;
    else
        puts("no es matriz diagonal \n") ;
  puts("\n viborita \n") ;
    mostrarViborita(m) ;
*/   puts("transpuesta respecto fila del medio \n") ;
    trasponer_fila_medio(m) ;
    mostrarMat(m) ;
/*
    if(esMatrizSimetricaDiagonal(m2))
        puts("es simetrica respecto diagonal sec") ;
    else
        puts("no") ;
*/
    return 0;
}

///
void cargarMat (int m [][TAM])
{
    int fi ,
        co ;

    for(fi = 0 ; fi < TAM ; fi ++)
        for (co=0 ; co < TAM ; co++)
                m[fi][co] = rand() % 23 - 5;

}

int suma (int tope)
{
    int acum=0 ;
    while( tope )
    {
        acum += tope ;
        tope -- ;
    }
    return acum ; ///return (1+tope)*tope /2 ;
}

void mostrarMat (int m [][TAM])
{
    int fi ,
        co ;

    for(fi = 0 ; fi <TAM ; fi ++)
        {   for (co=0 ; co < TAM ; co++)
                printf("%3d" , m[fi][co]) ;
                puts("");
        }

}

void trasponer (int m [][TAM])
{
    int aux , fi ,co ;

    for (fi=0 ; fi<TAM-1 ;fi++) ///for (fi = 1 ; fi<tam ; fi++)
        for (co=fi+1 ; co<TAM ; co++) ///for(co=0 ; co<fi ;co++)
    {
        aux = m[fi][co] ;
        m[fi][co] = m[co][fi] ;
        m[co][fi] = aux ;
    }
}

int suma_diagp_sup (int m [][TAM])
{
    int fi, co ,suma=0 ;
    for (fi=0 ; fi<TAM-1 ; fi++)
        for (co=fi+1 ; co<TAM ; co++ )
                suma += m[fi][co] ;
    return suma ;
}

int suma_diagp_sup_incluida (int m [][TAM])
{
    int fi, co ,suma=0 ;
    for (fi=0 ; fi<TAM ; fi++)
        for (co=fi ; co<TAM ; co++ )
                suma += m[fi][co] ;
    return suma ;
}

int suma_diags_sup (int m [][TAM])
{
    int fi , co , suma=0 ;
    for(fi=0 ; fi<TAM-1 ; fi++)
        for(co=0 ; co<TAM-1-fi ; co++)
        suma += m[fi][co] ;
    return suma ;
}

int suma_diags_sup_incluida (int m [][TAM])
{
    int fi , co , suma=0 ;
    for(fi=0 ; fi<TAM ; fi++)
        for(co=0 ; co<TAM-fi ; co++)
        suma += m[fi][co] ;
    return suma ;
}

int suma_diagp_inf (int m [][TAM])
{
    int fi, co ,suma=0 ;
    for (fi=1 ; fi<TAM ; fi++)
        for (co=0 ; co<fi ; co++ )
                suma += m[fi][co] ;
    return suma ;
}

int suma_diags_inf (int m [][TAM])
{
    int fi , co , suma=0 ;
    for(fi=1 ; fi<TAM ; fi++)
        for(co=TAM-1 ; co>TAM-fi-1 ; co--)
        suma += m[fi][co] ;
    return suma ;
}

int trazaDiagPrincipal (int m[][TAM])
{
    int fi , co , suma=0;
    /*for(fi=0 ; fi<TAM ; fi++)
        for(co=fi ; co<fi+1 ; co++)
            suma += m[fi][co] ;
            */
    for(fi=0 ; fi<TAM ; fi++)
        for(co=0 ; co<TAM ; co++)
        {
            if(fi == co)
                suma += m[fi][co] ;
        }
    return suma ;
}

int trazaDiagSecundaria (int m [][TAM])
{
    int fi , co , suma=0 ;
    /*for(fi=0 ; fi<TAM ; fi++)
        for(co=TAM-1-fi ; co>TAM-2-fi ; co--)
            suma += m[fi][co] ;
    */
    for(fi=0 ; fi<TAM ; fi++)
        for(co=0 ; co<TAM ; co++)
        {
            if(fi+co == TAM-1)
                suma += m[fi][co] ;
        }
    return suma ;
}

int esMatrizIdentidad(int m[][TAM])
{
    int fi , co ;
    for(fi=0 ; fi<TAM ; fi++)
        for(co=0 ; co<TAM ; co++)
    {
        if((m[fi][co]!=1 && fi==co) || (m[fi][co]!=0 && fi!=co) )
            return 0 ;
    }
    return 1 ;
}

int esMatrizSimetrica (int m [][TAM])
{
    int fi , co ;
    for(fi=0 ; fi<TAM ; fi++)
        for(co=0 ; co<TAM ; co++)
    {
        if( m[fi][co]!=m[co][fi] )
            return 0 ;
    }
    return 1 ;
}

int esMatrizSimetricaDiagonal (int m[][TAM])
{
    int fi , co ;
    for(fi=0 ; fi<TAM-1 ; fi++)
        for(co=TAM-2-fi ; co >= 0; co--)
    {
        if(m[fi][co] != m[TAM-co-1][TAM-fi-1])
            return 0 ;
    }
    return 1 ;
}

int esMatrizDiagonal (int m [][TAM])
{
    int fi , co ;
    for(fi=0 ; fi<TAM ; fi++)
        for(co=0 ; co<TAM ; co++)
    {
        if( (fi==co && m[fi][co]==0) || (fi!=co && m[fi][co]!=0) )
            return 0 ;
    }
    return 1 ;
}

void mostrarViborita (int m [][TAM])
{
    int fi , co ;
    for(fi=0 ; fi<TAM ; fi++)
    {
        if(fi%2 == 0)
        {
            for(co=0 ; co<TAM ; co++)
                printf("%3d" , m[fi][co]) ;
                puts("") ;
        }
        else
        {
            for(co=3 ; co>=0 ; co--)
                printf("%3d" , m[fi][co]) ;
                puts("") ;
        }
    }
}

void trasponer_fila_medio (int m[][TAM])
{
    int fi , fi2 , co ,aux;

    for(fi=0 , fi2=FILAS-1 ; fi<fi2 ; fi++ ,fi2--)
        for(co=0 ; co<COLUMNAS ; co++)
        {
            aux = m[fi][co] ;
            m[fi][co] = m[fi2][co] ;
            m[fi2][co] = aux ;
        }
}
