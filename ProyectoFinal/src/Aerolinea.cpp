#include "Aerolinea.h"

Aerolinea::Aerolinea()
{
    //ctor
}

Aerolinea::Aerolinea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, string matriculaAerea, int totalAvionesFlota, vector<int> aeropuertos):CompaniaAerea(id, nit, razonSocial, direccion, paginaWeb, agenda, representante){
  this->matriculaAerea     = matriculaAerea;
  this->totalAvionesFlota  = totalAvionesFlota;
  this->aeropuertos        = aeropuertos;
}

Aerolinea::~Aerolinea()
{
    //dtor
}

/* +───────────────────────────────────────────────────────────────────────+ */
/*       /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$   /$$$$$$         */
/*		 /$$__  $$| $$_____/|__  $$__/| $$_____/| $$__  $$ /$$__  $$         */
/*		| $$  \__/| $$         | $$   | $$      | $$  \ $$| $$  \__/         */
/*		|  $$$$$$ | $$$$$      | $$   | $$$$$   | $$$$$$$/|  $$$$$$          */
/*		 \____  $$| $$__/      | $$   | $$__/   | $$__  $$ \____  $$         */
/*		 /$$  \ $$| $$         | $$   | $$      | $$  \ $$ /$$  \ $$         */
/*		|  $$$$$$/| $$$$$$$$   | $$   | $$$$$$$$| $$  | $$|  $$$$$$/         */
/*		 \______/ |________/   |__/   |________/|__/  |__/ \______/          */
/* +───────────────────────────────────────────────────────────────────────+ */
/*Establece la matricula aerea de la aerolinea*/

void Aerolinea::setMatricula(string matricula){
  this->matriculaAerea = matricula;
}

/*Establece el total de aviones de la aerolinea*/

void Aerolinea::setTotalPlains(int total){
  this->totalAvionesFlota = total;
}

/*Establece la flota de aviones*/
void Aerolinea::setFlota(vector<Avion> flota){
  this->flota = flota;
}


/* +───────────────────────────────────────────────────────────────────────+ */
/*	      /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$   /$$$$$$ 	       */
/*       /$$__  $$| $$_____/|__  $$__/| $$_____/| $$__  $$ /$$__  $$		     */
/*      | $$  \__/| $$         | $$   | $$      | $$  \ $$| $$  \__/		     */
/*      | $$ /$$$$| $$$$$      | $$   | $$$$$   | $$$$$$$/|  $$$$$$  		     */
/*      | $$|_  $$| $$__/      | $$   | $$__/   | $$__  $$ \____  $$		     */
/*      | $$  \ $$| $$         | $$   | $$      | $$  \ $$ /$$  \ $$		     */
/*      |  $$$$$$/| $$$$$$$$   | $$   | $$$$$$$$| $$  | $$|  $$$$$$/         */
/*       \______/ |________/   |__/   |________/|__/  |__/ \______/          */
/* +───────────────────────────────────────────────────────────────────────+ */
/*Retorna la matricula de la aerolinea*/
string Aerolinea::getMatricula(){
  return this->matriculaAerea;
}

/*Retorna el total de aviones de la aerolinea*/
int Aerolinea::getTotal(){
  return this->totalAvionesFlota;
}

/*Retorna la flota de aviones*/
vector<Avion> Aerolinea::getFlota(){
  return this->flota;
}
