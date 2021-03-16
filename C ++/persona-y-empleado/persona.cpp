
#include "persona.h"


using namespace std;

#define DEPURAR

char *Persona::duplicarCadena(const char *s)const
{
    if(s && *s)
    {
        try
        {
            char *aux = new char[strlen(s) + 1];
            return strcpy(aux, s);
        }
        catch (std::bad_alloc &)
        {
        /// se debería lanzar una excepción a ser atrapada en el método
        ///    que utilice este método
        /// optaremos por no producir excepciones, que el programa siga adelante
        ///     mostrando un mensaje de error identificando el método en que se
        ///     produzca el error
        /// el mensaje a mostrar en el método en particular será
        ///     cerr << "ERROR: Sin Memoria en ... ." << endl;
        }
    }
    return NULL;
}
//*/
Persona::Persona(long dni, const char *ape, const char *nom, char sex)
    : dni(dni), sex(sex)
{
    this->ape = duplicarCadena(ape);
    this->nom = duplicarCadena(nom);
    if((ape && *ape && this->ape == NULL) ||
       (nom && *nom && this->nom == NULL))
        cerr << "ERROR - sin memoria 'constructor parametrizado' de Persona"
             << endl;
#ifdef DEPURAR
    cout << "Constructor parametrizado de Persona:  " << this << endl;
#endif // DEPURAR
}

Persona::~Persona(void)
{
    delete [] nom;
    delete [] ape;
    ape = NULL;
    nom = NULL;
#ifdef DEPURAR
    cout << "Destructor de Persona:  " << this << endl;
#endif // DEPURAR
}

Persona::Persona(const Persona &obj)
    : dni(obj.dni), ape(duplicarCadena(obj.ape)), nom(duplicarCadena(obj.nom)),
      sex(obj.sex)
{
    if((obj.ape && this->ape == NULL) ||
       (obj.nom && this->nom == NULL))
        cerr << "ERROR - sin memoria 'constructor de copia' de Persona"
             << endl;
#ifdef DEPURAR
    cout << "Constructor de copia de Persona: " << this << endl;
#endif // DEPURAR
}

ostream &operator <<(ostream &sal, const Persona &obj)
{
    sal << "D. N. I.:    " << obj.dni << endl
        << "Apellido(s): " << (obj.ape ? obj.ape : "") << endl
        << "Nombre(s):   " << (obj.nom ? obj.nom : "") << endl
        << "Sexo:        " << obj.sex << endl;
    return sal;
}

istream &operator >>(istream &ent, Persona &obj)
{
    ent.ignore(50000, '\n');
    cout << "D. N. I.:    ";
    ent >> obj.dni;

    ent.ignore(50000, '\n');
    cout << "Apellido(s): ";
    char cad[500];
    ent.getline(cad, sizeof(cad), '\n');
    delete []obj.ape;
    obj.ape = obj.duplicarCadena(cad);

    ent.ignore(50000, '\n');
    cout << "Nombre(s):   ";
    ent.getline(cad, sizeof(cad), '\n');
    delete []obj.nom;
    obj.nom = obj.duplicarCadena(cad);

    ent.ignore(50000, '\n');
    cout << "Sexo:        ";
    ent >> obj.sex;

    return ent;
}

Persona &Persona::operator =(const Persona &obj)
{
    dni = obj.dni;
    delete []nom;
    delete []ape;
    nom = duplicarCadena(obj.nom);
    ape = duplicarCadena(obj.ape);
    sex = obj.sex;
    if((obj.ape && ape == NULL) ||
       (obj.nom && nom == NULL))
        cerr << "ERROR - sin memoria 'operator =' de Persona"
             << endl;
#ifdef DEPURAR
    cout << "Operador de asignacion entre Personas:  " <<
            this << " = " << &obj << endl;
#endif // DEPURAR
    return *this;
}

bool Persona::operator !=(const Persona &obj)const
{
    if(dni != obj.dni || sex != obj.sex)
        return true;
    if((ape == NULL && obj.ape != NULL) ||
       (ape != NULL && obj.ape == NULL) ||
       (ape && obj.ape && strcmp(ape, obj.ape)))
        return true;
    if((nom == NULL && obj.nom != NULL) ||
       (nom != NULL && obj.nom == NULL) ||
       (nom && obj.nom && strcmp(nom, obj.nom)))
        return true;
    return false;
}

