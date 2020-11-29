#include "reptil.hpp"
#include "nativo.hpp"


class ReptilNativo : public Reptil, public Nativo {
public:
    ReptilNativo(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,bool peconhento,string tipo_veneno,string estado);
    ~ReptilNativo();

    friend ostream& operator<< (ostream& o, ReptilNativo& animal);
    ostream& imprimeDados(ostream& o) const;
};
