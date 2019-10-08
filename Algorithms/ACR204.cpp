// Beatriz Herguedas Pinedo

#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

template <class T>
class bintree {
protected:
	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y punteros al hijo izquierdo y derecho, que pueden ser
	nullptr si el hijo es vacío (no existe).
	*/
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r) : elem(e), left(l), right(r) {};
		T elem;
		Link left, right;
	};

	// puntero a la raíz del árbol
	Link raiz;

	// constructora privada
	bintree(Link const& r) : raiz(r) {}

private:
	int altura(Link const& raiz) {

		if (raiz == nullptr)
			return 0;

		else
			return max(altura1(raiz->left), altura1(raiz->right)) + 1;
	}

	int numNodos(Link const& raiz) {

		if (raiz == nullptr)
			return 0;

		else
			return numNodos1(raiz->left) + numNodos1(raiz->right) + 1;

	}

	int numHojas(Link const& raiz) {

		if (raiz == nullptr)
			return 0;

		else if (raiz->right == nullptr && raiz->left == nullptr)
			return 1;

		else if (raiz->right == nullptr)
			return numHojas1(raiz->left);

		else if (raiz->left == nullptr)
			return numHojas1(raiz->right);

		else
			return numHojas1(raiz->right) + numHojas1(raiz->left);

	}

	void mostrar(Link const& raiz) {

		if (raiz == nullptr) {
			cout << -1 << ' ';
		}

		else {
			cout << raiz->elem << ' ';
			mostrar(raiz->left);
			mostrar(raiz->right);
		}
	}

	void sumar(Link & raiz, Link const& raiz2) {

		if (raiz == nullptr) {
			raiz = raiz2;
		}

		else {
			if (raiz2 != nullptr) {
				raiz->elem = raiz->elem + raiz2->elem;
				sumar(raiz->left, raiz2->left);
				sumar(raiz->right, raiz2->right);
			}
		}
	}

public:
	// árbol vacío
	bintree() : raiz(nullptr) {}

	// árbol hoja
	bintree(T const& e) :
		raiz(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}

	// árbol con dos hijos
	bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		raiz(std::make_shared<TreeNode>(l.raiz, e, r.raiz)) {}

	// constructora por copia, operador de asignación y destructora por defecto

	// consultar si el árbol está vacío
	bool empty() const {
		return raiz == nullptr;
	}

	// consultar la raíz
	T const& root() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene raiz.");
		else return raiz->elem;
	}

	// consultar el hijo izquierdo
	bintree<T> left() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo izquierdo.");
		else return bintree<T>(raiz->left);
	}

	// consultar el hijo derecho
	bintree<T> right() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo derecho.");
		else return bintree(raiz->right);
	}


	// recorridos

	std::vector<T> preorder() const {
		std::vector<T> pre;
		preorder(raiz, pre);
		return pre;
	}

	std::vector<T> inorder() const {
		std::vector<T> in;
		inorder(raiz, in);
		return in;
	}

	std::vector<T> postorder() const {
		std::vector<T> post;
		postorder(raiz, post);
		return post;
	}

	std::vector<T> levelorder() const {
		std::vector<T> levels;
		if (!empty()) {
			std::queue<Link> pendientes;
			pendientes.push(raiz);
			while (!pendientes.empty()) {
				Link sig = pendientes.front();
				pendientes.pop();
				levels.push_back(sig->elem);
				if (sig->left != nullptr)
					pendientes.push(sig->left);
				if (sig->right != nullptr)
					pendientes.push(sig->right);
			}
		}
		return levels;
	}

	int altura() {
		return altura(raiz);
	}

	int numNodos() {
		return numNodos(raiz);
	}

	int numHojas() {
		return numHojas(raiz);
	}

	void mostrar() {
		mostrar(raiz);
		cout << '\n';
	}

	void sumar(bintree<int> const& arbol2) {
		sumar(raiz, arbol2.raiz);
	}


protected:
	static void preorder(Link a, std::vector<T> & pre) {
		if (a != nullptr) {
			pre.push_back(a->elem);
			preorder(a->left, pre);
			preorder(a->right, pre);
		}
		else {
			pre.push_back(-1);
		}
	}

	static void inorder(Link a, std::vector<T> & in) {
		if (a != nullptr) {
			inorder(a->left, in);
			in.push_back(a->elem);
			inorder(a->right, in);
		}
	}

	static void postorder(Link a, std::vector<T> & post) {
		if (a != nullptr) {
			postorder(a->left, post);
			postorder(a->right, post);
			post.push_back(a->elem);
		}
	}

public:
	// iterador que recorre el árbol en inorden
	class const_iterator {
	public:
		T const& operator*() const {
			if (ptr == nullptr) throw std::out_of_range("fuera del arbol");
			return ptr->elem;
		}

		T const* operator->() const {
			return &operator*();
		}

		bool operator==(const_iterator const& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const_iterator const& other) const {
			return !(*this == other);
		}

		const_iterator & operator++() {  // ++ prefijo
			next();
			return *this;
		}

	private:
		friend class bintree;
		Link ptr;
		std::stack<Link> ancestros;

		// constructores privados
		const_iterator() : ptr(nullptr) {}
		const_iterator(Link raiz) { ptr = first(raiz); }

		Link first(Link act) {
			if (act == nullptr) {
				return nullptr;
			}
			else {
				while (act->left != nullptr) {
					ancestros.push(act);
					act = act->left;
				}
				return act;
			}
		}

		void next() {
			if (ptr == nullptr) {
				throw std::range_error("El iterador no puede avanzar");
			}
			else if (ptr->right != nullptr) { // primero del hijo derecho
				ptr = first(ptr->right);
			}
			else if (ancestros.empty()) { // hemos llegado al final
				ptr = nullptr;
			}
			else { // podemos retroceder
				ptr = ancestros.top();
				ancestros.pop();
			}
		}

	};

	const_iterator begin() const {
		return const_iterator(raiz);
	}
	const_iterator end() const {
		return const_iterator();
	}
};

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree<T> leerArbol(T punto, T bola) {
	T raiz;
	std::cin >> raiz;

	if (!cin) return {};

	else {
		if (raiz == punto) { // es un árbol vacío
			return { punto };
		}

		else if (raiz == bola) {
			return{ bola };
		}


		else { // leer recursivamente los hijos
			auto iz = leerArbol(punto, bola);
			auto dr = leerArbol(punto, bola);
			return { iz, raiz, dr };
		}
	}
}

void bienDecorado(bintree<char> const & arbol, int & numBolas, bool & ok) {

	if (arbol.empty()) {
		ok = true;
		numBolas = 0;
	}

	else {
		int bolasLeft, bolasRight;
		bool okLeft, okRight;

		bienDecorado(arbol.left(), bolasLeft, okLeft);
		bienDecorado(arbol.right(), bolasRight, okRight);

		if (okLeft && okRight && abs(bolasRight - bolasLeft) <= 1) {
			ok = true;
		}

		else {
			ok = false;
		}

		if (arbol.root() == '*') {
			numBolas = bolasRight + bolasLeft + 1;
		}

		else {
			numBolas = bolasRight + bolasLeft;
		}
	}

}

bool resuelveCaso() {
	bintree<char> arbol;
	int numBolas;
	bool ok;

	arbol = leerArbol('.', '*');

	if (!std::cin)
		return false;

	bienDecorado(arbol, numBolas, ok);

	if (ok) {
		cout << "OK" << '\n';
	}

	else {
		cout << "KO" << '\n';
	}

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}