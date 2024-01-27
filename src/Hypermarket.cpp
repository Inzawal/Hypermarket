#include "Hypermarket.h"

void Hypermarket::comprar()            // Se utiliza para comprarle productos al Proveedor
{
    Menu menu;
    ArchivoHypermarket archivoDelLocal;
    ArchivoProveedor archivoDelProveedor;

    int idCompra, cantCompra, tipoProd;
    int bucle = 0;
    bool continuar = false;

    float fondos = archivoDelLocal.fondos(); // Traigo los fondos del local

    do
    {
        tipoProd = menu.menuProveedor(); //Accede al menu de productos del proveedor y guarda el tipo de producto ingresado
        if(tipoProd == 0)
        {
            return;
        }

        cout << "Ingrese el ID del producto que desee comprar: (1 a 10): ";
        idCompra = menu.validarInt(1,10, "Ingrese el ID del producto que desee comprar: (1 a 10): ");
        cout << endl;

        system("cls");

        cout << "PRODUCTO SELECCIONADO: " << endl << endl;
        float precio = archivoDelProveedor.precioYproducto(idCompra, tipoProd);    //Accede al menu de productos del proveedor y guarda el precio del producto seleccionado

        cout << "FONDOS: $" << fondos << endl;

        cout << "Desea comprar en unidades o en bultos (10 unidades): (Unidades: U | Bultos: B): ";

        do
        {
            switch(menu.validarChar())   //Una vez elegido el producto, se pregunta por la cantidad deseada del mismo
            {
            case 'u':
            case 'U':

                cout << "Cuantas unidades desea comprar?: ";
                cantCompra = menu.validarInt(1,0,"Cuantas unidades desea comprar?: ");
                cout << endl;
                precio *= cantCompra;
                bucle = 0;
                break;

            case 'b':
            case 'B':

                cout << "Cuantos bultos desea comprar?: "<< endl;
                cantCompra = menu.validarInt(1,0,"Cuantos bultos desea comprar?: ");
                cout << endl;
                cantCompra *= 10;
                precio *= cantCompra;
                precio *= 0.85;              //Comprando al por mayor tenemos un 15% de descuento
                bucle = 0;
                break;

            default:
                menu.OpcionNoValida();

                cout << endl << endl;
                cout << "Desea comprar en unidades o en bultos (10 unidades): (Unidades: U | Bultos: B): ";
                bucle = 1;
                break;
            }
        }
        while (bucle != 0);

        if(fondos - precio < 0)
        {
            cout << "La compra no puede realizarse por falta de fondos." << endl;
            _getch();
            return;
        }
        else
        {
            fondos -= precio;
            archivoDelLocal.modificarFondos(fondos);    //Se actualizan los nuevos fondos del local
            archivoDelLocal.modificarInventario(true, idCompra, tipoProd, cantCompra);  // se actualiza el inventario de productos del local
            cout << "Compra realizada!" << endl;
        }
        cout << "Total gastado: $" << precio << endl; //Si contamos con los fondos suficientes, la compra se realiza con exito, en caso contrario no puede realizarse
        cout << "Fondos actuales: $" <<  archivoDelLocal.fondos() << endl;
        cout << "Quiere hacer otra compra? (Si = 1 | No = 0): ";
        continuar = menu.validarInt(0,1, "Quiere hacer otra compra? (Si = 1 | No = 0): ");
        cout << endl;
    }
    while(continuar == true);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float Hypermarket::vender(float ventasTotalesHoy)      // Se utiliza cuando se hace una venta a algun cliente
{
    system("cls");
    cout << "+======================+" << endl;
    cout << "|--------VENTAS--------|" << endl;
    cout << "+======================+" << endl << endl;

    Menu menu;
    ArchivoHypermarket archivoDelLocal;

    float fondos = archivoDelLocal.fondos();     // Se guardan los fondos del local
    int idCompra, cantCompra, tipoProd;

    cout << "SELECCIONE EL TIPO DE PRODUCTO (1 a 4): ";                       // Se ubica el producto exacto y la cantidad que se esta buscando vender
    tipoProd = menu.validarInt(1,4,"SELECCIONE EL TIPO DE PRODUCTO (1 a 4): ");
    cout << endl;

    switch(tipoProd)
    {
    case 1:
        archivoDelLocal.listadoProductos(1, false);
        break;

    case 2:
        archivoDelLocal.listadoProductos(2, false);
        break;

    case 3:
        archivoDelLocal.listadoProductos(3, false);
        break;

    case 4:
        archivoDelLocal.listadoProductos(4, false);
        break;
    }

    cout << "SELECCIONE EL ID DEL PRODUCTO A VENDER (1 a 10): ";
    idCompra = menu.validarInt(1,10,"SELECCIONE EL ID DEL PRODUCTO A VENDER (1 a 10): ");
    cout << endl;

    float precio = archivoDelLocal.precioYproducto(idCompra, tipoProd);

    cout << "UNIDADES A VENDER: ";
    cantCompra = menu.validarInt(1,0,"UNIDADES A VENDER: ");
    cout << endl;

    if(cantCompra > archivoDelLocal.stock(idCompra, tipoProd))              // Si el Stock es menor a la cantidad que se quiere vender, la venta queda anulada
    {
        //                                                                                      Si es mayor o igual, se hace la venta, se descuenta la cantidad del stock,
        cout << "La venta no se pudo realizar por falta de stock" << endl; // se suma el monto a las ventas totales del dia (CierreZ) y a los fondos del local
        return ventasTotalesHoy;
    }
    else
    {
        precio *= cantCompra;
        cout << "VENTA REALIZADA CON EXITO" << endl;
        cout << "TOTAL DE LA VENTA: $" << precio << endl;

        ventasTotalesHoy += precio;
        fondos += precio;
        archivoDelLocal.modificarFondos(fondos);
        archivoDelLocal.modificarInventario(false, idCompra, tipoProd, cantCompra);
        _getch();
        return ventasTotalesHoy;
    }
}






