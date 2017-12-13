#include "Cliente.h"

Cliente::Cliente()
{
    //ctor
}
Cliente::Cliente(string _primerNombre, string _segundoNombre, string _primerApellido, string _segundoApellido, string _direccion, string _tipoDocumento, int _numeroDocumento, Telefono number, tm BornDate, bool golden):Persona(_primerNombre,_segundoNombre,_primerApellido,_segundoApellido,_direccion, _tipoDocumento,_numeroDocumento,number,BornDate)
{
  this->primerNombre     = _primerNombre;
  this->segundoNombre    = _segundoNombre;
  this->primerApellido   = _primerApellido;
  this->segundoApellido  = _segundoApellido;
  this->direccion        = _direccion;
  this->tipoDocumento    = _tipoDocumento;
  this->numeroDocumento  = _numeroDocumento;
  this->numero           = number;
  this->fechaNacimiento  = BornDate;
  this->golden           = golden;
}
Cliente::~Cliente()
{
    //dtor
}

////////////////////////////
//  ┌─┐┌─┐┌┬┐┌┬┐┌─┐┬─┐┌─┐ //
//  └─┐├┤  │  │ ├┤ ├┬┘└─┐ //
//  └─┘└─┘ ┴  ┴ └─┘┴└─└─┘ //
////////////////////////////
/*
Input: cadena de texto
Output: void
Funcion: Cambia el primer nombre a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setFirstName(string nombreCompleto)
{
  Persona::setFirstName(nombreCompleto);
}
/*
Input: cadena de texto
Output: void
Funcion: Cambia el segundo nombre a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setSecondName(string nombreCompleto)
{
  Persona::setSecondName(nombreCompleto);
}

/*
Input: cadena de texto
Output: void
Funcion: Cambia el primer apellido a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setFirstLastName(string apellido)
{
  Persona::setFirstLastName(apellido);
}

/*
Input: cadena de texto
Output: void
Funcion: Cambia el segundo apellido a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setSecondLastName(string apellido)
{
  Persona::setSecondLastName(apellido);
}
/*
Input: cadena de texto
Output: void
Funcion: Cambia la direccion de residencia a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setAddress(string direccion)
{
  Persona::setAddress(direccion);
}

/*
Input: cadena de texto
Output: void
Funcion: Cambia el tipo de documento a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setTypeDocument(string type)
{
  Persona::setTypeDocument(type);
}

/*
Input: numero entero
Output: void
Funcion: Cambia el numero del documento a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setNumDocument(int num)
{
  Persona::setNumDocument(num);
}
/*
Input: Un objeto tipo Telefono
Output: void
Funcion: Cambia el numero telefonico a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setPhone(Telefono tel)
{
  Persona::setPhone(tel);
}
/*
Input: estructura tm
Output: void
Funcion: cmabia la fecha de nacimiento de determinado (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setBirthday(tm nacimiento)
{
  Persona::setBirthday(nacimiento);
}

/*Agrega un id de un tiquuete comprado por el cliente*/
void Cliente::addTiquete(int id){
  this->tiquetes.push_back(id);
}

/*Establecer si es golden */
void Cliente::setGolden(bool gold){
  this->golden = gold;
}
////////////////////////////
//  ┌─┐┌─┐┌┬┐┌┬┐┌─┐┬─┐┌─┐ //
//  │ ┬├┤  │  │ ├┤ ├┬┘└─┐ //
//  └─┘└─┘ ┴  ┴ └─┘┴└─└─┘ //
////////////////////////////

/*
Input: void
Output: cadena de texto
Funcion: retorna el nombre de determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/

string Cliente::getName()
{
  return Persona::getName();
}
/*
Input: void
Output: cadena de texto
Funcion: retorna el apellido de determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
string Cliente::getLastName()
{
  return Persona::getLastName();
}
/*
Input: void
Output: cadena de texto
Funcion: retorna la direccion de residencia  de determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
string Cliente::getAddress()
{
    return Persona::getAddress();
}
/*
Input: void
Output: cadena de texto
Funcion: retorna el tipo de documento de determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
string Cliente::getTypeDocument()
{
  return Persona::getTypeDocument();
}
/*
Input: void
Output: numero entero
Funcion: retorna el numero de documento de determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
int Cliente::getNumDocument()
{
  return Persona::getNumDocument();
}
/*
Input: void
Output: Objeto de la Clase Telefono
Funcion: retorna el numero telefonico de determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
Telefono Cliente::getPhone()
{
  return Persona::getPhone();
}
/*
Input: void
Output: estructura tm
Funcion: retorna la fecha de nacimiento de determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
tm Cliente::getBirthday()
{
  return Persona::getBirthday();
}

/**/
bool Cliente::getGolden(){
  return this->golden;
}
