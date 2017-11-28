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

using namespace std;

int main()
{
    string name;
    Persona x;
    cin>>name;
    x.setName(name);
    cout<<x.getName();
    return 0;
}
