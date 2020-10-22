
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)

// Tamara Huertas Smolis (A78)

#include <iostream>               
#include <fstream>               
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
/*

Para la solucion del problema hacemos un unordered_map ya que la salida tiene que estar ordenada segun el ordene que te
van pidiendo los momentos del sensor. Usamos como clave de la tabla el nombre del sensor y como valor un vector que va guardando
las horas del sensor en orden, ya que te las proporcionan asi los datos de entrada.

Costes:

crear un unordered_map tiene coste lineal respecto al tamaño de la tabla. O(k)
el primer bucle tiene coste O(N) siendo N el numero de sensores que leo ya que insertar tiene coste constante,
 la operacion insert tambien y la operacion end tambien.
 
el segundo bucle tiene conste O(M) siendo M el numero de sesores a consultar ya que las operaciones de find, end,
 consultar el tamaño del vector y el operador [] tiene conste constante al ser una tabal de listas pequeñas

 Coste final O(max(N,M,k))

*/

using sensor = string;
using momento = string;


bool resuelveCaso() {
	
	unordered_map <sensor, vector<momento>> sensores;
	vector<momento> horas;
	string s; string m;
	int N, M, t;
	cin >> N >> M;
	if (!cin)
		return false;
	
	for (int i = 0; i < N; i++) {
		
		cin >> s >> m;
		sensores[s].push_back(m);
	}

	for (int i = 0; i < M; i++) {

		cin >> s >> t;
		auto it = sensores.find(s);
		if (it != sensores.end()) {
			if (it->second.size() >= t) {
				cout << it->second[t - 1] << ' ';
			}
			else {
				cout << "-- ";
			}
		}
		else {
			cout << "-- ";
		}
	}
	cout << endl;
	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
