//Beatriz Herguedas Pinedo

#include <algorithm>
#include <iostream>

using namespace std;

bool resuelveCaso() {
	int L, valor, maxant, maxact, maxini, minini, suma;

	cin >> L;

	if (L == 0)
		return false;

	cin >> valor;

	maxant = valor;
	maxact = max(valor, 0);
	maxini = valor;
	minini = valor;
	suma = valor;

	for (int i = 1; i < L; i++) {
		cin >> valor;

		maxact += valor;
		suma += valor;

		maxini = max(maxini, suma);
		minini = min(minini, suma);
		maxact = max(maxact, 0);
		maxant = max(maxact, maxant);
	}

	cout << max(maxant, suma - minini + maxini) << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}