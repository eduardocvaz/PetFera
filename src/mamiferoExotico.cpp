#include "mamiferoExotico.hpp"

MamiferoExotico::MamiferoExotico(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, string cor_da_pelagem,string pais_origem):
                Mamifero(nome,idade,sexo,tamanho,peso,valor,extinto, cor_da_pelagem),
                Exotico(pais_origem) {
    setTipo(mamiferoExotico);
}

MamiferoExotico::~MamiferoExotico() {}

ostream& MamiferoExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}