//Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxBurros(unordered_map<int, int> const &mapa) {
	int sol = 0;

	for (auto it : mapa) {
		sol += it.second / 2;
	}

	return sol;
}

void resuelveCaso() {
	int numBurros, numSacos, valor;
	unordered_map<int, int> mapa;

	cin >> numBurros >> numSacos;

	for (int i = 0; i < numSacos; i++) {
		cin >> valor;
		auto it = mapa.find(valor);

		if (it == mapa.end()) {
			mapa.insert({ valor, 1 });
		}

		else {
			it->second++;
		}
	}

	cout << min(numBurros, maxBurros(mapa)) << '\n';
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
  
	int numCasos;
	std::cin >> numCasos;
  
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	return 0;
}