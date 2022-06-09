// Plantilla_PostFija.cpp : Defines the entry point for the application.
#include <iostream>
#include <vector>
#include "Fraccion.h"
#include "Dobles.h"
#include "Conjuntos.h"
#include "Operando.h"
#include <stack>

using namespace std;
float Operar(float a, float b, char operando);
bool EsOperando(char elemento);
int esOperando(char elemento);
double resolver(string expr);
double operar(char operador, double a, double b);

stack<double> pila;

int main()
{
	Dobles doble1{ 3.14 };
	Dobles doble2{ 3.14 };
	Operando* respuesta = doble1 + doble2;
	cout << respuesta->toString() << endl;

	Fraccion fraccion1{ 3, 4 };
	Fraccion fraccion2{ 3, 4 };
	Operando* respuesta2 = fraccion1 + fraccion2;
	cout << respuesta2->toString() << endl;

	set<int> ny = {1, 2, 3};
	set<int> sofi = { 4, 5, 6 };
	Conjuntos conjunto1{ ny };
	Conjuntos conjunto2{ sofi };
	Operando* respuesta3 = conjunto1 + conjunto2;
	cout << respuesta3->toString() << endl;

	cout << resolver("58*6+") << endl;
	return 0;
}

double resolver(string expr) {
	for (int i = 0; i < expr.size(); i++) {
		char elemento = expr[i];
		if(esOperando(elemento)) {
			pila.push(elemento - '0');
		}else {
			double b = pila.top();
			pila.pop();
			double a = pila.top();
			pila.pop();
			double res = operar(elemento, a,b);
			pila.push(res);
		}
	}
	return pila.top();
}

double operar(char operador, double a, double b) {
	if (operador == '*') {
		return a*b;
	}
	if (operador == '+') {
		return a + b;
	}
	if (operador == '-') {
		return a - b;
	}
	if (operador == '/') {
		return a / b;
	}
}

int esOperando(char elemento) {
	if (elemento >= '0' && elemento <= '9') {
		return 1;
	}
	else {
		return 0;
	}
}
