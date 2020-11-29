#include "reptilExotico.hpp"
/**
 * @brief Constroi um novo objeto Reptil Exotico:: Reptil Exotico
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
 * @param pais_origem Pais de origem do animal
 */
ReptilExotico::ReptilExotico(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno,string pais_origem):
                Reptil(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador,tipo_veneno),
                Exotico(pais_origem) {
    setTipo(reptilExotico);
}
/**
 * @brief Destroi o objeto Reptil Exotico:: Reptil Exotico
 * 
 */
ReptilExotico::~ReptilExotico() {}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& ReptilExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}