#include "aveExotico.hpp"
/**
 * @brief Constroi um novo objeto Ave Exotico:: Ave Exotico
 * 
 * @param nome Nome da ave exotica
 * @param idade Idade da ave exotica
 * @param sexo Sexo da ave exotica
 * @param tamanho Tamanho da ave exotica
 * @param peso Peso da ave exotica
 * @param valor Preço da ave exotica
 * @param veterinario Veterinario responsavel pela ave exotica
 * @param tratador Tratador responsavel pela ave exotica
 * @param tamanho_do_bico Tamanho do pico da ave exotica
 * @param tamanho_da_envergadura Envergadura das asas da ave exotica
 * @param pais_origem Pais de origem da ave exotica
 */
AveExotico::AveExotico(string nome, string idade, string sexo, double tamanho, double peso, double valor,Veterinario* veterinario, Tratador* tratador,double tamanho_do_bico,double tamanho_da_envergadura,string pais_origem):
                Ave(nome,idade,sexo,tamanho,peso,valor,veterinario,tratador,tamanho_do_bico,tamanho_da_envergadura),
                Exotico(pais_origem) {
    setTipo(aveExotico);
}
/**
 * @brief Destroi o objeto Ave Exotico:: Ave Exotico
 * 
 */
AveExotico::~AveExotico() {}
/**
 * @brief Metodo para imprimir os dados da ave exotica
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& AveExotico::imprimeDados(ostream& o) const{

    //implementar
    return o;
}