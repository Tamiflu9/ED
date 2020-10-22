// Nombre del alumno: TAMARA HUERTAS SMOLIS
// Usuario del Juez: A78

#include "I18.h"


void resuelveCaso() {
	bintree_ext<char> arbol = leerArbol_ext('.');

	std::cout << arbol.nodos() << ' ' << arbol.hojas() << ' ' << arbol.alt() << std::endl;
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