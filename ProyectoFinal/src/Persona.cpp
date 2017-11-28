#include "Persona.h"

/*Constructor por defecto, establece valores predefinidos*/
Persona::Persona()
{
  time_t date = time(0);
	struct tm birthday = *localtime(&date);
  Telefono telefono;

  this->nombreCompleto   = "unamed person";
  this->apellidoCompleto = "lastname";
  this->direccion        = "no direction";
  this->tipoDocumento    = "CC";
  this->numeroDocumento  = 0000001;
  this->numero           = telefono;
  this->fechaNacimiento  = birthday;
}

Persona::Persona(string nombreCompleto, string apellidoCompleto, string direccion, string tipoDocumento, int numeroDocumento, Telefono numero, tm fechaNacimiento){
  this->nombreCompleto   = nombreCompleto;
  this->apellidoCompleto = apellidoCompleto;
  this->direccion        = direccion;
  this->tipoDocumento    = tipoDocumento;
  this->numeroDocumento  = numeroDocumento;
  this->numero           = numero;
  this->fechaNacimiento  = fechaNacimiento;
}

Persona::~Persona()
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

/*establece el nombre de la persona, se le pasa un string que es el nombre de la
  persona, no retorna nada.
*/
void Persona::setName(string nombreCompleto){
  this->nombreCompleto = nombreCompleto;
}

/*Establece  el apellido de la persona, recibe un string que es el  apellido, no
 retorna nada (void)
*/
void Persona::setLastName(string apellido){
  this->apellidoCompleto = apellido;
}

/*establece la direccion de la persona*/
void Persona::setAddress(string direccion){
  this->direccion = direccion;
}

/*establece el  tipo de documento de la persona, recibe un string que es el tipo
  las opciones son ["CC", "CE", "PT", "TI", "RC"] no retorna nada (void)
*/
void Persona::setTypeDocument(string type){
  this->tipoDocumento = type;
}

/*Establece el numero de documento, recibe un entero y no retorna nada*/
void Persona::setNumDocument(int num){
  this->numeroDocumento = num;
}

/*Establece el numero de telefono de la persona*/
void Persona::setPhone(Telefono tel){
  this->numero = tel;
}

/*Establece  la  fecha  de  nacimiento  de  la persona, recibe una estructura de
 tiempo tm, no retorna nada (void)*/
void Persona::setBirthday(tm nacimiento){
  this->fechaNacimiento = nacimiento;
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
string Persona::getName(){ //retorna el nombre de la persona
  return this->nombreCompleto;
}

string Persona::getLastName(){ //retorna el apellido de la persona
  return this->apellidoCompleto;
}

string Persona::getAddress(){ // retorna la direccion de la persona
  return this->direccion;
}

string Persona::getTypeDocument(){ //retorna el tipo de documento de la persona
  return this->tipoDocumento;
}

int Persona::getNumDocument(){ //retorna el número de documento de la persona
  return this->numeroDocumento;
}

Telefono Persona::getPhone(){//retorna el Telefono de la persona
  return this->numero;
}

tm Persona::getBirthday(){ //retorna la fecha de cumpleaños de la persona
  return this->fechaNacimiento;
}
