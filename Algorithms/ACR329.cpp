//Beatriz Herguedas Pinedo

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

bool resuelveCaso() {
	int N, W, E;
	vector<pair<int, int>> v;

	cin >> N;

	if (N == 0)
		return false;

	for (int i = 0; i < N; i++) {
		cin >> W >> E;
		v.push_back({ W, E });
	}

	sort(v.begin(), v.end());

	pair<int, int> ini = v[0];
	int cont = 1, iniInt = v[0].first, iniFin = v[0].second;

	for (int i = 1; i < v.size(); i++) {
		if (iniFin > v[i].first) {
			iniInt = v[i].first;
			iniFin = min(iniFin, v[i].second);
		}
		else {
			cont++;
			iniInt = v[i].first;
			iniFin = v[i].second;
		}
	}

	cout << cont << '\n';

	return true;

}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());

	return 0;
}