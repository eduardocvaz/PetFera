#include "Animal.hpp"

//construtor e destrutor
Animal::Animal(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto):
                sexo(sexo),
                tamanho(tamanho),
                peso(peso),
                nome(nome),
                nome_cientifico(nome_cientifico),
                alimentacao(alimentacao),
                extinto(extinto)
                {}

Animal::~Animal() {}

/* Gets & Sets*/
char Animal::getSexo() const{
    return this->sexo;
}

void Animal::setSexo(char sexo){
    this->sexo = sexo;
}

double Animal::getTamanho() const{
    return this->tamanho;
}

void Animal::setTamanho(double tamanho){
    this->tamanho = tamanho;
}

double Animal::getPeso() const{
    return this->peso;
}

void Animal::setPeso(double peso){
    this->peso = peso;
}

string Animal::getNome() const{
    return this->nome;
}

void Animal::setNome(string nome){
    this->nome = nome;
}

string Animal::getNomeCientifico() const{
    return this->nome_cientifico;
}

void Animal::setNomeCientifico(string nome_cientifico){
    this->nome_cientifico = nome_cientifico;
}

string Animal::getAlimentacao() const{
    return this->alimentacao;
}

void Animal::setAlimentacao(string alimentacao){
    this->alimentacao = alimentacao;
}