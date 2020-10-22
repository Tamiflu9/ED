// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include "list_eda.h"
#include <iostream>
#include <iomanip>
#include <fstream>

int afortunado(int n, int s) {
	list<int> l;
	list<int>::iterator it;
	
	// introducimos los alumnso en la lista
	for (int i = 0; i < n; i++) {
		l.push_back(i+1);
	}

	// igualamos el iterador al primer elemento de la lista
	it = l.begin();

	// mientras que haya mas de 1 alumno
	while (l.size() > 1) {
		int j = 0;
		// avanzamos el iterador el numero de saltos correspondiente
		while (j < s) {
			// si estamos en al final de la lista, volvemos a hacer que el iterador apunte al principio
			// si no, solo avanzamos
			if (*it == l.back()) {
				it = l.begin();
			}
			else {
				++it;
			}
			j++;
		}
		// si estamos en al final de la lista, borramos el elemento y volvemos a hacer que el iterador apunte al principio 
		// si no, solo borramos
		if (*it == l.back()) {
			it = l.erase(it);
			it = l.begin();
		}
		else {
			it = l.erase(it);
		}
	}
	// devolvemos el elemento apuntado por el iterador
	return *it;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, s;
	std::cin >> n;
	std::cin >> s;

	if (n == 0 && s == 0)
		return false;

	std::cout << afortunado(n, s) << std::endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}