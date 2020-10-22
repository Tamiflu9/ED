// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

bool simetrico(bintree<char> const&iz, bintree<char> const&dr) {

	// si los hijos estan vacios es simetrico
	if (iz.empty() && dr.empty()) {
		return true;
	}
	// si solo uno de los hijos esta vacio no es simetrico
	else if (iz.empty() || dr.empty()) {
		return false;
	}
	else {
		return (simetrico(iz.left(), dr.right()) && simetrico(iz.right(),dr.left()));
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() { 
	bintree<char> arbol = leerArbol('.');
	if (simetrico(arbol.left(), arbol.right())) {
		std::cout << "SI" << std::endl;
	}
	else {
		std::cout << "NO" << std:: endl;
	}
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