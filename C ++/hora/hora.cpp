
#include "hora.h"


using namespace std;

Hora::Hora(int hh, int mm, int ss)
    : hh(hh), mm(mm), ss(ss)
{
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
    AcomodarHora();
#ifdef DEPURAR
    cout << "Constructor parametrizado - objeto: " << this << endl;
#endif // DEPURAR
}

#ifdef DEPURAR
Hora::Hora(const Hora &obj)
{
    hh = obj.hh;
    mm = obj.mm;
    ss = obj.ss;
    AcomodarHora();
    cout << "Constructor de copia - objeto: " << this << endl;
}

Hora::~Hora(void)
{
    cout << "Destructor - objeto: " << this << endl;
}

Hora &Hora::operator =(const Hora &obj)
{
    hh = obj.hh;
    mm = obj.mm;
    ss = obj.ss;
    cout << "ejecutando 'operator =' con: " << this << " = " << &obj << endl;
    return *this;
}

#endif // DEPURAR

void Hora::Mostrar(void) const
{
    cout << hh << ':' << mm << ':' << ss;
}

ostream &operator <<(ostream &sal, const Hora &obj)
{
    sal << obj.hh << ':' << obj.mm << ':' << obj.ss;
    return sal;
}

void Hora::AcomodarHora(void)
{
    long segundos = hh * 3600L + mm * 60 + ss;
    segundos %= 86400L;
    if(segundos < 0)
        segundos += 86400L;
    hh = segundos / 3600;
    ss = segundos % 60;
    mm = segundos / 60 % 60;
}

Hora Hora::operator +(const Hora &obj) const
{
/// Hora aux(hh + obj.hh, mm + obj.mm, ss + obj.ss);
/// return aux;
    return Hora(hh + obj.hh, mm + obj.mm, ss + obj.ss);
}

Hora Hora::operator -(tSegundos ss) const
{
/// Hora aux(hh, mm, this->ss - ss);
/// return aux;
    return Hora(hh, mm, this->ss - ss);
}

Hora Hora::operator -(tMinutos mm) const
{
/// Hora aux(hh, this->mm - mm, ss);
/// return aux;
    return Hora(hh, this->mm - mm, ss);
}

Hora Hora::operator -(tHoras hh) const
{
/// Hora aux(this->hh - hh, mm, ss);
/// return aux;
    return Hora(this->hh - hh, mm, ss);
}

Hora operator +(tSegundos ss, const Hora &obj)
{
    return Hora(obj.hh, obj.mm, obj.ss + ss);
}

Hora &Hora::operator ++(void)     /// pre
{
    ss++;
    return *this;
}

Hora Hora::operator ++(int)       /// pos
{
    Hora aux(*this);
    ss++;
    return aux;
}

bool Hora::operator >(const Hora &obj) const
{
    return hh * 3600L + mm * 60 + ss > obj.hh * 3600L + obj.mm * 60 + obj.ss
                ? true : false;

//    if(hh > obj.hh)
//        return true;
//    if(hh == obj.hh && mm > obj.mm)
//        return true;
//    if(hh == obj.hh && mm == obj.mm && ss > == obj.ss)
//        return true;
}

