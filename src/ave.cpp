#include "ave.hpp"

Ave::Ave(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,double tamanho_do_bico,double tamanho_da_envergadura):
                Animal(nome,idade,sexo,tamanho,peso,valor,aveDomestico,extinto),
                tamanho_do_bico(tamanho_do_bico),
                tamanho_da_envergadura(tamanho_da_envergadura) {}

Ave::~Ave() {}

void Ave::setTamanhoBico(double tamanho_do_bico){
    this->tamanho_do_bico = tamanho_do_bico;
}

double Ave::getTamanhoBico() const{
    return this->tamanho_do_bico;
}

void Ave::setTamanhoEnvergadura(double tamanho_da_envergadura){
    this->tamanho_da_envergadura = tamanho_da_envergadura;
}

double Ave::getTamanhoEnvergadura() const{
    return this->tamanho_da_envergadura;
}

ostream& Ave::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

