// Beatriz Herguedas Pinedo

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool resuelveCaso(int numElems);
bool siemprePremio(vector<int> const& v, int indiceIni, int indiceFin, int &minimo, int &maximo);

int main()
{
	int numElems;

	cin >> numElems;

	while (cin)
	{
		if (resuelveCaso(numElems))
			cout << "SIEMPRE PREMIO\n";

		else
			cout << "ELEGIR OTRA\n";

		cin >> numElems;
	}
	return 0;
}

bool resuelveCaso(int numElems)
{
	vector<int> v;
	int aux, aux2;

	for (int i = 0; i < numElems; i++)
	{
		cin >> aux;
		v.push_back(aux);
	}

	return siemprePremio(v, 0, numElems, aux, aux2);
}


bool siemprePremio(vector<int> const& v, int indiceIni, int indiceFin, int &minimo, int &maximo)
{
		maximo = v[indiceIni]; int indiceMax = indiceIni;
		minimo = v[indiceIni];

		for (int i = indiceIni + 1; i < indiceFin; i++)
		{
			if (v[i] > maximo) { maximo = v[i]; indiceMax = i; }
			if (v[i] < minimo)  minimo = v[i];
		}

		if (indiceFin - indiceIni < 3)	return true;
		else
		{
			int maxDcha, maxIzq, minDcha, minIzq;
			
			if (indiceIni == indiceMax)
				return siemprePremio(v, indiceMax + 1, indiceFin, minDcha, minIzq);
			else if (indiceMax + 1 == indiceFin)
				return siemprePremio(v, indiceIni, indiceMax, minIzq, maxIzq);
			else
				return siemprePremio(v, indiceIni, indiceMax, minIzq, maxIzq)       &&
				       siemprePremio(v, indiceMax + 1, indiceFin, minDcha, maxDcha) &&
				       minIzq >= maxDcha;
		}
}