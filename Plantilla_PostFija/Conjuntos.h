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

	Conjuntos operator+(Conjuntos) override;
	Conjuntos operator-(Conjuntos) override;
	Conjuntos operator*(Conjuntos) override;
	Conjuntos operator/(Conjuntos) override;
	string toString() override;
	set<int> val;
}

Conjuntos::Conjuntos(){

}

Conjuntos::Conjuntos(set<int>& conjunto){
	val = conjunto;
}

Conjuntos::~Conjuntos() {

}

inline Conjuntos Conjuntos::operator+(Conjuntos)
{
	return Conjuntos();
}

inline Conjuntos Conjuntos::operator+(Conjuntos operando)
{
	Conjuntos oper();
	set_union(this->val.begin(), this->val.end(), operando.val.begin(), operando.val.end(), oper.val.begin());
	return oper;
}

inline Conjuntos Conjuntos::operator-(Conjuntos operando)
{
	Conjuntos oper();
	set_difference(this->val.begin(), this->val.end(), operando.val.begin(), operando.val.end(), oper.val.begin());
	return oper;
}

inline Conjuntos Conjuntos::operator*(Conjuntos operando)
{	
	Conjuntos oper();
	set_intersection(this->val.begin(), this->val.end(), operando.val.begin(), operando.val.end(), oper.val.begin());
	return oper;
}

inline Conjuntos Conjuntos::operator/(Conjuntos operando)
{
	Conjuntos oper();
	set_symmetric_difference(this->val.begin(), this->val.end(), operando.val.begin(), operando.val.end(), oper.val.begin());
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