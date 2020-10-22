// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

using namespace std;

struct tsol {
	bool completo;
	int altura; 
	int alturaMax; 
};

tsol resolver(bintree<char> const& a) {

	if (a.empty()) {
		return {false, 0, 0};
	}

	if (a.left().empty() && a.right().empty()) {
		return {true, 1, 1};
	}

	tsol iz = resolver(a.left());
	tsol dr = resolver(a.right());
	
	return {true, min(dr.altura, iz.altura) + 1, max(max(iz.alturaMax, dr.alturaMax), min(iz.altura,dr.altura) + 1)};
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	bintree<char> arbol = leerArbol('.');
	
	tsol sol = resolver(arbol);

	cout << sol.alturaMax << endl;
	
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