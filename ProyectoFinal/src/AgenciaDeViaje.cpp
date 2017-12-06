#include "AgenciaDeViaje.h"

AgenciaDeViaje::AgenciaDeViaje()
{
    //ctor
}

AgenciaDeViaje::AgenciaDeViaje(int _id,string _nit,string _razonSocial,string _direccion,string _paginaWeb,  vector<Telefono> agenda, Representante representante,  vector<Cliente> clientesGolden):CompaniaAerea(_id,_nit,_razonSocial,_direccion,_paginaWeb, agenda, representante, clientesGolden)
{
  //SI ESTAS PROPIEDADES LAS TIENE LA CLASE PADRE, NO HAY NECESIDAD DE VOLVER A TENERLAS ACA.
  /*this-> id           =   _id;
  this-> nit          =   _nit;
  this-> razonSocial  =   _razonSocial;
  this-> direccion    =   _direccion;
  this-> paginaWeb    =   _paginaWeb;
  representante;
  agenda(0);
  clientesGolden(0);
  transaciones(0);*/
}

AgenciaDeViaje::~AgenciaDeViaje()
{
    //dtor
}
    /* Getters*/
//Retorna el id de la agencia
int AgenciaDeViaje::getId(){
  return id;
}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::
//
//HAY QUE VERIFICAR SI ESTOS GETERS FUNCIONAN CON EL THIS-> PORQUE ESTAS PROPIEDADES LAS TIENE LA CLASE PADRE
//
//::::::::::::::::::::::::::::::::::::::::::::::::::::::
string AgenciaDeViaje::getNit()
{
    return this->nit;
}

string AgenciaDeViaje::getRazonSocial()
{
    return this->razonSocial;
}

string AgenciaDeViaje::getDireccion()
{
    return this->direccion;
}

string AgenciaDeViaje::getPaginaWeb()
{
    return this->paginaWeb;
}
