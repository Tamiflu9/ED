// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

using namespace std;

struct tsol {
	int num_adivinos;
	int num_pares;
};

tsol resolver(bintree<int> const& a) {

	if (a.empty()) {
		return { 0, 0 };
	}

	if (a.left().empty() && a.right().empty()) {
		if (a.root() % 2 == 0) {
			return { 0, 1 };
		}
		return { 0, 0 };
	}

	tsol iz = resolver(a.left());
	tsol dr = resolver(a.right());

	if (a.root() == iz.num_pares + dr.num_pares) {
		if (a.root() % 2 == 0) {
			return { iz.num_adivinos + dr.num_adivinos + 1, iz.num_pares + dr.num_pares + 1 };

		}
		else {
			return { iz.num_adivinos + dr.num_adivinos + 1, iz.num_pares + dr.num_pares };
		}
	}
	else {
		if (a.root() % 2 == 0) {
			return { iz.num_adivinos + dr.num_adivinos, iz.num_pares + dr.num_pares + 1 };

		}
		else {
			return { iz.num_adivinos + dr.num_adivinos, iz.num_pares + dr.num_pares };
		}
	}

}

unsigned int numero_adivinos(bintree<int> const& arbol) {
	return resolver(arbol).num_adivinos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	cout << numero_adivinos(arbol) << endl;
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