#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#include <iostream>
#include <string.h>

#include "persona.h"


using namespace std;

class Empleado : public Persona
{
    char    codEmp[8],
           *cargo;
public :
    Empleado(long dni = 0L,
             const char *ape = NULL, const char *nom = NULL, char sex = ' ',
             const char *codEmp = NULL, const char *cargo = NULL);
    ~Empleado(void);

    friend ostream &operator <<(ostream &sal, const Empleado &obj);

    Empleado &operator =(const Empleado &obj);
    bool operator !=(const Empleado &obj)const;
};


#endif
