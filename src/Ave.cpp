#include "Ave.hpp"

Ave::Ave(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,double tamanho_do_bico,double tamanho_da_invergadura):
                Animal(sexo,tamanho,peso,nome,nome_cientifico,alimentacao,extinto),
                tamanho_do_bico(tamanho_do_bico),
                tamanho_da_invergadura(tamanho_da_invergadura) {}

Ave::~Ave() {}


ostream& Ave::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

