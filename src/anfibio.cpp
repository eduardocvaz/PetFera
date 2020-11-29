#include "anfibio.hpp"
/**
 * @brief Constroi um novo objeto Anfibio:: Anfibio
 * 
 * @param nome Nome do animal
 * @param idade Idade do animal
 * @param sexo Sexo do animal
 * @param tamanho Tamanho do animal
 * @param peso Peso do animal
 * @param valor Preço do animal
 * @param veterinario Veterinario responsavel pelo animal
 * @param tratador Tratador responsavel pelo animal
 * @param tipo_pele Tipo de pele do anfibio
 */
Anfibio::Anfibio(string nome, string idade, char sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador,string tipo_pele):
        Animal(nome,idade,sexo,tamanho,peso,valor, veterinario, tratador, anfibioDomestico),
                tipo_pele(tipo_pele) {}
/**
 * @brief Destroi o objeto Anfibio:: Anfibio
 * 
 */
Anfibio::~Anfibio() {}
/**
 * @brief Metodo set para definir o tipo de pele do anfibio
 * 
 * @param tipo_pele Define o tipo de pele do anfibio
 */
void Anfibio::setTipoPele(string tipo_pele){
    this->tipo_pele = tipo_pele;
}
/**
 * @brief Metodo get para obter o tipo de pele do anfibio
 * 
 * @return retorna o tipo de pele do animal
 */
string Anfibio::getTipoPele() const{
    return this->tipo_pele;
}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& Anfibio::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

