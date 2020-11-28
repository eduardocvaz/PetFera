#pragma once

#include "animal.hpp"
#include "string"

class Anfibio : public Animal
{
protected:
    int mudas_total;
    string ultima_muda;

public:
    Anfibio(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, int mudas_total, string ultima_muda);
    virtual ~Anfibio();

    void setMudas(int mudas_total);
    int getMudas() const;
    void setUltimaMuda(string ultima_muda);
    string getUltimaMuda() const;

    friend ostream& operator<< (ostream& o, Anfibio& animal);
    virtual ostream& imprimeDados(ostream& o) const;
};






