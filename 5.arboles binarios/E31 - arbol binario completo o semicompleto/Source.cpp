// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tsol{
	bool completo;
	bool semicompleto;
	int altura;
};

tsol semi_completo(bintree<char> const& a) {

	if (a.empty()) {
		return {true, true, 0};
	}
	else {
		tsol izq = semi_completo(a.left());
		tsol dr = semi_completo(a.right());

		if (izq.completo && dr.completo && izq.altura == dr.altura) {
			return { true, true, izq.altura+1 };
		}
		else if (izq.semicompleto && dr.completo && izq.altura == dr.altura+1) {
			return { false, true, izq.altura+1 };
		}
		else if (izq.completo && dr.semicompleto && izq.altura == dr.altura) {
			return { false, true, izq.altura+1 };
		}
		else {
			return { false, false, izq.altura };
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	bintree<char> arbol = leerArbol('.');
	tsol final = semi_completo(arbol);

	if (final.completo) {
		cout << "COMPLETO" << endl;
	}
	else if (final.semicompleto) {
		cout << "SEMICOMPLETO" << endl;
	}
	else {
		cout << "NADA" << endl;
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