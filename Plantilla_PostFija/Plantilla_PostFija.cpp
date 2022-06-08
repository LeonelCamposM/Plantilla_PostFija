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
	return 0;
}
