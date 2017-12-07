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
    cout << "Aerolineas al comienzo de la ejecucion" << endl;
    control.listAerilineas();
    cout << "Crear una aerolinea" << endl;
    control.crearAerolinea(); 
    cout << "Aerolineas depues de la creacon" << endl;
    control.listAerilineas();
}
