//Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>

using namespace std;

int abadia(vector<int> const &v, int num) {
	int max = 0;
	int numAbadias = 0;

	for (int i = num - 1; i > - 1; i--) {
		if (v[i] > max) {
			numAbadias++;
			max = v[i];
		}
	}

	return numAbadias;
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

	cout << abadia(v, num) << '\n';

	return true;
}

int main() {
 
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}