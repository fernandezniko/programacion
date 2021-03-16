#include "stdio.h"
#include <iostream>

using namespace std;

#include "complejo.h"

int main()
{
    Complejo c1 , c2 , c3(10 , 5) , c4 , c5 , c6;
/*
    c1.mostrar() ;
    c2.mostrar() ;
    c3.mostrar() ;
*/
    cout << "C3: \n" << c3 << endl ;
    c4 = c3 ;
    cout << "C4 = C3" << endl ;
    cout << "C4: \n" << c4 << endl ;
    c1 = c3 + c4 ;
    cout << "C1 = C3 + C4" << endl ;
    cout << "C1: \n" << c1 << endl ;
/*
    c5 = c4++ ;
    cout << "DESPUES PRE/POS INCREMENTO" << endl ;
    cout << "C5: \n" << c5 << endl ;
    cout << "C4: \n" << c4 << endl ;

    c1 = c3 + c5 ;
    c2 = c3 + 7 ;
    c6 = 7 + c3 ;
    cout << "DESPUES DE LA SUMA \n" << endl ;
    cout << "C1 = C3 + C5" << endl ;
    cout << "C1: \n" << c1 << endl ;
    cout << "C2 = C3 + 7" << endl ;
    cout << "C2: \n" << c2 << endl ;
    cout << "C6 = 7 + C3" << endl ;
    cout << "C6: " << c6 << endl ;

    cout << "ingreso de un complejo" << endl ;
    cin >> c6 ;
    cout << "C6: " << c6 << endl ;
    */
    if(c3 == c4)
        cout << "SON IGUALES \n" << endl ;
    else
        cout << "SON DISTINTOS \n" << endl ;

    cout << "C3: " << c3 ;
    c3 += c4 ;
    cout << "C3 += C4" << endl ;
    cout << "C3: " << c3 << endl ;

    if(c3 > c4)
        cout << "ES MAYOR \n" << endl ;
    if(c4 < c3)
        cout << "ES MENOR \n" << endl ;
    if(c3 != c1)
        cout << "SON DISTINTOS \n" << endl ;

    return 0;
}
