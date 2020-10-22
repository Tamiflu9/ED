// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iomanip>
#include <fstream>
#include <iostream>
#include "list_eda.h"

using namespace std;

/*
Como los numeros ya estan ordenados de mayor a menos segun su valor absoluto
cuando encontremos un numero negativo lo insertamos por delante 
y cuando hay un numero positivo lo insertamos por detras
*/

bool resuelveCaso() {
	// leer los datos de la entrada

	list<int> lista;
	int n, elem, i = 0;

	cin >> n;

	if (n == 0) {
		return false;
	}

	while (i < n) {
		cin >> elem;

		if (elem > 0) {
			lista.push_back(elem);
		}
		else {
			lista.push_front(elem);
		}

		i++;
	}

	auto it = lista.begin();

	while (it != lista.end()) {
		cout << *it << ' ';
		++it;
	}

	cout << endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso());


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}