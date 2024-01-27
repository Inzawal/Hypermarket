#include<iostream>
using namespace std;
#include "ArchivoCierreZ.h"

char ArchivoCierreZ::hacerCierreZ(int dia, int mes, int anio, float ventasTotalesHoy)  // Esta funcion carga un nuevo cierreZ
{
    FILE *z;
    CierreZ cierre;

    z = fopen("cierreZ.dat", "rb+");
    if(z == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return 'a';
    }

    fseek(z, 0, SEEK_END);
    cierre.setVentasTotales(ventasTotalesHoy);
    cierre.setDia(dia);
    cierre.setMes(mes);
    cierre.setAnio(anio);
    fwrite(&cierre, sizeof(CierreZ), 1, z);

    fclose(z);

    cout << "Dia finalizado con exito!" << endl;
    return '0';                                              // Tiene que retornar para poder cerrar el programa
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoCierreZ::leerUltimoArchivo()     // Lee el ultimo registro del archivo "cierreZ.dat"
{

    FILE *z;
    CierreZ cierre;

    z = fopen("cierreZ.dat", "rb");
    if(z == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return;
    }

    fseek(z, -(sizeof(cierre)), SEEK_END);    // Se para en el ultimo byte del archivo, pero retrocede la cantidad de bits que pese 1 registro
    fread(&cierre, sizeof(CierreZ), 1, z);     // Gracias a esto nos aseguramos que siempre quede parado en el principio del ultimo registro

    cout << "+========================+" << endl;
    cout << "Fecha del CierreZ: " << cierre.getDia() << "/" << cierre.getMes() << "/" << cierre.getAnio() << endl;
    cout << "Total recaudado: $" << cierre.getVentasTotales() << endl;
    cout << "+========================+" << endl;

    _getch();
    system("cls");
    fclose(z);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoCierreZ::leerUltimaSemana()          // Hace lo mismo que la funcion "leerUltimoArchivo()" solo que lee los ultimos 7 registros.
{

    FILE *z;
    CierreZ cierre;

    z = fopen("cierreZ.dat", "rb");
    if(z == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return;
    }

    fseek(z, -(sizeof(cierre))*7, SEEK_END);              // Al igual que en "leerUltimoArchivo()" se para al final del archivo, pero retrocede 7 veces la cantidad de bits
    while(fread(&cierre, sizeof(CierreZ), 1, z) != 0)   // Que ocupa un registro
    {
        cout << "+========================+" << endl;
        cout << "Fecha del CierreZ: " << cierre.getDia() << "/" << cierre.getMes() << "/" << cierre.getAnio() << endl;
        cout << "Total recaudado: $" << cierre.getVentasTotales() << endl;
        cout << "+========================+" << endl;
    }
    _getch();
    system("cls");
    fclose(z);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoCierreZ::buscarPorFecha(){

    FILE *z;

    CierreZ cierre;
    Menu menu;
    int dia, mes, anio;

    z = fopen("cierreZ.dat", "rb");
    if(z == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return;
    }

    cout << "Introduzca la fecha a buscar: " << endl;
    cout << "Introduzca el dia: ";
    dia = menu.validarInt(1,31,"Introduzca el dia: ");

    cout << "Introduzca el mes: ";
    mes = menu.validarInt(1,12,"Introduzca el mes: ");

    cout << "Introduzca el anio: ";
    anio = menu.validarInt(1,0,"Introduzca el anio: ");

    while(fread(&cierre, sizeof(CierreZ), 1, z) != 0)           // Este While revisa todas las fechas buscando si alguna es igual a la del dia de hoy
    {
        if(cierre.getDia() == dia && cierre.getMes() == mes && cierre.getAnio() == anio)
        {
            cout << "+========================+" << endl;
            cout << "Fecha del CierreZ: " << cierre.getDia() << "/" << cierre.getMes() << "/" << cierre.getAnio() << endl;
            cout << "Total recaudado: $" << cierre.getVentasTotales() << endl;
            cout << "+========================+" << endl;
            fclose(z);
            _getch();
            return;
        }
    }

    cout << "La fecha que ha ingresado no se encuentra dentro de los registros" << endl;    //Si no encuentra una fecha identica, envia este mensaje
    fclose(z);
    _getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoCierreZ::inicializarFecha(int &dia, int &mes, int &anio) // Apenas iniciamos el programa ya carga con una fecha nueva automaticamente
{
    FILE *z;
    CierreZ cierre;

    z = fopen("cierreZ.dat", "rb");
    if(z == NULL)
    {
        cout << "No se ha podido abrir el archivo" << endl;
        return;
    }

    fseek(z, -(sizeof(cierre)), SEEK_END);   // Se para en el ultimo byte del archivo, pero retrocede la cantidad de bits que pese 1 registro
    fread(&cierre, sizeof(CierreZ), 1, z);   // Gracias a esto nos aseguramos que siempre quede parado en el principio del ultimo registro

    Fecha fecha(cierre.getDia(), cierre.getMes(), cierre.getAnio());
    fecha.agregarDias(1);                                                               // Carga la ultima fecha y le suma el dia en 1;

    dia = fecha.getDia();
    mes = fecha.getMes();
    anio = fecha.getAnio();

    fclose(z);
    system("cls");
}
