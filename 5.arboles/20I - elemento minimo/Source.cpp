// Nombre del alumno: TAMARA HUERTAS SMOLIS
// Usuario del Juez: A78

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "I20.h"

using namespace std;

bool resuelveCaso() {
	char tipo;

	std::cin >> tipo;
	if (!std::cin)
		return false;
	
	if (tipo == 'P') {
		bintree_ext<string> arbol = leerArbol_ext(string("#"));
		cout << arbol.mini() << endl;
	}
	else if (tipo == 'N') {
		bintree_ext<int> arbol = leerArbol_ext(-1);
		cout << arbol.mini() << endl;
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



