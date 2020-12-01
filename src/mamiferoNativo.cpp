#include "mamiferoNativo.hpp"
/**
 * @brief Constroi um novo objeto Mamifero Nativo:: Mamifero Nativo
 * 
 * @param nome Nome do mamifero nativo
 * @param idade Idade do mamifero nativo
 * @param sexo Sexo do mamifero nativo
 * @param tamanho Tamanho do mamifero nativo
 * @param peso Peso do mamifero nativo
 * @param valor Preço do mamifero nativo
 * @param veterinario Veterinario responsavel pelo mamifero nativo
 * @param tratador Tratador responsavel pelo mamifero nativo
 * @param cor_da_pelagem Cor da pelagem do mamifero nativo
 * @param estado Estado do mamifero nativo
 */
MamiferoNativo::MamiferoNativo(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string cor_da_pelagem,string estado):
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
 * @brief Metodo para imprimir os dados do mamifero nativo
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& MamiferoNativo::imprimeDados(ostream& o) const{

    //implementar
    return o;
}