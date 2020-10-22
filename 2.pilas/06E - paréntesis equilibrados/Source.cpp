// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>

using namespace std;


bool resuelveCaso() {
	stack<char>pila;
	int i = 0;
	string cadena;

	getline(cin, cadena);

	// leer los datos de la entrada
	if (!std::cin)
		return false;

	while (i < cadena.size()) {
		// vamos metiendo en la pila solo los paréntesis abiertos
		if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') {
			pila.push(cadena[i]);
		}
		else {
			// si el caracter que viene es un parentesis que cierra
			// vamos mirando si coincide con su corespondiente parentesis abierto y este tiene que estar en la cima de la pila
			// y si es asi desapilamos y si no apilamos
			if (cadena[i] == ')') {
				if (!pila.empty() && pila.top() == '(') {
					pila.pop();
				}
				else {
					pila.push(cadena[i]);
				}
			}
			else if (cadena[i] == ']') {
				if (!pila.empty() && pila.top() == '[') {
					pila.pop();
				}
				else {
					pila.push(cadena[i]);
				}
			}
			else if (cadena[i] == '}') {
				if (!pila.empty() && pila.top() == '{') {
					pila.pop();
				}
				else {
					pila.push(cadena[i]);
				}
			}
		}
		i++;
	}
	// miramos si la pila esta vacia
	// si lo esta es que los parentesis son equilibrados
	if (pila.empty()) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}

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