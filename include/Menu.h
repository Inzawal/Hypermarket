#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <limits>
#include "Fecha.h"
#include "CierreZ.h"
#include "Hypermarket.h"
#include "ArchivoProveedor.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCierreZ.h"
using namespace std;

class Menu
{
private:
    char opcion;

public:
    void OpcionNoValida();

    char validarChar();
    int validarInt(int, int, string);

    void menuHypermarket(Fecha);
    int menuProveedor();
    char menuCierreZ(Fecha, float ventasTotalesHoy);
    void menuEmpleado(Fecha);
    void menuInventario();
};

#endif // MENU_H
