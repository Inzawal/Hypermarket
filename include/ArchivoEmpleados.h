#ifndef ARCHIVOEMPLEADOS_H_INCLUDED
#define ARCHIVOEMPLEADOS_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include "Empleado.h"
#include "Hypermarket.h"
#include "Fecha.h"
#include "Menu.h"
using namespace std;

class ArchivoEmpleados
{
public:
    void AltaEmpleado(Fecha);
    void BuscarEmpleado();
    void BajaEmpleado();
    void ModificarEmpleado();
    void ListarEmpleados();
    void ListadoPermisos();
    void PagarEmpleado();
};


#endif // ARCHIVOEMPLEADOS_H_INCLUDED
