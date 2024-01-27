#ifndef ARCHIVOHYPERMARKET_H
#define ARCHIVOHYPERMARKET_H
#include<iostream>
#include <conio.h>
#include "Producto.h"
#include "Hypermarket.h"
using namespace std;

class ArchivoHypermarket
{
public:
    void listadoProductos(int, bool);
    int stock(int idCompra, int tipoProducto);  //Priv
    void cargarProducto();
    void modificarInventario(bool sumaOresta, int idProducto, int tipoProducto, int cant);
    float precioYproducto(int idCompra, int tipoProducto);  //Priv
    void modificarFondos(float monto); //Priv
    float fondos();
};

#endif // ARCHIVOHYPERMARKET_H
