#include "anfibio.hpp"
#include "nativo.hpp"

class AnfibioNativo : public Anfibio, public Nativo
{
public:
    AnfibioNativo(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_pele,string estado);
    ~AnfibioNativo();

    friend ostream& operator<< (ostream& o, AnfibioNativo& animal);
    ostream& imprimeDados(ostream& o) const;
};