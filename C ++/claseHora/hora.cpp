#include <iostream>

using namespace std;

#include "hora.h"

/*Hora::Hora()
//:hh(0) , mm(0) , ss(0)
{
    hh = 0 ;
    mm = 0 ;
    ss = 0 ;
}
*/
Hora::Hora(int hh , int mm , int ss)
//hh(hh , ss(ss) , mm(mm)
{
         this->hh = hh ;
         this->mm = mm ;
         this->ss = ss ;
}

ostream& operator << (ostream& salida , const Hora &obj)
{
    salida << obj.hh << ":"
           << obj.mm << ":"
           << obj.ss ;

    return salida ;
}

void Hora::mostrar(void) const
{
    cout << hh << ":" << mm << ":" << ss ;
}
