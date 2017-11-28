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
