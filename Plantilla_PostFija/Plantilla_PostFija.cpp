// Plantilla_PostFija.cpp : Defines the entry point for the application.
#include <iostream>
#include <vector>
#include "Fraccion.h"
#include "Dobles.h"
#include "Conjuntos.h"
#include "Operando.h"

using namespace std;
float Operar(float a, float b, char operando);
bool EsOperando(char elemento);

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

	return 0;
}
