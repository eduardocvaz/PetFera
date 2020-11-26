#include "Reptil.hpp"
#include <iomanip>
#include <iostream>

Reptil::Reptil(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto,Tratador& tratador, Veterinario& veterinario, bool peconheto, string tipo_veneno) : 
            Animal(sexo, tamanho, peso, nome, nome_cientifico, alimentacao, extinto,tratador,veterinario),
            peconheto(peconheto), 
            tipo_veneno(tipo_veneno) {}

Reptil::~Reptil() {}

ostream &Reptil::imprimeDados(ostream &o) const
{

    return o;
}
