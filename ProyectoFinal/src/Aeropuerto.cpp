#include "Aeropuerto.h"

Aeropuerto::Aeropuerto()
{
    //ctor
}
Aeropuerto::Aeropuerto(int _id,string _nombre,string _abreviatura,int _totalAvionesOperacion, int _volumenMaximoPersonas, vector<int> aerolineas)
{
  this->id                    = _id;
  this->nombre                = _nombre;
  this->abreviatura           = _abreviatura;
  this->totalAvionesOperacion = _totalAvionesOperacion;
  this->volumenMaximoPersonas = _volumenMaximoPersonas;
  this->aerolineas            = aerolineas;
}
Aeropuerto::~Aeropuerto()
{
    //dtor
}
/* Input: cadena de Texto
   output: void
   funcion: Cambia el nombre de determinado Aeropuerto
   Autor: Carlos Andres Cordoba Ramos*/
void Aeropuerto::setNombre(string nuevoNombre) {
  nombre = nuevoNombre;
}
/* Input: cadena de Texto
   output: void
   funcion: Cambia la abreviatura de determinado Aeropuerto
   Autor: Carlos Andres Cordoba Ramos*/
void  Aeropuerto::setAbreviatura(string nuevoAbreviatura) {
  abreviatura = nuevoAbreviatura;
}
/* Input: numero entero
   output: void
   funcion: Cambia el numero de aviones disponibles de determinado Aeropuerto
   Autor: Carlos Andres Cordoba Ramos*/
void  Aeropuerto::setFlotaAviones(int nuevaCantidad) {
  totalAvionesOperacion = nuevaCantidad;
}

/* Input: vector de aerolimneas
   output: void
   funcion: establece la lista de aerolineas que trabajan para el aeropuerto
   Autor: Camilo Arias*/
void Aeropuerto::setAerolineas(vector<int> aerolineas){
  this->aerolineas = aerolineas;
}

/* Input: numero entero
   output: void
   funcion: Cambia la capacidad maxima de personas
   para determinado Aeropuerto
   Autor: Carlos Andres Cordoba Ramos*/
void  Aeropuerto::setVolumenMaximoPersonas(int nuevaCantidad) {
  volumenMaximoPersonas=nuevaCantidad;
}


/*Agrega una aerolinea al vector Aerolineas
  addAerolinea(aerolinea) -> void
  aerolinea              == Aerolinea   Aerolinea a adicionar
*/
void Aeropuerto::addAerolinea(int aerolinea){
  this->aerolineas.push_back(aerolinea);
}

//::::::::::::::::::::::::::::::Geters::::::::::::::::::
/*Input: void
  output: int
  funcion: Retorna el id del aeropuerto
  Autor: Camilo Arias*/
int Aeropuerto::getId(){
  return id;
}

/* Input: void
   output: cadena de texto
   funcion: devuelve el nombre de determinado aeropuerto
   Autor: Carlos Andres Cordoba Ramos */
string  Aeropuerto::getNombre (){
 return nombre;
}
/* Input: void
   output: cadena de texto
   funcion: devuelvela abreviatura de determinado aeropuerto
   Autor: Carlos Andres Cordoba Ramos */
string  Aeropuerto::getAbreviatura (){
 return abreviatura;
}
/* Input: void
   output: nuemro entero
   funcion: devuelve la cantidad de aviones diponibles de determinado aeropuerto
   Autor: Carlos Andres Cordoba Ramos */
int  Aeropuerto::getCantidadFlota (){
 return totalAvionesOperacion;
}

/*Input: void
  output: vector de aerolijneas
  funcion: Retorna las aerolineas que trabajan para el aeropuerto
  Autor: Camilo Arias*/
vector<int> Aeropuerto::getAerolineas(){
  return this->aerolineas;
}

/* Input: void
   output: numero entero
   funcion: devuelve la cantidad maxima personas que pueden estar
   en determinado aeropuerto
   Autor: Carlos Andres Cordoba Ramos */
int  Aeropuerto::getMaximoPersonas (){
 return volumenMaximoPersonas;
}


/*Retorna true si una aerolinea ya se encuentra en el vactor  de aerolineas,  se
  le pasa el id de la aerolinea
  verifyIfAerolineExist(id) -> bool      true si ya se encuentra
  id                        == int       id de la aerolinea
*/
bool Aeropuerto::verifyIfAerolineExist(int id){
  bool exist = false;
  for(int i = 0; i < this->aerolineas.size(); ++i){
    if(this->aerolineas[i] == id){
      exist = true;
    }
  }
  return exist;
}
