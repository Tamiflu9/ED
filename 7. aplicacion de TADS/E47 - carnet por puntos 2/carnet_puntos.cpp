// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include "carnet_puntos2.h"

bool resuelveCaso() {
	// leer los datos de la entrada
	
	carnet_puntos autoescuela;
	string linea;

	getline(cin, linea);

	if (!std::cin)
		return false;

	while (linea != "FIN") {

		stringstream ss(linea);
		string operacion;
		ss >> operacion;

		if (operacion == "nuevo") {
			string dni;
			ss >> dni;
			try {
				autoescuela.nuevo(dni);
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "quitar") {
			string dni; int puntos;
			ss >> dni >> puntos;
			try {
				autoescuela.quitar(dni, puntos);
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "recuperar") {
			string dni; int puntos;
			ss >> dni >> puntos;
			try {
				autoescuela.recuperar(dni, puntos);
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "consultar") {
			string dni;
			ss >> dni;
			try{
				int p = autoescuela.consultar(dni);
				cout << "Puntos de " << dni << ": "<< p << endl;
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "cuantos_con_puntos") {
			int puntos;
			ss >> puntos;
			try{
				int c = autoescuela.cuantos_con_puntos(puntos);
				cout << "Con " << puntos << " puntos hay " << c << endl;
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "lista_por_puntos") {
			int puntos;
			ss >> puntos;
			try {
				std::list<std::string> l = autoescuela.lista_por_puntos(puntos);
				cout << "Tienen " << puntos << " puntos: ";
				for (auto it = l.begin(); it != l.end(); ++it) {
					cout << *it << ' ';
				}
				cout << endl;
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