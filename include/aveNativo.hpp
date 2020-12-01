#include "ave.hpp"
#include "nativo.hpp"

class AveNativo : public Ave, public Nativo {
public:
    AveNativo(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, double tamanho_do_bico,double tamanho_da_envergadura,string estado);
    ~AveNativo();

    friend ostream& operator<< (ostream& o, AveNativo& animal);
    ostream& imprimeDados(ostream& o) const;
};