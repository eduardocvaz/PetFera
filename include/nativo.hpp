#pragma once

#include "animal.hpp"
#include "string"
#include "anfibio.hpp"
#include "ave.hpp"
#include "mamifero.hpp"
#include "reptil.hpp"

class nativo
{
private:
    string estado;
public:
    nativo(string estado);
    ~nativo();
    string getEstado() const;
};

class anfibioNativo : public anfibio, public nativo
{
private:
public:
    anfibioNativo(/* args */);
    ~anfibioNativo();
};

class aveNativo : public ave, public nativo
{
private:
public:
    aveNativo(/* args */);
    ~aveNativo();
};

class mamiferoNativo : public mamifero, public nativo
{
private:
public:
    mamiferoNativo(/* args */);
    ~mamiferoNativo();
};

class reptilNativo : public reptil, public nativo
{
private:
public:
    reptilNativo(/* args */);
    ~reptilNativo();
};


