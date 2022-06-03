#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Operando.h"
using namespace std;

class Dobles : public Operando{
public:

	Dobles();
	Dobles(double);
	~Dobles() {};

	Dobles operator+(Dobles) override;
	Dobles operator-(Dobles) override;
	Dobles operator*(Dobles) override;
	Dobles operator/(Dobles) override;
	string toString() override;
	double valor;
}

inline Dobles::Dobles(){
	valor = 0.0;
}

inline Dobles::Dobles(double val){
	valor = val;
}

inline Dobles::~Dobles() {

}

inline Dobles Dobles::operator+(Dobles doble)
{
	Dobles operando();
	operando.valor = this->valor + doble.valor;
	return operando;
}

inline Dobles Dobles::operator-(Dobles doble)
{
	Dobles operando();
	operando.valor = this->valor - doble.valor;
	return operando;
}

inline Dobles Dobles::operator*(Dobles doble)
{
	Dobles operando();
	operando.valor = this->valor * doble.valor;
	return operando;
}

inline Dobles Dobles::operator/(Dobles doble)
{
	Dobles operando();
	operando.valor = this->valor / doble.valor;
	return operando;
}

inline string Dobles::toString()
{
	return "Tipo: Double \nValor: " + to_string(this->valor);
}