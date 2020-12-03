#include "animal.hpp"
/**
 * @brief Constrói um novo objeto do tipo Animal
 * 
 * @param nome Nome do animal
 * @param idade Idade do animal
 * @param sexo Sexo do animal
 * @param tamanho Tamanho do animal
 * @param peso Peso do animal
 * @param valor Preço do animal
 * @param veterinario Veterinario responsavel pelo animal
 * @param tratador  Tratador responsavel pelo animal
 * @param tipo Espécie do animal
 */
Animal::Animal(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, tpAnimal tipo):
                nome(nome),
                idade(idade),
                sexo(sexo),
                tamanho(tamanho),
                peso(peso),
                valor(valor),
                veterinario(veterinario),
                tratador(tratador),
                tipo_animal(tipo)
                {}
/**
 * @brief Destrói o objeto Animal
 * 
 */
Animal::~Animal() {}
/**
 * @brief Operador para imprimir dados do animal
 * 
 * @param o Variável para guardar impressão
 * @param animal Objeto do tipo Animal
 */
ostream& operator<< (ostream& o, Animal& animal) {
    return animal.imprimeDados(o);
}
/**
 * @brief Método get para obter o nome do animal
 * 
 * @return Retorna o nome do animal
 */
string Animal::getNome() const{
    return this->nome;
}
/**
 * @brief Metodo set para definir nome do animal
 * 
 * @param nome Define o nome do animal
 */
void Animal::setNome(string nome){
    this->nome = nome;
}
/**
 * @brief Método get para obter a idade do animal
 * 
 * @return Retorna a idade do animal
 */
string Animal::getIdade() const{
    return this->idade;
}
/**
 * @brief Método set para definir a idade do animal
 * 
 * @param nome Define a idade do animal
 */
void Animal::setIdade(string idade){
    this->idade = idade;
}
/**
 * @brief Método get para obter o sexo do animal
 * 
 * @return Macho ou Fêmea
 */
string Animal::getSexo() const{
    return this->sexo;
}
/**
 * @brief Método set para definir o sexo do animal
 * 
 * @param sexo  Define o sexo do animal
 */
void Animal::setSexo(string sexo){
    this->sexo = sexo;
}
/**
 * @brief Metodo get para obter o tamanho do animal
 * 
 * @return Retorna o tamanho do animal
 */
double Animal::getTamanho() const{
    return this->tamanho;
}
/**
 * @brief Metodo set para definir o tamanho do animal
 * 
 * @param tamanho Define o tamanho do animal
 */
void Animal::setTamanho(double tamanho){
    this->tamanho = tamanho;
}
/**
 * @brief Metodo get para obter o peso do animal
 * 
 * @return Retorna o peso do animal
 */
double Animal::getPeso() const{
    return this->peso;
}/**
 * @brief Metodo set para definir o peso do animal
 * 
 * @param peso Define o peso do animal
 */

void Animal::setPeso(double peso) {
    this->peso = peso;
}
/**
 * @brief Metodo get para obter o preço do animal
 * 
 * @return Retorno o preço do animal
 */
double Animal::getValor() const {
    return this->valor;
}
/**
 * @brief Metodo set para definir o preço do animal
 * 
 * @param valor Define o preço do animal
 */
void Animal::setValor(double valor) {
    this->valor = valor;
}
/**
 * @brief Metodo get para obter a espécie do animal
 * 
 * @return Retorna a espécie do animal
 */
tpAnimal Animal::getTipo() const {
    return this->tipo_animal;
}
/**
 * @brief Metodo set para definir a espécie do animal
 * 
 * @param tipo Define a espécie do animal
 */
void Animal::setTipo(tpAnimal tipo){
    this->tipo_animal = tipo;
}
/**
 * @brief Metodo get para obter o veterinario responsavel pelo animal
 * 
 * @return Retorna o veterinario responsavel pelo animal
 */
Veterinario* Animal::getVeterinario() const{
    return this->veterinario;
}
/**
 * @brief Metodo set para definir o veterinario responsavel pelo animal
 * 
 * @param veterinario Objeto do tipo Veterinário
 */
void Animal::setVeterinario(Veterinario* veterinario){
    this->veterinario = veterinario;
}
/**
 * @brief Metodo get para obter o tratador responsavel pelo animal
 * 
 * @return Retorna o tratador responsável pelo animal
 */
Tratador* Animal::getTratador() const{
    return this->tratador;
}
/**
 * @brief Metodo set para definir o tratador responsavel pelo animal
 * 
 * @param tratador Objeto do tipo Tratador
 */
void Animal::setTratador(Tratador* tratador){
    this->tratador = tratador;
}












