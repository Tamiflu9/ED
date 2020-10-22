// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "bintree_eda.h"

using namespace std;

struct tsol {
	int numTramos;
	int caudal;
};

tsol resolver(bintree<int> const& a) {

	if (a.empty()) {
		return { 0, 0 };
	}

	if (a.left().empty() && a.right().empty()) {
		return { 0, 1 };
	}
	
	tsol iz = resolver(a.left());
	tsol dr = resolver(a.right());
	
	int c = iz.caudal + dr.caudal - a.root();

	if (c < 0) {
		c = 0;
	}

	if (iz.caudal >= 3) {
		iz.numTramos++;
	}
	if (dr.caudal >= 3) {
		dr.numTramos++;
	}

	return { iz.numTramos + dr.numTramos, c };

	
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	bintree<int> arbol = leerArbol(-1);
	tsol sol = resolver(arbol);

	cout << sol.numTramos << endl;
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