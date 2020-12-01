#include "ave.hpp"
/**
 * @brief Constroi um novo objeto Ave:: Ave
 * 
 * @param nome Nome da ave
 * @param idade Idade da ave
 * @param sexo Sexo da ave
 * @param tamanho Tamanho da ave
 * @param peso Peso da ave
 * @param valor Preço da ave
 * @param veterinario Veterinario responsavel pela ave
 * @param tratador Tratador responsavel pela ave
 * @param tamanho_do_bico Tamanho do pico da ave
 * @param tamanho_da_envergadura Envergadura das asas da ave
 */
Ave::Ave(string nome, string idade, string sexo, double tamanho, double peso, double valor, Veterinario* veterinario, Tratador* tratador, double tamanho_do_bico,double tamanho_da_envergadura):
                Animal(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,aveDomestico),
                tamanho_do_bico(tamanho_do_bico),
                tamanho_da_envergadura(tamanho_da_envergadura) {}
/**
 * @brief Destroi o objeto Ave:: Ave
 * 
 */
Ave::~Ave() {}
/**
 * @brief Metodo set para definir o tamanho do bico da ave
 * 
 * @param tamanho_do_bico Define o tamanho do bico da ave
 */
void Ave::setTamanhoBico(double tamanho_do_bico){
    this->tamanho_do_bico = tamanho_do_bico;
}
/**
 * @brief Metodo get para obter o tamanho do bico da ave
 * 
 * @return Retorna o tamanho do bico da ave
 */
double Ave::getTamanhoBico() const{
    return this->tamanho_do_bico;
}
/**
 * @brief Metodo set para definir a envergadura das asas da ave
 * 
 * @param tamanho_da_envergadura Define a envergadura das asas da ave
 */
void Ave::setTamanhoEnvergadura(double tamanho_da_envergadura){
    this->tamanho_da_envergadura = tamanho_da_envergadura;
}
/**
 * @brief Metodo get para obter a envergadura das asas da ave
 * 
 * @return Retorna a envergadura das asas da ave
 */
double Ave::getTamanhoEnvergadura() const{
    return this->tamanho_da_envergadura;
}
/**
 * @brief Metodo para imprimir os dados da ave
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& Ave::imprimeDados(ostream& o) const{
    //corpo

    return o;
}

