#include "profissional.hpp"


/**
 * @brief Constroi um novo objeto Profissional:: Profissional
 * 
 * @param nome Nome do profissional
 * @param idade Idade do profissional
 * @param telefone Numero de contato do profissional
 * @param tipo Tipo de profissional(veterinario ou tratador)
 */
Profissional::Profissional(string nome, string idade, string telefone, tipoProfissional tipo):
                            nome(nome),
                            idade(idade),
                            telefone(telefone),
                            tipo_profissional(tipo)
                            {}
/**
 * @brief Destroi o objeto Profissional:: Profissional
 * 
 */
Profissional::~Profissional() {}
/**
 * @brief Metodo get para obter o nome do profissional
 * 
 * @return Retorna o nome do profissional
 */
string Profissional::getNome() const{
    return this->nome;
}
/**
 * @brief Metodo get para obter a idade do profissional
 * 
 * @return Retorna a idade do profissional 
 */
string Profissional::getIdade() const{
    return this->idade;
}
/**
 * @brief Metodo get para obter o telefone do profissional
 * 
 * @return Retorna o telefone do profissional  
 */
string Profissional::getTelefone() const{
    return this->telefone;
}
/**
 * @brief Metodo get para obter o tipo do profissional
 * 
 * @return Retorna o tipo do profissional 
 */
tipoProfissional Profissional::getTipo() const{
    return this->tipo_profissional;
}
/**
 * @brief Metodo set para definir o nome do profissional
 * 
 * @param nome Define o nome do profissional
 */
void Profissional::setNome(string nome){
    this->nome = nome;
}
/**
 * @brief Metodo set para definir a idade do profissional
 * 
 * @param idade Define a idade do profissional
 */
void Profissional::setIdade(string idade){
    this->idade = idade;
}
/**
 * @brief Metodo set para definir o telefone do profissional
 * 
 * @param telefone Define o telefone do profissional
 */
void Profissional::setTelefone(string telefone){
    this->telefone = telefone;
}

/**
 * @brief
 *
 * @param
 */
void Profissional::setTipo(tipoProfissional tipo){
    this->tipo_profissional = tipo;
}

/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& operator<< (ostream& o, Profissional& p){

    return p.imprimeDados(o);
}