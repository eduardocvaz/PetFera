#include "reptil.hpp"
#include "exotico.hpp"

class ReptilExotico : public Reptil, public Exotico {
public:
    ReptilExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno,string pais_origem);
    ~ReptilExotico();

    friend ostream& operator<< (ostream& o, ReptilExotico& animal);
    ostream& imprimeDados(ostream& o) const;
};