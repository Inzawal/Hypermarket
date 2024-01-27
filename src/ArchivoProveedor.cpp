#include "ArchivoProveedor.h"


void ArchivoProveedor::cargarProducto()     // Carga nuevos productos al archivo "listadoHypermarket.dat"
{
    FILE *p;
    bool cargOtro = true;

    p = fopen("listadoProductos.dat", "ab");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo ListadoProductos." << endl;
        fclose(p);
        return;
    }

    while(cargOtro)                                   // Mientras que cargOtro sea true, nos pide un nuevo producto a ingresar usando la funcion "cargar()"
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
void ArchivoProveedor::listadoProductos(int tipoDeProducto)     //Enseña un tipo de producto segun la variable "tipoDeProducto"
{
    Producto producto;
    FILE *p;

    p = fopen("listadoProductos.dat", "rb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo ListadoProductos." << endl;
        return;
    }

    while(fread(&producto, sizeof(Producto), 1, p) != 0)
    {
        if(producto.getTipoDeProducto() == tipoDeProducto)
        {
            producto.Mostrar(false);
        }
    }
    fclose(p);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float ArchivoProveedor::precioYproducto(int idCompra, int tipoProd)  // Retorna el precio de un producto en especifico
{
    Producto producto;
    FILE *p;

    p = fopen("listadoProductos.dat", "rb");
    if(p == NULL)
    {
        cout << "No se ha podido abrir el archivo ListadoProductos." << endl;
        return -1;
    }

    while(fread(&producto, sizeof(Producto), 1, p) != 0)    // Si coincide el tipoDeProducto y el ID, retorna el precio de ese producto
    {
        if(producto.getTipoDeProducto()==tipoProd)
        {
            if(idCompra == producto.getID())
            {
                producto.Mostrar(false);
                fclose(p);
                return producto.getPrecio();
            }
        }
    }
    return -1;
}
