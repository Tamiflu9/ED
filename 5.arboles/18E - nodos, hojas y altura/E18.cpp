// Nombre del alumno: TAMARA HUERTAS SMOLIS
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

#include "bintree_eda.h"


int numNodos(bintree<char> const &a) {
	if (a.empty()) {
		return 0;
	}
	else {
		return numNodos(a.left()) + numNodos(a.right()) + 1;
	}
}

int numHojas(bintree<char> const &a) {
	if (a.empty()) {
		return 0;
	}
	else if (a.left().empty() && a.right().empty()) {
		return 1;
	}
	else {
		return numHojas(a.left()) + numHojas(a.right());
	}
}

int altura(bintree<char> const &a) {
	if (a.empty()) {
		return 0;
	}
	else {
		return std::max(altura(a.left())+1, altura(a.right())+1);
	}

}

void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	std::cout << numNodos(arbol) << ' ' << numHojas(arbol) << ' ' << altura(arbol) << std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}