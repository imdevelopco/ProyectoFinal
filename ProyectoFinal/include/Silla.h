#ifndef SILLA_H
#define SILLA_H
#include <iostream>

using namespace std;

class Silla
{
    public:
        Silla();
        Silla(string numero, string tipo,int estado);
        virtual ~Silla();

        /*---------------------------------------*/
        /*                SETERS                 */
        /*---------------------------------------*/
        void setNumber(string num);
        void setType(string tipo);
        void setStatus(int estado);

        /*---------------------------------------*/
        /*                GETERS                 */
        /*---------------------------------------*/
        string getNumber();
        string getType();
        int getStatus();
    protected:

    private:
      string numero;
      string tipo; // opciones ["preferencial", "normal", "bajoCosto"]
      int estado; // 1= ocupada 0 = libre
};

#endif // SILLA_H
