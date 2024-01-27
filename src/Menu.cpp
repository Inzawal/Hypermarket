#include "Menu.h"

void Menu::OpcionNoValida()
{

    cout<< "Opcion no valida, por favor seleccione un valor permitido. ";
    _getch();

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char Menu::validarChar()
{
    char opcionChar;

    cin >> opcionChar;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Extrae los caracteres sobrantes

    if (cin.fail())                                                         // En caso de fallo, borra los contenidos de opcionChar
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        opcionChar = '\0';
    }

    cout << endl;
    return opcionChar;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Menu::validarInt(int numeroMenor, int numeroMayor, string frase)
{
    int opcionInt;
    cin >> opcionInt;

    if(numeroMayor == 0)
    {
        while(cin.fail() || opcionInt < numeroMenor)
        {
            cout << endl;
            cin.clear(); // Restablecer el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Extrae los caracteres sobrantes

            OpcionNoValida();

            cout << endl << endl;
            cout << frase;
            cin >> opcionInt;
        }
        return opcionInt;
    }
    else
    {
        while(cin.fail() || opcionInt < numeroMenor || opcionInt > numeroMayor )
        {
            cout << endl;
            cin.clear(); // Restablecer el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            OpcionNoValida();

            cout << endl << endl;
            cout << frase;
            cin >> opcionInt;
        }
        return opcionInt;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///MENU DEL HYPERMARKET
void Menu::menuHypermarket(Fecha fecha)   // Despliega un menu desde donde podemos acceder a las multiples opciones de Hypermarket
{

    CierreZ cierre;
    Hypermarket mercado;
    float ventasTotalesHoy = 0;

    do
    {
        system("cls");
        cout << "+=====================+" << endl;
        cout << "|-----HYPERMARKET-----|" << endl;
        cout << "|                     |" << endl;
        cout << "| 1 - COMPRAR         |" << endl;
        cout << "| 2 - VENDER          |" << endl;
        cout << "| 3 - CIERRE Z        |" << endl;
        cout << "| 4 - EMPLEADOS       |" << endl;
        cout << "| 5 - INVENTARIO      |" << endl;
        cout << "|                     |" << endl;
        cout << "| 0 - SALIR           |" << endl;
        cout << "+=====================+" << endl;

        cout << "QUE OPCION DESEA SELECCIONAR?: ";

        opcion = validarChar();

        switch(opcion)
        {

        case '1':
            mercado.comprar();
            break;

        case '2':
            ventasTotalesHoy = mercado.vender(ventasTotalesHoy);
            break;

        case '3':
            opcion = menuCierreZ(fecha, ventasTotalesHoy);
            break;

        case '4':
            menuEmpleado(fecha);
            break;

        case '5':
            menuInventario();
            break;

        case '0':
            break;

        default:
            OpcionNoValida();
            break;
        }
    }
    while(opcion != '0');
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Menu::menuProveedor()
{
    ArchivoProveedor archiProveedor;

    do
    {
        system("cls");
        cout << "+=====================+" << endl;
        cout << "|------PROVEEDOR------|" << endl;
        cout << "|                     |" << endl;
        cout << "| 1 - BEBIDA          |" << endl;
        cout << "| 2 - ROPA            |" << endl;
        cout << "| 3 - COMIDA          |" << endl;
        cout << "| 4 - ART. LIMPIEZA   |" << endl;
        cout << "|                     |" << endl;
        cout << "| 0 - ATRAS           |" << endl;
        cout << "+=====================+" << endl;
        cout << "QUE TIPO DE PRODUCTO ESTA BUSCANDO?: ";

        opcion = validarChar();

        switch(opcion)
        {

        case '1':
            archiProveedor.listadoProductos(1);
            return 1;
            break;
        case '2':
            archiProveedor.listadoProductos(2);
            return 2;
            break;
        case '3':
            archiProveedor.listadoProductos(3);
            return 3;
            break;
        case '4':
            archiProveedor.listadoProductos(4);
            return 4;
            break;

        case '0':
            break;

        default:
            OpcionNoValida();
            break;
        }
    }
    while(opcion != '0');
    opcion='1';
    return 0;       // Tiene que tener el return 0, en caso que no querramos comprar nada asi salimos de la funcion

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///MENU DEL CIERRE Z
char Menu::menuCierreZ(Fecha fecha, float ventasTotalesHoy)
{
    ArchivoCierreZ archivoCierreZ;
    char menuHypermarket = '1';

    do
    {
        system("cls");
        cout << "+======================+" << endl;
        cout << "|-------CIERRE Z-------|" << endl;
        cout << "|                      |" << endl;
        cout << "| 1 - ULTIMO CIERRE    |" << endl;
        cout << "| 2 - ULTIMA SEMANA    |" << endl;
        cout << "| 3 - BUSCAR CIERRE    |" << endl;
        cout << "| 4 - HACER  CIERRE    |" << endl;
        cout << "|                      |" << endl;
        cout << "| 0 - ATRAS            |" << endl;
        cout << "+======================+" << endl;

        cout << "QUE OPCION DESEA SELECCIONAR?: ";

        opcion = validarChar();

        switch(opcion)
        {

        case '1':
            archivoCierreZ.leerUltimoArchivo();
            break;

        case '2':
            archivoCierreZ.leerUltimaSemana();
            break;

        case '3':
            archivoCierreZ.buscarPorFecha();
            break;

        case '4':
            opcion = archivoCierreZ.hacerCierreZ(fecha.getDia(), fecha.getMes(), fecha.getAnio(), ventasTotalesHoy);
            menuHypermarket = '0';  // Cierra la terminal
            break;

        case '0':
            break;

        default:
            OpcionNoValida();
            break;
        }
    }
    while(opcion != '0');
    return menuHypermarket;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///MENU DEL EMPLEADO
void Menu::menuEmpleado(Fecha fecha)
{
    ArchivoEmpleados archiEmpleado;

    do
    {
        system("cls");
        cout << "+===========================+" << endl;
        cout << "|-----MENU DE EMPLEADOS-----|" << endl;
        cout << "|                           |" << endl;
        cout << "| 1 - LISTAR EMPLEADOS      |" << endl;
        cout << "| 2 - ALTA EMPLEADO         |" << endl;
        cout << "| 3 - BAJA EMPLEADO         |" << endl;
        cout << "| 4 - MODIFICAR EMPLEADO    |" << endl;
        cout << "| 5 - LISTAR PERMISOS       |" << endl;
        cout << "| 6 - BUSCAR EMPLEADO       |" << endl;
        cout << "| 7 - PAGOS                 |" << endl;
        cout << "|                           |" << endl;
        cout << "| 0 - ATRAS                 |" << endl;
        cout << "+===========================+" << endl;

        cout << "QUE OPCION DESEA SELECCIONAR?: ";

        opcion = validarChar();

        switch(opcion)
        {

        case '1':
            archiEmpleado.ListarEmpleados();
            break;

        case '2':
            archiEmpleado.AltaEmpleado(fecha);
            break;

        case '3':
            archiEmpleado.BajaEmpleado();
            break;

        case '4':
            archiEmpleado.ModificarEmpleado();
            break;

        case '5':
            archiEmpleado.ListadoPermisos();
            break;
        case '6':
            archiEmpleado.BuscarEmpleado();
            break;

        case '7':
            archiEmpleado.PagarEmpleado();
            break;

        case '0':
            break;

        default:
            OpcionNoValida();
            break;
        }
    }
    while(opcion != '0');
    opcion= '1';

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///MENU DEL INVENTARIO
void Menu::menuInventario()
{
    ArchivoHypermarket archiHypermarket;

    do
    {
        system("cls");
        cout << "+========================+" << endl;
        cout << "|-------INVENTARIO-------|" << endl;
        cout << "|                        |" << endl;
        cout << "| 1 - BEBIDA             |" << endl;
        cout << "| 2 - ROPA               |" << endl;
        cout << "| 3 - COMIDA             |" << endl;
        cout << "| 4 - ART. LIMPIEZA      |" << endl;
        cout << "| 5 - TODOS LOS PRODUCTOS|" << endl;
        cout << "|                        |" << endl;
        cout << "| 0 - ATRAS              |" << endl;
        cout << "+========================+" << endl;
        cout << "QUE TIPO DE PRODUCTO ESTA BUSCANDO?: ";

        opcion = validarChar();

        switch(opcion)
        {

        case '1':
            archiHypermarket.listadoProductos(1, true);
            break;
        case '2':
            archiHypermarket.listadoProductos(2, true);
            break;
        case '3':
            archiHypermarket.listadoProductos(3, true);
            break;
        case '4':
            archiHypermarket.listadoProductos(4, true);
            break;
        case '5':
            archiHypermarket.listadoProductos(5, true);
            break;

        case '0':
            break;

        default:
            OpcionNoValida();
            break;
        }

    }
    while(opcion != '0');
    opcion ='1';
}

