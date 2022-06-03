#pragma once
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Operando{
	
public:

	Operando();
	~Operando();

	virtual Operando operator+();
	virtual Operando operator-();
	virtual Operando operator*();
	virtual Operando operator/();
	virtual string toString();
	vector<Operando> metodoPlantilla(stringstream);

}

Operando::Operando(){

}

Operando::~Operando() {

}

inline Operando Operando::operator+()
{
	return Operando();
}

inline Operando Operando::operator-()
{
	return Operando();
}

inline Operando Operando::operator*()
{
	return Operando();
}

inline Operando Operando::operator/()
{
	return Operando();
}

inline vector<Operando> Operando::metodoPlantilla()
{
	return  vector<Operando>();
}

inline string Operando::toString()
{
	return "";
}