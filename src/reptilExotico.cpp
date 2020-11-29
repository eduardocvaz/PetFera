#include "reptilExotico.hpp"

ReptilExotico::ReptilExotico(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno,string pais_origem):
                Reptil(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador,tipo_veneno),
                Exotico(pais_origem) {
    setTipo(reptilExotico);
}

ReptilExotico::~ReptilExotico() {}

ostream& ReptilExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}