#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    ///strchr
    /*char s[12] = "Hola amigos";
    char c = 'a';
    printf( "s=%s \t", s );
    printf( "c=%c \n", c );
    printf( "strchr=%s \n", strchr( s, c ) );

    ///strcmp
    char s1[10] = "niko";
    char s2[10] = "NIKO";
    int i;
    printf( "s1=%s\t", s1 );
    printf( "s2=%s\n", s2 );
    i = strcmp( s1, s2 );
    printf( "s1 es " );
    if( i < 0 ) printf( "menor que" );
    else if( i > 0 ) printf( "mayor que" );
    else printf( "igual a" );
    printf( " s2\n" );
    */
    ///strncat
    /*char s1[11] = "Hola ";
    char s2[8] = "amigos";
    printf( "s1=%s\t", s1 );
    printf( "s2=%s\n", s2 );
    strncat( s1, s2, 3 );
    printf( "s1=%s\n", s1 );
    */
    ///strstr
    /*char s1[13] = "Hola a todos";
    char s2[3] = "la";
    printf( "s1=%s\n", s1 );
    printf( "s2=%s\n", s2 );
    printf( "strstr(s1,s2) = %s\n", strstr( s1, s2 ) );
    */
    ///strcspn
    /*char s1[13] = "Hola a todos";
    char s2[5] = "abcd";
    printf( "s1=%s\n", s1 );
    printf( "s2=%s\n", s2 );
    printf( "strcspn(s1,s2) = %d\n", strcspn( s1, s2 ) );
    */
    ///strpbrk
    char s1[13] = "Hola a todos";
    char s2[5] = "deip";
    printf( "s1=%s\n", s1 );
    printf( "s2=%s\n", s2 );
    printf( "strpbrk(s1,s2) = %s\n", strpbrk( s1, s2 ) );

    return 0;
}
