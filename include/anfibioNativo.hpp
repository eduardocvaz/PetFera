#include "anfibio.hpp"
#include "nativo.hpp"



class AnfibioNativo : public Anfibio, public Nativo
{
public:
    AnfibioNativo(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, int mudas_total, string ultima_muda,string estado);
    ~AnfibioNativo();
};