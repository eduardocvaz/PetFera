#include "nativo.hpp"
/**
 * @brief Constroi um novo objeto Nativo:: Nativo
 * 
 * @param estado Estado do animal
 */
Nativo::Nativo(string estado):
            estado(estado){}
/**
 * @brief Destroi o objeto Nativo:: Nativo
 * 
 */
Nativo::~Nativo() {}
/**
 * @brief Metodo get para obter o estado do animal
 * 
 * @return Retorna o estado do animal
 */
string Nativo::getEstado() const
{
    return this->estado;
}
/**
 * @brief Metodo set para definir o estado do animal
 * 
 * @param estado Define o estado do animal
 */
void Nativo::setEstado(string estado){
    this->estado = estado;
}