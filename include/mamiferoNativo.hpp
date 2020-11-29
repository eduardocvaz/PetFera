#include "mamifero.hpp"
#include "nativo.hpp"

class MamiferoNativo : public Mamifero, public Nativo
{
private:
public:
    MamiferoNativo(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,string cor_da_pelagem,string estado);
    ~MamiferoNativo();

    friend ostream& operator<< (ostream& o, MamiferoNativo& animal);
    ostream& imprimeDados(ostream& o) const;
};