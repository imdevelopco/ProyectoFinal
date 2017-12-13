#include "Aerolinea.h"
#include<vector>

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
//Entrada: void
//Salida: void
//Funcion: Dependiendo de lo que quiera el usuario, este metodo sera capaz
// de eliminar, agregar  aviones a determinada flota de y tambien cambiar el tamno de
//la flota en general
// Autor: Carlos Andres Cordoba Ramos
void Aerolinea::administrarAviones()
{
    int decision;
    Avion newAvion;
    do{
            cout<<"Que deseas hacer?"<<endl;
            cout<<"1.reducir el tamano de la flota"<<endl;
            cout<<"2.eliminar un avion de la flota"<<endl;
            cout<<"3.agregar un avion a la flota"<<endl;
            cin>>decision;
    }while((decision != 1)&&(decision != 2)&&(decision != 3));
    switch(decision){

    case 1:{
            int reductor;
            cout<<"cuantos aviones quiere que tenga la flota?"<<endl;
            cin>>reductor;
            flota.resize(reductor);
    };
    break;
    case 2:{
            string matricula;
            bool noEsta = false;
            cout<<"Digita la matricula del avion que quieres eliminar"<<endl;
            cin>>matricula;
            for (int i=0;i<flota.size();i++){
                if(matricula == flota[i].getMatricula()){
                        if(flota[i].getSillasDisponibles() > 0){
                            cout<<"No se puede eliminar el avion por que tiene tiquetes vendidos"<<endl;
                        }else if (flota[i].getSillasDisponibles() > 0){
                    flota.erase(flota.begin()+i);
                    cout<<"Se ha eliminado el avion de la flota"<<endl;
                    }
                }else{
                    noEsta=true;
                }
            }
            if(noEsta == true){
                cout<<"No se ha encontrado el avion en la flota"<<endl;
            }
        };
    break;
    case 3:{
            newAvion.llenarDatos();
            flota.push_back(newAvion);
            cout<<"Se ha insertado el avion en la flota con exito!"<<endl;
    };
    break;
    }


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
  showVuelosDisponibles(cyti) -> void    Salia en pantalla
  cyti                        == string nombre del aeropuerto
*/
void Aerolinea::showVuelosDisponibles(string cyti){

  for(int i = 0; i < this->flota.size(); ++i){
    Aeropuerto origen  = this->flota[i].getAeropuertoOrigen();
    if( this->flota[i].getSillasDisponibles() > 0 && origen.getNombre() == cyti){ //si hay sillas disponibles, se muestra el vuelo
      Aeropuerto destino = this->flota[i].getAeropuertoDestino();
      cout << to_string(i+1)+")   "+origen.getAbreviatura()+" -> "+destino.getAbreviatura() << endl;
      for(int j = 0; j < this->flota.size(); ++j){
        Aeropuerto origen2  = this->flota[j].getAeropuertoOrigen();
        Aeropuerto destino2 = this->flota[j].getAeropuertoDestino();
        if( this->flota[j].getSillasDisponibles() > 0 && (origen2.getNombre() == destino.getNombre() && destino2.getNombre() != origen.getNombre() ) ){
          cout << to_string(i+1)+"."+to_string(j+1)+") "+origen.getAbreviatura()+" -> "+destino.getAbreviatura()+" -> "+destino2.getAbreviatura() << endl;
        }
      }
    }
  }

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
void Aerolinea::imprimirTicket(int id_avion, string num_silla){

  Aeropuerto origen  = this->flota[id_avion].getAeropuertoOrigen();
  Aeropuerto destino = this->flota[id_avion].getAeropuertoDestino();

  cout << "\n" << endl;
  cout << "+------------------------------------+" << endl;
  cout << "|"+getRazonSocial()<< endl;
  cout << "| Origen  : "+ origen.getNombre() << endl;
  cout << "| Destino : "+ destino.getNombre() << endl;
  cout << "| Silla   : "+ num_silla << endl;
  cout << "+------------------------------------+\n" << endl;
}

/*Vende ticketes de avion
  sellTicket(tipoSilla, id_avion) -> string    numero de silla
  tipoSilla                       == string    tipo de silla a comprar opciones ["preferencial", "normal", "bajoCosto"]
  id_avion                        == int       posicion del avion en la flota
*/
string Aerolinea::sellTicket(string tipoSilla, int id_avion){
  string sillaNum = this->flota[id_avion].ocuparSilla(tipoSilla); //ocupamos la silla del avion
  imprimirTicket(id_avion, sillaNum); //mostramos el ticket
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
}
