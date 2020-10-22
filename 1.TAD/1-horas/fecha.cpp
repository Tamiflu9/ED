#include <iostream > 
#include <fstream >
#include "Fecha.h"

bool resuelveCaso() { 
	int d1,m1,a1,d2,m2,a2; 
	std::cin >> d1; 
	if (!std::cin) 
		return false;
	std::cin >> m1 >> a1; 
	std::cin >> d2 >> m2 >> a2; 

	try { 
		Fecha fActual(d1,m1,a1); 
		Fecha fVacaciones(d2,m2,a2); 
		std::cout << fVacaciones.numDias(fActual)<< '\n'; 
	} catch (std::invalid_argument & ia) { 
		std::cout << ia.what() << '\n'; 
	} 
	return true;
}

int main() { 
#ifndef DOMJUDGE 
	std::ifstream in("datos.txt"); 
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
//save old buf and redirect std::cin to casos.txt 
#endif
	
	//Resolvemos todos los casos
	while (resuelveCaso()) {

	} 

#ifndef DOMJUDGE 
// para dejar todo como estaba al principio 
	std::cin.rdbuf(cinbuf); 
	system("PAUSE"); 
#endif 
	return 0; 
}
