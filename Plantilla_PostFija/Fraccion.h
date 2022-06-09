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
	Fraccion(int, int);
	~Fraccion();
	Operando* operator+(Operando&) override;
	Operando* operator-(Operando&) override;
	Operando* operator*(Operando&) override;
	Operando* operator/(Operando&) override;
	string toString() override;
	int numerador;
	int denominador;
};


Fraccion::Fraccion(){
	numerador = 0;
	denominador = 0;
}
Fraccion::Fraccion(int numerador, int denominador) {
	this->numerador = numerador;
	this->denominador = denominador;
}

Fraccion::~Fraccion() {

}

inline Operando* Fraccion::operator+(Operando& fraccion)
{
	Fraccion& operando = static_cast<Fraccion&>(fraccion);
	Fraccion* operandoTemp = new Fraccion(operando.numerador, operando.denominador);
	if (this->denominador == operando.denominador) {
		operandoTemp->numerador = this->numerador + operando.numerador;
		operandoTemp->denominador = operando.denominador;
	} else {
		operandoTemp->numerador = this->numerador * operando.denominador + this->denominador * operando.numerador;
		operandoTemp->denominador = this->denominador * operando.denominador;
	}
	return operandoTemp;
}

inline Operando* Fraccion::operator-(Operando& fraccion)
{
	Fraccion& operando = static_cast<Fraccion&>(fraccion);
	Fraccion* operandoTemp = new Fraccion(operando.numerador, operando.denominador);
	if (this->denominador == operando.denominador) {
		operandoTemp->numerador = this->numerador - operando.numerador;
		operandoTemp->denominador = operando.denominador;
	} else {
		operandoTemp->numerador = this->numerador * operando.denominador - this->denominador * operando.numerador;
		operandoTemp->denominador = this->denominador * operando.denominador;
	}
	return operandoTemp;
}

inline Operando* Fraccion::operator*(Operando& fraccion)
{
	Fraccion& operando = static_cast<Fraccion&>(fraccion);
	Fraccion* operandoTemp = new Fraccion(operando.numerador, operando.denominador);
	operandoTemp->numerador = this->numerador * operando.numerador;
	operandoTemp->denominador = this->denominador * operando.denominador;
	return operandoTemp;
}

inline Operando* Fraccion::operator/(Operando& fraccion)
{
	Fraccion& operando = static_cast<Fraccion&>(fraccion);
	Fraccion* operandoTemp = new Fraccion(operando.numerador, operando.denominador);
	operandoTemp->numerador = this->numerador * operando.numerador;
	operandoTemp->denominador = this->denominador * operando.denominador;
	return operandoTemp;
}

inline string Fraccion::toString()
{
	stringstream ss;
	ss << "Tipo: Fraccion\nValor: " << numerador << "/"  << denominador;
	return ss.str();
}