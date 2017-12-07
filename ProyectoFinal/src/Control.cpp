#include "Control.h"
#include <iostream>
#include <string>

Control::Control()
{
    //ctor
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
    cout << i+1+") "+ this->representantes[i].getName() << endl;
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
  cout << this->aerolineas.size() << endl;
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
  // (id,nit,razonSocial,direccion,paginaWeb agenda, representante)
  AgenciaDeViaje agencia( getLastAgencyId() , nit, razon, direccion, pagina, telefono, representante);
  this->agencias.push_back(agencia);
}

/*Pide información al usuario por consola para crear un  aeropuerto, por  ultimo
  retorna el aeropuerto creado.
  createAirport() -> Aeropuerto;
*/
Aeropuerto Control::createAirport(){
  string nombre, abreviatura;
  int totalAvionesOperacion, volumenMaximoPersonas;

  cout << "::::::::::Crear Aeropuerto::::::::::" << endl;
  cout << "Nombre del aeropuerto" << endl ;
  cin >> nombre;
  cout << "abreviatura" << endl;
  cin >> abreviatura;
  cout << "Total aviones en operacion" << endl;
  cin >> totalAvionesOperacion;
  cout << "volumen maximo de personas" << endl;
  cin >> volumenMaximoPersonas;

  Aeropuerto aeropuerto(getLatsAirportId(),nombre, abreviatura, totalAvionesOperacion, volumenMaximoPersonas);
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
  vector<int> aeropuertos;

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
  cout << "Total flota de aviones" << endl;
  cin >> totalFlota;

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

  //aeropuertos a los que puede viajar
  if(this->aeropuertos.size() > 0){ //si hay aeropuertos, preguntamos a usuario si quiere crear o elegir
    do{
      cout << "Crear o elegir un aeropuertos a los que puede viajar la aerolinea (crear,elegir)" << endl;
      cin >> chooseAirport;
    }while(chooseAirport != "crear" && chooseAirport != "elegir");
  }
  else{ //si no hay aeropuertos, pasamos a crear
    cout << "Crear aeropuerto al que puede viajar la aerolinea" << endl;
    chooseAirport = "crear";
  }

  if(chooseAirport == "crear"){
    do {
      aeropuertos.push_back( createAirport().getId() );
      do{
        cout << "¿Quieres crear otro aeropuerto al que se puede viajar desde esta aerolinea? (s,n)" << endl;
        cin >> continueCreate;
      } while(continueCreate != 's' && continueCreate != 'n'); //validar que ingrese una opción correcta
    } while(continueCreate == 's');
  }
  else{ //si selecciono elegir
    do {
      int elegido;
      listAirports();
      do {
        cout << "Selecciona un aeropuerto" << endl;
        cin >> elegido;
      } while(!existAirport(elegido)); //verificar que el id que ingreso si pertenece a un aeropuerto

      if(aeropuertos.size() == 0){ //si no hay aeropuertos aún agregamos el aeropuerto seleccionado
          aeropuertos.push_back( elegido ); //se agrega el aeropuerto elegido al vector de aeropuertos al que puede viajar la aerolinea
      }
      else{ //si ya hay aeropuertos entonces verificamos si el aeropuerto ya fue agregado
        bool exist = false;
        for(int i = 0; i < aeropuertos.size(); ++i){ //recorremos los aeropuestos que se han agregado
          if(aeropuertos[i] == elegido){ //si ya existe, seteamos la variable existe como true (si existe)
            exist = true;
          }
        }

        if(!exist){ //si no existe el aeropuerto seleccionado en el vector de aeropuertos lo agregamos
          aeropuertos.push_back( elegido ); //se agrega el aeropuerto elegido al vector de aeropuertos al que puede viajar la aerolinea
        }
      }

      //preguntar al usuario si quiere agregar más aeropuertos
      do {
        cout << "¿Quieres agregar otro aeropuerto? (s,n)" << endl;
        cin >> continueChoose;
      } while(continueChoose != 's' && continueChoose != 'n'); //validar que ingrese una opcion correcta
    } while(continueChoose == 's');

  }

  Aerolinea aerolinea(getLastAerolineaId(), nit, razon, direccion, pagina, telefono, representante, matricula, totalFlota, aeropuertos);
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

/*Se le pasa un id de un aeropuerto y este metodo retorna dicho Aeropuerto*/
Aeropuerto Control::getAirport(int id){
  for (int i = 0; i < this->aeropuertos.size(); i++) {
    if(id == this->aeropuertos[i].getId()){
      return this->aeropuertos[i];
    }
  }
}
