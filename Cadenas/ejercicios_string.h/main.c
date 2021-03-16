#include <stdio.h>
#include <string.h>

char * my_strcat (char *s1 , const char *s2) ;
char * my_strncat (char *s1 , const char *s2 , size_t n) ;
char * my_strchr (char *s , int c) ;
char * my_strrchr (char *s , int c) ; ///hacer
int my_strcmp (const char *s1 , const char *s2) ;
int my_strcmp2 (const char *s1 , const char *s2) ;
int my_strncmp (const char *s1 , const char *s2 , size_t n) ; ///hacer
char * my_strcpy (char *s1 , const char *s2) ;
char * my_strncpy (char *s1 , const char *s2 , size_t n) ; ///hacer
size_t my_strlen (const char *s) ;
char * my_strstr (const char *s1 , const char *s2) ;

char a_mayuscula (char c) ;
char a_minuscula (char c) ;

int main()
{   /*
    char strA[80] = "Cadena a usar para el programa de ejemplo";
    char strB[80] = "1234567898765432123456789876543212345678987654321";
    char *pA; /// un apuntador al tipo caracter
    char *pB; /// otro apuntador al tipo caracter

    puts(strA); /// muestra la cadena strA
    pA = strA; /// apunta pA a la cadena strA
    puts(pA); /// muestra a donde apunta pA
    pB = strB; /// apunta pB a la cadena strB
    putchar('\n'); /// dejamos una línea en blanco

    while(*pA != '\0') /// linea A (ver texto)
    {
        *pB++ = *pA++; /// linea B (ver texto)
    }
    *pB = '\0'; /// linea C (ver texto)
    puts(strB); /// muestra strB en la pantalla
    */
    char s1[] = "Y los mios son de acero para darle mas trabajo al zapatero, viva yo he dicho" ;
    char s2[10] = "amigos"  ;
    char s3[] = "niko" ;
    char s4[] = "nIkO" ;
    //char c = 'k' ;
    int i ;
   /* my_strcpy(s2 , s1) ;
    printf("Cadena s1 copiada en s2:  ") ;
    puts(s2) ;
    printf("La cantidad de caracteres de \"%s\" es: %d\n" , s2 , my_strlen(s2)) ;
    printf("Cadena s3 copiada al final de s1:  ") ;
    my_strcat(s1 , s3) ;
    puts(s1) ;
    *///printf("s1= %s \n" , s1 ) ;
    //printf("c= %c \n" , c) ;
    //printf("strchr(s1 , 'y') = %s\n" , my_strchr(s1 , 'y')) ;
    i = my_strcmp2(s3 , s4) ;
    printf("La cadena s3 \"%s\" comparada con la cadena s4 \"%s\" \n" , s3 , s4) ;
    if ( i > 0 )
        printf( "es mayor \n") ;
    else
        if ( i<0 )
            printf("es menor \n");
        else
            printf("es igual \n") ;

    //my_strncat(s1 , s2 , 3) ;
    //puts(s1) ;
    //printf("La primera aparicion de \"%s\" en \"%s\" : %s\n" ,  s4 , s1 , my_strstr(s1 , s4)) ;

    return 0;
}

///
char * my_strcpy (char *destino , const char *fuente)
{
    char *aux ;
    aux = destino ;

    while ( *fuente )
    {
        *aux = *fuente ;
        aux ++ ;
        fuente ++ ;
    }

    *aux = '\0' ;

    return destino ;
}

size_t my_strlen (const char *s)
{
    size_t caracteres=0 ;

    while ( *s )
    {
        caracteres ++ ;
        s++ ;
    }

    return caracteres ;
}

char * my_strcat (char *destino , const char *fuente)
{
    char *aux ;
    aux = destino ;
    while (*aux)
        aux ++ ;
    while (*fuente)
    {
        *aux = *fuente ;
        fuente ++ ;
        aux ++ ;
    }
    *aux = '\0' ;
    return destino ;
}

char * my_strchr (char *s , int c)
{
    char *aux = NULL ;
    while (*s && c != (*s))
        s++ ;

    if (!*s)
        return aux ;
    aux = s ;

    return aux ;
}

int my_strcmp (const char *s1 , const char *s2)
{
    while ( *s1 )
    {
        if ( !*s2 )
            return 1 ;
        if ( *s1 < *s2 )
            return -1 ;
        if ( *s1 > *s2 )
            return 1 ;
        s1++ ;
        s2++ ;
    }
    if ( *s2 )
        return -1 ;

    return 0 ;
}

int my_strcmp2 (const char *s1 , const char *s2)
{
    while ( *s1 )
    {
        if ( *s2 == '\0' )
            return 1 ;
        if ( a_mayuscula(*s1) < a_mayuscula(*s2) )
            return -1 ;
        if ( a_mayuscula(*s1) > a_mayuscula(*s2) )
            return 1 ;
        s1++ ;
        s2++ ;
    }
    if ( *s2 )
        return -1 ;

    return 0 ;
}

char * my_strncat (char *s1 , const char *s2 , size_t n)
{
    int veces=0 ;
    char *aux=s1 ;
    while( *aux )
        aux++ ;
    while( *s2 && veces<n)
    {
        *aux = *s2 ;
        aux++ ;
        s2++ ;
        veces++ ;
    }
    *aux = '\0' ;

    return s1 ;
}

char * my_strstr (const char *s1 , const char *s2)
{
    int cantPal=0 ;
    int seRepite=0 ;
    char *auxs2 = s2 ;
    if(!*s2)
        return (char *) s1 ;
    while( *auxs2 )
    {
        auxs2++ ;
        cantPal++ ;
    }
    while( *s1 && *s2 && seRepite<cantPal)
    {
        if(*s1==*s2)
            {
                seRepite++ ;
                s1++ ;
                s2++ ;
            }
            else
            {
               s1++ ;
               s2 -= seRepite ;
               seRepite=0;
            }
    }
    if(seRepite==cantPal)
        return (char *)s1 - cantPal;

    return NULL ;
}

char a_mayuscula(char c)
{
    return (c >= 'a' && c <= 'z') ? c += ('A' - 'a') : c ;
}

char a_minuscula(char c)
{
    return (c >= 'A' && c <= 'Z') ? c += ('a' - 'A') : c ;
}
