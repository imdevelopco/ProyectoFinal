#include "Avion.h"

Avion::Avion()
{
  //Crear las sillas preferenciales
  for (int i = 0; i < 10; i++) {
    Silla silla("p-"+i,"preferencial",0);
    this->preferencial.push_back(silla);
  }

  //Crear las sillas normales
  for(int i = 0; i < 30; ++i){
    Silla silla("n-"+i,"normal",0);
    this->normal.push_back(silla);
  }

  //crear las sillas de bajo bajo costo
  for(int i = 0; i < 30; i++){
    Silla silla("b-"+i,"bajo costo",0);
    this->bajoCosto.push_back(silla);
  }

  this->matricula               = "matricula";
  this->estado                  = "Excelente";
  this->disponiblePreferencial  = this->preferencial.size();
  this->disponibleNormal        = this->normal.size();
  this->disponibleBajoCosto     = this->bajoCosto.size();
  this->cantidadGasolina        = 1000;
  this->tiempoMaximo            = 50;

  /*Se debe establecer el aeropuerto de origen y de destino por medio de los setters*/
}

Avion::Avion(vector<Silla> preferencial, vector<Silla> normal, vector<Silla> bajoCosto, string matricula, Aeropuerto origen, Aeropuerto destino, int cantidadGasolina, int tiempoMaximo){
  this->preferencial            = preferencial;
  this->normal                  = normal;
  this->bajoCosto               = bajoCosto;
  this->matricula               = matricula;
  this->estado                  = "Excelente";
  this->disponiblePreferencial  = preferencial.size();
  this->disponibleNormal        = normal.size();
  this->disponibleBajoCosto     = bajoCosto.size();
  this->origen                  = origen;
  this->destino                 = destino;
  this->cantidadGasolina        = cantidadGasolina;
  this->tiempoMaximo            = tiempoMaximo;
}

Avion::~Avion()
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
/*Establece las sillas preferenciales del avion
  setSillasPreferencial(sillas) -> void
  sillas                        == vector<Silla>
*/
void Avion::setSillasPreferencial(vector<Silla> sillas){
  this->preferencial = sillas;
}

/*Establece las sillas normales del avion
  setSillasNormal(sillas) -> void
  sillas                 == vector<Silla>
*/
void Avion::setSillasNormal(vector<Silla> sillas){
  this->normal = sillas;
}

/*Establece las sillas de bajo costo dl avion
  setSillasBajoCosto(sillas) -> void
  sillas                     == vector<Silla>
*/
void Avion::setSillasBajoCosto(vector<Silla> sillas){
  this->bajoCosto = sillas;
}

/*Establece la matricula del avion
  setMatricula(matricula) -> void
  matricula               == string
*/
void Avion::setMatricula(string matricula){
  this->matricula = matricula;
}

/*Establece el status del avion
  setStatus(status) -> void
  status            == string
*/
void Avion::setStatus(string status){
  this->estado = status;
}

/*Establece el total de sillas preferenciales disponibles
  setTotalDisponiblePreferencial(tot) -> void
  tot                                 == int
*/
void Avion::setTotalDisponiblePreferencial(int tot){
  this->disponiblePreferencial = tot;
}

/*Establece el total de sillas normales disponibles
  setTotalDisponibleNormal(tot) -> void
  tot                           == int      Total de sillas normales disponibles
*/
void Avion::setTotalDisponibleNormal(int tot){
  this->disponibleNormal = tot;
}

/*Establece el total de sillas  a bajo costo disponibles
  setTotalDisponibleBajo(tot) -> void
  tot                         == int      Total de sillas bajo costo disponibles
*/
void Avion::setTotalDisponibleBajo(int tot){
  this->disponibleBajoCosto = tot;
}

/*Establece el aeropuesto de origen del avion
  setAeropuertoOrigen(origen) -> void
  origen                      == Aeropuerto
*/
void Avion::setAeropuertoOrigen(Aeropuerto origen){
  this->origen = origen;
}

/*Establece el aeropuerto de destino de el avión
  setAeropuertoDestino(destino) -> void
  destino                       == Aeropuerto
*/
void Avion::setAeropuertoDestino(Aeropuerto destino){
  this->destino = destino;
}

/*Establece la cantidad de gasolina que le cabe al avion
  setCantidadGasolina(cant) -> void
  cant                      == int
*/
void Avion::setCantidadGasolina(int cant){
  this->cantidadGasolina = cant;
}

/*Establece el tiempo maximo de vuelo del avion
  setTiempoMaximo(tiempo) -> void;
  tiempo                  == int      Tiempo en horas de vuelo
*/
void Avion::setTiempoMaximo(int tiempo){
  this->tiempoMaximo = tiempo;
}

//Settea los valores por defecto de una instancia de la Clase avion
void Avion::llenarDatos()
{
    string placaAvion;
    int cantidadTanque;
    cout<<"Digite la matricula del avion"<<endl;
    cin>>placaAvion;
    setMatricula(placaAvion);
    cout<<"Digite la capacidad del tanque de gasolina del avion"<<endl;
    cin>>cantidadTanque;
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
vector<Silla> Avion::getSillasPreferencial(){ //retorna el array de sillas  pre-
    return this->preferencial;                //ferenciales
}

vector<Silla> Avion::getSillasNormal(){//retorna el array de dillas normales que
  return this->normal;                 //tiene el avion
}

vector<Silla> Avion::getSillasBajoCosto(){//retorna  el array  de sillas de bajo
  return this->bajoCosto;                 //costo que tiene el avion
}

string Avion::getMatricula(){//retorna la matricula del avión
  return this->matricula;
}

string Avion::getStatus(){//retorna el estado de avion
  return this->estado;
}

int Avion::getTotalDisponiblePreferencial(){//retorna la  cantidad disponible de
  return this->disponiblePreferencial;      //sillas preferenciales en el avion
}

int Avion::getTotalDisponibleNormal(){//retorna la cantidad  de sillas  normales
  return this->disponibleNormal;      //disponibles en el avión
}

int Avion::getTotalDisponibleBajo(){//retorna  el total  de sillas de bajo costo
  return this->disponibleBajoCosto; //disponibles en el avion
}

Aeropuerto Avion::getAeropuertoOrigen(){//retorna  el  aeropuerto  de origen del
  return this->origen;                  //avión
}

Aeropuerto Avion::getAeropuertoDestino(){//retorna  el  aeropuesro de destino de
  return this->destino;                  //el avion
}

int Avion::getCantidadGasolina(){//retorna  la  capacidad  total de gasolina del
  return this->cantidadGasolina; //avion;
}

int Avion::getTiempoMaximo(){//retorna el tiempo maximo de vuelo de el aavion
  return this->tiempoMaximo;
}
// Entrada: Void
// Salida: numero entero.
// Funcion: Retorna la cantidad de sillas disponibles en general sin tener en
// cuenta el tipo de silla.
// Autor: Carlos Andres Cordoba.
int Avion::getSillasDisponibles()
{
    int acum=0;
        for(int i =0;i<preferencial.size();i++){
        if( preferencial[i].getStatus() == 0)
        acum++;
        }
        for(int i =0;i<normal.size();i++){
        if( normal[i].getStatus() == 0)
        acum++;
        }
        for(int i =0;i<bajoCosto.size();i++){
        if( bajoCosto[i].getStatus() == 0)
        acum++;
        }
    return acum;
}
// Entrada: void
// Salida: cadena de texto.
// Funcion: Retorna la cantidad de sillas disponibles en por el tipo de silla.
// Autor: Carlos Andres Cordoba.
void Avion::getSillasDisponiblesPorCategoria()
{
    int costosa = 0,normalita = 0, barata = 0;
     for(int i =0;i<preferencial.size();i++){
        if( preferencial[i].getStatus() == 0)
        costosa++;
        }
        for(int i =0;i<normal.size();i++){
        if( normal[i].getStatus() == 0)
        normalita++;
        }
        for(int i =0;i<bajoCosto.size();i++){
        if( bajoCosto[i].getStatus() == 0)
        barata++;
        }
        cout<<"La diponibilidad es la siguiente:"<<endl;
        cout<<"Sillas Preferenciales: "<<costosa<<endl;
        cout<<"Sillas Normales: "<<normalita<<endl;
        cout<<"Sillas de bajo costo: "<<barata<<endl;
}

/*Retorna  la  cantidad  de  sillas  disponibles  de el tipo que se  le pase por
  parametro.
  getTotalBy(tipoSilla) -> int     Total de sillas disponibles de ese tipo
  tipoSilla             == string  Tipo de sillas ["preferencial","normal","bajo costo"]
*/
int Avion::getTotalBy(string tipoSilla){
  int totalSillas = 0;
  if(tipoSilla == "preferencial"){
    for(int i = 0; i < this->preferencial.size(); ++i){
      if(this->preferencial[i].getStatus() == 0){
        totalSillas++;
      }
    }
  }
  else if(tipoSilla == "normal"){
    for(int i = 0; i < this->normal.size(); ++i){
      if(this->normal[i].getStatus() == 0){
        totalSillas++;
      }
    }
  }
  else if(tipoSilla == "bajoCosto"){
    for(int i = 0; i < this->bajoCosto.size(); ++i){
      if(this->bajoCosto[i].getStatus() == 0){
        totalSillas++;
      }
    }
  }
  return totalSillas;
}

/*establece una silla del avion como ocupada, se le debe pasar el tipo de silla
  a ocupar.
  ocuparSilla(tipo) -> string   Numero de la silla ocupada
  tipo              == string   Tipo de silla opciones "preferencial", "normal", "bajoCosto"]
*/
string Avion::ocuparSilla(string tipo){
  int i = 0;
  string sillaNum;
  bool continueLoop = true;
  if(tipo == "preferencial"){
    do {
      if(this->preferencial[i].getStatus() == 0){ //si la silla esta libre
         this->preferencial[i].setStatus(1); //se establece la silla como ocupada
         sillaNum = this->preferencial[i].getNumber();
         continueLoop = false; //paramos el ciclo, asi solo pone un a silla como ocuapada
      }
    } while(continueLoop);
  }
  else if(tipo == "normal"){
    do {
      if(this->normal[i].getStatus() == 0){
         this->normal[i].setStatus(1); //se establece la silla como ocupada
         sillaNum = this->normal[i].getNumber();
         continueLoop = false; //paramos el ciclo, asi solo pone un a silla como ocuapada
      }
    } while(continueLoop);
  }
  else if(tipo == "bajoCosto"){
    do {
      if(this->bajoCosto[i].getStatus() == 0){
         this->bajoCosto[i].setStatus(1); //se establece la silla como ocupada
         sillaNum = this->bajoCosto[i].getNumber();
         continueLoop = false; //paramos el ciclo, asi solo pone un a silla como ocuapada
      }
    } while(continueLoop);
  }

  return sillaNum;
}
