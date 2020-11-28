#include "reptil.hpp"
#include "nativo.hpp"


class ReptilNativo : public Reptil, public Nativo
{
private:
public:
    ReptilNativo(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,bool peconhento,string tipo_veneno,string estado);
    ~ReptilNativo();
};
