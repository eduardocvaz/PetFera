#include "mamiferoNativo.hpp"
/**
 * @brief Constroi um novo objeto Mamifero Nativo:: Mamifero Nativo
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
 * @param estado Estado do animal
 */
MamiferoNativo::MamiferoNativo(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem,string estado):
                Mamifero(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador, cor_da_pelagem),
                Nativo(estado) {
    setTipo(mamiferoNativo);
}
/**
 * @brief Destroi o objeto Mamifero Nativo:: Mamifero Nativo
 * 
 */
MamiferoNativo::~MamiferoNativo() {}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& MamiferoNativo::imprimeDados(ostream& o) const{

    //implementar
    return o;
}