//Beatriz Herguedas Pinedo

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int piezaPerdida(vector<int> &v, int num) {

	sort(v.begin(), v.end());

	int i = 1;
	bool encontrado = false;

	while (i < num + 1 && !encontrado) {

		if (!binary_search(v.begin(), v.end(), i))
			encontrado = true;

		else
			i++;
	}

	return i;
}

bool resuelveCaso() {
	int num, valor;
	vector<int> v;

	cin >> num;

	if (num == 0)
		return false;

	for (int i = 0; i < num - 1; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	cout << piezaPerdida(v, num) << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}