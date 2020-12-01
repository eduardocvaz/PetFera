#include "anfibioExotico.hpp"
/**
 * @brief Constroi um novo objeto Anfibio Exotico:: Anfibio Exotico
 * 
 * @param nome Nome do animal
 * @param idade Idade do animal
 * @param sexo Sexo do animal
 * @param tamanho Tamanho do animal
 * @param peso Peso do animal
 * @param valor Preço do animal
 * @param veterinario Veterinario responsavel pelo animal
 * @param tratador  Tratador responsavel pelo animal
 * @param tipo_pele Tipo de pele do anfibio
 * @param pais_origem Pais de origem do animal exotico
 */
AnfibioExotico::AnfibioExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, string tipo_pele, string pais_origem):
                Anfibio(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tipo_pele),
                Exotico(pais_origem) {
    setTipo(anfibioExotico);
}
/**
 * @brief Destroi o objeto Anfibio Exotico:: Anfibio Exotico
 * 
 */
AnfibioExotico::~AnfibioExotico() {}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& AnfibioExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}