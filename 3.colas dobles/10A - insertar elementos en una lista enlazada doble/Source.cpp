// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include <iomanip>
#include <fstream>
#include "Header.h"


bool resuelveCaso() {
	// leer los datos de la entrada

	ListaInsertar<int> listaPrim;
	ListaInsertar<int> listaSec;


	int n, elem, m, i = 0;

	cin >> n;

	if (!std::cin)
		return false;

	while (i < n) {
		cin >> elem;
		listaPrim.push_back(elem);
		i++;
	}

	i = 0;

	cin >> n >> m;

	while (i < n) {
		cin >> elem;
		listaSec.push_back(elem);
		i++;
	}

	listaPrim.insertar(listaSec, m);
	
	listaPrim.print();
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