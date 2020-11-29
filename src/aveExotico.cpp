#include "aveExotico.hpp"

AveExotico::AveExotico(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,double tamanho_do_bico,double tamanho_da_envergadura,string pais_origem):
                Ave(nome,idade,sexo,tamanho,peso,valor,extinto,tamanho_do_bico,tamanho_da_envergadura),
                Exotico(pais_origem) {
    setTipo(aveExotico);
}

AveExotico::~AveExotico() {}

ostream& AveExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}