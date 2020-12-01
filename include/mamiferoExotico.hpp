#include "mamifero.hpp"
#include "exotico.hpp"

class MamiferoExotico : public Mamifero, public Exotico {
public:
    MamiferoExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem,string pais_origem);
    ~MamiferoExotico();

    friend ostream& operator<< (ostream& o, MamiferoExotico& animal);
    ostream& imprimeDados(ostream& o) const;
};
