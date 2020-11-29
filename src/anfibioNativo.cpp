#include "anfibioNativo.hpp"

AnfibioNativo::AnfibioNativo(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_pele, string estado):
                Anfibio(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele),
                Nativo(estado) {
    setTipo(anfibioNativo);
}

AnfibioNativo::~AnfibioNativo() {}

ostream& AnfibioNativo::imprimeDados(ostream& o) const{

    //implementar
    return o;
}