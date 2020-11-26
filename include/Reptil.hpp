#pragma once

#include "Animal.hpp"
#include "string"

class Reptil : public Animal
{
private:
    bool peconhento;
    string tipo_veneno;

public:
    Reptil(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,bool peconhento,string tipo_veneno);
    ~Reptil();

    void setPeconhento(bool peconhento);
    bool getPeconhento() const;
    void setTipoVeneno(string tipo_veneno);
    string getTipoVeneno() const;

    friend ostream& operator<< (ostream& o, Reptil& Reptil);

    ostream& imprimeDados(ostream& o) const;
};

