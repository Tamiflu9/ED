// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <algorithm>

using capitulo = int;
using pos = int;
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	std::unordered_map<capitulo, pos>::iterator it;
	std::unordered_map<capitulo, pos> dic;
	int Ncapitulos, cap;
	std::cin >> Ncapitulos;

	int maximo, p = 0;

	for (int i = 0; i < Ncapitulos; i++) {
		std::cin >> cap;

		if (dic.count(cap) && dic[cap] >= p) {
			p = dic[cap] + 1;
		}
		maximo = std::max(maximo, i - p + 1);
		dic[cap] = i;
	}

	std::cout << maximo << std::endl;
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