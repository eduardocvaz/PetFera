#include "mamifero.hpp"
#include "exotico.hpp"

class MamiferoExotico : public Mamifero, public Exotico {
public:
    MamiferoExotico(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,string cor_da_pelagem,string pais_origem);
    ~MamiferoExotico();

    friend ostream& operator<< (ostream& o, MamiferoExotico& animal);
    ostream& imprimeDados(ostream& o) const;
};
