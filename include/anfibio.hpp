#pragma once

#include "animal.hpp"
#include "string"

class Anfibio : public Animal //usar public pra ter acesso externo
{
protected:
    int mudas_total;
    string ultima_muda;

public:
    Anfibio(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto, int mudas_total, string ultima_muda);
    virtual ~Anfibio();

    void setMudas(int mudas_total);
    int getMudas() const;
    void setUltimaMuda(string ultima_muda);
    string getUltimaMuda() const;

    friend ostream& operator<< (ostream& o, Anfibio& anfibio);

    ostream& imprimeDados(ostream& o) const; // implementar de acordo com os atributos próprios
};






