#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

#include <iostream>

using namespace std;

class Hora
{
    private :
            int hh,
                mm,
                ss ;

    friend ostream & operator << (ostream &salida , const Hora &obj) ;

    public :
          ///  Hora() ; ///CONSTRUCTOR POR DEFECTO
          ///  Hora(int hh) ;
          ///  Hora(int hh , int mm) ;
          ///  Hora(int hh , int mm , int ss) ;
               Hora(int hh = 0 , int mm = 0 , int ss = 0) ; ///CONSTRUCTOR PARAMETRIZADO CON VALORES POR DEFECTO

               void mostrar (void) const ;

};

#endif // HORA_H_INCLUDED
