#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esAnagrama (char *s1 , char *s2) ;
int esAnagrama2 (char *s1 , char *s2) ;
int compararCadenas (const void * , const void *) ;

int main()
{
    char cad1[] = "mas a ganar" ;
    char cad2[] = "anagrama" ;

    if(esAnagrama(cad1 , cad2))
        printf("es anagrama\n" ) ;
    else
        puts("no es") ;

    return 0;
}

///
int esAnagrama (char *s1 , char *s2)
{
    int esta=0 ;
    char *aux1 = s1 ;

    if( *aux1 == '\0')
        return 0 ;

       while( *s2 )
        {
            if(*s2 == *aux1 && *aux1)
                {   //esta = 1 ;
                    *aux1 = '*' ;
                    aux1 = s1 ;
                    s2++ ;
                }
            else
                aux1++ ;
            //if(esta == 1)
            //    {
            //        s2++ ;
            //        esta = 0 ;
            //    }
            if(*aux1 == '\0')
                return 0 ;
        }


    return 1 ;
}

int compararCadenas (const void *d1 , const void *d2)
{
    char *p1 = (char *)d1 ;
    char *p2 = (char *)d2 ;

    return strcmp(p1 , p2) ;
}

int esAnagrama2 (char *s1 , char *s2)
{
     ///ordenar las dos cadenas y comparo
     if(strlen(s1) == strlen(s2))
     {
        qsort(s1 , strlen(s1) , sizeof(char) , compararCadenas) ;
        qsort(s2 , strlen(s2) , sizeof(char) , compararCadenas) ;
        while( *s1 )
        {   if(*s1 != *s2)
                return 0 ;
            else
            {   s1++ ;
                s2++ ;
            }
        }
     }
     return 1 ;
}


