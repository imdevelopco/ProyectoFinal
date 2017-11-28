#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
    public:
        Cliente();
        Cliente(string _nombreCompleto, string _apellidoCompleto, string _direccion, string _tipoDocumento, int _numeroDocumento, Telefono number, tm BornDate);
        virtual ~Cliente();

    protected:

    private:
      string nombreCompleto, apellidoCompleto, direccion;
      string tipoDocumento; // Opciones [CC, CE, PT, TI, RC]
      int numeroDocumento;
      Telefono numero;
      tm fechaNacimiento;
};

#endif // CLIENTE_H
