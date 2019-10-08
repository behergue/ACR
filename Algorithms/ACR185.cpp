// Beatriz Herguedas Pinedo

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstddef>  
#include <utility>

using namespace std;

class ingredientes {

private:
	vector<string> si, no, odia;

public:
	ingredientes() {}

	void anadir(string ingrediente, string clave) {

		if (clave == "SI:")
			si.push_back(ingrediente);

		else
			no.push_back(ingrediente);

	}

	vector<string> noGusta() {

		for (int i = 0; i < no.size(); i++) {
			bool encontrado = false;

			for (int j = 0; j < si.size(); j++)
				if (si[j] == no[i])
					encontrado = true;

			if(odia.size() > 0)
				for (int k = 0; k < odia.size(); k++)
					if (odia[k] == no[i])
						encontrado = true;

			if (!encontrado)
				odia.push_back(no[i]);
		}

		return odia;
	}
};

bool resuelveCaso() {
	int num;
	ingredientes ingred;
	string clave, ingrediente;
	vector<string> dislike;

	cin >> num;

	if (num == 0)
		return false;

	for (int i = 0; i < num; i++) {

		cin >> clave >> ingrediente;

		while (ingrediente != "FIN") {

			ingred.anadir(ingrediente, clave);
			cin >> ingrediente;
		}
	}

	dislike = ingred.noGusta();

	sort(dislike.begin(), dislike.end());

	if (dislike.size() > 0) {
		for (int i = 0; i < dislike.size(); i++) {
			cout << dislike[i];

			if (i < dislike.size() - 1)
				cout << " ";
		}
	}

	cout << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}