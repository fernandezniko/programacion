#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t mi_strcspn (const char *s1 , const char *s2) ;

int main()
{
    char cad[] = "Hola a todos" ;
    char c[] = "abcd" ;
    puts(cad) ;
    puts(c) ;

    printf("my_strcspn: %d" , mi_strcspn(cad , c)) ;

    return 0;
}

size_t mi_strcspn (const char *s1 , const char *s2)
{

    const char *pri = s2 ;
    size_t c=0 ;

    while(*s1)
    {
        while(*s2)
        {

            if(*s1 == *s2)
                return c ;
            else
                s2++ ;

            if(!*s2)
            {
                s2 = pri ;
                s1++ ;
                c++ ;
            }
        }
    }

    return c ;
    /*
    size_t cant=0 ;
    while(*s1 && !strchr(s2 , *s1))
    {
        cant++ ;
        s1++ ;
    }
    return cant ;
    */
}
