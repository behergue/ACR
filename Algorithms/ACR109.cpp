// Beatriz Herguedas Pinedo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;


bool resuelveCaso() {
	string categoria, local, visitante, ganador;
	int numSetsLocal, numSetsVisitante, puntosLocal, puntosVisitante;
	int totalPartidosJugados = 0, puntosGanador = 0, totalEquipos = 0;
	unordered_map<string, int> equipos; // mapa de equipos con sus puntuaciones
	bool empate = false;

	cin >> categoria;

	if (categoria == "FIN")
		return false;

	cin >> local;

	while (local != "FIN") {
		cin >> numSetsLocal >> visitante >> numSetsVisitante;

		if (numSetsLocal > numSetsVisitante) {
			puntosLocal = 2;
			puntosVisitante = 1;
		}

		else {
			puntosLocal = 1;
			puntosVisitante = 2;
		}

		auto it = equipos.find(local);
		auto it2 = equipos.find(visitante);

		if (it == equipos.end()) {
			equipos.insert({ local, puntosLocal });
			totalEquipos++;
		}

		else {
			it->second += puntosLocal;
		}

		it = equipos.find(local);

		if (it->second > puntosGanador) {
			ganador = it->first;
			empate = false;
			puntosGanador = it->second;
		}

		else if (it->second == puntosGanador) {
			empate = true;
		}

		if (it2 == equipos.end()) {
			equipos.insert({ visitante, puntosVisitante });
			totalEquipos++;
		}

		else {
			it2->second += puntosVisitante;
		}

		it2 = equipos.find(visitante);

		if (it2->second > puntosGanador) {
			ganador = it2->first;
			empate = false;
			puntosGanador = it2->second;
		}

		else if (it2->second == puntosGanador) {
			empate = true;
		}

		totalPartidosJugados++;

		cin >> local;
	}	

	int partidosTotales = totalEquipos * (totalEquipos - 1);
	int partidosNoJugados = partidosTotales - totalPartidosJugados;

	if (empate) {
		cout << "EMPATE " << partidosNoJugados << '\n';
	}

	else {
		cout << ganador << ' ' << partidosNoJugados << '\n';
	}

	return true;

}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}