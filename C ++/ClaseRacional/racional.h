#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED

#include <stdio.h>
#include <iostream>

using namespace std;

class Racional
{
    private:
            int numerador,
                denominador ;
    public:
            Racional(int numerador = 1 , int denominador = 1) ;

            friend ostream& operator << (ostream& sal , const Racional& obj) ;
            friend istream& operator  >> (istream& ent ,Racional& obj) ;

            Racional operator + (const Racional& obj) const ;
            Racional operator + (int n) const ;
            friend Racional operator + (int n , const Racional& obj) ;

            Racional operator * (const Racional& obj) const ;

            bool operator != (const Racional& obj) const ;

            float real() ;

            int obtenerMcd(int a , int b) ;
            void racionalizar () ;

};


#endif // RACIONAL_H_INCLUDED
