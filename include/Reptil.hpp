#pragma once
#include "animal.hpp"

class Reptil : protected Animal
{
protected:
public:
    Reptil();
    ~Reptil();
};

class ReptilNativo : public Reptil, AnimalNativo
{
public:
    ReptilNativo();
    ~ReptilNativo();
};

class ReptilExotico : public Reptil, AnimalExotico
{
public:
    ReptilExotico();
    ~ReptilExotico();
};