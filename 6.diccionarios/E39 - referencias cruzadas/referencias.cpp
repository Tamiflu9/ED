// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


/// Idea: guardamos en un map cada palabra del texto como clave y como valor para cada clave un vector de numeros con el valor 
/// de las lineas distintas donde aparece la palabra

/// coste de la funcion: O(N logN) donde N es el numero de palabras del texto
/// para cada palabra del exto hacemos un acceso al diccionario que tiene un coste logaritmico en el numero
/// de palabras distintas que hemos encontrado hast ahora. 
/// El numero de lineas no afecta, lo que afecta al coste es el numero de palabras. El tamaño del diccionario es el numero
/// de palabras distintas que tenga el texto.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
using palabra = string;

// para convertir las palabras a minusculas
void a_minusculas(string & s) {
	for (char & c : s)
		if ('A' <= c && c <= 'Z') // tolower(c) en <cctype>
			c = 'a' + (c - 'A');
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	map<palabra, vector<int>> tabla;
	int N;
	string cadena, plbr;
	getline(cin, cadena);
	stringstream ss(cadena);
	ss >> N;

	if (N == 0)
		return false;

	// i = cada linea del caso de prueba
	for (int i = 1; i < N+1; i++) {

		getline(cin, cadena);
		stringstream ss(cadena);
		ss >> plbr;

		// da una vuelta por cada palabra de la linea
		while (ss) {

			// comprobamos que la palabra tenga mas de 2 letras
			if (plbr.length() > 2) {

				// convertimos cada letra a minuscula con la funcion a_minuscula
				a_minusculas(plbr);
				
				// accedemos a la lista de valores asociados a esa palabra en el diccionario
				// este valor lo asociamos a una referencia para que luego podamos modificar el valor
				// operacion[] -> coste logaritmo
				vector<int> & lineas = tabla[plbr]; 
				
				// si el vector es vacio o si la linea en la que estamos no coincide con la ultima linea del vector
				// insertamos el valor de la linea actual al vector
				if (lineas.empty() ||i != lineas.back()) {
					// modificar el verctor -> coste constante
					lineas.push_back(i);
				}
			}
			// leemos la siguiente palabra
			ss >> plbr;
		}
	}
	
	// recorremos para cada palabra del diccionario todos los valores almacenados en el vector asociado a esa palabra
	for (map<palabra, vector<int>>::iterator it = tabla.begin(); it != tabla.end(); ++it) {
		cout << it->first << ' ';
		for (size_t i = 0; i < it->second.size(); i++) {
			cout << it->second[i] << ' ';
		}
		cout << endl;
	}

	cout << "---" << endl;
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