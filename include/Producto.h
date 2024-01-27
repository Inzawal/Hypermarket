#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<iostream>
#include <cstring>
#include "funciones.h"
#include "Menu.h"

using namespace std;

class Producto
{
private:
    char _nombre[20];
    float _precio;
    int _id, _tipoDeProducto, _cantidad;

public:
    void Cargar();
    void Mostrar(bool cantidad);

    ///Setters:
    void setNombre(char nombre[20]);
    void setPrecio(float);
    void setID(int);
    void setTipoDeProducto(int);
    void setCantidad(int);

    ///Getters:
    const char* getNombre();
    float getPrecio();
    int getID();
    int getTipoDeProducto();
    int getCantidad();
};

#endif // PRODUCTO_H
