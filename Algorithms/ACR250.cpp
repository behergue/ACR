//Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>

using namespace std;

int bombines(vector<int> const& v) {

	int dia = 0;
	int sumtotal = 0;
	int sumaux = 0;
	int	dif = 0;
	int min;

	for (int i = 0; i < v.size(); i++)
		sumtotal += v[i];

	min = abs(sumtotal);

	for (int i = 0; i < v.size(); i++) {
		sumaux += v[i];
		sumtotal -= v[i];

		dif = abs(sumtotal - sumaux);

		if (dif < min) {
			min = dif;
			dia = i + 1;
		}
	}

	return dia;
}

bool resuelveCaso() {
	int numDias;
	vector<int> v;

	cin >> numDias;

	if (numDias == 0)
		return false;
	
	v.resize(numDias);

	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];

	cout << bombines(v) << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}