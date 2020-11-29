#include "animal.hpp"

Animal::Animal(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, tpAnimal tipo):
                nome(nome),
                idade(idade),
                sexo(sexo),
                tamanho(tamanho),
                peso(peso),
                valor(valor),
                veterinario(veterinario),
                tratador(tratador),
                tipo(tipo)
                {}

Animal::~Animal() {}

ostream& operator<< (ostream& o, Animal& animal) {
    return animal.imprimeDados(o);
}

string Animal::getNome() const{
    return this->nome;
}

void Animal::setNome(string nome){
    this->nome = nome;
}

string Animal::getIdade() const{
    return this->idade;
}

void Animal::setIdade(string idade){
    this->idade = idade;
}

bool Animal::getSexo() const{
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

void Animal::setPeso(double peso) {
    this->peso = peso;
}

double Animal::getValor() const {
    return this->valor;
}

void Animal::setValor(double valor) {
    this->valor = valor;
}

tpAnimal Animal::getTipo() const {
    return this->tipo;
}

void Animal::setTipo(tpAnimal tipo){
    this->tipo = tipo;
}

Veterinario* Animal::getVeterinario() const{
    return this->veterinario;
}

void Animal::setVeterinario(Veterinario* veterinario){
    this->veterinario = veterinario;
}

Tratador* Animal::getTratador() const{
    return this->tratador;
}

void Animal::setTratador(Tratador* tratador){
    this->tratador = tratador;
}












