//Beatriz Herguedas Pinedo

#include <iostream>
#include <fstream>

using namespace std;

void conversion(int num) {

	if (num / 6 == 0) {
		cout << num;
	}

	else if (num / 6 <= 5) {
		cout << num / 6 << num % 6;
	}

	else {
		conversion(num / 6);
		cout << num % 6;
	}
}


void resuelveCaso() {
	int num;

	cin >> num;

	conversion(num);

	cout << '\n';
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