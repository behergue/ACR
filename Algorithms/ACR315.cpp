//Beatriz Herguedas Pinedo

#include <iostream>

using namespace std;

void resolver(int** datos, int& fila, int& columna, int &fils, int &cols, bool &bomba) {

	if (datos[fila][columna] > 9) {

		datos[fila][columna] -= 10;

		if (datos[fila][columna] == 4)
			bomba = true;

		else {

			int num = 0;

			for (int i = fila - 1; i < fila + 2; i++) {

				for (int j = columna - 1; j < columna + 2; j++) {

					if (0 <= i && i < fils && 0 <= j && j < cols && datos[i][j] == 14)
						num++;
				}
			}

			datos[fila][columna] = num;

			if (num == 0) {

				fila -= 2;

				for (int i = -1; i < 2; i++) {

					fila++;

					if (fila != -1 && fila != fils) {

						if (columna != 0) {

							columna--;

							resolver(datos, fila, columna, fils, cols, bomba);

							columna++;
						}

						resolver(datos, fila, columna, fils, cols, bomba);

						if (columna != cols - 1) {

							columna++;

							resolver(datos, fila, columna, fils, cols, bomba);

							columna--;
						}
					}
				}
				fila--;
			}
		}
	}
}

bool resuelveCaso() {
	int fils, cols, celdas;
	char a;

	cin >> fils;

	if (!cin)
		return false;

	cin >> cols;

	getchar();
	int ** datos = new int *[fils];

	for (int f = 0; f < fils; f++) {

		datos[f] = new int[cols];

		for (int c = 0; c < cols; c++) {

			a = getchar();

			if (a == '*')
				datos[f][c] = 14;

			if (a == '-')
				datos[f][c] = 15;
		}
		getchar();
	}


	cin >> celdas;

	int fila, columna;
	bool bomba = false;

	for (int i = 0; i < celdas; i++) {

		cin >> fila;
		fila--;

		cin >> columna;
		columna--;

		resolver(datos, fila, columna, fils, cols, bomba);
	}

	if (bomba) {
		cout << "GAME OVER\n";
	}

	else {

		for (int f = 0; f < fils; f++) {

			for (int c = 0; c < cols; c++) {

				if (datos[f][c] == 0)
					cout << "-";

				else if (datos[f][c] > 9)
					cout << "X";

				else
					cout << datos[f][c];
			}

			cout << "\n";
		}
	}

	for (int f = 0; f < fils; f++) {
		delete[] datos[f];
	}

	delete[] datos;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
