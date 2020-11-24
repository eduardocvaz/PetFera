#pragma once
#include "animal.hpp"



class Ave : protected Animal
{
protected:

public:
	Ave();
	~Ave();
};


class AveNativo : public Ave, AnimalNativo
{
public:
	AveNativo(); 
	~AveNativo();
};


class AveExotico : public Ave, AnimalExotico
{
public:
	AveExotico();
	~AveExotico();
};