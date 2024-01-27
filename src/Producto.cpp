#include "Producto.h"


void Producto::Cargar()     // Se utiliza para crear y cargar al archivo un nuevo producto. Vale aclarar que el Proveedor cuenta con un stock ilimitado
{
    Menu validacion;

    cout << "Nombre: ";
    scanf("%s",_nombre);
    cout << endl;

    cout << "Precio: $";
    _precio = validacion.validarInt(0,0,"Precio: $");
    cout << endl;

    cout << "ID: ";
    _id = validacion.validarInt(1,0,"ID: ");
    cout << endl;

    cout << "Tipo de Producto (1 a 4): ";
    _tipoDeProducto = validacion.validarInt(1,4,"Tipo de Producto (1 a 4): ");
    cout << endl;

    cout << "Cantidad: ";
     _cantidad = validacion.validarInt(1,4,"Cantidad: ");
    cout << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Producto::Mostrar(bool cantidad)    // Ense�a el producto
{
    if(cantidad == true)
    {
        cout << "----------------------" << endl;
        cout << "Nombre: "<< _nombre <<endl;
        cout << "Precio: $" << _precio <<endl;
        cout << "ID: " << _id <<endl;
        cout << "Tipo de Producto: " << _tipoDeProducto <<endl;
        cout << "Cantidad: " << _cantidad << endl;
        cout << "----------------------" << endl << endl;
    }
    else
    {
        cout << "----------------------" << endl;
        cout << "Nombre: "<< _nombre <<endl;
        cout << "Precio: $" << _precio <<endl;
        cout << "ID: " << _id <<endl;
        cout << "Tipo de Producto: " << _tipoDeProducto <<endl;
        cout << "----------------------" << endl << endl;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Producto::setID(int id)
{
    _id = id;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Producto::setNombre(char nombre[20])
{
    strcpy(_nombre, nombre);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Producto::setPrecio(float precio)
{
    _precio = precio;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Producto::setTipoDeProducto(int tipoDeProducto)
{
    _tipoDeProducto = tipoDeProducto;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Producto::setCantidad(int cantidad)
{
    _cantidad = cantidad;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Producto::getID()
{
    return _id;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* Producto::getNombre()
{
    return _nombre;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float Producto::getPrecio()
{
    return _precio;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Producto::getTipoDeProducto()
{
    return _tipoDeProducto;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Producto::getCantidad()
{
    return _cantidad;
}
