#include <string.h>
#include <iostream>

using namespace std;

class Circulo
{
    float x,
          y ;
    unsigned diam ;
    char *color ;

    public:
            Circulo(float x = 0.0 , float y = 0.0 , unsigned diam = 0 , const char *color="Blanco") ;
            Circulo(const Circulo& obj) ;

            friend ostream& operator << (ostream& sal , const Circulo& obj) ;
            friend istream& operator >> (istream& ent , Circulo& obj) ;

            Circulo& operator++ () ;    ///pre
            Circulo operator++ (int) ; ///post

            Circulo operator-- (int) ;
            Circulo& operator = (const Circulo& obj) ;

            void cambiarColor (const char *nue) ;
};


int main()
{
    Circulo c1(10.5, 20.0, 1, "Rojo Intenso"),
            c2,
            c3;

//    cout << c1  <<endl ;
//    cin >> c3 ;
//    cout << c3 ;

    c2 = c1--;    /// decrementa, si se puede, el diámetro

    c3 = c2++;    /// incrementa, si se puede, el diámetro

    Circulo c4 = c3++;

    c4.cambiarColor("Amarillo patito fluo");
    cout << c4 ;
    cout << c1 << c2 << c3 << (c4 = c3) << endl;

    return 0;
}

Circulo::Circulo(float x , float y  , unsigned diam  , const char *color)
{
    this->x = x ;
    this->y = y ;
    this->diam = diam ;

    this->color = new char[strlen(color) + 1];
    strcpy(this->color , color) ;
}

Circulo::Circulo(const Circulo& obj)
{
    x = obj.x ;
    y = obj.y ;
    diam = obj.diam ;
    color = new char[strlen(obj.color) + 1] ;
    strcpy(color , obj.color) ;
}

ostream& operator << (ostream& sal , const Circulo& obj)
{
    sal << "x: " << obj.x << endl
        << "Y: " << obj.y << endl
        << "Diametro: " << obj.diam << endl
        << "Color: " << obj.color << endl ;
    return sal ;
}

istream& operator >> (istream& ent , Circulo& obj)
{
    cout << "Ingrese x: " ;
    ent >> obj.x ;
    cout << "Ingrese y: " ;
    ent >> obj.y ;
    cout << "Ingrese diametro: " ;
    ent >> obj.diam ;
    cout << "Ingrese color: " ;
    ent >> obj.color ;

    return ent ;
}

Circulo& Circulo::operator++()
{
    diam++ ;
    return *this ;
}

Circulo Circulo::operator++(int)
{
    Circulo aux(*this);
    diam++ ;
    return aux ;
}

Circulo Circulo::operator--(int)
{
    Circulo aux(*this) ;
    diam-- ;
    return aux ;
}

Circulo& Circulo::operator=(const Circulo& obj)
{
    this->x = obj.x ;
    this->y = obj.y ;
    this->diam = obj.diam ;
    this->color = new char[strlen(obj.color) + 1] ;
    strcpy(color , obj.color) ;

    return *this ;
}

void Circulo::cambiarColor(const char *nue)
{
    delete[]color ;
    color = new char [strlen(nue) + 1] ;
    strcpy(color , nue) ;
}
