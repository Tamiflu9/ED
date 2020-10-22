// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include "Header.h"


bool resuelveCaso() {
	// leer los datos de la entrada
	stack<Accidentes> pila;
	int n, dia, mes, ano, vict, i = 0;
	char c;

	cin >> n;

	if (!cin) {
		return false;
	}


	while (i < n) {
		cin >> dia >> c >> mes >> c >> ano >> vict;
		Fecha prim(dia, mes, ano);
		Accidentes acc(prim, vict);
		bool encontrado = false;

		while (!encontrado && !pila.empty()) {
			
			if (vict < pila.top().getVictimas()) {
				cout << pila.top().getActual() << endl;
				pila.push(acc);
				encontrado = true;
			}
			else {
				pila.pop();
			}
		}

		if (pila.empty()) {
			cout << "NO HAY" << endl;
			pila.push(acc);
		}
		
		++i;
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