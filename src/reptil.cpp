#include "reptil.hpp"
#include <iomanip>
#include <iostream>

Reptil::Reptil(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto, bool peconheto, string tipo_veneno) :
            Animal(sexo, tamanho, peso, nome, nome_cientifico, alimentacao, extinto),
            peconhento(peconhento),
            tipo_veneno(tipo_veneno) {}

Reptil::~Reptil() {}

void Reptil::setPeconhento(bool peconhento){
    this->peconhento = peconhento;
}

bool Reptil::getPeconhento() const{
    return this->peconhento;
}

void Reptil::setTipoVeneno(string tipo_veneno){
    this->tipo_veneno = tipo_veneno;
}

string Reptil::getTipoVeneno() const{
    return this->tipo_veneno;
}

ostream &Reptil::imprimeDados(ostream &o) const
{

    return o;
}
