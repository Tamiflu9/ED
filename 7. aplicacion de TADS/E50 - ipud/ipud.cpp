// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

#include "ipud.h"

bool resuelveCaso() {
	// leer los datos de la entrada

	iPud ipud;
	string linea;

	getline(cin, linea);

	if (!std::cin)
		return false;

	while (linea != "FIN") {

		stringstream ss(linea);
		string operacion;
		ss >> operacion;

		if (operacion == "addSong") {
			string s, a; int d;
			ss >> s >> a >> d;
			try {
				ipud.addSong(s,a,d);
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "addToPlaylist") {
			string s;
			ss >> s;
			try {
				ipud.addToPlayList(s);
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "current") {
			try {
				string s = ipud.current();
				cout << s << endl;
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "play") {
			try {
				string s = ipud.play();
				cout << "Sonando " + s << endl;
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "totalTime") {
			try {
				int d = ipud.totalTime();
				cout << "Tiempo total " << d << endl;
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "recent") {
			int n;
			ss >> n;
			try {
				list<string> l = ipud.recent(n);
				cout << "Las "; cout << l.size(); cout << " mas recientes" << endl;
				for (auto it = l.begin(); it != l.end(); ++it) {
					cout << "    "<< *it << endl;
				}
			}
			catch (domain_error &de) {
				cout << de.what() << endl;
			}
		}
		else if (operacion == "deleteSong") {
			string s;
			ss >> s;
			try {
				ipud.deleteSong(s);
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