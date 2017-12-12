#include "AgenciaDeViaje.h"

AgenciaDeViaje::AgenciaDeViaje()
{
    //ctor
}

AgenciaDeViaje::AgenciaDeViaje(int _id,string _nit,string _razonSocial,string _direccion,string _paginaWeb,  vector<Telefono> agenda, Representante representante, vector<Aerolinea> aerolineas):CompaniaAerea(_id,_nit,_razonSocial,_direccion,_paginaWeb, agenda, representante)
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
  this->aerolineas = aerolineas;
}

AgenciaDeViaje::~AgenciaDeViaje()
{
    //dtor
}
    /* Getters*/
//Retorna el id de la agencia
/*int AgenciaDeViaje::getId(){
  return id;
}*/


vector<Aerolinea> AgenciaDeViaje::getAerolineas(){
  return this->aerolineas;
}
