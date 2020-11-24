#pragma once
#include "animal.hpp"



class Mamifero : protected Animal
{
protected:

public:
	Mamifero();
	~Mamifero();
};


class MamiferoNativo : public Mamifero, AnimalNativo
{
public:
	MamiferoNativo(); 
	~MamiferoNativo();
};


class MamiferoExotico : public Mamifero, AnimalExotico
{
public:
	MamiferoExotico();
	~MamiferoExotico();
};