#include "profissional.hpp"

Profissional::Profissional(string nome, string idade, string telefone):
                            nome(nome),
                            idade(idade),
                            telefone(telefone)
                            {}

Profissional::~Profissional(){

    for (auto& animal : this->meus_animais)
    {
        delete animal;
    }
}

string Profissional::getNome() const{
    return this->nome;
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

void Profissional::setIdade(string idade){
    this->idade = idade;
}
void Profissional::setTelefone(string telefone){
    this->telefone = telefone;
}

vector<Animal*> Profissional::getMeusAnimais() const{
    return this->meus_animais;
}

ostream& operator<< (ostream& o, Profissional & p){
    return p.imprimeDados(o);
}