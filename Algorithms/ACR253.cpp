//Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>
#include <queue> // std::priory_queue
#include <algorithm>
#include <limits> // std::numeric_limits

typedef pair<int, int> int_pair; // casilla, contador
struct Compare{
	bool operator() (int_pair const& lhs, int_pair const& rhs){
		return (lhs.second > rhs.second) || (lhs.second == rhs.second && lhs.first < rhs.first);
	}
};
typedef priority_queue<int_pair, vector<int_pair>, Compare> priory_queue_nodes; // coste, nodo


void procesar(int vertices, int dado, int serpientes, int escaleras) {
	
	vector<int> casillas_serpientes(vertices, -1), casillas_escaleras(vertices, -1);
	vector<bool> tablero(vertices, false); // casillas visitadas
	priory_queue_nodes nodosPorVisitar;
	int c1, c2;
	
	for (int i = 0; i < serpientes; i++) {
		cin >> c1 >> c2;
		casillas_serpientes[c1 - 1] = c2 - 1;
	}
	
	for (int i = 0; i < escaleras; i++) {
		cin >> c1 >> c2;
		casillas_escaleras[c1 - 1] = c2 - 1;
	}
	
	nodosPorVisitar.push({ 0,0 });
	
	int caminoMinimo = numeric_limits<int>::max();
	
	while (!nodosPorVisitar.empty()) {
		auto nodoActual = nodosPorVisitar.top();
		nodosPorVisitar.pop();
		
		//cout << "Visiting " << nodoActual.first << " with cost " << nodoActual.second << '\n';
		tablero[nodoActual.first] = true;
		if (nodoActual.second >= caminoMinimo)
			break;
		
		else if(nodoActual.first == vertices - 1)
			caminoMinimo = nodoActual.second;
		
		for (int i = 1; i <= dado && nodoActual.first + i <= vertices - 1; i++) {
			//cout << " - now checking " << nodoActual.first + i << '\n';
			if (tablero[nodoActual.first + i]) 
				continue; // Ya hemos estado por aquí
			
			if (casillas_escaleras[nodoActual.first + i] != -1) // Yuju! una escalera
				nodosPorVisitar.push({ casillas_escaleras[nodoActual.first + i], nodoActual.second + 1  });
			
			else if (casillas_serpientes[nodoActual.first + i] != -1) // No nos gustan las serpientes, pero podrían sernos beneficiosas
				nodosPorVisitar.push({ casillas_serpientes[nodoActual.first + i], nodoActual.second + 1});
			
			else if (nodoActual.first + i == vertices - 1) { // hemos llegado al final 
				nodosPorVisitar.push({ nodoActual.first + i, nodoActual.second + 1 });
			
			else  // no era una escalera, ni una serpiente, ni el final, ni hemos estado aún... Es una baldosa aburrida
				nodosPorVisitar.push({ nodoActual.first+i, nodoActual.second + 1});
			
			tablero[nodoActual.first + i] = true;
		}
	}
	cout << caminoMinimo << '\n';

}

int main() {
	int N, K, S, E;
	
	cin >> N >> K >> S >> E;
	
	while (N != 0) { 
		procesar(N*N, K, S, E);
		cin >> N >> K >> S >> E;
	}
	
	return 0;
}