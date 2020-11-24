#pragma once
#include "animal.hpp"

class Anfibio : protected Animal
{
protected:
public:
    Anfibio();
    ~Anfibio();
};

class AnfibioNativo : public Anfibio, AnimalNativo
{
public:
    AnfibioNativo();
    ~AnfibioNativo();
};

class AnfibioExotico : public Anfibio, AnimalExotico
{
public:
    AnfibioExotico();
    ~AnfibioExotico();
};