//Beatriz Herguedas Pinedo, DG209

#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool resuelveCaso() {
	int num;
	string nombre, veredicto, aux;
	map<string, int> mapa;

	cin >> num;

	if (num == 0)
		return false;

	getline(cin, aux);

	for (int i = 0; i < num; i++) {

		getline(cin, nombre);
		getline(cin, veredicto);

		auto it = mapa.find(nombre);

		if (it == mapa.end()) {
			mapa.insert({ nombre, 0 });
			it = mapa.find(nombre);
		}

		if (veredicto == "CORRECTO")
			it->second++;

		else
			it->second--;
	}

	for (auto i : mapa) {
		if (i.second != 0)
			cout << i.first << ", " << i.second << '\n';
	}

	cout << "---\n";

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}