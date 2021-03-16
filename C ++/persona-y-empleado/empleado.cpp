
#include "empleado.h"

#define DEPURAR

using namespace std;

Empleado::Empleado(long dni, const char *ape, const char *nom, char sex,
             const char *codEmp, const char *cargo)
    : Persona(dni, ape, nom, sex), cargo(duplicarCadena(cargo))
{
    *this->codEmp = '\0';
    if(codEmp && *codEmp)
    {
        strncat(this->codEmp, codEmp, sizeof(this->codEmp) - 1);
        if(strlen(codEmp) >= sizeof(this->codEmp))
            cerr << "ERROR - el argumento 'cargo' excede "
                 << sizeof(this->codEmp) - 1 << "caracteres"
                 << endl;
    }
    if(cargo && *cargo && this->cargo == NULL)
        cerr << "ERROR - sin memoria 'constructor parametrizado' de Empleado."
             << endl;
#ifdef DEPURAR
    cout << "Constructor parametrizado de Empleado: " << this << endl;
#endif // DEPURAR
}

Empleado::~Empleado(void)
{
    delete []cargo;
    cargo = NULL;
#ifdef DEPURAR
    cout << "Destructor de Empleado: " << this << endl;
#endif // DEPURAR
}

ostream &operator <<(ostream &sal, const Empleado &obj)
{
    sal << (const Persona &)obj
        << "Cod. Emple.: " << obj.codEmp << endl
        << "Cargo:       " << (obj.cargo ? obj.cargo : "") << endl;
    return sal;
}

Empleado &Empleado::operator =(const Empleado &obj)
{
    (Persona &)*this = (const Persona &)obj;
    strcpy(this->codEmp, obj.codEmp);
    delete [] cargo;
    cargo = duplicarCadena(obj.cargo);
    if(cargo == NULL && obj.cargo)
        cerr << "ERROR - sin memoria 'operator =' de Empleado." << endl;
#ifdef DEPURAR
    cout << "Operador de asignacion entre Empleados: " <<
            this << " = " << &obj << endl;
#endif // DEPURAR
    return *this;
}

bool Empleado::operator !=(const Empleado &obj)const
{
    if((const Persona &)*this != (const Persona &)obj)
        return true;
    if(strcmp(codEmp, obj.codEmp))
        return true;
    if((cargo == NULL && obj.cargo != NULL) ||
       (cargo != NULL && obj.cargo == NULL) ||
       (cargo && obj.cargo && strcmp(cargo, obj.cargo)))
        return true;
    return false;
}

