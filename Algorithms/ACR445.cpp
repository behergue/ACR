// Beatriz Herguedas Pinedo

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!std::cin) // fin de la entrada
		return false;
	int v1, v2;
	priority_queue <int, vector<int>, greater<int>> pqIni, pqFin;
	for (int i = 0; i < n; ++i) {
		cin >> v1 >> v2;
		pqIni.push(v1);
		pqFin.push(v2);
	}
	int maxAmigos = -1;
	int amigos = -1;
	
	// Vemos cuantos inis son menores que el fin mas pequeño
	while (!pqIni.empty()) {
		if (pqIni.top() < pqFin.top()) {
			amigos++;
			pqIni.pop();
		}
		else {
			amigos--;
			pqFin.pop();
		}
		if (amigos > maxAmigos) maxAmigos = amigos;
	}

	cout << maxAmigos << '\n';
	return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}