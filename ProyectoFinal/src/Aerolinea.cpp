#include "Aerolinea.h"

Aerolinea::Aerolinea()
{
    //ctor
}

Aerolinea::Aerolinea(string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, vector<Tiquete> transaciones, vector<Cliente> clientesGolden, string matriculaAerea, int totalAvionesFlota, vector<Aeropuerto> aeropuertos):CompaniaAerea(nit, razonSocial, direccion, paginaWeb, agenda, representante, transaciones, clientesGolden){

}

Aerolinea::~Aerolinea()
{
    //dtor
}
