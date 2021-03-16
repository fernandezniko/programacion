#include <iostream>

using namespace std;
#include "racional.h"

Racional::Racional(int num , int deno)
{
    int mcd = obtenerMcd(num , deno) ;
    if(deno)
    {
        if(mcd)
        {
            this->numerador = num / mcd ;
            this->denominador = deno / mcd ;
        }
        else
        {
            this->numerador = num ;
            this->denominador = deno ;
        }
    }
    else
        this->numerador = 0 ;


}

ostream& operator << (ostream& sal , const Racional &obj)
{
    sal << obj.numerador << "/" << obj.denominador << endl ;

    return sal ;
}

istream& operator >> (istream& ent , Racional &obj)
{
    cout << "Ingrese numerador: " ;
    ent >> obj.numerador  ;
    cout << "Ingrese denominador: " ;
    ent >> obj.denominador  ;

    return ent ;
}

Racional Racional::operator+(const Racional& obj) const
{
    int num , den ;

    num = this->numerador * obj.denominador + obj.numerador * this->denominador ;
    den = this->denominador * obj.denominador ;

    Racional aux(num , den) ;
    return aux ;
}

Racional Racional::operator+(int n) const
{
    Racional aux(this->numerador + n , this->denominador + n) ;

    return aux ;
}

Racional operator+(int n , const Racional& obj)
{
    Racional aux(n + obj.numerador , n + obj.denominador) ;

    return aux ;
}

Racional Racional::operator*(const Racional& obj) const
{
    Racional aux(this->numerador * obj.numerador , this->denominador * obj.denominador) ;

    return aux ;
}

bool Racional::operator!=(const Racional& obj) const
{
    return (this->numerador != obj.numerador || this->denominador != obj.denominador );
}

int Racional::obtenerMcd(int a , int b)
{
    if(b == 0)
        return a ;
    return obtenerMcd(b , a%b) ;
}

float Racional::real()
{
    return (float)numerador/denominador ;
}

void Racional::racionalizar ()
{
    int mcd = obtenerMcd(numerador , denominador) ;

    numerador = numerador/mcd ;
    denominador = denominador/mcd ;
}
