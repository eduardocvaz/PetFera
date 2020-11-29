#include "anfibio.hpp"
#include "exotico.hpp"

class AnfibioExotico : public Anfibio, public Exotico
{
public:
    AnfibioExotico(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, int mudas_total, string ultima_muda, string pais_origem);
    ~AnfibioExotico();

    friend ostream& operator<< (ostream& o, AnfibioExotico& animal);
    ostream& imprimeDados(ostream& o) const;
};