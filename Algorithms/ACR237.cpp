//Beatriz Herguedas Pinedo

#include <iostream>
#include <string>

using namespace std;

bool poliDivisible(long long int num, int tam) {

	if (tam == 1)
		return true;

	else if (num % tam == 0) 
		return poliDivisible(num / 10, tam - 1);

	else 
		return false;
}

bool resuelveCaso() {
	long long int num;
	string numero;

	cin >> num;

	if (!std::cin)
		return false;
	
	numero = to_string(num);

	if (poliDivisible(num, numero.size()))
		cout << "POLIDIVISIBLE\n";

	else 
		cout << "NO POLIDIVISIBLE\n";

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}