#include "ArchivoHypermarket.h"

void ArchivoHypermarket::cargarProducto()       // Carga nuevos productos al archivo "listadoHypermarket.dat"
{
    FILE *p;
    bool cargOtro = true;

    p = fopen("listadoHypermarket.dat", "ab");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        return;
    }

    while(cargOtro)                                     // Mientras que cargOtro sea true, nos pide un nuevo producto a ingresar usando la funcion "cargar()"
    {
        Producto producto;
        producto.Cargar();
        cout << "========================" << endl;
        fwrite(&producto, sizeof(Producto), 1, p);
        cout << "¡Se ha guardado el producto exitosamente!" << endl;
        cout << "¿Quiere cargar otro producto? (Si = 1 | No = 0): ";
        cin >> cargOtro;
        cout << endl;
        cout << "========================" << endl;
    }
    fclose(p);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoHypermarket::listadoProductos(int tipoDeProducto, bool mostrarFondos )  // Enseña un tipo de producto, o todos
{
    Producto producto;
    FILE *p;

    p = fopen("listadoHypermarket.dat", "rb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        return;
    }

    if(tipoDeProducto==5)                                     // Si la variable "tipoDeProducto" es cinco, enseña todos los contenidos del archivo.
    {
        while(fread(&producto, sizeof(Producto), 1, p) != 0)
        {
            producto.Mostrar(true);
        }
    }
    else                                                            // En otro caso, enseña solo los contenidos que coincidan con el numero de "tipoDeProducto"
    {
        while(fread(&producto, sizeof(Producto), 1, p) != 0)
        {
            if(producto.getTipoDeProducto() == tipoDeProducto)
            {
                producto.Mostrar(true);
            }
        }
    }

    if(mostrarFondos == true){
        cout << endl;
        cout << "Fondos: $" << fondos() << endl;
        _getch();
    }
    fclose(p);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoHypermarket::modificarFondos(float monto)   // modifica el valor de la cantidad de dinero que se encuentra en los fondos del local
{
    FILE *p;

    p = fopen("fondosHypermarket.dat", "wb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo fondosHypermarket." << endl;
        return;
    }

    fwrite(&monto, sizeof(float), 1, p);
    fclose(p);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float ArchivoHypermarket::fondos()       // Retorna la cantidad de fondos con los que contamos actualmente.
{
    FILE *p;
    float fondos;

    p = fopen("fondosHypermarket.dat", "rb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        return -1;
    }

    fread(&fondos, sizeof (float), 1, p);
    fclose(p);
    return fondos;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoHypermarket::modificarInventario(bool aumentar, int idProducto, int tipoProducto, int cant)
{
    // Suma o resta a la cantidad de un determinado producto que tengamos en el inventario.

    Producto producto;
    FILE *p;

    p = fopen("listadoHypermarket.dat", "rb+");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo." << endl;
        return;
    }

    while(fread(&producto, sizeof(Producto), 1, p) != 0)
    {
        if(tipoProducto == producto.getTipoDeProducto() && idProducto == producto.getID())
        {

            if(aumentar == true)   // Si es Bool es verdadero, suma la cantidad de ese producto en la cantidad
            {
                producto.setCantidad(producto.getCantidad()  + cant);
                fseek(p, -sizeof(producto),SEEK_CUR);
                fwrite(&producto, sizeof(Producto), 1, p);
                fclose(p);
                return;
            }
            else                     // Si el bool es falso, resta la cantidad de ese producto en la cantidad.
            {
                producto.setCantidad(producto.getCantidad()  - cant);
                fseek(p, -sizeof(producto),SEEK_CUR);
                fwrite(&producto, sizeof(Producto), 1, p);
                fclose(p);
                return;
            }
        }
    }

    cout << "Ese producto es inexistente." << endl;
    fclose(p);
    _getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float ArchivoHypermarket::precioYproducto(int idCompra, int tipoProd) //Retorna el precio de un producto seleccionado
{
    Producto producto;
    FILE *p;

    p = fopen("listadoHypermarket.dat", "rb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo listadoHypermarket." << endl;
        return -1;
    }

    while(fread(&producto, sizeof(Producto), 1, p) != 0)    // Si coincide el tipoDeProducto y el ID, retorna el precio de ese producto
    {
        if(producto.getTipoDeProducto()==tipoProd && producto.getID() == idCompra)
        {
            producto.Mostrar(true);
            fclose(p);
            return producto.getPrecio();
        }
    }
    fclose(p);
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ArchivoHypermarket::stock(int idCompra, int tipoProd)   // Retorna la cantidad que tenemos de un producto determinado
{
    Producto producto;                                                // Esta funcion no debe validar, dado que previamente siempre vamos a haber validado
    FILE *p;                                                                // Con la funcion precioYproducto()

    p = fopen("listadoHypermarket.dat", "rb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo listadoHypermarket." << endl;
        return -1;
    }

    while(fread(&producto, sizeof(Producto), 1, p) != 0)    // Si coincide el tipoDeProducto y el ID, retorna el precio de ese producto
    {
        if(producto.getTipoDeProducto()==tipoProd && producto.getID() == idCompra)
        {
            fclose(p);
            return producto.getCantidad();
        }
    }
    cout << "Ese producto es inexistente." << endl;
    fclose(p);
    _getch();
    return 0;
}
