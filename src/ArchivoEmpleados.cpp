#include "ArchivoEmpleados.h"

void ArchivoEmpleados::AltaEmpleado(Fecha fecha)   // Agrega un nuevo empleado al local o recontrata a un empleado previamente despedido.
{
    Empleado empleado;
    Menu validacion;
    FILE* e;
    int IDempleado;

    e = fopen("Empleados.dat","rb+");
    if(e == NULL)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO EMPLEADO" << endl;
        return;
    }

    cout << "Introduzca el ID del empleado: ";
    IDempleado = validacion.validarInt(1, 0, "Introduzca el ID del empleado: ");
    cout << endl;

    while(fread(&empleado, sizeof(Empleado), 1, e) != 0)
    {
        if(IDempleado == empleado.getId() && empleado.getEstadoLaboral() == false)
        {
            empleado.setEstadoLaboral(true);
            empleado.setDia(fecha.getDia());
            empleado.setMes(fecha.getMes());
            empleado.setAnio(fecha.getAnio());
            fseek(e, -sizeof(Empleado), SEEK_CUR);
            fwrite(&empleado, sizeof(Empleado), 1, e);
            fclose(e);
            return;
        }
        else if(IDempleado == empleado.getId() && empleado.getEstadoLaboral() == true)
        {
            cout << "Este empleado ya se encuentra contratado." << endl;
            _getch();
            fclose(e);
            return;
        }
    }
    empleado.Cargar(IDempleado, fecha);
    fwrite(&empleado, sizeof(Empleado), 1, e);
    fclose(e);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoEmpleados::BuscarEmpleado()   // Enseña un empleado especifico usando su ID
{
    Empleado empleado;
    Menu validacion;
    FILE* e;
    int id;

    e = fopen("Empleados.dat","rb");
    if(e == NULL)
    {
        cout << "ERROR DE LECTURA, NO SE PUDO BUSCAR AL EMPLEADO" << endl;
        return;
    }

    cout << "ID DEL EMPLEADO QUE BUSCA: ";
    id = validacion.validarInt(1, 0, "ID DEL EMPLEADO QUE BUSCA: ");
    cout << endl;

    while(fread(&empleado,sizeof(Empleado),1,e)!=0)
    {
        if(empleado.getId()==id)
        {
            empleado.Mostrar();
            fclose(e);
            _getch();
            return;
        }
    }

    cout << "EL EMPLEADO NO SE ENCUENTRA REGISTRADO." << endl;
    fclose(e);
    _getch();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoEmpleados::BajaEmpleado()   // Da de baja a algun empleado que se desee
{
    Empleado empleado;
    Menu validacion;
    FILE *e;
    int IDempleado;
    bool doyDeBaja;

    e = fopen("Empleados.dat", "rb+");
    if(e == NULL)
    {
        cout << "No se pudo acceder al archivo" << endl;
        return;
    }

    cout << "Introduzca el ID del empleado que desea dar de baja: ";
    IDempleado = validacion.validarInt(1, 0, "Introduzca el ID del empleado que desea dar de baja: ");
    cout << endl;

    while(fread(&empleado, sizeof(Empleado), 1, e) != 0)
    {
        if(IDempleado == empleado.getId() && empleado.getEstadoLaboral() == true)   // Si encuentra al empleado, verifica que sea el que se quiere dar de baja
        {
            empleado.Mostrar();
            cout << "Es este el empleado que desea dar de baja? (Si = 1 | No = 0): ";
            doyDeBaja= validacion.validarInt(0, 1, "Es este el empleado que desea dar de baja? (Si = 1 | No = 0): ");
            cout << endl;
            if(doyDeBaja == true)
            {
                empleado.setEstadoLaboral(false);
                fseek(e, -sizeof(Empleado), SEEK_CUR);
                fwrite(&empleado, sizeof(Empleado), 1, e);
                cout << "Cambio realizado con exito!" << endl;
                _getch();
                fclose(e);
                return;
            }
            else
            {
                fclose(e);
                return;
            }
        }
    }
    cout << "El empleado no existe o ya se encuentra dado de baja." << endl;
    _getch();
    fclose(e);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoEmpleados::ModificarEmpleado()   // Modifica el sueldo y/o el cargo de un empleado especifico
{
    FILE *e;
    Empleado empleado;
    Menu validacion;
    int IDempleado, cargoNuevo;
    float sueldoNuevo;
    bool modifico;

    e = fopen("Empleados.dat", "rb+");
    if(e == NULL)
    {
        cout << "No se pudo acceder al archivo" << endl;
        return;
    }

    cout << "ID de empleado: ";
    IDempleado = validacion.validarInt(1, 0, "ID de empleado: ");
    cout << endl;

    while(fread(&empleado, sizeof(Empleado), 1, e) != 0)
    {
        if(IDempleado == empleado.getId() && empleado.getEstadoLaboral() == true)   // Si encuentra al empleado, verifica que sea el que se quiere modificar
        {
            empleado.Mostrar();
            cout << "Es este el empleado que desea modificar? (Si = 1 | No = 0): ";
            modifico = validacion.validarInt(0, 1, "Es este el empleado que desea modificar? (Si = 1 | No = 0): ");
            cout << endl;
            if(modifico == true)
            {
                cout << "Nuevo sueldo: $";
                sueldoNuevo = validacion.validarInt(0, 0, "Nuevo sueldo: $");
                cout << endl;

                cout << "Nuevo cargo: ";
                cargoNuevo = validacion.validarInt(1, 4, "Nuevo cargo: ");
                cout << endl;

                empleado.setCargo(cargoNuevo);  // Guarda los cambios realizados y sale de la funcion.
                empleado.setSueldo(sueldoNuevo);
                fseek(e, -sizeof(Empleado), SEEK_CUR);
                fwrite(&empleado, sizeof(Empleado), 1, e);
                fclose(e);
                cout << "Cambios realizados con exito!" << endl;
                _getch();
                return;
            }
            else                                                            // En caso de equivocarse de ID, sale de la funcion.
            {
                fclose(e);
                return;
            }
        }
    }
    cout << "El empleado no existe o ya se encuentra dado de baja." << endl;
    _getch();
    fclose(e);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoEmpleados::ListarEmpleados()   //Muestra un listado con todos los empleados
{
    FILE* p;
    Empleado empleado;

    p = fopen("Empleados.dat","rb");
    if(p == NULL)
    {
        cout << "ERROR DE LECTURA, NO SE PUDO ABIR EL ARCHIVO" << endl;
        return;
    }

    while(fread(&empleado,sizeof(Empleado),1,p) != 0)
    {
        empleado.Mostrar();
    }
    _getch();
    fclose(p);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoEmpleados::ListadoPermisos()   // Muestra los permisos de los empleados
{
    cout << "El empleado tendra los permisos que le asigna su nivel, asi como todos los anteriores." << endl << endl;
    cout << "+================================================================================+" << endl;
    cout << "LIMPIEZA: Limpieza del establecimiento." << endl;                                                                        // Limpieza
    cout << "REPOSITOR: Reposicion de gondolas y contabilidad del stock." << endl;                                              // Repositor
    cout << "CAJERO: Manejo de caja registradora." << endl;                                                                         // Cajero
    cout << "GERENTE: Manejo de Stock con Proveedores. CierreZ" << endl;                                                      // Gerente
    cout << "JEFE: Contratacion o Despido de personal. Pagos y cambios de sueldo o ascenso" << endl;           // Jefe
    cout << "+================================================================================+" << endl;
    _getch();
    system("cls");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ArchivoEmpleados::PagarEmpleado() // En caso de ser posible, paga el sueldo al empleado con los fondos del local.
{
    FILE *e, *h;
    Empleado empleado;
    Menu validacion;
    ArchivoHypermarket fondosHypermarket;
    int IDempleado;
    bool pago;

    e = fopen("Empleados.dat", "rb");
    if(e == NULL)
    {
        cout << "No se pudo acceder al archivo Empleados.dat." << endl;
        return;
    }

    h = fopen("fondosHypermarket.dat", "rb+");
    if(h == NULL)
    {
        cout << "No se pudo acceder al archivo fondosHypermarket.dat." << endl;
        return;
    }

    fread(&fondosHypermarket, sizeof(ArchivoHypermarket), 1, h);

    cout << "ID del empleado: ";
    IDempleado = validacion.validarInt(1, 0, "ID de empleado: ");
    cout << endl;

    while(fread(&empleado, sizeof(Empleado), 1, e) != 0)
    {
        if(IDempleado == empleado.getId() && empleado.getEstadoLaboral() == true)   // Si coincide el ID, pregunta si ese es el empleado que se estaba buscando
        {
            empleado.Mostrar();
            cout << "Es este el empleado al que desea pagar? (Si = 1 | No = 0): ";
            pago = validacion.validarInt(0, 1, "Es este el empleado al que desea pagar? (Si = 1 | No = 0): ");
            cout << endl;
            if(pago == true)
            {
                if(fondosHypermarket.fondos() - empleado.getSueldo() >= 0)       // Siempre que los fondos no queden en valores negativos, realiza el pago
                {
                    fondosHypermarket.modificarFondos(fondosHypermarket.fondos() - empleado.getSueldo());
                    fseek(h, 0, SEEK_SET);
                    fwrite(&fondosHypermarket, sizeof(ArchivoHypermarket), 1, h);
                    fclose(h);
                    fclose(e);
                    cout << "Pago realizado con exito!" << endl;
                    _getch();
                    return;
                }
                else
                {
                    cout << "El pago no puede realizarse debido a fondos insuficientes." << endl;
                    _getch();
                    fclose(h);
                    fclose(e);
                    return;
                }
            }
            else                                                       // Si el ID no era el que se buscaba, sale de la funcion
            {
                fclose(e);
                fclose(h);
                return;
            }
        }
    }

    cout << "El ID es inexistente, o se encuentra dado de baja." << endl;
    _getch();
    fclose(e);
    fclose(h);
}
