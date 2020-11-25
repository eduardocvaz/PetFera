#include "Profissional.h"

Profissional::Profissional(string nome, string id, string idade, string telefone):
                            nome(nome),
                            id(id),
                            idade(idade),
                            telefone(telefone)
                            {}

Profissional::~Profissional(){}

string Profissional::getNome() const{
    return this->nome;
}

string Profissional::getId() const{
    return this->id;
}
string Profissional::getIdade() const{
    return this->idade;
}
string Profissional::getTelefone() const{
    return this->telefone;
}

void Profissional::setNome(string nome){
    this->nome = nome;
}

void Profissional::setId(string id){
    this->id = id;
}
void Profissional::setIdade(string idade){
    this->idade = idade;
}
void Profissional::setTelefone(string telefone){
    this->telefone = telefone;
}