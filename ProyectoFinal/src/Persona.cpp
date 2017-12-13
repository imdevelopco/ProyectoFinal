#include "Persona.h"

/*Constructor por defecto, establece valores predefinidos*/
Persona::Persona()
{
  time_t date = time(0);
	struct tm birthday = *localtime(&date);
  Telefono telefono;

  this->primerNombre     = "UnnamedPeerson";
  this->segundoNombre    = " ";
  this->primerApellido   = "no_lastName";
  this->segundoApellido  = " ";
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

/*establece el primer nombre de la persona, se le pasa un string que es el nombre de la
  persona, no retorna nada.
*/
void Persona::setFirstName(string nombre)
{
    this->primerNombre=nombre;
}
/*establece el segundo nombre de la persona, se le pasa un string que es el nombre de la
  persona, no retorna nada.
*/
void Persona::setSecondName(string nombre)
{
    this->segundoNombre=nombre;
}
/*Establece  el primer apellido de la persona, recibe un string que es el  apellido, no
 retorna nada (void)
*/
void Persona::setFirstLastName(string apellido)
{
    this->primerApellido=apellido;
}
/*Establece  el  segundo apellido de la persona, recibe un string que es el  apellido, no
 retorna nada (void)
*/
void Persona::setSecondLastName(string apellido)
{
    this->segundoApellido=apellido;
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
  Telefono tel;
  int day,mon,year;
  char nm,lm;


  cout<<"Digite el primer nombre" <<endl;
  cin>>primerNombre;
  cout<<"tiene segundo nombre?(Si=s,NO=n)"<<endl;
  do{
        cin>>nm;
        if (nm == 's')
        cout<<"Digite el segundo nombre" <<endl;
        cin>>segundoNombre;
    }while ((nm != 's')&&(nm != 'n'));
  cout<<"Digite el apellido"<<endl;
  cin>>primerApellido;
  cout<<"tiene segundo apellido?(Si=s,NO=n)"<<endl;
  do{
        cin>>lm;
        if (lm == 's')
        cout<<"Digite el segundo apellido"<<endl;
        cin>>segundoApellido;
    }while ((lm != 's')&&(lm != 'n'));
  cout<<"Digite el direccion" <<endl;
  cin>>direccion;
  cout<<"Digite el tipo de documento" <<endl;
  cin>>tipoDocumento;
  cout<<"Digite el numero de documento" <<endl;
  cin>>numeroDocumento;
  tel.llenarTelefono();
  /* aqui deberia estar lo de la fecha de nacimiento*/

}

