#include "Aeropuerto.h"
#include "Aerolinea.h"

Aeropuerto::Aeropuerto()
{
    //ctor
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
/* Input: numero entero
   output: void
   funcion: Cambia la capacidad maxima de personas
   para determinado Aeropuerto
   Autor: Carlos Andres Cordoba Ramos*/
void  Aeropuerto::setVolumenMaximoPersonas(int nuevaCantidad) {
  volumenMaximoPersonas=nuevaCantidad;
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
/* Input: void
   output: numero entero
   funcion: devuelve la cantidad maxima personas que pueden estar
   en determinado aeropuerto
   Autor: Carlos Andres Cordoba Ramos */
int  Aeropuerto::getMaximoPersonas (){
 return volumenMaximoPersonas;
}
