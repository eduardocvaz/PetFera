#pragma once

#include "animal.hpp"
#include "string"

class Reptil : public Animal
{
private:
    bool peconhento;
    string tipo_veneno;

public:
    Reptil(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto,bool peconhento,string tipo_veneno);
    ~Reptil();

    void setPeconhento(bool peconhento);
    bool getPeconhento() const;
    void setTipoVeneno(string tipo_veneno);
    string getTipoVeneno() const;

    friend ostream& operator<< (ostream& o, Reptil& Reptil);

    ostream& imprimeDados(ostream& o) const;
};

