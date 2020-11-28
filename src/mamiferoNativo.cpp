#include "mamiferoNativo.hpp"

MamiferoNativo::MamiferoNativo(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, string cor_da_pelagem,string estado):
                Mamifero(nome,idade,sexo,tamanho,peso,valor,extinto, cor_da_pelagem),
                Nativo(estado) {}