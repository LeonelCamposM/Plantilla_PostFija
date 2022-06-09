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

	virtual Operando* operator+(Operando&) { return new Operando(); };
	virtual Operando* operator-(Operando&) { return new Operando(); };
	virtual Operando* operator*(Operando&) { return new Operando(); };
	virtual Operando* operator/(Operando&) { return new Operando(); };
	virtual string toString() { return ""; };
	Operando* operar(string operador, Operando* a, Operando* b);
};

inline Operando* Operando::operar(string operador, Operando* a, Operando* b)
{
	if (operador == "*") {
		return (*a) * (*b);
	}
	if (operador == "+") {
		return (*a) + (*b);
	}
	if (operador == "-") {
		return (*a) - (*b);
	}
	if (operador == "/") {
		return (*a) / (*b);
	}
}
