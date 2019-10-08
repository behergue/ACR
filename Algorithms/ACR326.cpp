// Beatriz Herguedas Pinedo

//  ConjuntosDisjuntos.h
//
//  Implementación de estructuras de partición o conjuntos disjuntos
//  con unión por tamaño y compresión de caminos
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2015-2018  Alberto Verdejo
//

#ifndef CONJUNTOSDISJUNTOS_H_
#define CONJUNTOSDISJUNTOS_H_

#include <vector>
#include <iostream>
#include <algorithm>

class ConjuntosDisjuntos {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	ConjuntosDisjuntos(int N) : maximo(1), nelems(N), ncjtos(nelems), id(nelems, -1) {}

	// devuelve el número de conjuntos disjuntos
	int num_cjtos() const { return ncjtos; }

	//  devuelve el identificador del conjunto que contiene a p
	int buscar(int p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = buscar(id[p]);
	}

	// unir los conjuntos que contengan a p y q
	void unir(int p, int q) {
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) return;
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = int(i);
			if (tam(p) > maximo)
				maximo = tam(p);
		}
		else {
			id[j] += id[i]; id[i] = int(j);
			if (tam(q) > maximo)
				maximo = tam(q);
		}
		--ncjtos;
		
	}

	int tam(int p) const {
		return -id[buscar(p)];
	}

	bool unidos(int p, int q) const {
		return buscar(p) == buscar(q);
	}

	int conjuntoMax() {
		return maximo;
	}

protected:
	int maximo;
	int nelems;           // los elementos son 0 .. nelems-1
	int ncjtos;           // número de conjuntos disjuntos
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i

};


#endif
//
//  Matriz.h
//
//  Implementación de matrices (arrays bidimensionales)
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Created by Alberto Verdejo on 26/6/15.
//  Copyright (c) 2015 Alberto Verdejo. All rights reserved.
//

#ifndef MATRIZ_H
#define MATRIZ_H

#include <cstddef>  // size_t
#include <vector>

template <typename Object>
class Matriz {
public:
	// crea una matriz con fils filas y cols columnas,
	// con todas sus celdas inicializadas al valor e
	Matriz(size_t fils, size_t cols, Object e = Object()) : datos(fils, std::vector<Object>(cols, e)) {}

	// operadores para poder utilizar notación M[i][j]
	std::vector<Object> const& operator[](size_t f) const {
		return datos[f];
	}
	std::vector<Object> & operator[](size_t f) {
		return datos[f];
	}

	// métodos que lanzan una excepción si la posición no existe
	Object const& at(size_t f, size_t c) const {
		return datos.at(f).at(c);
	}
	Object & at(size_t f, size_t c) { // este método da problemas cuando Object == bool
		return datos.at(f).at(c);
	}

	size_t numfils() const { return datos.size(); }
	size_t numcols() const { return numfils() > 0 ? datos[0].size() : 0; }

	bool posCorrecta(int f, int c) const {
		return 0 <= f && f < numfils() && 0 <= c && c < numcols();
	}

private:
	std::vector<std::vector<Object>> datos;
};

#endif


#include <algorithm>
#include <assert.h>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool resuelveCaso() {
	int N, M, K, n, x, y, fila, col;
	stack<pair<int, int>> pila;
	bool hecho = false;

	cin >> N >> M >> K >> n;

	if (!std::cin)
		return false;

	M++;
	N++;

	ConjuntosDisjuntos espana(N * M);
	Matriz<bool> matris(N, M);

	matris[0][0] = true;
	matris[N - 1][M - 1] = true;

	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		pila.push({ x, y });
	}

	while (!pila.empty() && !hecho) {

		fila = pila.top().first;
		col = pila.top().second;

		if (!hecho) {
			for (int j = -K; j < K + 1; j++) {
				if (!hecho) {
					for (int l = -K; l < K + 1; l++) {

						if (sqrt(j*j + l * l) <= K && matris.posCorrecta(fila + j, col + l) && matris[fila + j][col + l])
							espana.unir(fila * M + col, (fila + j) * M + col + l);

						if (espana.unidos(0, N * M - 1))
							hecho = true;
					}
				}
			}
		}

		matris[fila][col] = true;
		pila.pop();
	}
	if (!hecho)
		cout << "NUNCA SE PUDO\n";

	else
		cout << fila << " " << col << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}