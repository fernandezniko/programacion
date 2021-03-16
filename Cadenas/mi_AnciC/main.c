#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * my_strcat (char *s1 , const char *s2) ;
char * my_strchr (char *s , int c) ;
int my_strcmp (const char *s1 , const char *s2) ;
int my_strncmp (const char *s1 , const char *s2 , size_t n) ;
char * my_strcpy (char *s1 , const char *s2) ;
size_t my_strlen (const char *s) ;

int main()
{
    char s1[] = "Hol"  ,
         s2[] = "Holaa" ;
         //c = 'a' ;

    puts(s1) ;
    puts(s2) ;

/*    printf("Despues de strcat: %s\n" , my_strcat(s1 , s2)) ;
    puts(s1) ;
    printf("Despues de strchr: %s\n" , my_strchr(s1 , 'a')) ;
    if(my_strcmp(s1 , s2) == 0)
        puts("Son iguales") ;
    else
        if(my_strcmp(s1 , s2) > 0)
            puts("S1 es mayor a s2") ;
        else
            puts("S1 es menor que s2") ;
    printf("Despues de strcpy: %s\n" , my_strcpy(s1 , s2)) ;
    printf("Longitud de s1: %d\n" , my_strlen(s1)) ;
*/
    if(my_strncmp(s1 , s2 , 3) == 0)
        puts("Son iguales") ;
    else
        if(my_strncmp(s1 , s2 , 3) > 0)
            puts("S1 es mayor a s2") ;
        else
            puts("S1 es menor que s2") ;
    return 0;
}

char * my_strcat (char *s1 , const char *s2)
{
    char *aux=s1 ;

    while(*aux)
        aux++ ;

    while(*s2)
    {
        *aux = *s2 ;
        aux++ ;
        s2++ ;
    }

    *aux = '\0' ;

    return s1 ;
}

char * my_strchr (char *s , int c)
{
    while(*s)
    {
        if(*s == c)
            return s ;
        else
            s++ ;
    }

    return NULL ;
}

int my_strcmp (const char *s1 , const char *s2)
{
    while(*s1)
    {
        if(*s1 == *s2)
        {
            s1++ ;
            s2++ ;
        }
        else
            if(*s1 > *s2)
                return 1 ;
            else
                return -1 ;
    }
    if(*s2)
        return -1 ;

    return 0 ;
}

char * my_strcpy (char *s1 , const char *s2)
{
    char *aux = s1 ;
    while(*s2)
    {
        *s1 = *s2 ;
        s2++ ;
        s1++ ;
    }

    *s1 = '\0' ;

    return aux ;
}

size_t my_strlen (const char *s)
{
    size_t cont=0 ;
    while(*s)
    {
        cont++ ;
        s++ ;
    }
    return cont ;
}

int my_strncmp (const char *s1 , const char *s2 , size_t n)
{
    if(n)
    {
        n-- ;
        while(*s1 && (*s1) == (*s2) && n)
        {
            s1++ ;
            s2++ ;
            n-- ;
        }

        return *s1 - *s2 ;
    }

    return 0 ;
}

