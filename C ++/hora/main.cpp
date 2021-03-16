
#include "main.h"

using namespace std;

int main()
{
    Hora    h1,
            h2(22),
            h3(22, 33),
            h4(22, 33, 44);
///*
    cout << "h1: ";
    h1.Mostrar();
    cout << endl;
    cout << "h2: ";
    h2.Mostrar();
    cout << endl;
    cout << "h3: " << h3 << endl << "h4: " << h4 << endl << endl;

    cout << "Creando objeto h5 como copia del h4:" << endl;
    Hora    h5(h4);
    cout << "h5: " << h5 << endl << endl;

    cout << "Antes de h1 = h2 = h3:" << endl <<
            "h1: " << h1 << endl <<
            "h2: " << h2 << endl <<
            "h5: " << h5 << endl;
    h1 = h2 = h5;
    cout << "Despues de h1 = h2 = h3:" << endl <<
            "h1: " << h1 << endl <<
            "h2: " << h2 << endl <<
            "h5: " << h5 << endl << endl;

    cout << "Antes de h1(" << h1 << ") = h3(" << h3 << " + h2(" << h2 << ")" <<
            endl;
    h1 = h3 + h2;
    cout << h1 << " = " << h3 << " + " << h2 << endl << endl;


    tSegundos   segundos = 50;
    cout << "Antes de h1(" << h1 << ") = h3(" << h3 << ") - " <<
            segundos << " segundos:" << endl;
    h1 = h3 - segundos;
    cout << "Despues h1 y h3 tienen: " << h1 << " y " << h3 << endl << endl;

    tMinutos minutos = 40;
    cout << "Antes de h1(" << h1 << ") = h3(" << h3 << ") - " <<
            minutos << " minutos:" << endl;
    h1 = h3 - minutos;
    cout << "Despues h1 y h3 tienen: " << h1 << " y " << h3 << endl << endl;

    tHoras horas = 30;
    cout << "Antes de h1(" << h1 << ") = h3(" << h3 << ") - " <<
            horas << " horas:" << endl;
    h1 = h3 - horas;
    cout << "Despues h1 y h3 tienen: " << h1 << " y " << h3 << endl << endl;

    cout << "Antes de los incrementos: " << h5 << endl;
    cout << "mostrando el objeto h5 preincrementado " << ++h5 << endl;
    cout << "mostrando el objeto h5 posincrementado " << h5++ << endl;
    cout << "Después: " << h5 << endl << endl;

    cout << "determinando si h1(" << h1 << ") es mayor que h5(" << h5 << ") ";
    if(h1 > h5)
        cout << "ES MAYOR" << endl;
    else
        cout << "NO ES MAYOR" << endl;
/// */
    return 0;
}
