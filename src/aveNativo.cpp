#include "aveNativo.hpp"

AveNativo::AveNativo(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,double tamanho_do_bico,double tamanho_da_envergadura,string estado):
                Ave(nome,idade,sexo,tamanho,peso,valor,extinto,tamanho_do_bico,tamanho_da_envergadura),
                Nativo(estado) {
    setTipo(aveNativo);
}


AveNativo::~AveNativo() {}

ostream& AveNativo::imprimeDados(ostream& o) const{

    //implementar
    return o;
}