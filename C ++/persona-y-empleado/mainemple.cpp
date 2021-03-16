
#include "mainemple.h"


using namespace std;

int main()
{
    Empleado e1,
             e2,
             e3(22333444, "Martinez del Campo", "Maria Pia de los Angeles", 'f',
                NULL,
                "Jefa de Seccion Contrataciones de Servicios de Terceros"),
             e4(44333222, "Sa", "Leo", 'M',
                "44SLM22",
                "Operario de Limpieza");

    cout << "Antes:" << endl;
    cout << "1er empleado" << endl << e1 << endl;
    cout << "2do empleado" << endl << e2 << endl;
    cout << "3er empleado" << endl << e3 << endl;
    cout << "4to empleado" << endl << e4 << endl;

    e1 = e2 = e3;

    cout << "El 1er empleado y el 2do empleado son "
         << (e1 != e2 ? "distintos." : "iguales.") << endl;

    cout << endl << "Despues:" << endl;
    cout << "1er empleado" << endl << e1 << endl;
    cout << "2do empleado" << endl << e2 << endl;
    cout << "3er empleado" << endl << e3 << endl;
    cout << "4to empleado" << endl << e4 << endl;

    return 0;
}


