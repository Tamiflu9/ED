// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

using namespace std;

struct tsol {
	int num_aSalvo;
	int num_caballeros;
};

tsol resolver(bintree<char> const& arbol, int num_monstruos) {

	if (arbol.empty()) {
		return { 0, 0 };
	}
	else {
		if (arbol.root() == 'M') {
			num_monstruos += 1;
		}

		tsol iz = resolver(arbol.left(), num_monstruos);
		tsol dr = resolver(arbol.right(), num_monstruos);

		if (arbol.root() == 'D') {
			if (num_monstruos <= iz.num_caballeros + dr.num_caballeros) {
				return { iz.num_aSalvo + dr.num_aSalvo + 1, iz.num_caballeros + dr.num_caballeros };
			}
		}
		
		if (arbol.root() == 'C') {
			return { iz.num_aSalvo + dr.num_aSalvo, iz.num_caballeros + dr.num_caballeros + 1 };
		}
		else {
			return { iz.num_aSalvo + dr.num_aSalvo, iz.num_caballeros + dr.num_caballeros };
		}
	}
}

int num_a_salvo(bintree<char> const& mapa) {
	return resolver(mapa, 0).num_aSalvo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	cout << num_a_salvo(arbol) << endl;
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