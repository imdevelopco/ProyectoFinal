#include "Representante.h"

Representante::Representante()
{
    //ctor
}

Representante::Representante(string nombreCompleto, string apellidoCompleto, string direccion, string tipoDocumento, int numeroDocumento, Telefono numero, tm fechaNacimiento):Persona(nombreCompleto,apellidoCompleto,direccion,tipoDocumento,numeroDocumento,numero,fechaNacimiento){
  
}

Representante::~Representante()
{
    //dtor
}
