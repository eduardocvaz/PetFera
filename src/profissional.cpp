#include "profissional.hpp"

Profissional::Profissional(string nome, string idade, string telefone, tipoProfissional tipo):
                            nome(nome),
                            idade(idade),
                            telefone(telefone),
                            tipo(tipo)
                            {}

Profissional::~Profissional() {}

string Profissional::getNome() const{
    return this->nome;
}

string Profissional::getIdade() const{
    return this->idade;
}
string Profissional::getTelefone() const{
    return this->telefone;
}

tipoProfissional Profissional::getTipo() const{
    return this->tipo;
}

void Profissional::setNome(string nome){
    this->nome = nome;
}

void Profissional::setIdade(string idade){
    this->idade = idade;
}
void Profissional::setTelefone(string telefone){
    this->telefone = telefone;
}

ostream& operator<< (ostream& o, Profissional& p){
    return p.imprimeDados(o);
}