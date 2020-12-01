#include "reptil.hpp"
#include "nativo.hpp"


class ReptilNativo : public Reptil, public Nativo {
public:
    ReptilNativo(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador,string tipo_veneno,string estado);
    ~ReptilNativo();

    friend ostream& operator<< (ostream& o, ReptilNativo& animal);
    ostream& imprimeDados(ostream& o) const;
};
