#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <string.h>
#include <stddef.h>

using namespace std;


class Persona
{
private :
    long    dni;
    char   *ape,
           *nom,
            sex;

public :
    Persona(long dni = 0,
            const char *ape = "",
            const char *nom = NULL,
            char sex = ' ');
    ~Persona(void);
    Persona(const Persona &obj);
    Persona &operator =(const Persona &obj);

    friend ostream &operator <<(ostream &sal, const Persona &obj);
    friend istream &operator >>(istream &ent, Persona &obj);

    bool operator !=(const Persona &obj)const;

protected :
    char *duplicarCadena(const char *s)const;

};

#endif
