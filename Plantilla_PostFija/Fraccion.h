#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Operando.h"

using namespace std;

class Fraccion : public Operando
{
	
public:

	Fraccion() {};
	~Fraccion() {};
	Fraccion operator+(Fraccion) override;
	Fraccion operator-(Fraccion) override;
	Fraccion operator*(Fraccion) override;
	Fraccion operator/(Fraccion) override;
	string toString() override;
	int numerador;
	int denominador;
}


inline Fraccion::Fraccion(){
	numerador = 0;
	denominador = 0;
}

inline Fraccion::~Fraccion() {

}

inline Fraccion Fraccion::operator+(Fraccion fraccion)
{
	Fraccion operando();
	if (this->denominador == fraccion.denominador) {
		operando.numerador = this->numerador + fraccion.numerador;
		operando.denominador = fraccion.denominador;
	} else {
		operando.numerador = this->numerador * fraccion.denominador + this->denominador * fraccion.numerador;
		operando.denominador = this->denominador * fraccion.denominador;
	}
	return operando;
}

inline Fraccion Fraccion::operator-(Fraccion fraccion)
{
	Fraccion operando();
	if (this.denominador == fraccion.denominador) {
		operando.numerador = this->numerador - fraccion.numerador;
		operando.denominador = fraccion.denominador;
	} else {
		operando.numerador = this->numerador * fraccion.denominador - this->denominador * fraccion.numerador;
		operando.denominador = this->denominador * fraccion.denominador;
	}
	return operando;
}

inline Fraccion Fraccion::operator*(Fraccion fraccion)
{
	Fraccion operando();
	operando.numerador = this->numerador * fraccion.numerador;
	operando.denominador = this->denominador * fraccion.deminador;
	return operando;
}

inline Fraccion Fraccion::operator/(Fraccion fraccion)
{
	Fraccion operando();
	operando.numerador = this->numerador * fraccion.numerador;
	operando.denominador = this->denominador * fraccion.denominador;
	return operando;
}

inline string Fraccion::toString()
{
	stringstream ss;
	ss << "Tipo: Fracción\nValor: " << numerador << "/"  << denominador;
	return ss.str();
}