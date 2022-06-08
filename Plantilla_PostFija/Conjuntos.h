#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include<algorithm>
#include "Operando.h"


using namespace std;

class Conjuntos : public Operando
{

public:
	Conjuntos();
	Conjuntos(set<int>&);
	~Conjuntos();

	Operando operator+(Operando&) override;
	Operando operator-(Operando&) override;
	Operando operator*(Operando&) override;
	Operando operator/(Operando&) override;
	string toString() override;
	set<int> val;
};

Conjuntos::Conjuntos()
{
}

Conjuntos::Conjuntos(set<int>& value)
{
	val = value;
}

Conjuntos::~Conjuntos(){

}

inline Operando Conjuntos::operator+(Operando& operando)
{
	Conjuntos& conjuntos = static_cast<Conjuntos&>(operando);
	Conjuntos respuesta{};
	set_union(begin(this->val), end(this->val), begin(conjuntos.val), end(conjuntos.val), inserter(respuesta.val, end(respuesta.val)));
	Operando oper = respuesta;
	return oper;
}

inline Operando Conjuntos::operator-(Operando& operando)
{
	Conjuntos& conjuntos = static_cast<Conjuntos&>(operando);
	Conjuntos respuesta{};
	set_difference(begin(this->val), end(this->val), begin(conjuntos.val), end(conjuntos.val), inserter(respuesta.val, end(respuesta.val)));
	Operando oper = respuesta;
	return oper;
}

inline Operando Conjuntos::operator*(Operando& operando)
{	
	Conjuntos& conjuntos = static_cast<Conjuntos&>(operando);
	Conjuntos respuesta{};
	set_intersection(begin(this->val), end(this->val), begin(conjuntos.val), end(conjuntos.val), inserter(respuesta.val, end(respuesta.val)));
	Operando oper = respuesta;
	return oper;
}

inline Operando Conjuntos::operator/(Operando& operando)
{
	Conjuntos& conjuntos = static_cast<Conjuntos&>(operando);
	Conjuntos respuesta{};
	set_symmetric_difference(begin(this->val), end(this->val), begin(conjuntos.val), end(conjuntos.val), inserter(respuesta.val, end(respuesta.val)));
	Operando oper = respuesta;
	return oper;
}

inline string Conjuntos::toString()
{
	stringstream ss;
	ss << "Tipo: Conjunto \nValor: ";
	for(int i = 0; i < this->val.size(); i++){
		ss << *this->val.find(i) << " ";
	}
	return ss.str();
}