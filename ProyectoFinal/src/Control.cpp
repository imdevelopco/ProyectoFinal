#include "Control.h"
#include <iostream>
#include <string>

Control::Control()
{
    //ctor
}

Control::Control(vector<Aeropuerto> aeropuertos, vector<AgenciaDeViaje> agencias, vector<Aerolinea> aerolineas, vector<Representante> representantes)
{
  this->aeropuertos    = aeropuertos;
  this->agencias       = agencias;
  this->aerolineas     = aerolineas;
  this->representantes = representantes;
}

Control::~Control()
{
    //dtor
}

/*Retorna un id unico para  ser usado  cuando se crea un agencia, toma el número
  mayor de las agencia y retorna ese número + 1
  getLastAgencyId() -> int
*/
int Control::getLastAgencyId(){
  int mayor = 0;
  /*for(AgenciaDeViaje agencia : this->agencias){ //recorremos las agencias
      //si el id de la agencia es mayor, la establecemos como el id mayor, si no
      //se deja el mismo valor.
      mayor = (agencia.getId() > mayor) ? agencia.getId() : mayor;
  }*/
  for(int i = 0; i < this->agencias.size(); ++i){
    mayor = (this->agencias[i].getId() > mayor) ? this->agencias[i].getId() : mayor;
  }
  return mayor+1;
}

/*Retorna el ultimo id mas grande +1 de las aerolineas, sirve para  crear el  id
  unico
  getLastAerolineaId() -> int
*/
int Control::getLastAerolineaId(){
  int mayor = 0;
  for(int i = 0; i < this->aerolineas.size(); ++i){
    mayor = (this->aerolineas[i].getId() > mayor) ? this->aerolineas[i].getId() : mayor;
  }
  return mayor+1;
}

/*Retorna  un  numero  para  ser  usado  como  id de un aeropuerto, verifica los
  aeropuertos y obtiene el id más grande y le suma uno.
  getLatsAirportId() -> int
*/
int Control::getLatsAirportId(){
  int mayor = 0;
  for(int i = 0; i < this->aeropuertos.size(); ++i){
    mayor = (this->aeropuertos[i].getId() > mayor) ? this->aeropuertos[i].getId() : mayor;
  }
  return mayor+1;
}

/*Retorna un  numero  para ser  usado como  id unico de tiquete, toma numero más
 grande de los tiquetes y le suma uno
*/
int Control::getLastTiketId(){
  int mayor = 0;
  for(int i = 0; i < this->tiquetes.size(); ++i){
    mayor = (this->tiquetes[i].getId() > mayor) ? this->tiquetes[i].getId() : mayor;
  }
  return mayor+1;
}

/*Pide información para crear un número de telefono, por ultimo lo retorna.
  createPhone() -> Telefono
*/
Telefono Control::createPhone(){
  //string tipo, int indicativo, int numero
  string type; //["celular", "móvil", "trabajo"]
  int indicative, number;
  cout << "::::::::::Crear Telefono::::::::::" << endl;
  do{
    cout << "Tipo (celular,movil,trabajo)" << endl;
    cin >> type;
  }while(type != "celular" && type != "movil" && type != "trabajo");//no continua si no ingresa un valor valido

  cout << "Indicativo " << endl;
  cin >> indicative;

  cout << "Numero " << endl;
  cin >> number;

  Telefono tel(type, indicative, number);
  return tel;
}


/*Pide información al usuario para  crear un representante, por  ultimo  retorna
 el representante creado
 createRepesent() -> Representante
*/
Representante Control::createRepesent(){
  string firstName, secondName, firstLastName, secondLastName, address, documentType;
  int numberDocument, mes, dia;
  Telefono number;
  struct tm BornDate;
  char haveSecondName, haveSecondLastName;

  cout << "::::::::::Crear Representante::::::::::" << endl;
  cout << "Primer nombre:" << endl;
  cin >> firstName;

  //verificar si tiene segundo nombre y guardarlo en tal caso.
  do {
    cout << "tiene segundo nombre? (s/n)" << endl;
    cin >> haveSecondName;
  } while(haveSecondName != 'n' && haveSecondName != 's'); //verificar que ingreso un valor correcto

  if(haveSecondName == 's'){
    cout << "Segundo nombre" << endl;
    cin >> secondName;
  }
  else{
    secondName = "";
  }

  cout << "Primer apellido:" << endl;
  cin >> firstLastName;

  //verificar si tiene segundo apellido y guardarlo en tal caso.
  do {
    cout << "tiene segundo apellido? (s/n)" << endl;
    cin >> haveSecondLastName;
  } while(haveSecondLastName != 'n' && haveSecondLastName != 's'); //verificar que ingreso un valor correcto

  if(haveSecondLastName == 's'){
    cout << "Segundo apellido" << endl;
    cin >> secondLastName;
  }
  else{
    secondLastName = "";
  }

  cout << "Direccion:" << endl;
  cin >> address;

  do {
    cout << "Tipo documento (CC, CE, PT, TI, RC)" << endl;
    cin >> documentType;
  } while(documentType != "CC" && documentType !="CE" && documentType != "PT" && documentType != "TI" && documentType != "RC");

  cout << "Numero documento:" << endl;
  cin >> numberDocument;

  number = createPhone(); //crear el número de telefono del Representante

  cout << "Ano de nacimiento:" << endl;
  cin >> BornDate.tm_year;

  do{
    cout << "Mes de nacimiento:" << endl;
    cin >> mes;
  }
  while(mes < 1 || mes > 12 ); //validar el mes
  BornDate.tm_mon  =  mes-1;

  do{
    cout << "Dia de nacimiento:" << endl;
    cin >> dia;
  }
  while(dia < 1 || dia > 31); //validar el día
	BornDate.tm_mday = dia;

  Representante representante(firstName, secondName, firstLastName, secondLastName, address, documentType, numberDocument, number, BornDate);
  this->representantes.push_back(representante);
  return representante;
}

/*Lista los representantes en pantalla, no retorna nada, este metodo sirve para
  ver los representantes existentes
  listRepresnts() -> void
*/
void Control::listRepresnts(){
  for(int i = 0; i < this->representantes.size(); ++i){
    cout << to_string(i+1)+") "+ this->representantes[i].getName() << endl;
  }
}

/*Lita en pantalla las agencias existentes en this->agencias,  no retorna  nada
  sirve para ver cuales son las agencias existente
*/
void Control::listAgencias(){
  /*for(AgenciaDeViaje agencia : this->agencias){
    cout << agencia.getId()+") "+agencia.getRazonSocial() << endl;
  }*/
  for(int i = 0; i < this->agencias.size(); ++i){
    cout << to_string(this->agencias[i].getId())+") "+this->agencias[i].getRazonSocial() << endl;
  }
}

/*Lista en pantalla las aerolineas*/
void Control::listAerilineas(){
  for (int i = 0; i < this->aerolineas.size(); i++) {
    cout << to_string( this->aerolineas[i].getId() )+" ) "+this->aerolineas[i].getRazonSocial() << endl;
  }
}

/*lista en pantalla los aeropuertos existentes en el vector aeropuertos*/
void Control::listAirports(){
  for (int i = 0; i < this->aeropuertos.size(); ++i) {
    cout << to_string( this->aeropuertos[i].getId() )+" )"+ this->aeropuertos[i].getNombre() << endl;
  }
}

/*lista en pantalla los clientes*/

/*Lista las aerolineas que se le pasen por parametro*/
void Control::listThisAerolineas(vector<Aerolinea> aerolineas){
  for(int i = 0; i < aerolineas.size(); ++i){
    cout << to_string(aerolineas[i].getId())+") "+aerolineas[i].getRazonSocial() << endl;
  }
}

/*Pide información al usuario para crear una agencia, no retorna nada,  solo  la
 almacena en el atributo (variable de clase) this->agencias
 crearAgencia() -> void
*/
void Control::crearAgencia(){
  string nit, razon, direccion, pagina, choose;
  int representante_id;
  Representante representante;
  vector<Telefono> telefono;

  cout << "::::::::::Crear agencia::::::::::" << endl;
  cout << "Ingresa el NIT:" << endl;
  cin >> nit;
  cout << "Ingresa la razon social:" << endl;
  cin >> razon;
  cout << "Ingresa la direccion" << endl;
  cin >> direccion;
  cout << "Ingresa la pagina web" << endl;
  cin >> pagina;
  telefono.push_back( createPhone() );


  if(this->representantes.size() > 0){ //si hay representantes preguntamos al usuario si quiere crear uno o elegirlo
    do {
      cout << "Desea elegir o crear un representante (elegir,crear)" << endl;
      cin >> choose;
    } while(choose != "elegir" && choose != "crear");
  }
  else{ //si no hay representantes pasamos directamente a crearlo

    choose = "crear";
  }

  if(choose == "crear"){ //crear un representante
    representante = createRepesent();
  }
  else{ //elegir un representante
    listRepresnts();
    do {
      cout << "Elige un representante" << endl;
      cin >> representante_id;
    } while(representante_id < 1 || representante_id > this->representantes.size()); //validar que eligió un representante de la lista
    representante = this->representantes[representante_id-1];
  }

  AgenciaDeViaje agencia( getLastAgencyId() , nit, razon, direccion, pagina, telefono, representante, this->aerolineas);
  this->agencias.push_back(agencia);
}

/*Pide información al usuario por consola para crear un  aeropuerto, por  ultimo
  retorna el aeropuerto creado.
  createAirport() -> Aeropuerto;
*/
Aeropuerto Control::createAirport(){
  string nombre, abreviatura;
  int totalAvionesOperacion, volumenMaximoPersonas, chooseAerolinea, chooseAirport;
  char continueAddAeropuertos, continueAddAerolinea;
  bool add, addAerolinea;
  vector<int> aerolineas;

  cout << "::::::::::Crear Aeropuerto::::::::::" << endl;
  cout << "Nombre del aeropuerto" << endl ;
  cin >> nombre;
  cout << "abreviatura" << endl;
  cin >> abreviatura;
  cout << "Total aviones en operacion" << endl;
  cin >> totalAvionesOperacion;
  cout << "volumen maximo de personas" << endl;
  cin >> volumenMaximoPersonas;

  if(this->aerolineas.size() > 0){
    cout << "Aerolineas en el aeropuerto" << endl;
    do {
      listAerilineas();
      do {
        cout << "Ingresa el id de la aerolinea" << endl;
        cin >> chooseAerolinea;
      } while( !existAerolinea(chooseAerolinea) );

      if(aerolineas.size() > 0){ //si hay mas aerolineas, pasamos averificar que no agrege una que ya exista
        addAerolinea = true;
        for (int i = 0; i < aerolineas.size(); i++) {
          if(aerolineas[i] == chooseAerolinea){
            addAerolinea = false;
          }
        }
      }
      else{
        addAerolinea = true;
      }

      if(addAerolinea){
        aerolineas.push_back(chooseAerolinea );
      }

      do {
        cout << "deseas ingresar otra aerolinea (s,n)" << endl;
        cin >> continueAddAerolinea;
      } while(continueAddAerolinea != 's' && continueAddAerolinea != 'n');

    } while(continueAddAerolinea == 's');
  }

  Aeropuerto aeropuerto(getLatsAirportId(),nombre, abreviatura, totalAvionesOperacion, volumenMaximoPersonas, aerolineas);
  this->aeropuertos.push_back(aeropuerto);
  return aeropuerto;
}

/*Pide información al usuario para crear una aerolinea*/
void Control::crearAerolinea(){
  string nit, razon, direccion, pagina, matricula, choose, chooseAirport;
  char continueCreate, continueChoose;
  int representante_id, totalFlota;
  Representante representante;
  vector<Telefono> telefono;

  cout << "::::::::::Crear Aerolinea::::::::::" << endl;
  cout << "Ingresa el NIT:" << endl;
  cin >> nit;
  cout << "Ingresa la razon social:" << endl;
  cin >> razon;
  cout << "Ingresa la direccion" << endl;
  cin >> direccion;
  cout << "Ingresa la pagina web" << endl;
  cin >> pagina;
  telefono.push_back( createPhone() );
  cout << "Ingresa la matricula aerea" << endl;
  cin >> matricula;

  if(this->representantes.size() > 0){ //si hay representantes preguntamos al usuario si quiere crear uno o elegirlo
    do {
      cout << "Desea elegir o crear un representante (elegir,crear)" << endl;
      cin >> choose;
    } while(choose != "elegir" && choose != "crear");
  }
  else{ //si no hay representantes pasamos directamente a crearlo
    choose = "crear";
  }

  if(choose == "crear"){ //crear un representante
    representante = createRepesent();
  }
  else{ //elegir un representante
    listRepresnts();
    do {
      cout << "Elige un representante" << endl;
      cin >> representante_id;
    } while(representante_id < 1 || representante_id > this->representantes.size()); //validar que eligió un representante de la lista
    representante = this->representantes[representante_id-1];
  }


  Aerolinea aerolinea(getLastAerolineaId(), nit, razon, direccion, pagina, telefono, representante, matricula);
  this->aerolineas.push_back(aerolinea);
}

/*Verifica si el id que se pase pertenece a un aeropuerto, retorna true si es asi
  existAirport(int id) -> bool
  id                   == int      Id a verificar
*/
bool Control::existAirport(int id){
  bool exist = false;
  for (int i = 0; i < this->aeropuertos.size(); i++) {
    if(id == this->aeropuertos[i].getId()){
      exist = true;
    }
  }
  return exist;
}

/*verifica si el id perenece a una agencia, retorna true si es asi*/
bool Control::existAgencia(int id){
  bool exist = false;
  for(int i = 0; i < this->agencias.size(); i++){
    if(id == this->agencias[i].getId() ){
      exist = true;
    }
  }
  return exist;
}

/*Verifica si el id que se pase pertenezca a una aerolinea, retorna true si es asi
  existAerolinea(id) -> bool     True si el id pertece a alguna aerolinea
  id                 == int      Id a verificar
*/
bool Control::existAerolinea(int id){
  bool exist = false;
  for(int i = 0; i < this->aerolineas.size(); ++i){
    if(this->aerolineas[i].getId() == id){
      exist = true;
    }
  }
  return exist;
}

/*Verifica que el id que se pase por parametro sea de una agencia,  qeu  tambien
  se le pasa por parametro.
  existAerolineaInThis(aerolineas, id)  -> bool   True si existe
  aerolineas                            == vector<Aerolinea>
  id                                    == int
*/
bool Control::existAerolineaInThis(vector<Aerolinea> aerolineas, int id){
    bool exist = false;
    for(int i = 0; i < aerolineas.size(); ++i){
      if(aerolineas[i].getId() == id){
        exist = true;
      }
    }
    return exist;
}

/*Se le pasa un id de un aeropuerto y este metodo retorna dicho Aeropuerto*/
Aeropuerto Control::getAirport(int id){
  for (int i = 0; i < this->aeropuertos.size(); i++) {
    if(id == this->aeropuertos[i].getId()){
      return this->aeropuertos[i];
    }
  }
}

/*Se le pasa el id de una aerolinea y este metodo lo retorna*/
Aerolinea Control::getAeroline(int id){
  for(int i = 0; i < this->aerolineas.size(); ++i){
    if(id == this->aerolineas[i].getId() ){
      return this->aerolineas[i];
    }
  }
}

/*se le pasa el id de una agencia de viaje y la retorna*/
AgenciaDeViaje Control::getAgencia(int id){
  for(int i = 0; i < this->agencias.size(); ++i){
    if(id == this->agencias[i].getId() ){
      return this->agencias[i];
    }
  }
}

/*Se le da un id de una aerolinea y retorna la pocision de esat aeroline en el vector de arolineas*/
int Control::getPositionAeroline(int id){
  for(int i = 0; i < this->aerolineas.size(); ++i){
    if (id == this->aerolineas[i].getId() ){
      return i;
    }
  }
}

/*Se le pasa un id de una agencia y retorna la posicion en la que se encuentra en el array de agencias*/
int Control::getPositionAgency(int id){
  for(int i = 0; i < this->agencias.size(); ++i){
    if (id == this->agencias[i].getId() ){
      return i;
    }
  }
}

/*Se le pasa un id de un aeropuetp y retorna la posicion en la que se encuentra en el array de aeropuertos*/
int Control::getPositionAirport(int id){
  for(int i = 0; i < this->aeropuertos.size(); ++i){
    if (id == this->aeropuertos[i].getId() ){
      return i;
    }
  }
}

/*Pide infoemación por consola al usuario para qeu establesca una aerolina en un
  aeropuerto. (agregar aerolineas a un aeropuerto)
*/
void Control::addAeroliaToAirport(){
  int airportChoose, airlaineChoose;
  Aeropuerto airport;
  Aerolinea airline;
  bool exist;

  cout << "::::::::::Agregar aerolinea a aeropuerto::::::::::" << endl;
  cout << "Selecciona un aeropuerto" << endl;
  listAirports();
  do {
    cout << "Ingresa el id del aeropuerto" << endl;
    cin >> airportChoose;
  } while(!existAirport(airportChoose)); //verificar que el aeropuerto exista

  cout << "Selecciona la aerolinea que le deseas agregar" << endl;
  listAerilineas();
  do {
    cout << "Ingresa el id de la aerolinea" <<endl;
    cin >> airlaineChoose;
  } while(!existAerolinea(airlaineChoose)); //verificar que ingrese un id de una aerolinea

  vector<int> aerolineas = this->aeropuertos[getPositionAirport(airportChoose)].getAerolineas();
  for (int i = 0; i < aerolineas.size(); i++) {
    exist = false;
    if(aerolineas[i] == airlaineChoose){
      exist = true;
    }
  }

  if(!exist){
    this->aeropuertos[getPositionAirport(airportChoose)].addAerolinea(airlaineChoose);
  }
  else{
    cout << "El aeropuerto ya cuenta con esta aerolinea" << endl;
  }
}

/*WEstablece el total de aviones de una aerolinea*/
void Control::setAvionesDeAerolinea(){
  int idAerolinea, totalAviones;
  Aerolinea aerolinea;

  cout << "Establecer aviones de una aerolinea" << endl;
  listAerilineas();
  do {
    cout << "ingresa el id del aerolinea" << endl;
    cin >> idAerolinea;
  } while( !existAerolinea(idAerolinea) );

  cout << "ingresa el total de aviones" << endl;
  cin >> totalAviones;
  aerolinea = getAeroline(idAerolinea);
  aerolinea.setTotalPlains(totalAviones);
}

/*retorna el precio de una silla preferencial*/
int Control::getVariacionPrecio(int base, string tipo){
  int percent = (15 * base) / 100;
  if(tipo == "preferencial"){
    return (base + percent);
  }
  return (base - percent);
}

/*Pide informacion al usuario para vender un tiquete*/
void Control::venderTiket(){
  string compania, haveEscalas;
  int agencia_id, aerolinea_id, aeropuertoOrigen_id, client_id;
  Aeropuerto origen;
  vector<Aeropuerto> destinos, destinos2;
  vector<int> vuelos;
  vector<string> tickets;
  Cliente client;

  cout << "\n :::::::::Vender ticket:::::::" << endl;
  do {
    cout << "Agencia o aerolinea? (agencia, aerolinea)" << endl;
    cin >> compania;
  } while(compania != "agencia" && compania != "aerolinea");

  if(compania == "agencia"){ // si selecciono una agencia, mostramos la lista de agencias
        //┌─┐┌─┐┌─┐┌┐┌┌─┐┬┌─┐
        //├─┤│ ┬├┤ ││││  │├─┤
        //┴ ┴└─┘└─┘┘└┘└─┘┴┴ ┴
        listAgencias();
        do {
          cout << "Ingresa el id de la agencia" << endl;
          cin >> agencia_id;
        } while( !existAgencia(agencia_id) );

        //mostramos las aerolineas de la agencia
        vector<Aerolinea> aerolineasDeagencia = getAgencia(agencia_id).getAerolineas();
        cout << "Aerolineas de la  agencia" << endl;
        listThisAerolineas(aerolineasDeagencia);
        do {
            cout << "Ingresa el id de una aerolinea de la agencia" << endl;
            cin >> aerolinea_id;
        } while( !existAerolineaInThis(aerolineasDeagencia, aerolinea_id) ); //verificamos que el id que ingreso es de un
  }
  else{ //si selecciono una aerolinea le mostramos la lista de aerolineas
        //┌─┐┌─┐┬─┐┌─┐┬  ┬┌┐┌┌─┐┌─┐
        //├─┤├┤ ├┬┘│ ││  ││││├┤ ├─┤
        //┴ ┴└─┘┴└─└─┘┴─┘┴┘└┘└─┘┴ ┴
        cout << "Aerolineas" << endl;
        listAerilineas();
        do {
          cout << "ingresa el id de la aerolinea" << endl;
          cin >> aerolinea_id;
        } while( !existAerolinea(aerolinea_id) );
  }

  //Seleccionar cliente
  cout << "Selecionar Cliente" << endl;
  if(compania == "agencia"){
    this->agencias[getPositionAgency(agencia_id)].listClients();
    do {
      cout << "Ingresa la posicion del cliente" << endl;
      cin >> client_id;
    } while(client_id < 1 || client_id > this->agencias[getPositionAgency(agencia_id)].getClients().size() );
    vector<Cliente> clientes = this->agencias[getPositionAgency(agencia_id)].getClients();
    client = clientes[client_id-1];
  }
  else{
    this->aerolineas[getPositionAeroline(aerolinea_id)].listClients();
    do {
      cout << "Ingresa la posicion del cliente" << endl;
      cin >> client_id;
    } while( client_id < 1 || client_id > this->aerolineas[getPositionAeroline(aerolinea_id)].getClients().size() );
    vector<Cliente> clientes = this->aerolineas[getPositionAeroline(aerolinea_id)].getClients();
    client = clientes[client_id-1];
  }


  //este metodo pide la ciudad de origen, y muestra los vuelos de la agencia selecionada y de la ciudad selecionada, tambien retorna el total de vuielos disponibles
  int vuelosDisponibles = listaDeVuelosDisponibles(aerolinea_id, client);
  if( vuelosDisponibles > 0 ){ // si hay vuelos disponibles
      do {
        cout << "el vuelo tiene escalas? (si,no)" << endl;
        cin >> haveEscalas;
      } while(haveEscalas != "si" && haveEscalas != "no");

      if(haveEscalas == "si"){
        string vuelo;
        char * split;
        cout << "ingresa el numero del vuelo, recuerda poner el punto (numero_vuelo.numero_segundo_vuelo ej 1.3)" << endl;
        cin >> vuelo;
        int pos = vuelo.find(".");
        string vuelo1 = vuelo.substr(0,pos);
        string vuelo2 = vuelo.substr(pos+1);
        int fly1 = stoi( vuelo1 );
        int fly2 = stoi( vuelo2 );

        if( this->aerolineas[getPositionAeroline(aerolinea_id)].verifyDisponiilidad(fly1-1) && this->aerolineas[getPositionAeroline(aerolinea_id)].verifyDisponiilidad(fly2-1)  ){ //verificar que el vuelo tenga sillas disponibles
          if( this->aerolineas[getPositionAeroline(aerolinea_id)].getDestinoPlain(fly1-1) == this->aerolineas[getPositionAeroline(aerolinea_id)].getOrigenPlain(fly2-1) ){
            vuelos.push_back(fly1);
            vuelos.push_back(fly2);
          }
        }
      }
      else{ //si no tiene escalas
        int vuelo;
        cout << "ingresar el número del vuelo" << endl;
        cin >> vuelo;

        if( this->aerolineas[getPositionAeroline(aerolinea_id)].verifyDisponiilidad(vuelo-1) ){ //verificar que el vuelo tenga sillas disponibles
          vuelos.push_back(vuelo);
        }
        else{
          cout << "Este vuelo no tiene sillas disponibles (aca nunca va a entrar porque siempre se muestran los vuelos disponibles)" << endl;
        }
      }

      for (int i = 0; i < vuelos.size(); i++) {
        string tipoSilla;
        int cantSillas;

        cout << "\nSillas disponibles" << endl;
        vector<Avion> flota = this->aerolineas[getPositionAeroline(aerolinea_id)].getFlota();
        //flota[vuelos[i]-1].getSillasDisponiblesPorCategoria(); //-> mostrar las sillas disponibles, todas no diferencia tipo de cliente
        flota[vuelos[i]-1].getSillasDisponiblesPorCategoria( client.getGolden() );

        if( !client.getGolden() ){ //si el cliente no es golden
          do {
            cout << "que tipo de sillas desea (normal,bajoCosto)" << endl;
            cin >> tipoSilla;
          } while( tipoSilla != "normal" &&  tipoSilla != "bajoCosto");
        }
        else{//si el cliente es golden se le dean sillas preferenciales
          tipoSilla = "preferencial";
        }



        do {
          cout << "Cuantas sillas desea comprar" << endl;
          cin >> cantSillas;
        } while(cantSillas < 1);

        if( flota[vuelos[i]-1].getTotalBy(tipoSilla) >= cantSillas){ //se puede vender las sillas
          for (int j = 0; j < cantSillas; j++) {

            int ticket_id = getLastTiketId();
            int precio;
           //obtener el precio de la silla normal del avion, y dependiendo que tipo de silla elijio poner el aumento del 15 o eldecremento del 15

            if(tipoSilla == "normal"){
               precio = flota[vuelos[i]-1].getPrecioNormal();
            }
            else if( tipoSilla == "preferencial" ){
               precio = getVariacionPrecio( flota[vuelos[i]-1].getPrecioNormal(), "preferencial" );
            }
            else if( tipoSilla == "bajoCosto" ){
               precio = getVariacionPrecio( flota[vuelos[i]-1].getPrecioNormal(), "bajoCosto" );
            }

            string silla = this->aerolineas[getPositionAeroline(aerolinea_id)].sellTicket(tipoSilla, vuelos[i]-1, precio); //vender el tiquete (ocupar la silla en el avion) retorna el numero de la silla ocupada

            Tiquete tiquet(ticket_id, flota[vuelos[i]-1].getAeropuertoOrigen(), flota[vuelos[i]-1].getAeropuertoDestino(), ticket_id, this->aerolineas[getPositionAeroline(aerolinea_id)], flota[vuelos[i]-1], silla, "No check", client, precio);

            //guardar la transacion
            if(compania == "agencia"){
              this->agencias[getPositionAgency(agencia_id)].addTransacion(ticket_id);
              //darle el tiquete al cliente
              this->agencias[getPositionAgency(agencia_id)].tiketToClient(ticket_id, client_id-1);
            }
            else{
              this->aerolineas[getPositionAeroline(aerolinea_id)].addTransacion(ticket_id);
              //darle el tiquete al cliente
              this->aerolineas[getPositionAeroline(aerolinea_id)].tiketToClient(ticket_id, client_id-1);
            }


          }
        }
        else{ //no hay esa cantidad de sillas
          cout << "No hay esa cantidad de sillas disponibles" << endl;
        }
      }
  }
  else{
    cout << "No hay vuelos disponibles";
  }


  //cout << "Imprimir ticketes" << endl;

}



/*Crea un grupo de sillas */
vector<Silla> Control::createSilla(string tipo){
  int cant;
  vector<Silla> sillas;

  cout << "Cuantas sillas de este tipo tiene el avion" << endl;
  cin >> cant;

  for(int i = 0; i < cant; ++i){
    Silla silla(tipo+"-"+to_string(i), tipo,0);
    sillas.push_back(silla);
  }

  return sillas;
}

/*crea un avion*/
Avion Control::createPlain(){
  vector<Silla> preferencial, normal, bajoCosto;
  string matricula;
  Aeropuerto origen, destino;
  int airportOrigen_id, airportDestino_id, cantidadGasolina, tiempoMaximo, precioSillaNormal;

  cout << "Sillas preferenciales" << endl;
  preferencial = createSilla("preferencial");

  cout << "Sillas normales" << endl;
  normal = createSilla("normal");

  cout << "Sillas bajo costo" << endl;
  bajoCosto = createSilla("bajoCosto");

  cout << "Matricula" << endl;
  cin >> matricula;

  if(this->aeropuertos.size() > 0){
    //seleccionar aeropuerto de origen
    cout << "Aeropuerto de origen" << endl;
    listAirports();
    do {
      cout << "Ingresa el id del aeropuerto" << endl;
      cin >> airportOrigen_id;
    } while(!existAirport(airportOrigen_id) );
    origen = getAirport(airportOrigen_id);

    //seleccionar aeropuerto de destino
    cout << "Aeropuerto de destino" << endl;
    listAirports();
    do {
      cout << "Ingresa el id del aeropuerto" << endl;
      cin >> airportDestino_id;
    } while(!existAirport(airportDestino_id) || airportOrigen_id == airportDestino_id); //validar que sea un aeropuerto valido y no sea el mismo de origen
    destino = getAirport(airportDestino_id);
  }

  cout << "Cantidad de gasolina" << endl;
  cin >> cantidadGasolina;

  cout << "Tiempo maximo de vuelo" << endl;
  cin >> tiempoMaximo;

  cout << "Precio silla normal" << endl;
  cin >> precioSillaNormal;

  Avion avion(preferencial, normal, bajoCosto, matricula, origen, destino, cantidadGasolina, tiempoMaximo, precioSillaNormal);
  return avion;
}

/* Crea una flota de aviones para una aerolinea*/
void Control::setFlota(){
  int aerolinea_id, totalPlains;
  vector<Avion> flota;

  cout << "Establecer flota de aviones de una aerolinea" << endl;
  cout << "Selecciona la aerolinea" << endl;
  listAerilineas();
  do{
    cout << "Ingresa el id de la aerolinea" << endl;
    cin >> aerolinea_id;
  }while ( !existAerolinea(aerolinea_id) );

  cout << "Total de aviones en la flota" << endl;
  cin >> totalPlains;

  for (int i = 0; i < totalPlains; i++){
    cout << ":::::: Avion "+to_string(i+1)+" de "+to_string(totalPlains) << endl;
    flota.push_back( createPlain() );
  }

  this->aerolineas[getPositionAeroline(aerolinea_id)].setFlota(flota);
}

/*Lista las rutas de una aerolinea
 primero  pide  la  aerolinea  de la que se quiere conocer los vuelos y luego la
 ciudad de origen
*/
int Control::listaDeVuelosDisponibles(int aerolinea_id, Cliente client){
  int city_id;
  int totalDisponibles = 0;
  Aerolinea aerolinea;
  vector<Avion> flota;
  vector<string> cyties;

  cout << "Vuelos disponibles " << endl;

  aerolinea = getAeroline(aerolinea_id);
  flota     = aerolinea.getFlota();

  cyties = aerolinea.getCytiesOrigenFl();

  if (flota.size() > 0) {
    cout << "Elige la ciudad de origen" << endl;
    for(int i = 0; i < cyties.size(); ++i){
      cout << to_string(i+1)+") "+cyties[i] << endl;
    }
    do {
      cout << "Ingresa el id se la ciudad" << endl;
      cin >> city_id;
    } while(city_id < 0 || city_id > cyties.size() );

    //aerolinea.showVuelosDisponibles(cyties[city_id-1]); //con este metodo muestra todos los asientos disponibles, no importa el tipo de cliente que sea
    totalDisponibles = aerolinea.showVuelosDisponibles(cyties[city_id-1], client.getGolden() );
  }
  return totalDisponibles;
}

/**/
void Control::crearClientes()
{
    int cantCli, aerolinea_id, agencia_id;
    string compania;
    time_t date = time(0);
    Telefono phone;
   	struct tm thisDate = *localtime(&date);

    do {
      cout << "Crear clientes para agencia o aerolinea? (agencia, aerolinea)" << endl;
      cin >> compania;
    } while(compania != "agencia" && compania != "aerolinea");

    if(compania == "agencia"){
      listAgencias();
      do {
        cout << "Ingresa el id de la agencia" << endl;
        cin >> agencia_id;
      } while( !existAgencia(agencia_id) );
    }
    else{
      listAerilineas();
      do {
        cout << "ingresa el id de la aerolinea" << endl;
        cin >> aerolinea_id;
      } while( !existAerolinea(aerolinea_id) );
    }

    cout<<"Cuantos clientes desea crear?"<<endl;
    cin>>cantCli;
    for (int i =0;i<cantCli;i++){
        Cliente *client = new Cliente("primerNombre"+to_string(i+1),"segundoNombre"+to_string(i+1),"primerApellido"+to_string(i+1),"segundoApellido"+to_string(i+1),"direccion"+to_string(i+1),"CC",10000+i,phone,thisDate, false);
        if(compania == "agencia"){
          this->agencias[getPositionAgency(agencia_id)].addClient(*client);
        }
        else{
          this->aerolineas[getPositionAeroline(aerolinea_id)].addClient(*client);
        }
    }
}

void Control::administrarAviones(Aerolinea vivaColombia)
{
    int decision;
    Avion newAvion;
    do{
            cout<<"Que deseas hacer?"<<endl;
            cout<<"1.agregar un avion a la flota"<<endl;
            cout<<"2.eliminar un avion de la flota"<<endl;
            cin>>decision;
    }while((decision != 1)&&(decision != 2));
    switch(decision){

    case 1:{

            string placaAvion;
            int cantidadTanque,precioNormal,idAeropuertoOrigen,idAeropuertoDestino,tiempoAire;

            cout<<"Digite la matricula del avion"<<endl;
            cin>>placaAvion;
            newAvion.setMatricula(placaAvion);
            cout<<"Digite la capacidad del tanque de gasolina del avion"<<endl;
            cin>>cantidadTanque;
            newAvion.setCantidadGasolina(cantidadTanque);
            cout<<"Digite el precio las sillas categoria normal"<<endl;
            cin>>precioNormal;
            newAvion.setPrecioSillNormal(precioNormal);
            cout<<"Digite el tiempo de vuelo"<<endl;
            cin>>tiempoAire;
            newAvion.setTiempoMaximo(tiempoAire);
            do{
                    do{
                            cout<<"Digite el id del aeropuerto de origen"<<endl;
                            listAirports();
                            cin>>idAeropuertoOrigen;
                    }while(existAirport(idAeropuertoOrigen) == false);
                    do{
                            cout<<"Digite el id del aeropuerto de Destino"<<endl;
                            listAirports();
                            cin>>idAeropuertoDestino;
                    }while(existAirport(idAeropuertoDestino) == false);
            }while(idAeropuertoDestino == idAeropuertoOrigen);
            newAvion.setAeropuertoOrigen(getAirport(idAeropuertoOrigen));
            newAvion.setAeropuertoDestino(getAirport(idAeropuertoDestino));
            vivaColombia.addAvionToFlota(newAvion);
    };
    break;
    case 2:{
            string matricula;
            bool noEsta = false;
            cout<<"Digita la matricula del avion que quieres eliminar"<<endl;
            cin>>matricula;
            for (int i=0;i<vivaColombia.getFlota().size();i++){
                if(matricula == (vivaColombia.getFlota())[i].getMatricula()){
                        if(vivaColombia.getFlota()[i].getSillasDisponibles() > 0){
                            cout<<"No se puede eliminar el avion por que tiene tiquetes vendidos"<<endl;
                        }else if (vivaColombia.getFlota()[i].getSillasDisponibles() > 0){
                    vivaColombia.getFlota().erase(vivaColombia.getFlota().begin()+i);
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

    }
}
