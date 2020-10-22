// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include "Header.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int n, m, p, x;
	ListaInserta<int> lista; // lista principal
	ListaInserta<int> elem; // lista de elementos a insertar

	if (!std::cin)
		return false;

	// numero de elementos de la lista principal
	std::cin >> n; 
	// insertamos los n elementos a la lista principal
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		lista.push(x);
	}
	// numero de elementos a insertar y la posicion desde donde insertar
	std::cin >> m;
	std::cin >> p;
	// insertamos los m elementos en la lista de elem
	for (int i = 0; i < m; i++) {
		std::cin >> x;
		elem.push(x);
	}

	lista.inserta(elem, p);
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