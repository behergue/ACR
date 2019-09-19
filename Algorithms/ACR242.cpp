//Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>

using namespace std;

long long int numParejas(vector<int> const &v) {
	long long int resultado = 0;
	long long int suma = v[0];

	for (int i = 1; i < v.size(); i++) {
		resultado += suma * v[i];
		suma += v[i];
	}

	return resultado;
}

bool resuelveCaso() {
	int num, valor;
	vector<int> v;

	cin >> num;

	if (num == 0)
		return false;

	for (int i = 0; i < num; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	cout << numParejas(v) << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}