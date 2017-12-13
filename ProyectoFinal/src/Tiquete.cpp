#include "Tiquete.h"

Tiquete::Tiquete()
{
    Aeropuerto aeropuertoOrigen;
    Aeropuerto aeropuestoDestino;
    Aerolinea aerolines;
    Avion avion;
    Cliente cliente;

    this->id = 0;
    this->origen = aeropuertoOrigen;
    this->destino = aeropuestoDestino;
    this->numeroTiquerte = 0;
    this->aerolines = aerolines;
    this->avion = avion;
    this->silla = silla;
    this->estado = "No check";
    this->cliente = cliente;
}

Tiquete::Tiquete(int id, Aeropuerto origen,Aeropuerto destino,int numeroTiquerte,Aerolinea aerolines,Avion avion,string silla,string estado,Cliente cliente){
   this->id             = id;
   this->origen         = origen;
   this->destino        = destino;
   this->numeroTiquerte = numeroTiquerte;
   this->aerolines      = aerolines;
   this->avion          = avion;
   this->silla          = silla;
   this->estado         = estado;
   this->cliente        = cliente;
}

Tiquete::~Tiquete()
{
    //dtor
}

/* +───────────────────────────────────────────────────────────────────────+ */
/*       /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$   /$$$$$$         */
/*		 /$$__  $$| $$_____/|__  $$__/| $$_____/| $$__  $$ /$$__  $$         */
/*		| $$  \__/| $$         | $$   | $$      | $$  \ $$| $$  \__/         */
/*		|  $$$$$$ | $$$$$      | $$   | $$$$$   | $$$$$$$/|  $$$$$$          */
/*		 \____  $$| $$__/      | $$   | $$__/   | $$__  $$ \____  $$         */
/*		 /$$  \ $$| $$         | $$   | $$      | $$  \ $$ /$$  \ $$         */
/*		|  $$$$$$/| $$$$$$$$   | $$   | $$$$$$$$| $$  | $$|  $$$$$$/         */
/*		 \______/ |________/   |__/   |________/|__/  |__/ \______/          */
/* +───────────────────────────────────────────────────────────────────────+ */
/*Establece el id del tiquete*/
void Tiquete::setId(int id){
  this->id = id;
}

/*Establece el aeropuerto de origen del tiquete*/
void Tiquete::setOrigen(Aeropuerto origen){
  this->origen = origen;
}

/*Establece el aeropuerto de destino del tiquete*/
void Tiquete::setDestinity(Aeropuerto des){
  this->destino = des;
}

/*Establece el numero del tiquete*/
void Tiquete::setTiquetNumber(int num){
  this->numeroTiquerte = num;
}

/*Establece la aerolinea en la que se viaja*/
void Tiquete::setAerolinea(Aerolinea aero){
  this->aerolines = aero;
}

/*Establece el avion del tiquete*/
void Tiquete::setAirplain(Avion airplain){
  this->avion = airplain;
}

/*Establece la silla del tiquete*/
void Tiquete::setChair(string silla){
  this->silla = silla;
}

/*Establece el estado del tiquete*/
void Tiquete::setStatus(string status){
  this->estado = status;
}

/*Establece el cliente del tiquete*/
void Tiquete::setCliente(Cliente cliente){
  this->cliente = cliente;
}


/* +───────────────────────────────────────────────────────────────────────+ */
/*	      /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$   /$$$$$$ 	       */
/*       /$$__  $$| $$_____/|__  $$__/| $$_____/| $$__  $$ /$$__  $$		     */
/*      | $$  \__/| $$         | $$   | $$      | $$  \ $$| $$  \__/		     */
/*      | $$ /$$$$| $$$$$      | $$   | $$$$$   | $$$$$$$/|  $$$$$$  		     */
/*      | $$|_  $$| $$__/      | $$   | $$__/   | $$__  $$ \____  $$		     */
/*      | $$  \ $$| $$         | $$   | $$      | $$  \ $$ /$$  \ $$		     */
/*      |  $$$$$$/| $$$$$$$$   | $$   | $$$$$$$$| $$  | $$|  $$$$$$/         */
/*       \______/ |________/   |__/   |________/|__/  |__/ \______/          */
/* +───────────────────────────────────────────────────────────────────────+ */
/*Retorna el id del tiquete*/
int Tiquete::getId(){
  return this->id;
}

/*Retorna el aeropuesto de origen*/
Aeropuerto Tiquete::getOrigen(){
  return this->origen;
}

/*Retorna elñ aeropuerto de destino*/
Aeropuerto Tiquete::getDestinity(){
  return this->destino;
}

/*Retorna el numero del tiquete*/
int Tiquete::getTiquetNumber(){
  return this->numeroTiquerte;
}

/*Retorna la aerolinea*/
Aerolinea Tiquete::getAerolinea(){
  return this->aerolines;
}

/*Retorna el avion*/
Avion Tiquete::getAirplain(){
  return this->avion;
}

/*Retorna la silla*/
string Tiquete::getChair(){
  return this->silla;
}

/*Retorna el estado*/
string Tiquete::getStatus(){
  return this->estado;
}

/*Retorna el cliente*/
Cliente Tiquete::getCliente(){
  return this->cliente;
}
