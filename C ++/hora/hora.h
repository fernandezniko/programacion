#ifndef HORA_H_
#define HORA_H_

#include <iostream>

/// si no se declara esta etiqueta, no ejecutará cosas innecesarias
#define DEPURAR

typedef long long       tSegundos;
typedef long            tMinutos;
typedef int             tHoras;

using namespace std;

class Hora
{
    int     hh,
            mm,
            ss;

    friend ostream &operator <<(ostream &sal, const Hora &obj);
    friend Hora operator +(tSegundos ss, const Hora &obj);
    void AcomodarHora(void);

public :
    Hora(int hh = 0, int mm = 0, int ss = 0);
#ifdef DEPURAR
    Hora(const Hora &obj);
    ~Hora(void);
    Hora &operator =(const Hora &obj);
#endif // DEPURAR
    void Mostrar(void) const;
    Hora operator +(const Hora &obj) const;
    Hora operator -(tSegundos ss) const;
    Hora operator -(tMinutos mm) const;
    Hora operator -(tHoras hh) const;
    Hora &operator ++(void);    /// pre
    Hora operator ++(int);      /// pos
    bool operator >(const Hora &obj) const;
};

#endif // HORA_H_


