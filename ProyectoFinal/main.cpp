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
  /*
  int numero = 12; //para ver la direccion de memoria de cualquier variable se usa el & antes de ella
  int *puntero = &numero; //cuando empieza en * es un punturo y guarda direcciones de memoria

  cout << puntero << endl; //si se imprime asi muestra la dirección de memoria
  cout << *puntero << endl; //si se imprime asi muestra el contenido
  */
  time_t date = time(0);
	struct tm birthday = *localtime(&date);
  vector<Telefono> agenda;
  vector<int> aeropuertos;
  vector<Aerolinea> aerolineas;
  vector<Aeropuerto> aeropuertosDestino;

  Telefono telefono("celular", 57, 8828263);
  Telefono telefono2("celular", 57, 856521);
  agenda.push_back(telefono);
  Representante representante("Fernanda", "Maria", "Tovar", "Caicedo", "Calle 34", "CC", 454521, telefono2, birthday);
  Aeropuerto aeropuerto(1,"Alfonzo bonilla Aragon-Cali", "CALI",50, 1500, aerolineas, aeropuertosDestino);
  aeropuertos.push_back(1);
  Aerolinea *aerolinea = new Aerolinea(1, "1212", "airf", "calle13", "www.airf.com", agenda, representante, "7852-m", 20,  aeropuertos);

  /*
    Control control;
    cout << "Aerolineas al comienzo de la ejecucion" << endl;
    control.listAerilineas();
    cout << "Crear una aerolinea" << endl;
    control.crearAerolinea();
    cout << "Aerolineas depues de la creacon" << endl;
    control.listAerilineas(); */
}
