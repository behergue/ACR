// Beatriz Herguedas

#include <stdexcept>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

template <class T>
class queue {
protected:

	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente, que puede ser nullptr si
	el nodo es el último de la lista enlazada.
	*/
	struct Nodo {
		Nodo() : sig(nullptr) {} //constructor por defecto del nodo
		Nodo(T const& elem, Nodo * si = nullptr) : elem(elem), sig(si) {} //constructor
		T elem; //elemento
		Nodo * sig; //puntero que apunta al siguiente elemento
	};

	// punteros al primer y último elemento
	Nodo * prim;
	Nodo * ult;

	// número de elementos en la cola
	size_t nelems;

public:

	// constructor: cola vacía
	queue() : prim(nullptr), ult(nullptr), nelems(0) {}

	// destructor
	~queue() {
		libera();
	}

	// constructor por copia
	queue(queue<T> const& other) {
		copia(other);
	}

	// operador de asignación
	queue<T> & operator=(queue<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// añadir un elemento al final de la cola
	void push(T const& elem) {
		Nodo * nuevo = new Nodo(elem);

		if (ult != nullptr)
			ult->sig = nuevo;
		ult = nuevo;
		if (prim == nullptr) // la cola estaba vacía
			prim = nuevo;
		++nelems;
	}

	// consultar el primero de la cola
	T const& front() const {
		if (empty())
			throw std::domain_error("la cola vacia no tiene primero");
		return prim->elem;
	}

	// eliminar el primero de la cola
	void pop() {
		if (empty())
			throw std::domain_error("eliminando de una cola vacia");
		Nodo * a_borrar = prim;
		prim = prim->sig;
		if (prim == nullptr) // la cola se ha quedado vacía
			ult = nullptr;
		delete a_borrar;
		--nelems;
	}

	// consultar si la cola está vacía
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tamaño de la cola
	size_t size() const {
		return nelems;
	}

	//mostrar toda la lista
	void mostrar() {
		Nodo *cont = prim;

		for (int i = 0; i < nelems; i++) {
			cout << cont->elem;
			cont = cont->sig;
			if (i < nelems - 1)
				cout << " ";
		}
		cout << '\n';
	}

	//duplicar toda la lista
	void duplicar() {
		Nodo *cont = prim;

		for (int i = 0; i < nelems; i++) {
			Nodo *aux = new Nodo(cont->elem, cont->sig);
			cont->sig = aux;
			cont = aux->sig;
		}

		if (!empty()) {

			ult = ult->sig;

		}
		nelems = nelems * 2;
	}

	//invertir la lista
	void invertir() {

		if (!empty()) {
			Nodo * aux1 = prim;

			if (nelems > 1) {
				Nodo * aux2 = prim->sig;
				Nodo * aux3 = nullptr;
				aux1->sig = nullptr;

				for (int i = 0; i < nelems - 1; i++) {

					aux3 = aux2->sig;
					aux2->sig = aux1;
					aux1 = aux2;
					aux2 = aux3;
				}
			}

			ult = prim;
			prim = aux1;
		}
	}



	void camas(int numCamas, int numPalabras) {
		ult->sig = prim;
		Nodo * aux = prim;
		Nodo * aux2 = ult;

		while (nelems > numCamas) {
			if (numPalabras > 1) {
				for (int i = 0; i < numPalabras - 1; i++) {

					aux2 = aux;
					aux = aux->sig;
				}
			}

			if (aux == ult) {
				ult = aux2;
			}

			else if (aux == prim) {
				prim = prim->sig;
			}

			aux2->sig = aux->sig;
			delete aux;
			aux = aux2->sig;
			nelems--;
		}

		if (nelems == 1) {
			prim = aux;
			ult = aux;
		}

		ult->sig = nullptr;
	}

protected:

	void libera() {
		while (prim != nullptr) {
			Nodo * a_borrar = prim;
			prim = prim->sig;
			delete a_borrar;
		}
		ult = nullptr;
	}

	// this está sin inicializar
	void copia(queue const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			Nodo * act = other.prim; // recorre la cola original
			Nodo * ant = new Nodo(act->elem); // último nodo copiado
			prim = ant;
			while (act->sig != nullptr) {
				act = act->sig;
				ant->sig = new Nodo(act->elem);
				ant = ant->sig;
			}
			ult = ant;
			nelems = other.nelems;
		}
	}
};

void resuelveCaso() {
	queue<string> peregrinos;
	string valor;
	int numCamas, numPalabras;

	cin >> valor;

	while (valor != "F") {
		peregrinos.push(valor);
		cin >> valor;
	}

	cin >> numCamas >> numPalabras;

	if (numCamas >= peregrinos.size())
		cout << "TODOS TIENEN CAMA\n";

	else if (numCamas == 0)
		cout << "NADIE TIENE CAMA\n";

	else {

		peregrinos.camas(numCamas, numPalabras);
		peregrinos.mostrar();
	}
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