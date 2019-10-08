// Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>
using namespace std;

long long resolver(vector<int> &v, int &ini, int &fin) {
	
	if (ini == fin) 
		return 0;
	
	else {
		int m = (ini + fin) / 2;
		long long tiempo = resolver(v, ini, m);
		m++;
		tiempo += resolver(v, m, fin);

		int izq = ini, der = m, general = ini;
		fin++;
		vector<int> w;
		
		while (izq != m && der != fin) {
			if (v[izq] <= v[der]) {
				w.push_back(v[izq]);
				general++;
				izq++;
			}
			else {
				w.push_back(v[der]);
				tiempo += der - general;
				general++;
				der++;
			}
		}
		
		while (izq != m) {
			w.push_back(v[izq]);
			izq++;
		}
		
		while (der != fin) {
			w.push_back(v[der]);
			der++;
		}

		general = ini;
		while (general != fin) {
			v[general] = w[general - ini];
			general++;
		}
		fin--;

		return tiempo;
	}
}

bool resuelveCaso() {
	vector<int> v;
	int total;
	cin >> total;
	
	if (total==0) 
		return false;

	int num;
	for (int i = 0; i < total; i++) {
		cin >> num;
		v.push_back(num);
	}

	int ini = 0;
	total--;
	cout << resolver(v, ini, total) << "\n";

	return true;
}

int main() {

	while (resuelveCaso());
	
	return 0;
}