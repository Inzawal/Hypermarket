#ifndef ARCHIVOPROVEEDOR_H
#define ARCHIVOPROVEEDOR_H
#include<iostream>
#include "Producto.h"
#include "Menu.h"
using namespace std;

class ArchivoProveedor
{
public:
    void listadoProductos(int);
    void cargarProducto();
    float precioYproducto(int idCompra, int tipoProducto);
};

#endif // ARCHIVOPROVEEDOR_H
