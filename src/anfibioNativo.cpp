#include "anfibioNativo.hpp"

AnfibioNativo::AnfibioNativo(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, int mudas_total, string ultima_muda,string estado):
                Anfibio(nome,idade,sexo,tamanho,peso,valor,extinto,mudas_total,ultima_muda),
                Nativo(estado) {}