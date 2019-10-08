Ir al contenido (saltar navegación)
Toggle navigation



¡Acepta el reto!
Estás en: Inicio Problemas Por volúmenes Volumen 3 Problema 303 Envío 345013 
 Enunciado 
 Enviar 
 Estadísticas 
 Créditos 
 Mis envíos 
¿Es un árbol AVL?
Envío 345013
Fecha 
10/09/2019, 23:52:49 (CEST)
Lenguaje del envío 
C++
Veredicto 
Accepted (AC) 
Tiempo 
1.424 segs.
Memoria 
2400 KiB
Posición 
29 (en el momento de hacer el envío)
Comentario 
0/500
 
 
  Guardar 

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
// Beatriz Herguedas Pinedo

//  bintree_eda.h
//
//  Implementación de árboles binarios (con compartición de nodos)
//  con recorridos en profundidad y por niveles
//  e iterador para recorrer en inorden (basado en una pila de
//  antecesores pendientes)
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2016-2018 Alberto Verdejo
//

#ifndef bintree_eda_h
#define bintree_eda_h

#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>

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

protected:
	static void preorder(Link a, std::vector<T> & pre) {
		if (a != nullptr) {
			pre.push_back(a->elem);
			preorder(a->left, pre);
			preorder(a->right, pre);
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
		// construye el iterador al primero
		const_iterator(Link raiz) { ptr = first(raiz); }

		// construye el iterador al último
		const_iterator() : ptr(nullptr) {}

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
inline bintree<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return { iz, raiz, dr };
	}
}

#endif // bintree_eda_h

//MARP10, Beatriz Herguedas Pinedo

#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

bool AVL(bintree<int> const & arbol, int & altura, int & maxim, int & minim) {

	if (arbol.empty()) {
		altura = 0;
		return true;
	}

	else if (arbol.left().empty() && arbol.right().empty()) {
		altura = 1;
		maxim = arbol.root();
		minim = arbol.root();
		return true;
	}

	else if (arbol.right().empty()) {

		int alturaIzq, maxIzq, minIzq;
		bool AVLIzq;

		AVLIzq = AVL(arbol.left(), alturaIzq, maxIzq, minIzq);

		altura = alturaIzq + 1;
		minim = min(minIzq, arbol.root());
		maxim = max(maxIzq, arbol.root());

		if (AVLIzq && alturaIzq < 2 && arbol.root() > maxIzq)
			return true;

		else
			return false;
	}

	else if (arbol.left().empty()) {

		int alturaDcha, maxDcha, minDcha;
		bool AVLDcha;

		AVLDcha = AVL(arbol.right(), alturaDcha, maxDcha, minDcha);

		altura = alturaDcha + 1;
		minim = min(maxDcha, arbol.root());
		maxim = max(maxDcha, arbol.root());

		if (AVLDcha && alturaDcha < 2 && arbol.root() < minDcha)
			return true;

		else
			return false;
	}

	else {
		int alturaIzq, alturaDcha;
		int maxIzq, maxDcha;
		int minIzq, minDcha;
		bool AVLIzq, AVLDcha;

		AVLIzq = AVL(arbol.left(), alturaIzq, maxIzq, minIzq);
		AVLDcha = AVL(arbol.right(), alturaDcha, maxDcha, minDcha);

		altura = max(alturaIzq, alturaDcha) + 1;
		minim= min(min(minIzq, minDcha), arbol.root());
		maxim = max(max(maxIzq, maxDcha), arbol.root());


		if (AVLIzq && AVLDcha && abs(alturaIzq - alturaDcha) < 2
			&& arbol.root() > maxIzq && arbol.root() < minDcha)
			return true;

		else
			return false;
	}
}


void resuelveCaso() {
	bintree<int> arbol;
	int altura, maxim, minim;

	arbol = leerArbol(-1);

	if (AVL(arbol, altura, maxim, minim))
		cout << "SI\n";

	else
		cout << "NO\n";
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