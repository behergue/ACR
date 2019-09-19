//Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>

using namespace std;

void resolver(bool comb[], int v, int ini, int fin, bool &imp) {

	if (fin == ini) {
		if (v != 0)
			comb[ini] = true;

		else
			comb[ini] = false;

		if (imp) 
			cout << " ";

		else 
			imp = true;

		for (int i = 0; i < fin + 1; i++) {
			if (comb[i])
				cout << "V";

			else
				cout << "C";
		}
	}

	else {

		if (fin - ini + 1 > v) {

			comb[ini] = false;
			resolver(comb, v, ini + 1, fin, imp);
		}

		if (v != 0) {
			comb[ini] = true;
			resolver(comb, v - 1, ini + 1, fin, imp);
		}
	}
}

void resuelveCaso() {
	int c, v;
	bool comb[15];
	int ini = 0;

	cin >> c;
	cin >> v;
	
	int fin = c + v - 1;
	bool imp = false;

	resolver(comb, v, ini, fin, imp);

	cout << "\n";
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