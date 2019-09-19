//Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>

using namespace std;

vector <vector <long long int>> operator*(vector <vector <long long int>> const& v1,
	vector <vector <long long int>> const& v2) {

	vector <vector <long long int>> u;

	u.push_back({ (v1[0][0] * v2[0][0] + v1[0][1] * v2[1][0]) % 46337,
		(v1[0][0] * v2[0][1] + v1[0][1] * v2[1][1]) % 46337 });

	u.push_back({ (v1[1][0] * v2[0][0] + v1[1][1] * v2[1][0]) % 46337,
		(v1[1][0] * v2[0][1] + v1[1][1] * v2[1][1]) % 46337 });

	return u;
};

vector <vector <long long int>> fibonacci(long long int n) {

	if (n == 1) 
		return{ { 0, 1 }, { 1, 1 } };

	else if (n == 2)
		return{ { 1, 1 }, { 1, 2 } };

	else {
		vector <vector <long long int>> mitad = fibonacci(n / 2);

		if (n % 2 == 0) 
			return mitad * mitad;

		else {
			vector <vector <long long int>> unidad = { { 0, 1 }, { 1, 1 } };
			return mitad * mitad * unidad;
		}
	}
}

bool resuelveCaso() {
	long long int n;

	cin >> n;

	if (n == 0)
		return false;

	cout << fibonacci(n)[0][1] << '\n';

	return true;
}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}