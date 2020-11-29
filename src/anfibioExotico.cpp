#include "anfibioExotico.hpp"

AnfibioExotico::AnfibioExotico(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_pele, string pais_origem):
                Anfibio(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele),
                Exotico(pais_origem) {
    setTipo(anfibioExotico);
}

AnfibioExotico::~AnfibioExotico() {}

ostream& AnfibioExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}