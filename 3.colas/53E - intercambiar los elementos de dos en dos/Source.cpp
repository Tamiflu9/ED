// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include <iomanip>
#include <fstream>
#include "Header.h"

/*

Coste de intercambiar elementos: coste lineal
	-> numero de vueltas igual a n/2, siendo n el numero de elementos de la lista 
		en cada vuetla del bucle se hace un numero contante de intercambios de punteros

Coste final: O(n) 

*/

bool resuelveCaso() {
	// leer los datos de la entrada

	ListaIntercambia<int> lista;

	int n, elem, i = 0;

	cin >> n;

	if (n == 0)
		return false;

	while (i < n) {
		cin >> elem;
		lista.push(elem);
		i++;
	}

	lista.intercambiar();
	
	lista.print();
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