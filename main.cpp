#include <iostream>
#include "Hypermarket.h"
#include "Producto.h"
#include "ArchivoProveedor.h"
#include "ArchivoHypermarket.h"
#include "ArchivoEmpleados.h"
#include "Fecha.h"
#include <cctype>
using namespace std;

int main()
{

    int dia, mes, anio;
    Hypermarket local;
    Menu menu;
    ArchivoCierreZ cierre;

    cierre.inicializarFecha(dia, mes, anio);
    Fecha fecha(dia, mes, anio);
    menu.menuHypermarket(fecha);

    return 0;
}
