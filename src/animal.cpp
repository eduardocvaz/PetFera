#include "animal.hpp"

Animal::Animal(string nome, string idade, bool sexo, double tamanho, double peso, double valor, tpAnimal tipo, bool extinto):
                nome(nome),
                idade(idade),
                sexo(sexo),
                tamanho(tamanho),
                peso(peso),
                valor(valor),
                tipo(tipo),
                extinto(extinto)
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

void Animal::setSexo(bool sexo){
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

bool Animal::getExtinto() const {
    return this->extinto;
}
void Animal::setExtinto(bool extinto) {
    this->extinto = extinto;
}














