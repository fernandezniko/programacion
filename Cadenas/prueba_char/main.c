#include <stdio.h>
#include <stdlib.h>

int main()
{
    char numero=65 ;

    printf("%s" , &numero) ;
    numero++ ;
    printf("%s" , &numero) ;

    return 0;
}
