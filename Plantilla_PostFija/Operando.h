#pragma once
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Operando
{

public:

	Operando() {};
	~Operando() {};

	virtual Operando operator+(Operando&) { return Operando(); };
	virtual Operando operator-(Operando&) { return Operando(); };
	virtual Operando operator*(Operando&) { return Operando(); };
	virtual Operando operator/(Operando&) { return Operando(); };
	virtual string toString() { return ""; };
	vector<Operando> metodoPlantilla(stringstream);
};

inline vector<Operando> Operando::metodoPlantilla(stringstream ss)
{
	return vector<Operando>();
}
