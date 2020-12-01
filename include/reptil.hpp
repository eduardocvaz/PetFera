#pragma once

#include "animal.hpp"

class Reptil : public Animal
{
private:
    string tipo_veneno;

public:
    Reptil(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno);
    ~Reptil();

    void setTipoVeneno(string tipo_veneno);
    string getTipoVeneno() const;

    friend ostream& operator<< (ostream& o, Reptil& reptil);
    virtual ostream& imprimeDados(ostream& o) const;
};

