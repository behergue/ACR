//Beatriz Herguedas Pinedo

#include <iostream>

using namespace std;

int pajaritas(int ancho, int alto) {

	if (ancho < 10 || alto < 10) 
		return 0;

	else if (ancho == alto)
		return 1;

	else {
		if (ancho > alto) 
			return ancho / alto + pajaritas(ancho % alto, alto);

		else 
			return alto / ancho + pajaritas(alto % ancho, ancho);
	}
}

bool resuelveCaso() {
	int ancho, alto;

	cin >> ancho >> alto;

	if (ancho == 0 && alto == 0)
		return false;

	cout << pajaritas(ancho, alto) << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}