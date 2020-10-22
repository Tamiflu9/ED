// Nombre del alumno: TAMARA HUERTAS SMOLIS
// Usuario del Juez: A78

#include <iostream>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

using namespace std;

int diametro(bintree<char> const &a, int &altura) {
	// si el arbol es vacio la altura es 0 y el diametro es 0 tambien
	if (a.empty()) {
		altura = 0;
		return 0;
	}
	else {
		int altIz, altDr;
		int dimIz = diametro(a.left(), altIz);
		int dimDr = diametro(a.right(), altDr);

		// la altura es la suma de del maximo entre las alturas de los hijos + 1
		altura = 1 + max(altDr, altIz);

		// el diametro es el maximo valor entre el camino mas largo que pasa por la raiz (1+altura de los hijos) 
		//o el mayor de los diametros de los hijos
		return max(1 + altIz + altDr, max(dimDr, dimIz));
	}	
}

int diametro(bintree<char> const &arbol) {
	int altura;
	return diametro(arbol, altura);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	std::cout << diametro(arbol) << std::endl;
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