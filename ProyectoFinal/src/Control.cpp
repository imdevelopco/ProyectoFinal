#include "Control.h"

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

/*Pide información al usuario para crear una agencia, no retorna nada,  solo  la
 almacena en el atributo (variable de clase) this->agencias
 crearAgencia() -> void
*/
void Control::crearAgencia(){
  string nit, razon, direccion, pagina, choose;
  int representante_id;
  Representante representante;
  cout << "::::::::::Crear agencia::::::::::" << endl;
  cout << "Ingresa el NIT:" << endl;
  cin >> nit;
  cout << "Ingresa la razon social:" << endl;
  cin >> razon;
  cout << "Ingresa la direccion" << endl;
  cin >> direccion;
  cout << "Ingresa la pagina web" << endl;
  cin >> pagina;

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

  AgenciaDeViaje agencia( getLastAgencyId() , nit, razon, direccion, pagina, representante);
  this->agencias.push_back(agencia);
}

/*Lita en pantalla las agencias existentes en this->agencias,  no retorna  nada
  sirve para ver cuales son las agencias existente
*/
void Control::listAgencias(){
  /*for(AgenciaDeViaje agencia : this->agencias){
    cout << agencia.getId()+") "+agencia.getRazonSocial() << endl;
  }*/
cout << this->agencias.size() << endl;
  for(int i = 0; i < this->agencias.size(); ++i){
    /*
    ███████╗███████╗████████╗ ██████╗     ███╗   ██╗ ██████╗     ███████╗███████╗    ███████╗███████╗████████╗ █████╗     ██╗   ██╗██╗███████╗███╗   ██╗██████╗  ██████╗
    ██╔════╝██╔════╝╚══██╔══╝██╔═══██╗    ████╗  ██║██╔═══██╗    ██╔════╝██╔════╝    ██╔════╝██╔════╝╚══██╔══╝██╔══██╗    ██║   ██║██║██╔════╝████╗  ██║██╔══██╗██╔═══██╗
    █████╗  ███████╗   ██║   ██║   ██║    ██╔██╗ ██║██║   ██║    ███████╗█████╗      █████╗  ███████╗   ██║   ███████║    ██║   ██║██║█████╗  ██╔██╗ ██║██║  ██║██║   ██║
    ██╔══╝  ╚════██║   ██║   ██║   ██║    ██║╚██╗██║██║   ██║    ╚════██║██╔══╝      ██╔══╝  ╚════██║   ██║   ██╔══██║    ╚██╗ ██╔╝██║██╔══╝  ██║╚██╗██║██║  ██║██║   ██║
    ███████╗███████║   ██║   ╚██████╔╝    ██║ ╚████║╚██████╔╝    ███████║███████╗    ███████╗███████║   ██║   ██║  ██║     ╚████╔╝ ██║███████╗██║ ╚████║██████╔╝╚██████╔╝
    ╚══════╝╚══════╝   ╚═╝    ╚═════╝     ╚═╝  ╚═══╝ ╚═════╝     ╚══════╝╚══════╝    ╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝      ╚═══╝  ╚═╝╚══════╝╚═╝  ╚═══╝╚═════╝  ╚═════╝
*/
    cout << this->agencias[i].getId()+") "+this->agencias[i].getRazonSocial() << endl;
  }
}