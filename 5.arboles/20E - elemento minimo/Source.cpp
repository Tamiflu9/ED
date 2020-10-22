// Nombre del alumno: TAMARA HUERTAS SMOLIS
// Usuario del Juez: A78

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "bintree_eda.h"

using namespace std;

template<class T>
T minimo(bintree<T> const &a) {
	if (a.left().empty() && a.right().empty()) {
		return a.root();
	}
	else {
		T m = a.root();
		if (!a.left().empty()) {
			T aux = minimo(a.left());
			m = std::min(m, aux);
		}
		if (!a.right().empty()) {
			T aux = minimo(a.right());
			m = std::min(m, aux);
		}
		
		return m;
	}
}

bool resuelveCaso() {
	char tipo;

	std::cin >> tipo;
	if (!std::cin)
		return false;

	if (tipo == 'P') {
		bintree<string> arbol = leerArbol(std::string("#"));
		std::cout << minimo(arbol) << std::endl;
	}
	else if (tipo == 'N') {
		bintree<int> arbol = leerArbol(-1);
		std::cout << minimo(arbol) << std::endl;
	}

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



