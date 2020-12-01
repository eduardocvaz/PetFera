#pragma once

#include "animal.hpp"

class Anfibio : public Animal
{
protected:
    string tipo_pele;

public:
    Anfibio(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_pele);
    virtual ~Anfibio();

    void setTipoPele(string tipo_pele);
    string getTipoPele() const;

    friend ostream& operator<< (ostream& o, Anfibio& animal);
    virtual ostream& imprimeDados(ostream& o) const;
};






