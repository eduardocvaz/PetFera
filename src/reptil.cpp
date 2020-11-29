#include "reptil.hpp"

Reptil::Reptil(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, bool peconheto, string tipo_veneno) :
            Animal(nome,idade,sexo,tamanho,peso,valor,reptilDomestico,extinto),
            peconhento(peconheto),
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
    //implementar
    return o;
}
