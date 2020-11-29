#include "mamifero.hpp"
/**
 * @brief Constroi um novo objeto Mamifero:: Mamifero
 * 
 * @param nome Nome do animal
 * @param idade Idade do animal
 * @param sexo Sexo do animal
 * @param tamanho Tamanho do animal
 * @param peso Peso do animal
 * @param valor Preço do animal
 * @param veterinario Veterinario responsavel pelo animal
 * @param tratador Tratador responsavel pelo animal
 * @param cor_da_pelagem Cor da pelagem do mamifero
 */
Mamifero::Mamifero(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem):
                Animal(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,mamiferoDomestico),
                cor_da_pelagem(cor_da_pelagem) {}
/**
 * @brief Destroi o objeto Mamifero:: Mamifero
 * 
 */
Mamifero::~Mamifero() {}
/**
 * @brief Metodo set para definir c
 * 
 * @param cor_da_pelagem Define a cor da pelagem do mimefero
 */
void Mamifero::setCorPelagem(string cor_da_pelagem) {
    this->cor_da_pelagem = cor_da_pelagem;
}
/**
 * @brief Metodo get para obter Metodo get para obter a cor da pelagem do mimefero
 * 
 * @return Retorna a cor da pelagem do mimefero
 */
string Mamifero::getCorPelagem() const{
    return this->cor_da_pelagem;
}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& Mamifero::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

