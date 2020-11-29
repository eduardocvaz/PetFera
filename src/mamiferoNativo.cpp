#include "mamiferoNativo.hpp"

MamiferoNativo::MamiferoNativo(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem,string estado):
                Mamifero(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador, cor_da_pelagem),
                Nativo(estado) {
    setTipo(mamiferoNativo);
}

MamiferoNativo::~MamiferoNativo() {}

ostream& MamiferoNativo::imprimeDados(ostream& o) const{

    //implementar
    return o;
}