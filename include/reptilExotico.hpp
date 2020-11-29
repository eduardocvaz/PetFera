#include "reptil.hpp"
#include "exotico.hpp"

class ReptilExotico : public Reptil, public Exotico
{
private:
public:
    ReptilExotico(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,bool peconhento,string tipo_veneno,string pais_origem);
    ~ReptilExotico();

    friend ostream& operator<< (ostream& o, ReptilExotico& animal);
    ostream& imprimeDados(ostream& o) const;
};