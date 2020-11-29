#pragma once

#include <string>

using std::string;

class Nativo
{
private:
    string estado;
public:
    Nativo(string estado);
    ~Nativo();

    string getEstado() const;
    void setEstado(string estado);
};



