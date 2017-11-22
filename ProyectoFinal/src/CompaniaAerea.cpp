#include "CompaniaAerea.h"
#include <iostream>
#include <vector>
#include "Telefono.h"
#include "Representante.h"

using namespace std;

CompaniaAerea::CompaniaAerea()
{
  Telefono telfono;
  Representante representante;
  this->nit            = 0000;
  this->razonSocial    = "unamed";
  this->direccion      = "calle 0";
  this->paginaWeb      = "www.unamed.com";
  this->agenda         = {telfono};
  this->representante  = representante;
  this->transaciones   = transaciones; // hay que hacer tiquetes
  this->clientesGolden = clientesGolden;
}

CompaniaAerea::CompaniaAerea(string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, vector<Tiquete> transaciones, vector<Cliente> clientesGolden){
  this->nit            = nit;
  this->razonSocial    = razonSocial;
  this->direccion      = direccion;
  this->paginaWeb      = paginaWeb;
  this->agenda         = agenda;
  this->representante  = representante;
  this->transaciones   = transaciones;
  this->clientesGolden = clientesGolden;
}

CompaniaAerea::~CompaniaAerea()
{
    //dtor
}
