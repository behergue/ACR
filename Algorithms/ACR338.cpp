// Beatriz Herguedas Pinedo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include<string>
#include <unordered_map>
#include <map>

using namespace std;

bool resuelveCaso() {
	unordered_map<int, int> exams, pillados;
	vector<int> v;
	int numExams, numRecuerda, valor;
	int  copiotas = 0;
	int cont = 0;
	int pilladitos = 0;

	cin >> numExams;

	if (!std::cin)
		return false;

	cin >> numRecuerda;

	for (int i = 0; i < numExams; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	for (int i = 0; i < numExams; i++) {
		valor = v[i];
		auto it = exams.find(valor);

		if (it == exams.end()) {
			exams.insert({ valor, 1 });
		}

		else {
			it->second++;
			copiotas++;
		}

		auto it2 = pillados.find(valor);

		if (it2 != pillados.end()) {
			pilladitos++;
		}

		if (cont < numRecuerda) {
			cont++;
		}

		else {
			auto it3 = pillados.find(v[i - numRecuerda]);

			it3->second--;

			if (it3->second == 0) {
				pillados.erase(it3);
			}
		}

		it2 = pillados.find(valor);

		if (it2 == pillados.end()) {
			pillados.insert({ valor, 1 });
		}

		else {
			it2->second++;
		}
	}

	cout << copiotas << ' ' << pilladitos << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}