// Beatriz Herguedas Pinedo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

struct carta{
	int num;
	char palo;
};

bool sePuedeColocar(carta cart, stack<carta> const &O, stack<carta> const &C, stack<carta> const &E, stack<carta> const &B) {

	if (cart.palo == 'O' && cart.num == O.top().num + 1 || cart.palo == 'C' && cart.num == C.top().num + 1 ||
		cart.palo == 'E' && cart.num == E.top().num + 1 || cart.palo == 'B' && cart.num == B.top().num + 1)
		return true;

	else if (cart.palo == 'O' && cart.num == 10 && O.top().num == 7 || cart.palo == 'C' && cart.num == 10 && C.top().num == 7 ||
		cart.palo == 'E' && cart.num == 10 && E.top().num == 7|| cart.palo == 'B' && cart.num == 10 && B.top().num == 7)
		return true;

	else
		return false;
}

stack<carta> averiguaPalo(carta cart, stack<carta> const &O, stack<carta> const &C, stack<carta> const &E, stack<carta> const &B) {
	if (cart.palo == 'O')
		return O;

	else if (cart.palo == 'C')
		return C;

	else if (cart.palo == 'E')
		return E;

	else if (cart.palo == 'B')
		return B;
}

void colocar(carta cart, stack<carta> &pal) {
	pal.push(cart);
}

void jugar(stack<carta> &mazo, stack<carta> &visibles, stack<carta> &O, stack<carta> &C, stack<carta> &E, stack<carta> &B) {

	while (!mazo.empty()) {

		visibles.push(mazo.top());
		mazo.pop();

		if (mazo.size() > 0) {
			visibles.push(mazo.top());
			mazo.pop();
		}

		bool sePuede = true;
		while (sePuede && !visibles.empty()) {

			if (sePuedeColocar(visibles.top(), O, C, E, B)) {

				if (visibles.top().palo == 'O')
					O.push(visibles.top());

				else if (visibles.top().palo == 'C')
					C.push(visibles.top());

				else if (visibles.top().palo == 'E')
					E.push(visibles.top());

				else if (visibles.top().palo == 'B')
					B.push(visibles.top());

				visibles.pop();
			}

			else
				sePuede = false;

		}
	}
}

bool gana(stack<carta> &mazo) {
	stack<carta> O, C, E, B, visibles;
	bool win = false, lose = false;
	carta cartaCero;
	cartaCero.num = 0;
	O.push(cartaCero);
	C.push(cartaCero);
	E.push(cartaCero);
	B.push(cartaCero);

	int num = mazo.size();

	while (!win && !lose) {

		jugar(mazo, visibles, O, C, E, B);

		if (visibles.empty())
			win = true;

		else if (visibles.size() == num)
			lose = true;

		else {
			while (!visibles.empty()) {
				mazo.push(visibles.top());
				visibles.pop();
			}
			num = mazo.size();
		}
	}

	return win;
}

bool resuelveCaso() {
	vector<carta> aux;
	stack<carta> mazo;
	int numPalos;
	carta carta;

	cin >> numPalos;

	if (numPalos == 0)
		return false;

	for (int i = 0; i < numPalos * 10; i++) {
		cin >> carta.num >> carta.palo;
		aux.push_back(carta);
	}

	for (int i = aux.size() - 1; i >= 0 ; i--) {
		mazo.push(aux[i]);
	}

	if (gana(mazo))
		cout << "GANA\n";

	else
		cout << "PIERDE\n";

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}