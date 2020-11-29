#include "ave.hpp"
#include "nativo.hpp"

class AveNativo : public Ave, public Nativo
{
private:
public:
    AveNativo(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,double tamanho_do_bico,double tamanho_da_envergadura,string estado);
    ~AveNativo();

    friend ostream& operator<< (ostream& o, AveNativo& animal);
    ostream& imprimeDados(ostream& o) const;
};