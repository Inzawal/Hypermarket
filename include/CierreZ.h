#ifndef CIERREZ_H
#define CIERREZ_H
#include "Fecha.h"
#include "ArchivoCierreZ.h"
#include "Menu.h"

class CierreZ
{
private:

    float _ventasTotales = 0;
    int _dia, _mes, _anio;

public:

    void modificarCierreZ(float venta = 0);

    float getVentasTotales();
    void setVentasTotales(float venta);

    int getDia();
    int getMes();
    int getAnio();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

};

#endif // CIERREZ_H
