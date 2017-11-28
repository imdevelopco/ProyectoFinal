#include "Representante.h"

Representante::Representante()
{
    //ctor
}

Representante::Representante(string _primerNombre, string _segundoNombre, string _primerApellido, string _segundoApellido, string _direccion, string _tipoDocumento, int _numeroDocumento, Telefono number, tm BornDate):Persona(_primerNombre,  _segundoNombre,  _primerApellido,  _segundoApellido,  _direccion,  _tipoDocumento, _numeroDocumento,number,BornDate)
{

}


Representante::~Representante()
{
    //dtor
}
