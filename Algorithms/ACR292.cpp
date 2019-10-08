// Beatriz Herguedas Pinedo

//  GrafoDirigidoValorado.h
//
//  Implementación de grafos dirigidos valorados
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Created by Alberto Verdejo on 26/6/15.
//  Copyright (c) 2015 Alberto Verdejo. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template <typename Valor>
class AristaDirigida_impl;

template <typename Valor>
class AristaDirigida {
public:
	AristaDirigida();
	AristaDirigida(size_t v, size_t w, Valor valor);
	size_t from() const;
	size_t to() const;
	Valor valor() const;
	void print(std::ostream & o = std::cout) const;
private:
	std::shared_ptr<AristaDirigida_impl<Valor>> pimpl;
};

template <typename Valor>
inline std::ostream& operator<<(std::ostream & o, AristaDirigida<Valor> const& ar) {
	ar.print(o);
	return o;
}

template <typename Valor>
inline bool operator<(AristaDirigida<Valor> const& a, AristaDirigida<Valor> const& b)
{
	return a.valor() < b.valor();
}


template <typename Valor>
using AdysDirVal = std::vector<AristaDirigida<Valor>>;  // lista de adyacentes a un vértice

template <typename Valor>
class GrafoDirigidoValorado {
public:

	/**
	 * Crea un grafo con V vértices.
	 */
	GrafoDirigidoValorado(size_t v) : _V(v), _E(0), _adj(_V) {}

	/**
	 * Devuelve el número de vértices del grafo.
	 */
	size_t V() const { return _V; }

	/**
	 * Devuelve el número de aristas del grafo.
	 */
	size_t E() const { return _E; }

	/**
	 * Añade la arista dirigida v-w al grafo.
	 * @throws invalid_argument si algún vértice no existe
	 */
	void ponArista(AristaDirigida<Valor> arista);

	/**
	 * Comprueba si hay arista de v a w.
	 */
	bool hayArista(size_t v, size_t w) const;

	/**
	 * Devuelve la lista de adyacencia de v.
	 * @throws invalid_argument si v no existe
	 */
	AdysDirVal<Valor> const& adj(size_t v) const;

	/**
	* Devuelve el grafo dirigido inverso.
	*/
	GrafoDirigidoValorado<Valor> reverse() const;

	/**
	 * Muestra el grafo en el stream de salida o
	 */
	void print(std::ostream& o = std::cout) const;

private:
	size_t _V;   // número de vértices
	size_t _E;   // número de aristas
	std::vector<AdysDirVal<Valor>> _adj;   // vector de listas de adyacentes

};

/**
 * Para mostrar grafos por la salida estándar.
 */
template <typename Valor>
inline std::ostream& operator<<(std::ostream& o, const GrafoDirigidoValorado<Valor>& g) {
	g.print(o);
	return o;
}


// IMPLEMENTACIÓN

template <typename Valor>
AristaDirigida<Valor>::AristaDirigida()
	: pimpl(nullptr) {}

template <typename Valor>
AristaDirigida<Valor>::AristaDirigida(size_t v, size_t w, Valor valor)
	: pimpl(std::make_shared<AristaDirigida_impl<Valor>>(v, w, valor)) {}

template <typename Valor>
size_t AristaDirigida<Valor>::from() const { return pimpl->from(); }

template <typename Valor>
size_t AristaDirigida<Valor>::to() const { return pimpl->to(); }

template <typename Valor>
Valor AristaDirigida<Valor>::valor() const { return pimpl->valor(); }

template <typename Valor>
void AristaDirigida<Valor>::print(std::ostream & o) const { pimpl->print(o); }


template <typename Valor>
class AristaDirigida_impl {
public:
	AristaDirigida_impl(size_t v, size_t w, Valor valor) : v(v), w(w), _valor(valor) {};
	size_t from() const { return v; }
	size_t to() const { return w; }
	Valor valor() const { return _valor; }
	void print(std::ostream& o) const {
		o << "(" << v << ", " << w << ", " << _valor << ")";
	}
private:
	size_t v, w;
	Valor _valor;
};


template <typename Valor>
void GrafoDirigidoValorado<Valor>::ponArista(AristaDirigida<Valor> arista) {
	size_t v = arista.from();
	size_t w = arista.to();
	if (v >= _V || w >= _V) throw std::invalid_argument("Vertice inexistente");
	++_E;
	_adj[v].push_back(arista);
}

template <typename Valor>
bool GrafoDirigidoValorado<Valor>::hayArista(size_t v, size_t w) const {
	for (auto a : _adj[v])
		if (a.to() == w) return true;
	return false;
}

template <typename Valor>
AdysDirVal<Valor>  const& GrafoDirigidoValorado<Valor>::adj(size_t v) const {
	if (v >= _V) throw std::invalid_argument("Vertice inexistente");
	return _adj[v];
}

template <typename Valor>
GrafoDirigidoValorado<Valor> GrafoDirigidoValorado<Valor>::reverse() const {
	GrafoDirigidoValorado R(_V);
	for (auto v = 0; v < _V; ++v) {
		for (auto a : _adj[v]) {
			R.ponArista(AristaDirigida<Valor>(a.to(), a.from(), a.valor()));
		}
	}
	return R;
}

template <typename Valor>
void GrafoDirigidoValorado<Valor>::print(std::ostream& o) const {
	o << _V << " vértices, " << _E << " aristas\n";
	for (auto v = 0; v < _V; ++v) {
		o << v << ": ";
		for (auto a : _adj[v]) {
			o << a << " ";
		}
		o << "\n";
	}
}

//
//  IndexPQ.h
//
//  Implementación de colas con prioridad mediante montículos.
//  Los elementos son enteros de 0 a N-1 que tienen asociada una prioridad
//  dentro de la cola. La prioridad de un elemento puede ser modificada
//  con coste en O(log N).
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2015-2018  Alberto Verdejo
//

#include <iostream>
#include <stdexcept>
#include <vector>


// T es el tipo de las prioridades
// Comparator dice cuándo un valor de tipo T es más prioritario que otro
template <typename T = int, typename Comparator = std::less<T>>
class IndexPQ {
public:
	// registro para las parejas < elem, prioridad >
	struct Par {
		int elem;
		T prioridad;
	};

private:
	// vector que contiene los datos (pares < elem, prio >)
	std::vector<Par> array;     // primer elemento en la posición 1

	// vector que contiene las posiciones en array de los elementos
	std::vector<int> posiciones;   // un 0 indica que el elemento no está

	/* Objeto función que sabe comparar prioridades.
	 antes(a,b) es cierto si a es más prioritario que b */
	Comparator antes;

public:
	IndexPQ(int N, Comparator c = Comparator()) : array(1), posiciones(N, 0), antes(c) {}

	IndexPQ(IndexPQ<T, Comparator> const&) = default;

	IndexPQ<T, Comparator>& operator=(IndexPQ<T, Comparator> const&) = default;

	~IndexPQ() = default;

	// e debe ser uno de los posibles elementos
	void push(int e, T const& p) {
		if (posiciones.at(e) != 0)
			throw std::invalid_argument("No se pueden insertar elementos repetidos.");
		else {
			array.push_back({ e, p });
			posiciones[e] = array.size() - 1;
			flotar(array.size() - 1);
		}
	}

	void update(int e, T const& p) {
		int i = posiciones.at(e);
		if (i == 0) // el elemento e se inserta por primera vez
			push(e, p);
		else {
			array[i].prioridad = p;
			if (i != 1 && antes(array[i].prioridad, array[i / 2].prioridad))
				flotar(i);
			else // puede hacer falta hundir a e
				hundir(i);
		}
	}

	int size() const {
		return array.size() - 1;
	}

	bool empty() const {
		return size() == 0;
	}

	Par const& top() const {
		if (size() == 0)
			throw std::domain_error("No se puede consultar el primero de una cola vacia");
		else return array[1];
	}

	void pop() {
		if (size() == 0) throw std::domain_error("No se puede eliminar el primero de una cola vacía.");
		else {
			posiciones[array[1].elem] = 0; // para indicar que no está
			if (size() > 1) {
				array[1] = std::move(array.back());
				posiciones[array[1].elem] = 1;
				array.pop_back();
				hundir(1);
			}
			else
				array.pop_back();
		}
	}

private:

	void flotar(int i) {
		Par parmov = std::move(array[i]);
		int hueco = i;
		while (hueco != 1 && antes(parmov.prioridad, array[hueco / 2].prioridad)) {
			array[hueco] = std::move(array[hueco / 2]); posiciones[array[hueco].elem] = hueco;
			hueco /= 2;
		}
		array[hueco] = std::move(parmov); posiciones[array[hueco].elem] = hueco;
	}

	void hundir(int i) {
		Par parmov = std::move(array[i]);
		int hueco = i;
		int hijo = 2 * hueco; // hijo izquierdo, si existe
		while (hijo <= size()) {
			// cambiar al hijo derecho de i si existe y va antes que el izquierdo
			if (hijo < size() && antes(array[hijo + 1].prioridad, array[hijo].prioridad))
				++hijo;
			// flotar el hijo si va antes que el elemento hundiéndose
			if (antes(array[hijo].prioridad, parmov.prioridad)) {
				array[hueco] = std::move(array[hijo]); posiciones[array[hueco].elem] = hueco;
				hueco = hijo; hijo = 2 * hueco;
			}
			else break;
		}
		array[hueco] = std::move(parmov); posiciones[array[hueco].elem] = hueco;
	}

};

#include <algorithm>
#include <assert.h>
#include <climits>
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
	int N, C, origen, destino, esfuerzo, O, P, casa;
	bool imposible = false;

	cin >> N >> C;

	if (!std::cin)
		return false;

	GrafoDirigidoValorado<int> gIda(N + 1);
	GrafoDirigidoValorado<int> gVuelta(N + 1);
	vector<int> marcado(N + 1);

	for (int i = 0; i < C; i++) {
		cin >> origen >> destino >> esfuerzo;
		gIda.ponArista(AristaDirigida<int>(origen, destino, esfuerzo));
		gVuelta.ponArista(AristaDirigida<int>(destino, origen, esfuerzo));
	}

	cin >> O >> P;

	vector<int> distTo1(N + 1, INT_MAX);
	IndexPQ<int> pq1(N + 1);

	pq1.push(O, 0);
	distTo1[O] = 0;

	while (!pq1.empty()) {
		int b = pq1.top().elem;
		pq1.pop();

		for (AristaDirigida<int> a : gIda.adj(b)) {
			int x = a.from();
			int w = a.to();

			if (distTo1[w] > distTo1[x] + a.valor()) {
				distTo1[w] = distTo1[x] + a.valor();
				pq1.update(w, distTo1[w]);
			}
		}
	}

	vector<int> distTo2(N + 1, INT_MAX);
	IndexPQ<int> pq2(N + 1);

	pq2.push(O, 0);
	distTo2[O] = 0;

	while (!pq2.empty()) {
		int b = pq2.top().elem;
		pq2.pop();

		for (AristaDirigida<int> a : gVuelta.adj(b)) {
			int x = a.from();
			int w = a.to();

			if (distTo2[w] > distTo2[x] + a.valor()) {
				distTo2[w] = distTo2[x] + a.valor();
				pq2.update(w, distTo2[w]);
			}
		}
	}

	int cont = 0;

	for (int i = 0; i < P; i++) {

		cin >> casa;

		if (!imposible) {

			if (distTo1[casa] == INT_MAX || distTo2[casa] == INT_MAX)
				imposible = true;

			else
				cont += distTo1[casa] + distTo2[casa];
		}
	}

	if (imposible)
		cout << "Imposible\n";

	else
		cout << cont << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}