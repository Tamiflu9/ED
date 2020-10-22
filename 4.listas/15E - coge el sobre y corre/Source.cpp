// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include "list_eda.h"

#include <iostream>
#include <iomanip>
#include <fstream>

void dinero(list<int> &l, int k) {
	// si hay elementos en la lista
	if (l.size() > 0 ) {
		// si solo hay un comensal (el presidente) de volvemos cada elemento
		list<int>::iterator it = l.begin();
		if (k == 1) {
			std::cout << *it << " ";
		}
		else {
			int i = 0;
			list<int>::iterator max;
			// nos guardamos el puntero al siguiente elemento si el iterador no ha llegado al final de la lista
			if (*it == l.back()) {
				max = it;
			}
			else {
				max = ++it;
			}
			// vamos comparando el iterador y el max, y vamos actualizando el elemento mas grande en ese intervalo de k numeros (comensales)
			while (i < k - 1) {
				if (*it > *max) {
					max = it;
				}
				// avanzamos el iterador si no hemos llegado al final de la lista
				++it;
				++i;
			}
			// mostramos el elemento mas grande de ese intervalo de k numeros
			std::cout << *max << " ";
		}
		// eliminamos el primer elemento de la lista
		l.pop_front();
		// llamamos a la funcion con la nueva lista, sin el primer elemento
		dinero(l, k);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, k, v;
	list<int> l;
	std::cin >> n;
	std::cin >> k;

	if (n == 0 && k == 0)
		return false;

	for (int i = 0; i < n; i++) {
		std::cin >> v;
		l.push_back(v);
	}
	dinero(l, k);
	std::cout << std::endl;
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