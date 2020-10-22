// Nombre del alumno: TAMARA HUERTAS SMOLIS
// Usuario del Juez: A78

#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

using namespace std;

void frontera(bintree<int> const &a){
	// si el arbol esta vacion sale
	if (a.empty()) {
		return;
	}
	else {
		// si el nodo es una hoja, mostramos el valor porque sería frontera
		if (a.left().empty() && a.right().empty()) {
			std::cout << a.root() << " " ;
		}
		// miramos los dos hijos
			frontera(a.left());
			frontera(a.right());
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	frontera(arbol);
	std::cout << endl;
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