//Beatriz Herguedas Pinedo

#include <iostream>

using namespace std;

int suma(int num) {
	int sum;

	if (num / 10 == 0) {
		sum = num % 10;
		cout << num;
	}

	else {
		sum = suma(num / 10) + (num % 10);
		cout << " + " << (num % 10);
	}

	return sum;
}

bool resuelveCaso() {
	int n;

	cin >> n;

	if (n < 0)
		return false;

	cout << " = " << suma(n) << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}