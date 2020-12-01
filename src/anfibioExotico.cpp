#include "anfibioExotico.hpp"
/**
 * @brief Constroi um novo objeto Anfibio Exotico:: Anfibio Exotico
 * 
 * @param nome Nome do anfibio exotico
 * @param idade Idade do anfibio exotico
 * @param sexo Sexo do anfibio exotico
 * @param tamanho Tamanho do anfibio exotico
 * @param peso Peso do anfibio exotico
 * @param valor Preço do anfibio exotico
 * @param veterinario Veterinario responsavel pelo anfibio exotico
 * @param tratador  Tratador responsavel pelo anfibio exotico
 * @param tipo_pele Tipo de pele do anfibio exotico
 * @param pais_origem Pais de origem do anfibio exotico
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
 * @brief Metodo para imprimir os dados do anfibio exotico
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& AnfibioExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}