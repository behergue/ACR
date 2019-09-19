//Beatriz Herguedas Pinedo

#include <iostream>

using namespace std;

bool resuelveCaso() {
	int n, valor, maxtotal, maxninos, ninos;

	cin >> n;

	if (n == 0)
		return false;

	cin >> valor;

	maxtotal = valor;
	maxninos = valor;
	ninos = 1;

	for (int i = 1; i < n; i++) {
		cin >> valor;

		if (valor <= maxninos) {
			ninos = i + 1;
			maxninos = maxtotal;
		}
		
		if (valor > maxtotal) {
			maxtotal = valor;
		}
	}

	cout << ninos << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}