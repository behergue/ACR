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
#include <queue>
#include <stdexcept>

using namespace std;

long long int operar(long long int op1, long long int op2, char c) {
	if (c == '+') {
		return op1 + op2;
	}

	else if (c == '-') {
		return op1 - op2;
	}

	else if (c == '*') {
		return op1 * op2;
	}

	else if (c == '/') {

		if (op2 == 0)
			throw domain_error("ERROR");

		else
			return op1 / op2;
	}
}

int resultPila(string valor) {
	long long int op1, op2;
	stack<long long int> pila;

	for (char c : valor) {

		if (isdigit(c)) {
			pila.push((long long int) c - 48);
		}

		else {
			op2 = pila.top();
			pila.pop();
			op1 = pila.top();
			pila.pop();

			long long int resultado = operar(op1, op2, c);

			pila.push(resultado);
		}
	}

	return pila.top();
}

int resultCola(string valor) {
	long long int op1, op2;
	queue<long long int> cola;

	for (char c : valor) {

		if (isdigit(c)) {
			cola.push((long long int)c - 48);
		}

		else {
			op2 = cola.front();
			cola.pop();
			op1 = cola.front();
			cola.pop();

			long long int resultado = operar(op1, op2, c);

			cola.push(resultado);
		}
	}

	return cola.front();
}

bool resuelveCaso() {
	string valor;
	bool error = false;
	long long int resCola, resPila;

	cin >> valor;

	if (!std::cin)
		return false;

	try {
		resPila = resultPila(valor);
		cout << resPila;
	}
	catch (domain_error e) {
		cout << e.what();
		error = true;
	}

	try {
		resCola = resultCola(valor);
		
		if (!error && resPila == resCola)
			cout << " = ";

		else
			cout << " != ";

		cout << resCola << '\n';
	}
	catch (domain_error e) {
		if (error)
			cout << " = ";

		else
			cout << " != ";

		cout << e.what() << '\n';
	}

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}