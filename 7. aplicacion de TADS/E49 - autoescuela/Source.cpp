// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include "Header.h"

bool resuelveCaso() {
	// leer los datos de la entrada

	autoescuela autos;
	string linea;

	getline(cin, linea);

	if (!std::cin)
		return false;

	while (linea != "FIN") {

		stringstream ss(linea);
		string operacion;
		ss >> operacion;

		if (operacion == "alta") {
			string a, p;
			ss >> a >> p;
			try {
				autos.alta(a,p);
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "es_alumno") {
			string a, p;
			ss >> a >> p;
			try {
				if (autos.es_alumno(a,p)) {
					cout << a << " es alumno de " << p << endl;
				}
				else {
					cout << a << " no es alumno de " << p << endl;
				}
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "puntuacion") {
			string a; int p;
			ss >> a;
			try {
				p = autos.puntuacion(a);
				cout << "Puntuacion de " << a << ": " << p << endl;
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "actualizar") {
			string a; int n;
			ss >> a >> n;
			try {
				autos.actualizar(a,n);
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "examen") {
			string p;  int n;
			ss >> p >> n;
			try {
				vector<string> l = autos.examen(p,n);
				cout << "Alumnos de " << p << " a examen: " << endl;
				for (size_t i = 0; i < l.size(); i++) {
					cout << l[i] << endl;
				}
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "aprobar") {
			string a;
			ss >> a;
			try {
				autos.aprobar(a);
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		getline(cin, linea);
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