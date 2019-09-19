//Beatriz Herguedas Pinedo

#include <iostream>
#include <string>

using namespace std;

int bolsa(string &secuencia, int sumaclave) {

	int suma = 0;
	int cont = 0;

	for (int i = secuencia.size() - 1; i > -1; i--) {

		suma += (int(secuencia[i]) - '0');

		while (suma > sumaclave) {

			suma -= (int(secuencia[secuencia.size() - 1]) - '0');
			secuencia.pop_back();
		}

		if (suma == sumaclave) 
			cont++;
	}

	return cont;
}

void resuelveCaso() {
	int sumaclave;
	string secuencia;

	cin >> sumaclave >> secuencia;

	cout << bolsa(secuencia, sumaclave) << '\n';
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