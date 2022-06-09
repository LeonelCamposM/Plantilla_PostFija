// Plantilla_PostFija.cpp : Defines the entry point for the application.
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "Fraccion.h"
#include "Dobles.h"
#include "Conjuntos.h"
#include "Operando.h"

using namespace std;

bool esOperando(string elemento);
string resolver(string expr);
vector<string> tokenizar(string expr, char delimitador);
int averiguarTipoDato(string token);

int main()
{
	Dobles doble{3.14};
	cout << doble.toString() << endl;

	Fraccion fraccion{3, 4};
	cout << fraccion.toString() << endl;

	set<int> set1 = {1, 2, 3};
	Conjuntos conjunto{ set1 };
	cout << conjunto.toString() << endl;

	cout << "---------------------" << endl << endl;
	cout << resolver("5.0,9.0,+,6.0,*,5.0,2.0,/,-") << endl;
	cout << "---------------------" << endl << endl;
	cout << resolver("2/4,2/4,*,13/4,+,1/2,/,2/4,-") << endl;
	cout << "---------------------" << endl << endl;
	cout << resolver("{1 2 3 4},{5 6 7 8},*,{9 10 11},+,{9 12 13},/,{10 11},-") << endl;
	return 0;
}

vector<string> tokenizar(string expr, char delimitador) {
	vector <string> tokens;
	stringstream ss(expr);
	string intermediate;
	while (getline(ss, intermediate, delimitador))
	{
		tokens.push_back(intermediate);
	}
	return tokens;
}

int averiguarTipoDato(string token) { 
	size_t found = token.find("/");
	if (found != string::npos) {
		return 0;
	}
	size_t found2 = token.find("{");
	if (found2 != string::npos) {
		return 1;
	}
	size_t found3 = token.find(".");
	if (found3 != string::npos) {
		return 2;
	}
}

string resolver(string expr) {
	cout << expr << endl;
	vector <string> tokens = tokenizar(expr, ',');
	int tipo = averiguarTipoDato(tokens[0]);
	
	stack<Operando*> pila;
	
	for (int i = 0; i < tokens.size(); i++) {
		string elemento = tokens[i];
		if(esOperando(elemento)) {
			switch (tipo)
			{
			case 0: {
				size_t pos = elemento.find("/");
				string numerador = elemento.substr(0, pos);
				string denominador = elemento.substr(pos+1);
				Fraccion* elementoTemp = new Fraccion(stoi(numerador), stoi(denominador));
				pila.push(elementoTemp);
			}
				  break;
			case 1: {
				vector <string> conjunto = tokenizar(elemento, ' ');
				set<int> conjuntoElementos;
				for (int i = 0; i < conjunto.size(); i++) {
					if (i== 0)
						conjunto[i].replace(0, 1, " ");
					if (i == conjunto.size())
						conjunto[i].replace(1, 2, " ");
					conjuntoElementos.insert(stoi(conjunto[i]));
				}
				Conjuntos* elementoTemp = new Conjuntos(conjuntoElementos);
				pila.push(elementoTemp);
			}
				  break;
			case 2: {
				Dobles* elementoTemp =  new Dobles(stod(elemento));
				pila.push(elementoTemp);
			}
				  break;
			}
		}else {
			Operando* b = pila.top();
			pila.pop();
			Operando* a = pila.top();
			pila.pop();
			Operando* res = a->operar(elemento, a, b);
			pila.push(res);
		}
	}
	return pila.top()->toString();
}

bool esOperando(string elemento) {
	if (elemento == "+" || elemento == "-" || elemento == "*" || elemento == "/") {
		return false;
	}
	else {
		return true;
	}
}
