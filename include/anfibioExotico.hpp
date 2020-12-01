#include "anfibio.hpp"
#include "exotico.hpp"

class AnfibioExotico : public Anfibio, public Exotico
{
public:
    AnfibioExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_pele, string pais_origem);
    ~AnfibioExotico();

    friend ostream& operator<< (ostream& o, AnfibioExotico& animal);
    ostream& imprimeDados(ostream& o) const;
};