#include "Cliente.h"

Cliente::Cliente()
{
    //ctor
}
Cliente::Cliente(string _nombreCompleto, string _apellidoCompleto, string _direccion, string _tipoDocumento, int _numeroDocumento, Telefono number, tm BornDate):Persona(__apellidoCompleto,_direccion,_tipoDocumento,_numeroDocumento,number,BornDate)
{
  this->nombreCompleto   = _nombreCompleto;
  this->apellidoCompleto = _apellidoCompleto;
  this->direccion        = _direccion;
  this->tipoDocumento    = _tipoDocumento;
  this->numeroDocumento  = _numeroDocumento;
  this->numero           = number;
  this->fechaNacimiento  = BornDate;

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
Funcion: Cambia el nombre a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setName(string nombreCompleto)
{
  Persona::setName();
}

/*
Input: cadena de texto
Output: void
Funcion: Cambia el apellido a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setLastName(string apellido)
{
  Persona::setLastName();
}

/*
Input: cadena de texto
Output: void
Funcion: Cambia la direccion de residencia a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setAddress(string direccion)
{
  Persona::setAddress();
}

/*
Input: cadena de texto
Output: void
Funcion: Cambia el tipo de documento a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setTypeDocument(string type)
{
  Persona::setTypeDocument();
}

/*
Input: numero entero
Output: void
Funcion: Cambia el numero del documento a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setNumDocument(int num)
{
  Persona::setNumDocument();
}
/*
Input: Un objeto tipo Telefono
Output: void
Funcion: Cambia el numero telefonico a determinado Cliente (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setPhone(Telefono tel)
{
  Persona::setPhone();
}
/*
Input: estructura tm
Output: void
Funcion: cmabia la fecha de nacimiento de determinado (Se hereda de la clase Persona)
Autor: Carlos Andres Cordoba Ramos
*/
void Cliente::setBirthday(tm nacimiento)
{
  Persona::setBirthday();
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
