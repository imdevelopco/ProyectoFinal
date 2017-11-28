#include "Persona.h"

/*Constructor por defecto, establece valores predefinidos*/
Persona::Persona()
{
  time_t date = time(0);
	struct tm birthday = *localtime(&date);
  Telefono telefono;

  //this->nombreCompleto   = "unamed person";
  //this->apellidoCompleto = "lastname";
  this->direccion        = "no direction";
  this->tipoDocumento    = "CC";
  this->numeroDocumento  = 0000001;
  this->numero           = telefono;
  this->fechaNacimiento  = birthday;
}

Persona::Persona(string _primerNombre, string _segundoNombre, string _primerApellido, string _segundoApellido, string _direccion, string _tipoDocumento, int _numeroDocumento, Telefono number, tm BornDate)
{
  this->primerNombre     = _primerNombre;
  this->segundoNombre    = _segundoNombre;
  this->primerApellido   = _primerApellido;
  this->segundoApellido  = _segundoApellido;
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
void Persona::setName(string nombre){
  int decision;
  do{
    cout<<"Cual nombre desea cambiar"<<endl;
    cout<<"primer nombre (Presione 1)"<<endl;
    cout<<"segundo nombre (Presione 2)"<<endl;
    cin>>decision;
    if(decision == 1)
    this->primerNombre=nombre;
    else if (decision == 2)
    this->segundoNombre=nombre;
    else
    cout<<"Opcion no valida"<<endl;
  }while((decision != 1)||(decision != 2));
}

/*Establece  el apellido de la persona, recibe un string que es el  apellido, no
 retorna nada (void)
*/
void Persona::setLastName(string apellido){
  this->primerApellido = apellido;
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
  return primerNombre + " " + segundoNombre;
}

string Persona::getLastName(){ //retorna el apellido de la persona
  return primerApellido + " " + segundoApellido;
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

/////////////////////////////////////////////////////
//              Metodos de la Clase                //
/////////////////////////////////////////////////////

/*
Input: Datos por pantalla
Output: Instancia de la clase Persona
Funcion: Cambia los atributos de un objeto con atributos definidos
por los que le pase el usuario en pantalla
Autor: Carlos Andres Cordoba Ramos
*/

void Persona::crearPersona()
{
//  char
//  cout<<"Cual es el nombre?"<<endl;
//  cin>>nombreCompleto;
//  cout<< <<endl;
//  cout<< <<endl;
//  cout<< <<endl;
//  cout<< <<endl;
//  cout<< <<endl;


}
