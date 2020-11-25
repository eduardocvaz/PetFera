#pragma once

#include "date.hpp"
#include "Animal.hpp"

class Anfibio : public Animal //usar public pra ter acesso externo
{
protected:
    int mudas_total;
    date ultima_muda;

public:
    Anfibio(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao,int mudas_total,date ultima_muda);
    ~Anfibio();

    friend ostream& operator<< (ostream& o, Anfibio& anfibio);

    ostream& imprimeDados(ostream& o) const; // implementar de acordo com os atributos próprios
};

