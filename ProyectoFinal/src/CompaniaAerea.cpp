#include "CompaniaAerea.h"

CompaniaAerea::CompaniaAerea()
{
  Telefono telfono;
  Representante representante;
  Cliente cliente;
  this->id             = 0;
  this->nit            = "0";
  this->razonSocial    = "unamed";
  this->direccion      = "calle 0";
  this->paginaWeb      = "www.unamed.com";
  this->agenda.push_back(telfono);
  this->representante  = representante;
  this->transaciones.push_back(0);
  this->clientesGolden.push_back(cliente);
}

CompaniaAerea::CompaniaAerea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, vector<Cliente> clientesGolden){
  this->id             = id;
  this->nit            = nit;
  this->razonSocial    = razonSocial;
  this->direccion      = direccion;
  this->paginaWeb      = paginaWeb;
  this->agenda         = agenda;
  this->representante  = representante;
  this->clientesGolden = clientesGolden;
  this->transaciones.push_back(0);
}


//sobrecarga de Contructores
CompaniaAerea::CompaniaAerea(int _id,string _nit,string _razonSocial,string _direccion,string _paginaWeb,Representante representante){

}
CompaniaAerea::~CompaniaAerea()
{
    //dtor
}
/* Getters*/
string CompaniaAerea::getNit()
{
  return nit;
}
string CompaniaAerea::getRazonSocial()
{
    return razonSocial;
}
string CompaniaAerea::getDireccion()
{
    return direccion;
}
string CompaniaAerea::getPaginaWeb()
{
    return paginaWeb;
}
