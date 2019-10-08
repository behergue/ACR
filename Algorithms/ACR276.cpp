// Beatriz Herguedas Pinedo

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

class hora {

private:
	int horas, minutos;

public:

	hora() {};

	hora(int m) {
		horas = m / 60;
		minutos = m % 60;
	}

	hora(int h, int m) {

		if (h < 0 || h > 23) {
			throw domain_error("ERROR");
		}
		else {
			this->horas = h;
		}

		if (m < 0 || m > 59) {
			throw domain_error("ERROR");
		}
		else {
			this->minutos = m;
		}
	}

	int getHoras() {
		return horas;
	}

	int getMinutos() {
		return minutos;
	}

	bool operator<(hora const & h) const{

		if (this->horas < h.horas) {
			return true;
		}

		else if (this->horas == h.horas && this->minutos < h.minutos) {
			return true;
		}

		else {
			return false;
		}
	}

	bool operator==(hora const & h) {
		return this->horas == h.horas && this->minutos == h.minutos;
	}

	hora operator+(hora const & h) {

		hora suma;

		int min = this->minutos + h.minutos;
		suma.minutos = min % 60;

		int hor = this->horas + h.horas + min / 60;

		suma.horas = hor;

		return suma;
	}
};

inline istream &operator>>(istream & in, hora &h) {
	int hh, mm;
	char aux;

	in >> hh >> aux >> mm;

	h = hora(hh, mm);

	return in;
}

inline ostream &operator<<(ostream & out, hora h) {

	out << setfill('0') << setw(2) << h.getHoras() << ":" << setfill('0') << setw(2)
		<< h.getMinutos();

	return out;
}

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

int peliculas(vector<pair<hora, hora>> & v) {

	sort(v.begin(), v.end());

	int cont = 1;
	hora fin = v[0].second;
	hora descanso = hora(10);

	for (int i = 1; i < v.size(); i++) {

		if (v[i].first < fin) {
			if (v[i].second < fin)
				fin = v[i].second;
		}

		else if(fin + descanso< v[i].first || fin + descanso == v[i].first) {
			cont++;
			fin = v[i].second;
		}
	}

	return cont;
}

bool resuelveCaso() {
	int N, duracion;
	hora empieza, dur, termina;
	vector<pair<hora, hora>> v;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> empieza >> duracion;
		dur = hora(duracion);
		termina = empieza + dur;
		v.push_back({ empieza, termina });
	}

	cout << peliculas(v) << '\n';

	return true;

}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}