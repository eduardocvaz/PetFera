#include "reptilNativo.hpp"
/**
 * @brief Constroi um novo objeto Reptil Nativo:: Reptil Nativo
 * 
 * @param nome Nome do reptil nativo
 * @param idade Idade do reptil nativo
 * @param sexo Sexo do reptil nativo
 * @param tamanho Tamanho do reptil nativo
 * @param peso Peso do reptil nativo
 * @param valor Preço do reptil nativo
 * @param veterinario Veterinario responsavel pelo reptil nativo
 * @param tratador Tratador responsavel pelo reptil nativo
 * @param tipo_veneno Tipo de veneno do Réptil nativo
 * @param estado Estado do reptil nativo
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
 * @brief Metodo para imprimir os dados do reptil nativo
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& ReptilNativo::imprimeDados(ostream& o) const{

    //implementar
    return o;
}