//Beatriz Herguedas Pinedo

#include <iostream>

using namespace std;

long long int eleva(long long int x, int n) {

	long long int aux;

	if (n == 0) 
		return 1;

	else {

		if (n % 2 == 0) 
			return (eleva(x, n / 2) * eleva(x, n / 2)) % 31543;

		else
			return (x * eleva(x, n / 2) * eleva(x, n / 2)) % 31543;
	}
}

bool resuelveCaso() {
	long long int x;
	int n;

	cin >> x >> n;

	if (x == 0 && n == 0)
		return false;

	cout << eleva(x, n) << '\n';

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}