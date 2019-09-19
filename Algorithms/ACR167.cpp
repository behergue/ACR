//Beatriz Herguedas Pinedo

#include <iostream>

using namespace std;

int fractales(int longitud, int numCuadrados) {
	int suma;

	if (longitud == 1)
		suma = 4 * numCuadrados;

	else
		suma = fractales(longitud / 2, 4 * numCuadrados) + 
		numCuadrados * 4 * longitud;

	return suma;
}


bool resuelveCaso() {
	int longitud;

	cin >> longitud;

	if (!std::cin)
		return false;

	if (longitud == 0)
		cout << "0 \n";

	else 
		cout << fractales(longitud, 1) << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}