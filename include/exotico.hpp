#pragma once

#include <string>

using std::string;

class Exotico
{
private:
    string pais_origem;
public:
    Exotico(string pais_origem);
    ~Exotico();

    string getPais_origem() const;
    void setPais_origem(string pais_origem);
};






