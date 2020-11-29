#include "tratador.hpp"
/**
 * @brief Constroi um novo objeto Tratador:: Tratador
 * 
 * @param nome Nome do tratador
 * @param idade Idade do tratador
 * @param telefone Numero para contato do tratador
 * @param nivel Nivel de segurança que o tratador tem
 */
Tratador::Tratador(string nome, string idade, string telefone, nivelSeguranca nivel):
                    Profissional(nome, idade, telefone, tipoTratador),
                    nivel(nivel) {}
/**
 * @brief Destroi o objeto Tratador:: Tratador
 * 
 */
Tratador::~Tratador() {}
/**
 * @brief Metodo set para definir o nivel de seguranção que o tratador tem
 * 
 * @param nivel Define o nivel de seguranção que o tratador tem
 */
void Tratador::setNivel(nivelSeguranca nivel){
    this->nivel = nivel;
}
/**
 * @brief Metodo set para definir o nivel de seguranção que o tratador tem
 * 
 * @return Retorna o nivel de seguranção que o tratador tem
 */
nivelSeguranca Tratador::getNivel() const{
    return this->nivel;
}
/**
 * @brief Metodo para imprimir os dados do animal
 * 
 * @param o Varivel para guardar impressão
 * @return Retorna a impressão
 */
ostream& Tratador::imprimeDados(ostream& o) const{
    //implementar
    return o;
}