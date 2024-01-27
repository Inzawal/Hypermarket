#ifndef ARCHIVOCIERREZ_H
#define ARCHIVOCIERREZ_H
#include <conio.h>
#include "CierreZ.h"
#include "Fecha.h"

class ArchivoCierreZ
{
public:

    char hacerCierreZ(int dia, int mes, int anio, float totalFondos);     // Realiza en cierre de jornada y cierra la terminal
    void leerUltimoArchivo();                                                        // Enseña el ultimo CierreZ realizado
    void leerUltimaSemana();                                                        // Enseña los ultimos 7 CierreZ realizados
    void buscarPorFecha();                                                           // Enseña el CierreZ que estemos buscando segun su fecha
    void inicializarFecha(int &dia, int &mes, int &anio);                   // Apenas iniciamos el programa, carga la fecha siguiente.
};

#endif // ARCHIVOCIERREZ_H
