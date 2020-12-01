#include "mamifero.hpp"
#include "nativo.hpp"

class MamiferoNativo : public Mamifero, public Nativo {
public:
    MamiferoNativo(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem,string estado);
    ~MamiferoNativo();

    friend ostream& operator<< (ostream& o, MamiferoNativo& animal);
    ostream& imprimeDados(ostream& o) const;
};