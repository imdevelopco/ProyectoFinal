#include "Tiquete.h"

Tiquete::Tiquete()
{
    Aeropuerto aeropuertoOrigen;
    Aeropuerto aeropuestoDestino;
    Aerolinea aerolines;
    Avion avion;
    Silla silla;
    Cliente cliente;

    this->id = 0;
    this->origen = aeropuertoOrigen;
    this->destino = aeropuestoDestino;
    this->numeroTiquerte = 0;
    this->aerolines = aerolines;
    this->avion = avion;
    this->silla = silla;
    this->estado = "No check";
    this->cliente = cliente;
}

Tiquete::Tiquete(int id, Aeropuerto origen,Aeropuerto destino,int numeroTiquerte,Aerolinea aerolines,Avion avion,Silla silla,string estado,Cliente cliente){
   this->origen = origen;
   this->destino = destino;
   this->numeroTiquerte = numeroTiquerte;
   this->aerolines = aerolines;
   this->avion = avion;
   this->silla = silla;
   this->estado = estado;
   this->cliente = cliente;
}

Tiquete::~Tiquete()
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
