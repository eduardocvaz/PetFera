#include "reptilNativo.hpp"
/**
 * @brief Constroi um novo objeto Reptil Nativo:: Reptil Nativo
 * 
 * @param nome Nome do animal
 * @param idade Idade do animal
 * @param sexo Sexo do animal
 * @param tamanho Tamanho do animal
 * @param peso Peso do animal
 * @param valor Preço do animal
 * @param veterinario Veterinario responsavel pelo animal
 * @param tratador Tratador responsavel pelo animal
 * @param tipo_veneno Tipo de veneno do Réptil
 * @param estado Estado do animal
 */
ReptilNativo::ReptilNativo(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno,string estado):
                Reptil(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador,tipo_veneno),
                Nativo(estado) {
    setTipo(reptilNativo);
}
/**
 * @brief Destroi o objeto Reptil Nativo:: Reptil Nativo
 * 
 */
ReptilNativo::~ReptilNativo() {}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& ReptilNativo::imprimeDados(ostream& o) const{

    //implementar
    return o;
}