// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

#include "bintree_eda.h"

bintree<int> reconstruir(std::vector<int> const&preorden,int &p, std::vector<int> const&inorden, int &i, int tope) {

	if (p == preorden.size() || inorden[i] == tope) {
		return {};
	}

	int raiz = preorden[p];
	++p;

	bintree<int> iz = reconstruir(preorden, p, inorden, i, raiz);
	++i;
	bintree<int> dr =  reconstruir(preorden, p, inorden, i, tope);

	return{ iz, raiz, dr };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string pre, in;
	getline(std::cin, pre);
	getline(std::cin, in);

	if (!std::cin)
		return false;

	int num;
	std::stringstream spre(pre);
	std::vector<int> preorden;
	while (spre >> num) {
		preorden.push_back(num);
	}
	std::stringstream sin(in);
	std::vector<int> inorden;
	while (sin >> num) {
		inorden.push_back(num);
	}

	int p = 0; int i = 0;
	auto arb = reconstruir(preorden, p, inorden, i, -1);
	auto arbpostorden = arb.postorder();
	bool primero = true;

	for (int x: arbpostorden) {
		if (!primero) std::cout << " ";
		else primero = false;
		std::cout << x;
	}

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