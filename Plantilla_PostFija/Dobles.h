#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Operando.h"
using namespace std;

class Dobles : public Operando {
public:

	Dobles();
	Dobles(double);
	~Dobles();

	Operando operator+(Operando&) override;
	Operando operator-(Operando&) override;
	Operando operator*(Operando&) override;
	Operando operator/(Operando&) override;
	string toString() override;
	double valor;
};

Dobles::Dobles(){
	valor = 0.0;
}

Dobles::Dobles(double val){
	valor = val;
}

Dobles::~Dobles() {

}

inline Operando Dobles::operator+(Operando& doble)
{
	Dobles& operando = static_cast<Dobles&>(doble);
	operando.valor += this->valor;
	return operando;
}

inline Operando Dobles::operator-(Operando& doble)
{
	Dobles& operando = static_cast<Dobles&>(doble);
	operando.valor -= this->valor;
	return operando;
}

inline Operando Dobles::operator*(Operando& doble)
{
	Dobles& operando = static_cast<Dobles&>(doble);
	operando.valor *= this->valor;
	return operando;
}

inline Operando Dobles::operator/(Operando& doble)
{
	Dobles& operando = static_cast<Dobles&>(doble);
	operando.valor /= this->valor;
	return operando;
}

inline string Dobles::toString()
{
	return "Tipo: Double \nValor: " + to_string(this->valor);
}