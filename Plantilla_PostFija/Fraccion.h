#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Operando.h"

using namespace std;

class Fraccion : public Operando
{

public:
	Fraccion();
	~Fraccion();
	Operando operator+(Operando&) override;
	Operando operator-(Operando&) override;
	Operando operator*(Operando&) override;
	Operando operator/(Operando&) override;
	string toString() override;
	int numerador;
	int denominador;
};


Fraccion::Fraccion(){
	numerador = 0;
	denominador = 0;
}

Fraccion::~Fraccion() {

}

inline Operando Fraccion::operator+(Operando& fraccion)
{
	Fraccion& operando = static_cast<Fraccion&>(fraccion);
	if (this->denominador == operando.denominador) {
		operando.numerador = this->numerador + operando.numerador;
		operando.denominador = operando.denominador;
	} else {
		operando.numerador = this->numerador * operando.denominador + this->denominador * operando.numerador;
		operando.denominador = this->denominador * operando.denominador;
	}
	return operando;
}

inline Operando Fraccion::operator-(Operando& fraccion)
{
	Fraccion& operando = static_cast<Fraccion&>(fraccion);
	if (this->denominador == operando.denominador) {
		operando.numerador = this->numerador - operando.numerador;
		operando.denominador = operando.denominador;
	} else {
		operando.numerador = this->numerador * operando.denominador - this->denominador * operando.numerador;
		operando.denominador = this->denominador * operando.denominador;
	}
	return operando;
}

inline Operando Fraccion::operator*(Operando& fraccion)
{
	Fraccion& operando = static_cast<Fraccion&>(fraccion);
	operando.numerador = this->numerador * operando.numerador;
	operando.denominador = this->denominador * operando.denominador;
	return operando;
}

inline Operando Fraccion::operator/(Operando& fraccion)
{
	Fraccion& operando = static_cast<Fraccion&>(fraccion);
	operando.numerador = this->numerador * operando.numerador;
	operando.denominador = this->denominador * operando.denominador;
	return operando;
}

inline string Fraccion::toString()
{
	stringstream ss;
	ss << "Tipo: Fracción\nValor: " << numerador << "/"  << denominador;
	return ss.str();
}