#include "CompaniaAerea.h"

CompaniaAerea::CompaniaAerea()
{
  Telefono telfono;
  Representante representante;
  Cliente cliente;
  this->id             = 0;
  this->nit            = "0";
  this->razonSocial    = "unamed";
  this->direccion      = "calle 0";
  this->paginaWeb      = "www.unamed.com";
  this->agenda.push_back(telfono);
  this->representante  = representante;
}

CompaniaAerea::CompaniaAerea(int id, string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante){
  this->id             = id;
  this->nit            = nit;
  this->razonSocial    = razonSocial;
  this->direccion      = direccion;
  this->paginaWeb      = paginaWeb;
  this->agenda         = agenda;
  this->representante  = representante;
  //this->clientesGolden no se inisializa
}


//sobrecarga de Contructores
CompaniaAerea::CompaniaAerea(int _id,string _nit,string _razonSocial,string _direccion,string _paginaWeb,Representante representante){

}
CompaniaAerea::~CompaniaAerea()
{
    //dtor
}

/* Setters*/
void CompaniaAerea::addTransacion(int id){
  this->transaciones.push_back(id);
}

void CompaniaAerea::addClient(Cliente client){
  this->clientesTotal.push_back(client);
}

void CompaniaAerea::tiketToClient(int tiket_id, int pos_client){
  this->clientesTotal[pos_client].addTiquete(tiket_id);
}

void CompaniaAerea::setClientes(vector<Cliente> clients){
  this->clientesTotal = clients;
}


/* Getters*/
int CompaniaAerea::getId(){
  return id;
}

string CompaniaAerea::getNit()
{
  return nit;
}

string CompaniaAerea::getRazonSocial()
{
    return razonSocial;
}

string CompaniaAerea::getDireccion()
{
    return direccion;
}

string CompaniaAerea::getPaginaWeb()
{
    return paginaWeb;
}

vector<Cliente> CompaniaAerea::getClients(){
  return this->clientesTotal;
}

/*Lista los nombres de los clientes*/
void CompaniaAerea::listClients(){
  for (int i = 0; i < this->clientesTotal.size() ; i++) {
    cout << to_string(i+1)+") "+this->clientesTotal[i].getName()+" "+this->clientesTotal[i].getLastName() << endl;
  }
}

/*Retorna el array de tiquetes, transaciones*/
vector<int> CompaniaAerea::getTransaciones(){
  return this->transaciones;
}

/*Muestra en pantalla los clientes preferenciales*/
void CompaniaAerea::listClientsPreferenciales(){
  for (int i = 0; i < this->clientesTotal.size() ; i++) {
    if( !this->clientesTotal[i].getGolden() ){
      cout << to_string(i+1)+") "+this->clientesTotal[i].getName()+" "+this->clientesTotal[i].getLastName() << endl;
    }
  }
}

/*Retorna true si el indice que se pase por parametro pertenece a un cliente normal*/
bool CompaniaAerea::thisIndexIsOfANormalClient(int index){
  int is = false;
  for (int i = 0; i < this->clientesTotal.size(); i++) {
    if( !this->clientesTotal[i].getGolden() && (i+1) == index ){
      is = true;
    }
  }
  return is;
}
