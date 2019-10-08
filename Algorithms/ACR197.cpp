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
#include <deque>

using namespace std;

bool resuelveCaso() {
	deque<char> cola1, cola2;
	stack<char> pila;
	string palabra;

	getline(cin, palabra);

	if (!std::cin)
		return false;

	cout << palabra << " => ";

	int cont = 0;
	for (char c : palabra) {

		if (cont % 2 == 0)
			cola1.push_back(c);

		else
			pila.push(c);

		cont++;
	}

	while (!pila.empty()) {

		cola1.push_back(pila.top());
		pila.pop();
	}

	while (!cola1.empty()) {

		if (cola1.front() == 'a' || cola1.front() == 'e' || cola1.front() == 'i' || cola1.front() == 'o' || cola1.front() == 'u' ||
			cola1.front() == 'A' || cola1.front() == 'E' || cola1.front() == 'I' || cola1.front() == 'O' || cola1.front() == 'U') {

			while (!pila.empty()) {
				cola2.push_back(pila.top());
				pila.pop();
			}

			cola2.push_back(cola1.front());
			cola1.pop_front();
		}

		else if(cola1.size() == 1) {

			pila.push(cola1.front());
			cola1.pop_front();

			while (!pila.empty()) {
				cola2.push_back(pila.top());
				pila.pop();
			}
		}

		else {
			pila.push(cola1.front());
			cola1.pop_front();
		}
	}

	while (!cola2.empty()) {
		cout << cola2.front();
		cola2.pop_front();
	}

	cout << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());


	return 0;
}