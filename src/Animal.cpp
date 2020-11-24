#include <iostream>
#include "Animal.hpp"

/* Gets e Sets*/

char Animal::get_sexo()
{
    return this->sexo;
}
void Animal::set_sexo(char sexo)
{
    this->sexo = sexo;
}

double Animal::get_tamanho()
{
    return this->tamanho;
}
void Animal::set_tamanho(double tamanho)
{
    this->tamanho = tamanho;
}
string Animal::get_nome()
{
    return this->nome;
}
void Animal::set_nome(string nome)
{
    this->nome = nome;
}
string Animal::get_nome_cientifico()
{
    return this->nome_cientifico;
}
void Animal::set_nome_cientifico(string nome_cientifico)
{
    this->nome_cientifico = nome_cientifico;
}
string Animal::get_alimentacao()
{
    return this->alimentacao;
}
void Animal::set_alimentacao(string alimentacao)
{
    this->alimentacao = alimentacao;
}