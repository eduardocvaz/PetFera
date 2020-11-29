#include "reptil.hpp"

Reptil::Reptil(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno) :
            Animal(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,reptilDomestico),
            tipo_veneno(tipo_veneno) {}

Reptil::~Reptil() {}

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
