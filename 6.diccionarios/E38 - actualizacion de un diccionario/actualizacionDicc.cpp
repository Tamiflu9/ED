// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using letra = std::string;
using valor = std::string;

void resuelveCaso(map<letra, valor> const& viejo, map<letra, valor> const& nuevo) {
	vector<letra> anadidos; // para meter  las claves de los elementos queno estaban en el diccionario viejo
	vector<letra> eliminados; // para meter las claves que estaban en el diccionario viejo pero no en el nuevo
	vector<letra> modificados; // para meter los valores de las claves que estan en los diccionarios y que han cambiado

	std::map<letra, valor>::iterator ant = viejo.begin(); // para el dicionario viejo
	std::map<letra, valor>::iterator act = nuevo.begin(); // para el diccionario nuevo

	while (ant != viejo.end() && act != nuevo.end()) {

		// si el elemento del diccionario viejo es menor, no esta en el dicionario nuevo
		// se ha eliminado
		if (ant->first < act->first) {
			
			eliminados.push_back(ant->first);
			++ant;
		}
		// si el elemento del diccionario nuevo es menor, no esta en el diccionario viejo
		// se ha añadido
		else if (ant->first > act->first) {
			anadidos.push_back(act->first);
			++act;
		}
		// si los elementos son igules, miramos el valor
		// por si se ha modificado
		else if (ant->first == act->first) {
			if (ant->second != act->second) {
				modificados.push_back(ant->first);
			}
			++ant;
			++act;
		}
	}

	if (ant != viejo.end()) {
		while (ant != viejo.end()) {
			eliminados.push_back(ant->first);
			++ant;
		}
	}

	if (act != nuevo.end()) {
		while (act != nuevo.end()) {
			anadidos.push_back(act->first);
			++act;
		}
	}

	if (!anadidos.empty()) {
		cout << "+ ";
		for (size_t i = 0; i < anadidos.size(); i++) {
			cout << anadidos[i] << ' ';
		}
		cout << endl;
	}

	if (!eliminados.empty()) {
		cout << "- ";
		for (size_t i = 0; i < eliminados.size(); i++) {
			cout << eliminados[i] << ' ';
		}
		cout << endl;
	}

	if (!modificados.empty()) {
		cout << "* ";
		for (size_t i = 0; i < modificados.size(); i++) {
			cout << modificados[i] << ' ';
		}
		cout << endl;
	}

	if (modificados.empty() && anadidos.empty() && eliminados.empty()) {
		cout << "Sin Cambios" << endl;
	}

	cout << "---" << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int n; string c;
	cin >> n;
	getline(cin, c);

	for (int i = 0; i < n; ++i) {
		string cadena, cadena2;
		map<letra, valor> viejoDic;
		map<letra, valor> nuevoDic;

		getline(cin, cadena);
		getline(cin, cadena2);
		stringstream s1(cadena); // copia cadena en ss
		stringstream s2(cadena2);
		string letr; int val;
		s1 >> letr >> val;  // obtiene de s1 letra y valor
		while (s1) { // Mientras no se acabe la linea
			viejoDic[letr] = val;
			s1 >> letr >> val;
		}

		s2 >> letr >> val;
		while (s2) {
			nuevoDic[letr] = val;
			s2 >> letr >> val;
		}

		resuelveCaso(viejoDic, nuevoDic);
	}

	
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
