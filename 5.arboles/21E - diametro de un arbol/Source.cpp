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
	int altura;
	int diametro;
};

tsol resolver(bintree<char> const& a) {

	if (a.empty()) {
		return { 0, 0 };
	}

	tsol iz = resolver(a.left());
	tsol dr = resolver(a.right());

	// si el camino mas largo es el que para por la raiz recorriendo los dos hijos principales
	if (dr.altura + iz.altura + 1 > dr.diametro && dr.altura + iz.altura + 1 > iz.diametro) {
		return { max(iz.altura,dr.altura) + 1, dr.altura + iz.altura + 1 };
	}

	// si el camino mas largo esta en uno de los dos hijos sin pasar por la raiz
	return { max(iz.altura,dr.altura), max(iz.diametro,dr.diametro) };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	bintree<char> arbol = leerArbol('.');
	tsol sol = resolver(arbol);

	cout << sol.diametro << endl;
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