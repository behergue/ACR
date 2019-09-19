//Beatriz Herguedas Pinedo

#include <iostream>

using namespace std;

int operar() {
	char c;

	cin >> c;

	if (isalnum(c)) 
		return c - '0';

	else {
		int sum1 = operar();
		int sum2 = operar();

		if (c == '+') 
			return sum1 + sum2;

		else if (c == '-') 
			return sum1 - sum2;

		else if (c == '*')
			return sum1 * sum2;

		else return 
			sum1 / sum2;
	}
}


void resuelveCaso() {
	cout << operar() << '\n';
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