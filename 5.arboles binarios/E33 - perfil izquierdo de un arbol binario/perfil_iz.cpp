// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

using namespace std;

/*
tenemos una cola de pares para guardar ir guardando el arbol con el nivel correspondiente y 
un vector de pares para guardar la primera raiz de cada nodo del arbol que aparece en un nivel,
el que esta mas a la izquierda.
*/

using nivel = int;
using nodo = int;

vector<pair<int, int>> levelorder(bintree<int> const& a) {
	vector<pair<nodo,nivel>> levels;

	if (!a.empty()) {
		queue<pair<bintree<int>, nivel>> pendientes;

		pendientes.push({ a, 1});

		while (!pendientes.empty()) {

			//vamos sacando los arboles que hemos ido metiendo para ir analizandolos
			bintree<int> sig_arb = pendientes.front().first;
			int nivel = pendientes.front().second;

			pendientes.pop();
			
			// si somos la raiz añadimos al vector
			if (nivel == 1) {
				levels.push_back({ sig_arb.root(), nivel });
			}
			else {
				// si en el vector todavia no hay ningun elemento de ese nivel, lo metemos en el vector
				if (levels.back().second != nivel) {
					levels.push_back({ sig_arb.root(), nivel });
				}
			}

			// si el hijo izquierdo o el hijo derecho no osn vacion los añadimos para analizalos a la vuelta siguiente 
			// e incrementeamos el nivel

			if (!sig_arb.left().empty()) {
				pendientes.push({ sig_arb.left(), nivel + 1 });
			}
			
			if (!sig_arb.right().empty()) {
				pendientes.push({ sig_arb.right(), nivel + 1 });
			}

		}
	}

	return levels;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	bintree<int> arbol = leerArbol(-1);

	auto v = levelorder(arbol);

	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}

	cout << endl;
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