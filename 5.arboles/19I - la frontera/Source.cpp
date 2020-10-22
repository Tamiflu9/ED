// Nombre del alumno: TAMARA HUERTAS SMOLIS
// Usuario del Juez: A78

#include "I19.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree_ext<int> arbol = leerArbol_ext(-1);
	std::vector<int> v;
	v = arbol.frontera_ext();
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << endl;
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