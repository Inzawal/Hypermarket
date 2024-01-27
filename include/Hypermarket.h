#ifndef HYPERMARKET_H
#define HYPERMARKET_H
#include<iostream>
#include "Menu.h"
#include "ArchivoHypermarket.h"
#include "ArchivoProveedor.h"
#include "ArchivoEmpleados.h"
#include "ArchivoCierreZ.h"
#include "Fecha.h"
#include "CierreZ.h"

using namespace std;


class Hypermarket
{
private:
    float _fondos = 0;

public:

    void comprar();
    float vender(float ventasTotalesHoy);
};

#endif // HYPERMARKET_H
