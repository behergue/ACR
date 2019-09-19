//Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>

using namespace std;

void racha(vector <int> &v, int &ini, int &fin)
{
	int maxsum = v[0];
	int sumaux = v[0];
	int i = 1;
	int j = 1;

	ini = 1;
	fin = 1;

	while (i < v.size()) {

		if (sumaux < 0) {

			if (v[i] > 0) {

				j = i + 1;
				sumaux = v[i];
			}
		}

		else if (sumaux > 0) {

			if (v[i] > 0) 
				sumaux += v[i];

			if (v[i] < 0) 
				sumaux += v[i];
		}

		else {
			sumaux = v[i];
			j = i + 1;
		}

		if (sumaux > maxsum) {
			maxsum = sumaux;
			ini = j;
			fin = i + 1;
		}

		else if (sumaux == maxsum) {

			if (fin - ini + 1 > i + 1 - j + 1) {
				ini = j;
				fin = i + 1;
			}
		}

		i = i + 1;
	}
}

void resuelveCaso() {
	int n, ini, fin;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	racha(a, ini, fin);

	cout << ini << " " << fin << "\n";
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