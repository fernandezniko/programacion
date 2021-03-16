#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Cadena
{
    private:
            char * cad ;
    public:
            Cadena(const char *cade = NULL) ;
            Cadena(const Cadena& obj) ;
            ~Cadena() ;

            Cadena& operator = (const Cadena& obj) ;
            Cadena operator + (const Cadena& obj) const ; /// c2 + c3
            Cadena operator + (const char *s) const ;
            friend Cadena operator + (const char *s , const Cadena& obj) ;

            friend ostream& operator << (ostream &sal , const Cadena& obj) ;
            friend istream& operator >> (istream &ent , Cadena& obj) ;

            bool operator == (const Cadena& obj) const ;
            bool operator != (const Cadena& obj) const ;
};
#endif // CADENA_H_INCLUDED
