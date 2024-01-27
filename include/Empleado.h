#ifndef EMPLEADO_H
#define EMPLEADO_H
#include<iostream>
#include <cstring>
#include "Fecha.h"
#include <Menu.h>
using namespace std;

class Empleado
{
private:
    char _nombre[30];
    char _apellido[30];
    int _id;
    float _sueldo;
    char _cargo;
    bool _estadoLaboral;
    int _dia, _mes, _anio;

public:

    void Cargar(int id, Fecha fecha);
    void Mostrar();

    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setId(char id);
    void setSueldo(float sueldo);
    void setCargo(char cargo);
    void setEstadoLaboral(bool estadoLaboral);
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    const char *getNombre();
    const char *getApellido();
    int getId();
    float getSueldo();
    char getCargo();
    bool getEstadoLaboral();
    int getDia();
    int getAnio();
    int getMes();
};

#endif // EMPLEADO_H
