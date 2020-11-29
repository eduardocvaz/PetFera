#include "reptilNativo.hpp"

ReptilNativo::ReptilNativo(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, bool peconheto, string tipo_veneno,string estado):
                Reptil(nome,idade,sexo,tamanho,peso,valor,extinto,peconheto,tipo_veneno),
                Nativo(estado) {
    setTipo(reptilNativo);
}

ReptilNativo::~ReptilNativo() {}

ostream& ReptilNativo::imprimeDados(ostream& o) const{

    //implementar
    return o;
}