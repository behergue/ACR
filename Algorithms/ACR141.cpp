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

bool resuelveCaso() {
	stack<char> pila;
	string expresion;
	vector<char> v;
	bool ok = true;
	int cont = 0;

	getline(cin, expresion);

	if (!std::cin)
		return false;

	for (char c : expresion)
		v.push_back(c);

	int i = 0;
	while (ok && i < v.size()) {

		if (v[i] == '(' || v[i] == '[' || v[i] == '{')
			pila.push(v[i]);

		else if (v[i] == ')') {
			if (!pila.empty() && pila.top() == '(')
				pila.pop();

			else
				ok = false;
		}

		else if (v[i] == ']') {
			if (!pila.empty() && pila.top() == '[')
				pila.pop();

			else
				ok = false;
		}

		else if (v[i] == '}') {
			if (!pila.empty() && pila.top() == '{')
				pila.pop();

			else
				ok = false;
		}

		i++;
	}

	if (!pila.empty())
		ok = false;

	if (ok)
		cout << "YES\n";

	else
		cout << "NO\n";

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}