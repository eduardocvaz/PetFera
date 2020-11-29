#include "mamiferoExotico.hpp"

MamiferoExotico::MamiferoExotico(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem,string pais_origem):
                Mamifero(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador, cor_da_pelagem),
                Exotico(pais_origem) {
    setTipo(mamiferoExotico);
}

MamiferoExotico::~MamiferoExotico() {}

ostream& MamiferoExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}