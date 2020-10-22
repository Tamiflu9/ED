// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"
#include "queue_eda.h"

//de cada arbol guardamos el link y el nivel
struct tsol{
	bintree<int> link;
	int nivel;
};

// para saber si los nodos son numeros primos
bool es_primo(int num) {
	int ndivisores = 0, i = 1;
	if (num == 1 || num == 0){
		return false;
	}
	while(i <= num){
		if (num % i == 0) {
			ndivisores++;
			i++;
		}
		else {
			i++;
		}
	}	
	if (ndivisores == 2) {
		return true;
	}
	else {
		return false;
	}
}

// busqueda en anchura (iterativo)
void barrera(bintree<int> const&a) {
	bool encontrado = false; // si hemos encontrado un multiplo de 7
	int cercano = 0; int profundidad = 0;
	
	// se empieza el recorrido si el arbol no esta vacio y si la raiz no es un numero primo para que sea un camino accesible
	if (!a.empty() && !es_primo(a.root())) {

		queue<struct tsol> cola; // cola de structs
		tsol raiz; 

		// como la raiz es accesible la añadimos a la cola
		raiz.link = a; raiz.nivel = 1;
		cola.push(raiz);

		// mientras que no hayamos encontrado el elemento mas cercano multiplo de 7 
		// o la cola siga llena, seguimos
		while (!encontrado && !cola.empty()) {

			// consultamos si el primer elemento de la cola y lo sacamos
			//  y si el elemento es multiplo de 7 hemos acabado
			tsol aux = cola.front(); cola.pop();
		
			if (aux.link.root() % 7 == 0) {
				encontrado = true;
				cercano = aux.link.root(); profundidad = aux.nivel;
			}
			else { 
				// nos guardamos en la cola los caminos que son accesibles del hijo izquierdo y del derecho
				tsol iz; 
				iz.link = aux.link.left(); iz.nivel = aux.nivel + 1;
				if (!iz.link.empty() && !es_primo(iz.link.root())) {
					cola.push(iz);
				}

				tsol dr;
				dr.link = aux.link.right(); dr.nivel = aux.nivel + 1;
				if (!dr.link.empty() && !es_primo(dr.link.root())) {
					cola.push(dr);
				}

			}
		}
	}

	if (encontrado) {
		std::cout << cercano << " " << profundidad << std::endl;
	}
	else {
		std::cout << "NO HAY" << std::endl;
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() { // linel en el numero de nodos
	bintree<int> arbol = leerArbol(-1);
	barrera(arbol);
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