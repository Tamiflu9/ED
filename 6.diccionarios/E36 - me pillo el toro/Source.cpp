// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>

using alumno = std::string;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	std::map <alumno, int> dic;
	int n; 
	int x;
	std::string al, nota;
	std::cin >> n;

	if (n == 0)
		return false;
	
	// para cada alumno 
	while (n > 0) {
		std::cin.ignore();
		std::getline(std::cin, al);
		std::cin >> nota;
		// comprobamos que nota tiene, si positiva o negativa
		if (nota == "CORRECTO") x = 1;
		if (nota == "INCORRECTO") x = -1;
		// miramos si el alumno está:
		// en caso afirmativo sumamos la nueva nota
		// en caso negativo insertamos el alumno
		if (dic.count(al) > 0) {
			std::map<alumno, int>::iterator it = dic.find(al);
			it->second += x;
		}
		else {
			dic.insert(std::pair<alumno, int>(al, x));
		}
		n--;
	}

	// imprimos las notas de los alumnos si son distintas a 0
	for (std::map<alumno, int>::iterator i = dic.begin(); i != dic.end(); ++i) {
		if (i->second != 0) {
			std::cout << i->first << ", " << i->second << std::endl;
		}
	}
	
	std::cout << "---" << std::endl;
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