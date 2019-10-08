// Beatriz Herguedas Pinedo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;


bool resuelveCaso() {
	unordered_map<string, int> reyes;
	int numReyes, numDesc;
	string nombre;

	cin >> numReyes;

	if (numReyes == 0)
		return false;

	for (int i = 0; i < numReyes; i++) {
		cin >> nombre;
		auto it = reyes.find(nombre);

		if (it == reyes.end()) {
			reyes.insert({ nombre, 1 });
		}
		else {
			it->second++;
		}
	}

	cin >> numDesc;

	for (int i = 0; i < numDesc; i++) {
		cin >> nombre;
		auto it = reyes.find(nombre);

		if (it == reyes.end()) {
			cout << 1 << '\n';
			reyes.insert({ nombre, 1 });
		}
		else {
			it->second++;
			cout << it->second << '\n';
		}
	}

	cout  << '\n';

	return true;

}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}