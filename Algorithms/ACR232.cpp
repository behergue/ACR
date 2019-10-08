// Beatriz Herguedas Pinedo

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

struct tFecha {
	int dia, mes, anio;
};

bool operator==(tFecha const &fecha1, tFecha const &fecha2) {
	 return fecha1.mes == fecha2.mes && fecha1.dia == fecha2.dia;
}

int noCumpleanos(tFecha &nacimiento, tFecha &hoy) {

	vector<int> diasMes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int dias = 0;
	
	if (nacimiento == hoy)
		dias = 0;

	else {
		if (nacimiento.anio == hoy.anio) {

			if (nacimiento.mes == hoy.mes)
				dias =  hoy.dia - nacimiento.dia;

			else {
				dias += diasMes[nacimiento.mes - 1] - nacimiento.dia;
				for (int i = nacimiento.mes; i < hoy.mes - 1; i++) {
					dias += diasMes[i];
				}

				dias += hoy.dia;
			}
		}

		else {
				dias += diasMes[nacimiento.mes - 1] - nacimiento.dia;

				for (int i = nacimiento.mes; i < diasMes.size(); i++){
					dias += diasMes[i];
				}

				dias += 364 * (hoy.anio - nacimiento.anio - 1);

				for (int i = 0; i < hoy.mes - 1; i++) {
					dias += diasMes[i];
				}

				dias += hoy.dia;

				if (hoy.mes > nacimiento.mes || hoy.mes == nacimiento.mes && hoy.dia > nacimiento.dia)
					dias--;
		}
	}

	return dias;
}

bool resuelveCaso() {
	tFecha nacimiento, hoy;

	cin >> nacimiento.dia >> nacimiento.mes >> nacimiento.anio >> hoy.dia >> hoy.mes >> hoy.anio;

	if (nacimiento.dia == 0 && nacimiento.mes == 0 && nacimiento.anio == 0 && hoy.dia == 0 && hoy.mes == 0 && hoy.anio == 0)
		return false;

	int sol = noCumpleanos(nacimiento, hoy);

	cout << sol << '\n';

	return true;

}

int main() {

	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso())

	return 0;
}