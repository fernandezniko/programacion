#include "racional.h"
#include <iostream>

using namespace std;

int main()
{
    Racional r1(42 , 49) ,r2(3,11) ,r3 , r4, r5 , r6, r7(r1+r2);

    cout << r1 ;
/*    r3 = r1 * r2 ;
    r4 = r3 + 5 ;
    r5 = 8 + r3;
    r6 = r3 + r5;
    cout << r1 << r2 << r3 << r4 << r5  << endl;
    if (r5 != r2)
      cout << "Son distintos" << endl;
    // e indique cómo utiliza el método real con el objeto r7
*/
    //cout << r7.real() ;

    return 0;
}
