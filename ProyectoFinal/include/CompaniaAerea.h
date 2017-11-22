#ifndef COMPANIAAEREA_H
#define COMPANIAAEREA_H


class CompaniaAerea
{
    public:
        CompaniaAerea();
        CompaniaAerea(string nit, string razonSocial, string direccion, string paginaWeb,  vector<Telefono> agenda, Representante representante, vector<Tiquete> transaciones, vector<Cliente> clientesGolden);
        virtual ~CompaniaAerea();

    protected:

    private:
      string nit;
      string razonSocial;
      string direccion;
      string paginaWeb;
      vector<Telefono> agenda;
      Representante representante;
      vector<Tiquete> transaciones;
      vector<Cliente> clientesGolden;
};

#endif // COMPANIAAEREA_H
