// Beatriz Herguedas Pinedo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void voltear(stack<int> &pila, int numVolteo) {
	vector<int> aux;

	for (int i = 0; i < numVolteo; i++) {
		aux.push_back(pila.top());
		pila.pop();
	}

	for (int i = 0; i < aux.size(); i++) {
		pila.push(aux[i]);
	}
}

bool resuelveCaso() {
	int valor, numVolteos, numVolteo;
	stack<int> pila;

	cin >> valor;

	if (valor == - 1)
		return false;

	while (valor != -1) {
		pila.push(valor);
		cin >> valor;
	}

	cin >> numVolteos;

	if (numVolteos > 0) {
		for (int i = 0; i < numVolteos; i++) {
			cin >> numVolteo;
			voltear(pila, numVolteo);
		}
	}

	cout << pila.top() << '\n';

	return true;

}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}