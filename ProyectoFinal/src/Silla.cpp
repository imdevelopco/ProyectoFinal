#include "Silla.h"

using namespace std;

Silla::Silla()
{
  this->numero = "";
  this->tipo   = "normal";
}

Silla::Silla(string numero, string tipo){
   this->numero = numero;
   this->tipo   = tipo;
}

Silla::~Silla()
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
void Silla::setNumber(string num){ //establece el numero de la silla
  this->numero = num;
}

void Silla::setType(string tipo){ //establerce el tipo de la suilla
  this->tipo = tipo;
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
string Silla::getNumber(){ //retorna el número de la silla
  return this->numero;
}

string Silla::getType(){ //retorna el tipo de la silla.
  return this->tipo;
}
