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
  for(AgenciaDeViaje agencia : this->agencias){ //recorremos las agencias
      //si el id de la agencia es mayor, la establecemos como el id mayor, si no
      //se deja el mismo valor.
      mayor = (agencia.getId() > mayor) ? agencia.getId() : mayor;
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
*/
void Control::listRepresnts(){
  for(int i = 0; i < this->representantes.size(); ++i){
    cout << i+1+") "+ this->representantes[i].getName() << endl;
  }
}

void Control::crearAgencia(){
  string nit, razon, direccion, pagina;
  cout << "::::::::::Crear agencia::::::::::" << endl;
  cout << "Ingresa el NIT:" << endl;
  cin >> nit;
  cout << "Ingresa la razón social:" << endl;
  cin >> razon;
  cout << "Ingresa la dirección" << endl;
  cin >> direccion;
  cout << "Ingresa la pagina web" << endl;
  cin >> pagina;
  cout << "Informacion del representante" << endl;
}
