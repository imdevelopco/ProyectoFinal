#include "AgenciaDeViaje.h"

AgenciaDeViaje::AgenciaDeViaje()
{
    //ctor
}
AgenciaDeViaje::AgenciaDeViaje(int _id,string _nit,string _razonSocial,string _direccion,string _paginaWeb,Representante representante):CompaniaAerea(_id,_nit,_razonSocial,_direccion,_paginaWeb,representante)
{
  this-> id           =   _id;
  this-> nit          =   _nit;
  this-> razonSocial  =   _razonSocial;
  this-> direccion    =   _direccion;
  this-> paginaWeb    =   _paginaWeb;
  representante;
  vector <Telefono>agenda(0);
  vector <Cliente>clientesGolden(0);
  vector<int>transaciones(0);


}
AgenciaDeViaje::~AgenciaDeViaje()
{
    //dtor
}
