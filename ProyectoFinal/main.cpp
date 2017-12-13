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

  //  ╔═╗┌─┐┬─┐┌─┐┬  ┬┌┐┌┌─┐┌─┐┌─┐
  //  ╠═╣├┤ ├┬┘│ ││  ││││├┤ ├─┤└─┐
  //  ╩ ╩└─┘┴└─└─┘┴─┘┴┘└┘└─┘┴ ┴└─┘
  Aerolinea *aerolinea = new Aerolinea(1, "1212", "airf", "calle13", "www.airf.com", agenda, representante, "7852-m", 20,  aeropuertos);
  aerolineas_id.push_back(1);
  aerolineas.push_back(*aerolinea);
  //   ╔═╗┌─┐┌─┐┌┐┌┌─┐┬┌─┐┌─┐
  //   ╠═╣│ ┬├┤ ││││  │├─┤└─┐
  //   ╩ ╩└─┘└─┘┘└┘└─┘┴┴ ┴└─┘

  AgenciaDeViaje *agencia = new AgenciaDeViaje(1,"8589","passVu","calle45","www.passVu.com", agenda, representante, aerolineas);
  agencias.push_back(*agencia);


  //Sillas
/*
   vector<Silla> preferencial(0);
   vector<Silla> normal(0);
   vector<Silla> bajoCosto(0);
  for(int i = 0;i<30;i++)
  {
      Silla *sillaCostosa= new Silla("p-"+to_string(i+1),"preferencial",0);
      preferencial.push_back(*sillaCostosa);
  }
  for(int i = 0;i<30;i++)
  {
      Silla *sillaNormal= new Silla("p-"+to_string(i+1),"normal",1);
      normal.push_back(*sillaNormal);
  }
  for(int i = 0;i<30;i++)
  {
      Silla *sillita= new Silla("p-"+to_string(i+1),"bajoCosto",0);
      bajoCosto.push_back(*sillita);
  }
 // Avion
  Avion JayJayElAvioncito (preferencial,normal,bajoCosto,"ABC-123",aeropuerto1,aeropuerto2,30000,2);
  cout<<"Puesto Disponibls: "<<JayJayElAvioncito.getSillasDisponibles()<<endl;
  JayJayElAvioncito.getSillasDisponiblesPorCategoria();
  // Se crea flota para agregarla al puntero aerolinea
  vector<Avion> flotas;
  // se inserta el avion creado en el vector nuevo
  flotas.push_back(JayJayElAvioncito);

  aerolinea->setFlota(flotas);
  aerolinea->administrarAviones();
*/

 Control control(todosAeropuertos, agencias, aerolineas);

 //┌─┐┬  ┬┌─┐┌┐┌┌┬┐┌─┐┌─┐
 //│  │  │├┤ │││ │ ├┤ └─┐
 //└─┘┴─┘┴└─┘┘└┘ ┴ └─┘└─┘

  control.crearClientes();

  control.setFlota();

  control.venderTiket();

  control.venderTiket();
  control.venderTiket();


  /*  cout << "Aerolineas al comienzo de la ejecucion" << endl;
    control.listAerilineas();
    cout << "Crear una aerolinea" << endl;
    control.crearAerolinea();
    cout << "Aerolineas depues de la creacon" << endl;
    control.listAerilineas(); */
}
