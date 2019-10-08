//Beatriz Herguedas Pinedo, DG209

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdio.h>

using namespace std;

int altura() {
	int n;
	int m = 0;

	cin >> n;

	if (n == 0) {
		return 1;
	}

	else {
		for (int i = 0; i < n; i++) {
			m = max(m, altura());
		}
	}
	return m + 1;
}

void resuelveCaso() {
	cout << altura() << '\n';
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