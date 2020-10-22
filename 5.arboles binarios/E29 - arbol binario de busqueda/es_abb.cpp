// Nombre del alumno: TAMARA HUERTAS SMOLIS
// Usuario del Juez: A78

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

template <typename T>
struct tSol {
	bool abb;
	int min, max;
};

template <typename T>
tSol<T> bus(bintree<T> const &arbol) {
	tSol<T> res;
	
	// si el arbol esta vacio, es arbol de busqueda
	if (arbol.empty()) {
		res.abb = true;
	}
	else {
		tSol<T> iz = bus(arbol.left()); // hijo izquierdo, su minimo y maximo
		tSol<T> dr = bus(arbol.right()); // hijo derecho, su minimo y maximo

		// si el arbol izquierdo es vacio, la raiz es el elemento mas pequeño del arbol
		// si no, el elemento menor del arbol es el minimo del lado izquierdo
		if (arbol.left().empty()) {
			res.min = arbol.root();
		}
		else {
			res.min = iz.min;
		}
		// si el arbol derecho es vacio, el maximo es la raiz del arbol
		// si no es el maximo elemento del hijo derecho
		if (arbol.right().empty()) {
			res.max = arbol.root();
		}
		else {
			res.max = dr.max;
		}

		// la raiz tiene que ser mayor al maximo elemento del hijo izquierdo, si el hijo izquierdo esta vacio se cumple 
		// la raiz tiene que ser menor al minimo elemento del hijo derecho, si el hijo derecho esta vacio se cumple
		bool ordenado = (arbol.left().empty() || iz.max < arbol.root()) &&
			(arbol.right().empty() || dr.min > arbol.root());

		// para que sea de busqueda tiene que ser de busqueda el hijo izquierdo y derecho y tiene que cumplir la condicion anterior
		res.abb = iz.abb & dr.abb && ordenado;
	}
	return res;
}

template <typename T>
bool busqueda(bintree<T> const &a) {
	return bus(a).abb;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	auto arbol = leerArbol(-1);
	if (busqueda(arbol)) {
		std::cout << "SI" << std::endl;
	}
	else {
		std::cout << "NO" << std:: endl;
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