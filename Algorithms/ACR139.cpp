// Beatriz Herguedas Pinedo

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstddef>  
#include <utility>

using namespace std;

long int siguiente(long int num) {
	long int suma = 0;

	while (num > 0) {

		int digito = num % 10;
		suma += digito * digito * digito;
		num /= 10;
	}

	return suma;
}

bool cubinfinito(long int num, vector<int> &v) {

	bool encontrado = false;

	v.push_back(num);

	while (num != 1 && !encontrado) {

		num = siguiente(num);
		v.push_back(num);

		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] == num)
				encontrado = true;
		}
	}

	return num == 1;
}


bool resuelveCaso() {
	long int num;
	vector<int> v;

	cin >> num;

	if (num == 0)
		return false;

	bool cub = cubinfinito(num, v);

	for (int i = 0; i < v.size(); i++) {

		cout << v[i];

		if (i < v.size() - 1)
			cout << " - ";
		else
			cout << " -> ";
	}

	if (cub)
		cout << "cubifinito.\n";

	else
		cout << "no cubifinito.\n";

	return true;

}

int main() {

	cin.sync_with_stdio(false);
	while (resuelveCaso());

	return 0;
}