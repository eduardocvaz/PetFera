#include "anfibioExotico.hpp"

AnfibioExotico::AnfibioExotico(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, int mudas_total, string ultima_muda,string pais_origem):
                Anfibio(nome,idade,sexo,tamanho,peso,valor,extinto,mudas_total,ultima_muda),
                Exotico(pais_origem) {
    setTipo(anfibioExotico);
}

AnfibioExotico::~AnfibioExotico() {}

ostream& AnfibioExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}