// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

struct tsol {

	int generaciones; // si cumple las caracteristicas de arbol genealogico
	bool genealogico; // numero de generaciones
};
tsol generaciones(bintree<int> const&arbol) {
	// si el arbol es vacio, es arbol genealogico
	if (arbol.empty()) {
		return { 0, true };
	}

	tsol izq = generaciones(arbol.left());
	// si el hijo izquierdo no cumple las caracteristicas de genealogico
	if (!izq.genealogico) {
		return { 0, false };
	}

	tsol der = generaciones(arbol.right());
	// si el hijo derecho no cumple las caracteristicas de genealogico
	if (!der.genealogico) {
		return{ 0, false };
	}

	// si el hijo izquierdo es vacio y el derecho no, no se cumplen las caracteristicas de genealogico
	if (arbol.left().empty() && !arbol.right().empty()) {
		return { 0, false };
	}
	// si el hijo derecho es vacio pero el izquierdo no
	// y cumple que es mas pequeño al menos 18 años que el padre,
	// entonces se cumplen las caracteristicas de genealogico
	else if (!arbol.left().empty() && arbol.right().empty()) {
		if (arbol.root() >= arbol.left().root() + 18) {
			return { izq.generaciones + 1, true };
		}
		else {
			return { 0, false };
		}
	}
	// si los hijos no son vacios,
	// y cumple que son mas pequeños al menos 18 años que el padre
	// y que el hijo izquierdo es mas grande que el hijo derecho al menos en dos años
	// entonces se cumplen las caracteristicas de genealogico
	else if (!arbol.left().empty() && !arbol.right().empty()) {
		if (arbol.root() >= arbol.left().root() + 18 && arbol.root() >= arbol.right().root() + 18) {
			if (arbol.left().root() >= arbol.right().root() + 2) {
				return { std::max(izq.generaciones, der.generaciones) + 1, true };
			}
			else {
				return { 0, false };
			}
		}
		else {
			return { 0, false };
		}
	}
	else {
		return { 1, true };
	}

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);

	tsol sol = generaciones(arbol);

	if (sol.genealogico) {
		std::cout << "SI" << ' ' << sol.generaciones << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
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