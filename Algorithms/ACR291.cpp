// Beatriz Herguedas Pinedo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

void aMinusculas(string & palabra) {

	for (int i = 0; i < palabra.size(); i++) {

		if (isupper(palabra[i])) {
			palabra[i] = tolower(palabra[i]);
		}
	}
}

bool resuelveCaso() {
	int numLineas;
	map<string, vector<int>> mapa;
	stringstream ss;
	string linea, palabra, aux;

	cin >> numLineas;

	if (numLineas == 0)
		return false;

	getline(cin, aux);

	for (int i = 0; i < numLineas; i++) {

		getline(cin, linea);

		ss.clear();
		ss << linea;

		while (ss >> palabra) {

			if (palabra.size() > 2) {

				aMinusculas(palabra);

				auto it = mapa.find(palabra);

				if (it == mapa.end()) {
					mapa.insert({ palabra, { i + 1} });
				}

				else {

					if (it->second.back() != i + 1) {
						it->second.push_back(i + 1);
					}
				}

			}
		}
	}

	for (auto i : mapa) {

		cout << i.first << ' ';

		for (int j = 0; j < i.second.size(); j++) {

			cout << i.second[j];

			if (j < i.second.size() - 1) {
				cout << ' ';
			}
		}

		cout << '\n';
	}

	cout << "----\n";


	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}