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
#include "Persona.h"

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
  vector<int> aerolineas_id;
  vector<Aerolinea> aerolineas;
  vector<AgenciaDeViaje> agencias;

  Telefono telefono("celular", 57, 8828263);
  Telefono telefono2("celular", 57, 856521);
  agenda.push_back(telefono);
  Representante representante("Fernanda", "Maria", "Tovar", "Caicedo", "Calle 34", "CC", 454521, telefono2, birthday);
  Aeropuerto aeropuerto(1,"Alfonzo bonilla Aragon-Cali", "CALI",50, 1500, aerolineas_id);



  //  ╔═╗┌─┐┬─┐┌─┐┌─┐┬ ┬┌─┐┬─┐┌┬┐┌─┐┌─┐
  //  ╠═╣├┤ ├┬┘│ │├─┘│ │├┤ ├┬┘ │ │ │└─┐
  //  ╩ ╩└─┘┴└─└─┘┴  └─┘└─┘┴└─ ┴ └─┘└─┘
  Aeropuerto aeropuerto1(1,"Alfonzo bonilla Aragon-Cali", "CALI",50, 1500, aerolineas_id);
  Aeropuerto aeropuerto2(2,"El dorado-Bogota", "BOG",50, 1500, aerolineas_id);
  Aeropuerto aeropuerto3(3,"Medellin", "MED",50, 1500, aerolineas_id);
  Aeropuerto aeropuerto4(4,"Barranquilla", "BARR",50, 1500, aerolineas_id);
  Aeropuerto aeropuerto5(5,"Cartagena", "CAR",50, 1500, aerolineas_id);
  Aeropuerto aeropuerto6(6,"new york", "NYC",50, 1500, aerolineas_id);
  Aeropuerto aeropuerto7(7,"Miami", "MIA",50, 1500, aerolineas_id);
  Aeropuerto aeropuerto8(8,"Londres", "LON",50, 1500, aerolineas_id);

  todosAeropuertos.push_back(aeropuerto1);
  todosAeropuertos.push_back(aeropuerto2);
  todosAeropuertos.push_back(aeropuerto3);
  todosAeropuertos.push_back(aeropuerto4);
  todosAeropuertos.push_back(aeropuerto5);
  aeropuertos.push_back(1);// aeropuertos a los que puede viajar la aerolinea
  aeropuertos.push_back(2);// aeropuertos a los que puede viajar la aerolinea
  aeropuertos.push_back(3);// aeropuertos a los que puede viajar la aerolinea

  // ┌─┐┬  ┬┌─┐┌┐┌┌┬┐┌─┐┌─┐
  // │  │  │├┤ │││ │ ├┤ └─┐
  // └─┘┴─┘┴└─┘┘└┘ ┴ └─┘└─┘
  Cliente cliente1("Carlos", "Andres", "Cordoba", "Ramos", "calle34", "CC", 1143856542, telefono, birthday, true);
  Cliente cliente2("Andres", "Camilo", "Arias", "Martinez", "calle5ta", "CC", 1143856254, telefono, birthday, true);
  Cliente cliente3("Sanya", "Samy", "Perez", "Cardona", "calle585", "CC", 1143856, telefono, birthday, false);
  Cliente cliente4("Leidy", "Laura", "Arias", "Martinez", "calle5ta", "CC", 1143856241, telefono, birthday, true);
  Cliente cliente5("Maria", "Fernanda", "Torres", "Aguirre", "calle15", "CC", 114385642, telefono, birthday, true);
  Cliente cliente6("Pablo", "Emilio", "Gutierrez", "Madronero", "cakle4", "CC", 114856245, telefono, birthday, false);

  vector<Cliente> clientes1, clientes2;
  clientes1.push_back(cliente1);
  clientes1.push_back(cliente2);
  clientes1.push_back(cliente3);

  clientes2.push_back(cliente4);
  clientes2.push_back(cliente5);
  clientes2.push_back(cliente6);

  //  ╔═╗┌─┐┬─┐┌─┐┬  ┬┌┐┌┌─┐┌─┐┌─┐
  //  ╠═╣├┤ ├┬┘│ ││  ││││├┤ ├─┤└─┐
  //  ╩ ╩└─┘┴└─└─┘┴─┘┴┘└┘└─┘┴ ┴└─┘
  Aerolinea *aerolinea = new Aerolinea(1, "1212", "airf", "calle13", "www.airf.com", agenda, representante, "7852-m", 20,  aeropuertos);
  aerolineas_id.push_back(1);
  aerolinea->setClientes(clientes1);
  aerolineas.push_back(*aerolinea);


  //   ╔═╗┌─┐┌─┐┌┐┌┌─┐┬┌─┐┌─┐
  //   ╠═╣│ ┬├┤ ││││  │├─┤└─┐
  //   ╩ ╩└─┘└─┘┘└┘└─┘┴┴ ┴└─┘

  AgenciaDeViaje *agencia = new AgenciaDeViaje(1,"8589","passVu","calle45","www.passVu.com", agenda, representante, aerolineas);
  agencia->setClientes(clientes2);
  agencias.push_back(*agencia);




  //╦ ╔╗╔ ╦ ╔═╗ ╦ ╔═╗
  //║ ║║║ ║ ║   ║ ║ ║
  //╩ ╝╚╝ ╩ ╚═╝ ╩ ╚═╝
  Control control(todosAeropuertos, agencias, aerolineas);





}
