#include "Animal.hpp"

//construtor e destrutor
Animal::Animal(char sexo, double tamanho, double peso, string nome, string nome_cientifico, string alimentacao, bool extinto, Tratador& tratador, Veterinario& veterinario):
                sexo(sexo),
                tamanho(tamanho),
                peso(peso),
                nome(nome),
                nome_cientifico(nome_cientifico),
                alimentacao(alimentacao),
                extinto(extinto),
                tratador(tratador),
                veterinario(veterinario)
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

bool Animal::getExtinto() const{
    return this->extinto;
}
void Animal::setExtinto(bool extinto){
    this->extinto = extinto;
}

Tratador& Animal::getTratador() const{
    return this->tratador;
}

void Animal::setTratador(Tratador& tratador){
    this->tratador = tratador;
}

Veterinario& Animal::getVeterinario() const{
    return this->veterinario;
}
void Animal::setVeterinario(Veterinario& veterinario){
    this->veterinario = veterinario;
}













