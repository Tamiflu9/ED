#include <iostream> 
#include <fstream> 
#include <set>

bool resuelveCaso() { 
// Lectura de datos 
	int numGrupos; 
	std::cin >> numGrupos; 
	if (numGrupos == 0) 
		return false; 
	std::string anfitrion; 
	std::cin >> anfitrion; 
	// Anade al anfitrion al conjunto 
	std::set<std::string > s; 
	s.insert(anfitrion); 
	// Lee cada uno de los grupo. Si el conocido esta en el 
	// grupo a~nade a los miembros al grupo, en caso contrario 
	// debe leer los nombres de los integrantes del grupo antes 
	// de poder tratar al siguiente grupo 
	for (int i = 0; i < numGrupos; ++i) { 
		std::string conocido; 
		int numMiembros; 
		std::cin >> conocido >> numMiembros; 
		if (s.find(conocido) == s.end()) { 
			for (int j = 0; j < numMiembros; ++j) { 
				std::string aux; std::cin >> aux; 
			} 
			std::cout << "NO\n"; 
		} else { 
			std::cout << "SI\n"; 
			for (int j = 0; j < numMiembros; ++j) { 
				std::string aux; std::cin >> aux; s.insert(aux); 
			} 
		} 
	} 
	for (std::string const& i : s) 
		std::cout << i << '\n'; 
	std::cout << "---\n"; 
	return true; 
}

int main() { 
// Para la entrada por fichero. 
#ifndef DOMJUDGE 
	std::ifstream in("datos.txt"); 
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt 
#endif 
	while (resuelveCaso()){ 

	} 
// Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio 
	std::cin.rdbuf(cinbuf); 
	system("PAUSE"); 
#endif
	return 0;
}