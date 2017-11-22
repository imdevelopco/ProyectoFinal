#include "Telefono.h"

/*Constructor vcio, establece los atributos con vbalores predeterminados*/
Telefono::Telefono()
{
  this->tipo       = "celular";
  this->indicativo = 57;
  this->numero     = 000000000;
}

/*Constructor :
   tipo        == string  Opciones  ["celular", "móvil", "trabajo"]
   indicativo  == int     Indicatico del país
   numero      == int     Numero de telfono
*/
Telefono::Telefono(string tipo, int indicativo, int numero){
  this->tipo       = tipo;
  this->indicativo = indicativo;
  this->numero     = numero;
}

Telefono::~Telefono()
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
// Establece el tipo de numero telefonico, no retorna nada (void)
void Telefono::setType(string type){
   this->tipo = type;
}

//establece el indicativo del numero telefonico, no tiene retorno
void Telefono::setIndicativo(int indicativo){
  this->indicativo = indicativo;
}

//establece el numeo de telefono del número telefonico, no retorna nada
void Telefono::setNumber(int num){
  this->numero = num;
}

/* +───────────────────────────────────────────────────────────────────────+ */
/*	      /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$   /$$$$$$ 	     */
/*       /$$__  $$| $$_____/|__  $$__/| $$_____/| $$__  $$ /$$__  $$		 */
/*      | $$  \__/| $$         | $$   | $$      | $$  \ $$| $$  \__/		 */
/*      | $$ /$$$$| $$$$$      | $$   | $$$$$   | $$$$$$$/|  $$$$$$  		 */
/*      | $$|_  $$| $$__/      | $$   | $$__/   | $$__  $$ \____  $$		 */
/*      | $$  \ $$| $$         | $$   | $$      | $$  \ $$ /$$  \ $$		 */
/*      |  $$$$$$/| $$$$$$$$   | $$   | $$$$$$$$| $$  | $$|  $$$$$$/         */
/*       \______/ |________/   |__/   |________/|__/  |__/ \______/          */
/* +───────────────────────────────────────────────────────────────────────+ */
//retorna el tipo del numero telefonioco ["celular", "móvil", "trabajo"]
string Telefono::getType(){
  return this->tipo;
}

//retorna el indicativo
int Telefono::getIndicativo(){
  return this->indicativo;
}

//retorna el número
int Telefono::getNumber(){
  return this->numero;
}
