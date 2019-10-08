// Beatriz Herguedas Pinedo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

bool resuelveCaso() {
	list<char> lista;
	string palabra;

	getline(cin, palabra);

	if (!std::cin)
		return false;

	auto it = lista.begin();

	for (char c : palabra) {

		if (c == '-') {
			it = lista.begin();
		}

		else if (c == '+') {
			it = lista.end();
		}

		else if (c == '*') {
			if (it != lista.end()) {
				it++;
			}
		}

		else if (c == '3') {
			if (it != lista.end()) {
				it = lista.erase(it);
			}
		}

		else {
			it = lista.insert(it, c);
			it++;
		}
	}

	for (char c: lista) {
		cout << c ;
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