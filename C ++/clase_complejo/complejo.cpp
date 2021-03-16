#include "complejo.h"

#include <iostream>

using namespace std;
/*
Complejo::Complejo()
{
    re = 0 ;
    im = 0 ;
}

Complejo::Complejo(float re)
{
    this->re = re ;
    im = 0 ;
}

Complejo::Complejo(float re , float im)
{
    this->re = re ;
    this->im = im ;
}
*/
Complejo::Complejo(float re , float im)
{
    this->re = re ;
    this->im = im ;

    //cout << "Ejecutando Constructor, ID: " << this << endl ;
}

Complejo::~Complejo()
{
    //cout << "Ejecutando Destructor Para " << this << endl ;
}

Complejo::Complejo(const Complejo&obj)
{
    re = obj.re ;
    im = obj.im ;
}

ostream& operator << (ostream& salida , const Complejo& obj)
{
    salida << "Parte real: " << obj.re << "\n"
           << "Parte imaginaria: " << obj.im << "\n" << endl ;

    return salida ;
}

istream& operator >> (istream& entrada , Complejo &obj)
{
    cout << "Ingrese parte real: " << endl ;
    entrada >> obj.re ;
    cout << "Ingrese parte imaginaria: " << endl ;
    entrada >> obj.im ;

    return entrada ;
}

Complejo& Complejo::operator = (const Complejo &obj)
{
    re = obj.re ;
    im = obj.im ;

    return *this ;
}

Complejo Complejo::operator + (const Complejo &obj) const
{
    Complejo aux(re + obj.re , im + obj.im) ;

    return aux ;
}

Complejo Complejo::operator + (const float &m) const
{
    Complejo aux(re + m , im) ;

    return aux ;
}

Complejo operator + (const float &m , const Complejo &obj)
{
    Complejo aux(m + obj.re , obj.im) ;

    return aux ;
}

Complejo& Complejo::operator ++()
{
    re ++ ;
    im ++ ;
    return *this ;
}

Complejo Complejo::operator ++(int )
{
    Complejo aux(*this)  ;
    re++ ;
    im++ ;
    return aux ;
}

bool Complejo::operator == (const Complejo &obj) const
{
    return (re == obj.re && im == obj.im) ;
}

bool Complejo::operator > (const Complejo &obj) const
{
    return (re > obj.re || im > obj.im) ;
}

bool Complejo::operator < (const Complejo &obj) const
{
    return (re < obj.re || im < obj.im) ;
}

bool Complejo::operator != (const Complejo &obj) const
{
    return (re != obj.re || im != obj.im ) ;
}

Complejo & Complejo::operator += (const Complejo& obj)
{
    im += obj.im ;
    re += obj.re ;

    return *this ;
}

void Complejo::mostrar() const
{
    cout << "parte real: " << re << "\n" << "parte imaginaria: " << im <<"\n"<< endl ;
}
