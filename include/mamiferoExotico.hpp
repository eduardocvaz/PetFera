#include "mamifero.hpp"
#include "exotico.hpp"


class MamiferoExotico : public Mamifero, public Exotico
{
private:
public:
    MamiferoExotico(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,string cor_da_pelagem,string pais_origem);
    ~MamiferoExotico();
};
