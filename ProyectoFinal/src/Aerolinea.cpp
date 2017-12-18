#include "Aerolinea.h"
#include<vector>

Aerolinea::Aerolinea()
{
    //ctor
}

Aerolinea::Aerolinea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, string matriculaAerea):CompaniaAerea(id, nit, razonSocial, direccion, paginaWeb, agenda, representante){
  this->matriculaAerea     = matriculaAerea;
}

Aerolinea::~Aerolinea()
{

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
//falta comentario
// Autor: Carlos Andres Cordoba Ramos
void Aerolinea::addAvionToFlota(Avion avioneta)
{
    flota.push_back(avioneta);
    cout<<"Se ha insertado el avion a la flota!!"<<endl;
}
void Aerolinea::addAvionToFlota(Avion *avioneta)
{
    flota.push_back(*avioneta);
    cout<<"Se ha insertado el avion a la flota!!"<<endl;
}
/*retorna los aeropuertos de origen de una flota de aviones*/
vector<string> Aerolinea::getCytiesOrigenFl(){
  vector<string> origen;
  for(int i = 0; i < this->flota.size(); ++i){
    Aeropuerto aeropuertoOrigen = this->flota[i].getAeropuertoOrigen();
    if(origen.size() > 0){ //si ya hay elementos en origen, verifi
      bool save = true;
      for(int j = 0; j < origen.size(); j++){
        if (origen[j] == aeropuertoOrigen.getNombre()) {
          save = false;
        }
      }

      if(save){
        origen.push_back( aeropuertoOrigen.getNombre() );
      }
    }
    else{
      origen.push_back( aeropuertoOrigen.getNombre() );
    }
  }

  return origen;
}


/*Muestra en pantalla los vuelos disponibles, verifica si el vuelo tiene sillas
  disponibles, si es asi lo muestra
  showVuelosDisponibles(cyti) -> int    total vuelos disponibles
  cyti                        == string nombre del aeropuerto
*/
int Aerolinea::showVuelosDisponibles(string cyti){
  int TotalDispo = 0;
  for(int i = 0; i < this->flota.size(); ++i){
    Aeropuerto origen  = this->flota[i].getAeropuertoOrigen();
    if( this->flota[i].getSillasDisponibles() > 0 && origen.getNombre() == cyti){ //si hay sillas disponibles, se muestra el vuelo
      Aeropuerto destino = this->flota[i].getAeropuertoDestino();
      cout << to_string(i+1)+")   "+origen.getAbreviatura()+" -> "+destino.getAbreviatura() << endl;
      TotalDispo++;
      for(int j = 0; j < this->flota.size(); ++j){
        Aeropuerto origen2  = this->flota[j].getAeropuertoOrigen();
        Aeropuerto destino2 = this->flota[j].getAeropuertoDestino();
        if( this->flota[j].getSillasDisponibles() > 0 && (origen2.getNombre() == destino.getNombre() && destino2.getNombre() != origen.getNombre() ) ){
          cout << to_string(i+1)+"."+to_string(j+1)+") "+origen.getAbreviatura()+" -> "+destino.getAbreviatura()+" -> "+destino2.getAbreviatura() << endl;
          TotalDispo++;
        }
      }
    }
  }
  return TotalDispo;
}

/*Muestra en pantalla los vuelos disponibles, verifica si el vuelo tiene sillas
  disponibles para el tipo de cliente que e le pase por parametro,  si es asi lo
  muestra
  showVuelosDisponibles(cyti, golden) -> int    total de vuelos disponibles
  cyti                                == string nombre del aeropuerto
  golden                              == bool   si es un cliente golden se pasa true
*/
int Aerolinea::showVuelosDisponibles(string cyti, bool golden){
  int TotalDispo = 0;

  for(int i = 0; i < this->flota.size(); ++i){
    int disponibles;

    if(golden){
      disponibles = this->flota[i].getTotalBy("preferencial"); //"preferencial","normal","bajoCosto"
    }
    else{
      disponibles = this->flota[i].getTotalBy("normal") + this->flota[i].getTotalBy("bajoCosto");
    }

    Aeropuerto origen  = this->flota[i].getAeropuertoOrigen();
    if( disponibles > 0 && origen.getNombre() == cyti){ //si hay sillas disponibles, se muestra el vuelo
      Aeropuerto destino = this->flota[i].getAeropuertoDestino();
      cout << to_string(i+1)+")   "+origen.getAbreviatura()+" -> "+destino.getAbreviatura() << endl;
      TotalDispo++;
      for(int j = 0; j < this->flota.size(); ++j){
        int disponibles2;
        Aeropuerto origen2  = this->flota[j].getAeropuertoOrigen();
        Aeropuerto destino2 = this->flota[j].getAeropuertoDestino();

        if(golden){
          disponibles2 = this->flota[j].getTotalBy("preferencial"); //"preferencial","normal","bajoCosto"
        }
        else{
          disponibles2 = this->flota[j].getTotalBy("normal") + this->flota[j].getTotalBy("bajoCosto");
        }

        if( disponibles2 > 0 && (origen2.getNombre() == destino.getNombre() && destino2.getNombre() != origen.getNombre() ) ){
          cout << to_string(i+1)+"."+to_string(j+1)+") "+origen.getAbreviatura()+" -> "+destino.getAbreviatura()+" -> "+destino2.getAbreviatura() << endl;
          TotalDispo++;
        }
      }
    }
  }
  return TotalDispo;
}

/*se le pasa la posicion del avion en el vector de la flota y verifica si  tiene
  sillas disponibles, si es asi retorna true.
  verifyDisponiilidad(pos) -> bool     True si hay sillas disponibles, de cualquier Tipo
  pos                      == int
*/
bool Aerolinea::verifyDisponiilidad(int pos){
  if( this->flota[pos].getSillasDisponibles() > 0 ){ //si el vuelo tiene alguna silla disponible
    return true;
  }
  return false;
}

/*muestra en pantalla el tikete vendido*/
void Aerolinea::imprimirTicket(int id_avion, string num_silla, int precio){

  Aeropuerto origen  = this->flota[id_avion].getAeropuertoOrigen();
  Aeropuerto destino = this->flota[id_avion].getAeropuertoDestino();

  cout << "\n" << endl;
  cout << "+------------------------------------+" << endl;
  cout << "|"+getRazonSocial()<< endl;
  cout << "| Origen  : "+ origen.getNombre() << endl;
  cout << "| Destino : "+ destino.getNombre() << endl;
  cout << "| Silla   : "+ num_silla << endl;
  cout << "| Precio  : $"+ to_string(precio) << endl;
  cout << "+------------------------------------+\n" << endl;
}

/*Vende ticketes de avion
  sellTicket(tipoSilla, id_avion, precio) -> string    numero de silla
  tipoSilla                               == string    tipo de silla a comprar opciones ["preferencial", "normal", "bajoCosto"]
  id_avion                                == int       posicion del avion en la flota
  precio                                  == int       precio del tikete
*/
string Aerolinea::sellTicket(string tipoSilla, int id_avion, int precio){
  string sillaNum = this->flota[id_avion].ocuparSilla(tipoSilla); //ocupamos la silla del avion
  imprimirTicket(id_avion, sillaNum, precio); //mostramos el ticket
  return sillaNum;
}

/*retorna el nombre del aeropuerto de oigen de un avion de la flota*/
string Aerolinea::getOrigenPlain(int pos){
  string origen = this->flota[pos].getAeropuertoOrigen().getNombre();
  return origen;
}

/*retorna el nombre del aeropuerto de destrino de un avion de la flota*/
string Aerolinea::getDestinoPlain(int pos){
  string destino = this->flota[pos].getAeropuertoDestino().getNombre();
  return destino;
}
/*muestra en pantalla,la lista de las matriculas de los aviones en la flota*/
void Aerolinea::listAviones()
{
    cout<<"Aviones de la flota:"<<endl;
    for (int i= 0;i<flota.size();i++)
    {
        cout<<"Avion # "<<i+1<<" "<<flota[i].getMatricula()<<endl;
    }
}

int Aerolinea::getCantidadAvionesFlota()
{
    return flota.size();
}
