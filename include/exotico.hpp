#pragma once

#include "animal.hpp"
#include "string"
#include "anfibio.hpp"
#include "ave.hpp"
#include "mamifero.hpp"
#include "reptil.hpp"

class exotico
{
private:
    string pais_origem;
public:
    exotico(string pais_origem);
    ~exotico();
    string getPais_origem() const;
};

class anfibioExotico : public anfibio, public exotico
{
private:
public:
    anfibioExotico(/* args */);
    ~anfibioExotico();
};

class aveExotico : public ave, public exotico
{
private:
public:
    aveExotico(/* args */);
    ~aveExotico();
};

class mamiferoExotico : public mamifero, public exotico
{
private:
public:
    mamiferoExotico(/* args */);
    ~mamiferoExotico();
};

class reptilExotico : public reptil, public exotico
{
private:
public:
    reptilExotico(/* args */);
    ~reptilExotico();
};


