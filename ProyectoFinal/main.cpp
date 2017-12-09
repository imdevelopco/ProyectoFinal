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
  vector<Aeropuerto> todosAeropuertos;
  vector<Aerolinea> aerolineas;
  vector<Aeropuerto> aeropuertosDestino;
  vector<Aeropuerto> aeropuertosDestino1;
  vector<Aeropuerto> aeropuertosDestino2;
  vector<Aeropuerto> aeropuertosDestino3;
  vector<AgenciaDeViaje> agencias;

  Telefono telefono("celular", 57, 8828263);
  Telefono telefono2("celular", 57, 856521);
  agenda.push_back(telefono);
  Representante representante("Fernanda", "Maria", "Tovar", "Caicedo", "Calle 34", "CC", 454521, telefono2, birthday);
  Aeropuerto aeropuerto(1,"Alfonzo bonilla Aragon-Cali", "CALI",50, 1500, aerolineas, aeropuertosDestino);



  //  ╔═╗┌─┐┬─┐┌─┐┌─┐┬ ┬┌─┐┬─┐┌┬┐┌─┐┌─┐
  //  ╠═╣├┤ ├┬┘│ │├─┘│ │├┤ ├┬┘ │ │ │└─┐
  //  ╩ ╩└─┘┴└─└─┘┴  └─┘└─┘┴└─ ┴ └─┘└─┘
  Aeropuerto aeropuerto1(1,"Alfonzo bonilla Aragon-Cali", "CALI",50, 1500, aerolineas, aeropuertosDestino);
  Aeropuerto aeropuerto2(2,"El dorado-Bogota", "BOG",50, 1500, aerolineas, aeropuertosDestino);
  Aeropuerto aeropuerto3(3,"Medellin", "MED",50, 1500, aerolineas, aeropuertosDestino);
  Aeropuerto aeropuerto4(4,"Barranquilla", "BARR",50, 1500, aerolineas, aeropuertosDestino);
  Aeropuerto aeropuerto5(5,"Cartagena", "CAR",50, 1500, aerolineas, aeropuertosDestino);
  Aeropuerto aeropuerto6(6,"new york", "NYC",50, 1500, aerolineas, aeropuertosDestino);
  Aeropuerto aeropuerto7(7,"Miami", "MIA",50, 1500, aerolineas, aeropuertosDestino);
  Aeropuerto aeropuerto8(8,"Londres", "LON",50, 1500, aerolineas, aeropuertosDestino);
  aeropuertosDestino2.push_back(aeropuerto6);
  aeropuertosDestino2.push_back(aeropuerto7);
  aeropuertosDestino2.push_back(aeropuerto8);
  aeropuerto2.setAeropuertosDestino(aeropuertosDestino2); //poner los aeropuertos de destiono para bogota

  aeropuertosDestino1.push_back(aeropuerto2);
  aeropuertosDestino1.push_back(aeropuerto3);
  aeropuertosDestino1.push_back(aeropuerto4);
  aeropuertosDestino1.push_back(aeropuerto5);
  aeropuerto1.setAeropuertosDestino(aeropuertosDestino1); //poner los aeropuertos de destino al aeropuerto de cali



  todosAeropuertos.push_back(aeropuerto1);
  todosAeropuertos.push_back(aeropuerto2);
  todosAeropuertos.push_back(aeropuerto3);
  todosAeropuertos.push_back(aeropuerto4);
  todosAeropuertos.push_back(aeropuerto5);
  aeropuertos.push_back(1);// aeropuertos a los que puede viajar la aerolinea
  aeropuertos.push_back(2);// aeropuertos a los que puede viajar la aerolinea
  aeropuertos.push_back(3);// aeropuertos a los que puede viajar la aerolinea

  //  ╔═╗┌─┐┬─┐┌─┐┬  ┬┌┐┌┌─┐┌─┐┌─┐
  //  ╠═╣├┤ ├┬┘│ ││  ││││├┤ ├─┤└─┐
  //  ╩ ╩└─┘┴└─└─┘┴─┘┴┘└┘└─┘┴ ┴└─┘
  Aerolinea *aerolinea = new Aerolinea(1, "1212", "airf", "calle13", "www.airf.com", agenda, representante, "7852-m", 20,  aeropuertos);
  aerolineas.push_back(*aerolinea);
  //   ╔═╗┌─┐┌─┐┌┐┌┌─┐┬┌─┐┌─┐
  //   ╠═╣│ ┬├┤ ││││  │├─┤└─┐
  //   ╩ ╩└─┘└─┘┘└┘└─┘┴┴ ┴└─┘
  AgenciaDeViaje *agencia = new AgenciaDeViaje(1,"8589","passVu","calle45","www.passVu.com", agenda, representante, aerolineas);
  agencias.push_back(*agencia);

    Control control(todosAeropuertos, agencias, aerolineas);
    control.venderTiket();
  /*  cout << "Aerolineas al comienzo de la ejecucion" << endl;
    control.listAerilineas();
    cout << "Crear una aerolinea" << endl;
    control.crearAerolinea();
    cout << "Aerolineas depues de la creacon" << endl;
    control.listAerilineas(); */
}
