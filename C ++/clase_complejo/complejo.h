#ifndef COMPLEJO_H_INCLUDED
#define COMPLEJO_H_INCLUDED
#include <iostream>

using namespace std;

class Complejo
{
    private :
            float re,
                  im ;
    public :
            /*Complejo() ; ///CONSTRUCTOR POR DEFECTO
            Complejo(float re ) ; ///CONSTRUCTOR PARAMETRIZADO
            Complejo(float re , float im) ; ///CONSTRUCTOR PARAMETRIZADO
            */
            Complejo(float re=0 , float im=0) ; ///CONSTRUCTOR PARAMETRIZADO CON VALORES POR DEFECTO
            ~Complejo() ; ///DESTRUCTOR; NO HACE FALTA PORQUE NO HAY ASIGNACION DINAMICA DE MEMORIA
            Complejo(const Complejo&obj) ; ///CONSTRUCTOR DE COPIA; NO HACE FALTA PORQUE NO HAY ASIGNACION DINAMICA DE MEMORIA

            friend ostream& operator << (ostream& salida , const Complejo &obj) ;
            friend istream& operator >> (istream& entrada , Complejo &obj) ;

            Complejo& operator = (const Complejo &obj) ;

            Complejo operator + (const Complejo &obj) const ; ///sumo un complejo con otro complejo c1 + c2
            Complejo operator + (const float &m) const ; ///sumo un float a la parte real c1 + 7
            friend Complejo operator + (const float &m , const Complejo &obj) ; ///sumo un float a la parte real 7 + c1

            Complejo & operator += (const Complejo& obj) ;

            Complejo& operator ++ () ;///PRE
            Complejo operator ++ (int) ;///POST

            bool operator == (const Complejo &obj) const ;
            bool operator > (const Complejo &obj) const ;
            bool operator < (const Complejo &obj) const ;
            bool operator != (const Complejo &obj) const ;

            void mostrar() const ;
};

#endif // COMPLEJO_H_INCLUDED
