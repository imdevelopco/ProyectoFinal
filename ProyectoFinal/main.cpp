#include <iostream>
#include "Cliente.h"
#include "Persona.h"
#include "Aerolinea.h"
#include "Aeropuerto.h"
#include "AgenciaDeViaje.h"
#include "CompaniaAerea.h"
#include "Avion.h"
#include "Representante.h"
#include "Silla.h"
#include "Telefono.h"
#include "Tiquete.h"
#include "Control.h"

using namespace std;

int main()
{
    Control control;
    cout << "Agencias al comienzo de la ejecucion" << endl;
    control.listAgencias();
    cout << "Crear una agencia" << endl;
    control.crearAgencia(); //este metodo si esta guardando
    cout << "Agencias depues de la creacon" << endl;
    control.listAgencias(); //pero este metodo no esta mostrando la lista
}
