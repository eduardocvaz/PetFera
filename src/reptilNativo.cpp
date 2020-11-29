#include "reptilNativo.hpp"

ReptilNativo::ReptilNativo(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno,string estado):
                Reptil(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador,tipo_veneno),
                Nativo(estado) {
    setTipo(reptilNativo);
}

ReptilNativo::~ReptilNativo() {}

ostream& ReptilNativo::imprimeDados(ostream& o) const{

    //implementar
    return o;
}