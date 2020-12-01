#include "reptilExotico.hpp"
/**
 * @brief Constroi um novo objeto Reptil Exotico:: Reptil Exotico
 * 
 * @param nome Nome do reptil exotico
 * @param idade Idade do reptil exotico
 * @param sexo Sexo do reptil exotico
 * @param tamanho Tamanho do reptil exotico
 * @param peso Peso do reptil exotico
 * @param valor Preço do reptil exotico
 * @param veterinario Veterinario responsavel pelo reptil exotico
 * @param tratador Tratador responsavel pelo reptil exotico
 * @param tipo_veneno Tipo de veneno do Réptil
 * @param pais_origem Pais de origem do reptil exotico
 */
ReptilExotico::ReptilExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_veneno,string pais_origem):
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
 * @brief Metodo para imprimir os dados do reptil exotico
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& ReptilExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}