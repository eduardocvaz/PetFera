#include "ave.hpp"
#include "exotico.hpp"

class AveExotico : public Ave, public Exotico {
public:
    AveExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, double tamanho_do_bico,double tamanho_da_envergadura,string pais_origem);
    ~AveExotico();

    friend ostream& operator<< (ostream& o, AveExotico& animal);
    ostream& imprimeDados(ostream& o) const;
};