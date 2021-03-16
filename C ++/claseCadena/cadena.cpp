#include "cadena.h"
#include <iostream>

using namespace std;

Cadena::Cadena(const char *cade)
{
    if(cade)
    {
        this->cad = new char[strlen(cade) + 1] ;
        strcpy(this->cad , cade) ;
    }
    else
        this->cad = NULL ;
}

Cadena::~Cadena()
{
    delete[]cad ;
}

Cadena::Cadena(const Cadena& obj)
{
    cad = new char [ strlen(obj.cad) ] ;
    strcpy(cad , obj.cad) ;
}

ostream& operator << (ostream& sal , const Cadena& obj)
{
    sal << "cad: " << obj.cad << endl ;

    return sal ;
}

istream& operator >> (istream& ent , Cadena& obj)
{
    cout << "Ingrese cadena: "  ;
    ent >> obj.cad ;

    return ent ;
}

bool Cadena::operator == (const Cadena& obj) const
{
    if(strcmp(this->cad , obj.cad) == 0)
        return true  ;
    return false ;
    //return strcmp(cad , obj.cad) == 0 ;
}

bool Cadena::operator != (const Cadena& obj) const
{
    if(strcmp(cad , obj.cad))
        return true ;
    return false ;
}

Cadena& Cadena::operator = (const Cadena& obj)
{
    this->cad = new char[strlen(obj.cad) + 1] ;
    strcpy(this->cad , obj.cad) ;

    return *this ;
}

Cadena Cadena::operator + (const Cadena& obj) const
{
    Cadena aux ;

    aux.cad = new char [strlen(cad) + strlen(obj.cad) + 1] ;
    strcpy(aux.cad , cad) ;
    strcat(aux.cad , obj.cad) ;

    return aux ;
}

Cadena Cadena::operator+(const char *s) const
{
    Cadena aux ;

    aux.cad = new char [strlen(cad) + strlen(s) + 1] ;
    strcpy(aux.cad , cad) ;
    strcat(aux.cad , s) ;

    return aux ;
}

Cadena operator + (const char *s , const Cadena& obj)
{
    Cadena aux ;

    aux.cad = new char[strlen(s) + strlen(obj.cad) + 1] ;
    strcpy(aux.cad , s) ;
    strcat(aux.cad , obj.cad) ;

    return aux ;
}
