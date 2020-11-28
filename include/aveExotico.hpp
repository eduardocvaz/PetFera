#include "ave.hpp"
#include "exotico.hpp"

class AveExotico : public Ave, public Exotico
{
private:
public:
    AveExotico(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,double tamanho_do_bico,double tamanho_da_envergadura,string pais_origem);
    ~AveExotico();
};