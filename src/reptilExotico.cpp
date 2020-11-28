#include "reptilExotico.hpp"

ReptilExotico::ReptilExotico(string nome, string idade, bool sexo, double tamanho, double peso, double valor, bool extinto, bool peconheto, string tipo_veneno,string pais_origem):
                Reptil(nome,idade,sexo,tamanho,peso,valor,extinto,peconheto,tipo_veneno),
                Exotico(pais_origem) {}