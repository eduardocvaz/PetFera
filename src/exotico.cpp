#include "exotico.hpp"
/**
 * @brief Constroi um novo objeto Exotico:: Exotico
 * 
 * @param pais_origem  Pais  de origem do animal
 */
Exotico::Exotico(string pais_origem):
            pais_origem(pais_origem){}
/**
 * @brief Destroi o objeto Exotico:: Exotico
 * 
 */
Exotico::~Exotico() {}
/**
 * @brief Metodo get para obter o pais de origem do animal
 * 
 * @return Retorna o pais de origem
 */
string Exotico::getPais_origem() const
{
    return this->pais_origem;
}
/**
 * @brief Metodo set para definir o pais de origem do animal
 * 
 * @param pais_origem Define o pais de origem de uma animal
 */
void Exotico::setPais_origem(string pais_origem){
    this->pais_origem = pais_origem;
}