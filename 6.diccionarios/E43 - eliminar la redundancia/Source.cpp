// Nombre del alumno: Tamara Huertas Smolis
// Usuario del Juez: A78

/*
 Para resolver el problema usamos un diccionario sin orden (unorder_map) en el que guardamos los valores de los numeros como claves 
 y como valor asociado a ese numero, la cantidad de veces que aparece en la lista.
 El diccionario no necesita orden ya que la salida se pide ordenada por orden de aparicion.
 Tendremos un vector en el que guardamos los numeros segun van apareciendo en el texto para conservar el orden de entrada.

 Costes:
	el coste de la operacion empty() para ver si la tabla esta vacia es constante.
	el coste de la operacion insert() para insertas un elemento en la tabla es constante.
	el coste de la operacion find() que obtiene un iterador a una clave concreta de la tabla tiene coste constante.

	el coste de la opracion push_back() para insertar un elemento en el vector es constante.

1. El coste de crear la tabla es del orden de k (tamaño de la tabla), porque se trata de un diccionario sin orden.
2. El coste del bucle de lectura es O(n), siendo n el tamaño de la lista de numeros.
3. El coste del bucle de salida de datos es O(n), ya que tenemos un iterador que recorre todo el vector mediante un bucle for. 
   En cada vuelta del bucle se accede a la componente del vector y a la tabla. Ambas acciones tienen coste constante. 
   El coste de escribir los datos es constante.

-> Los costes se producen de forma secuencial, por lo que el coste final es el maximo de todos ellos.
   COSTE: O(max(n, k)) siendo n el tamaño de la lista de numeros y k el tamaño de la tabla.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>

using numero = int;
using numApariciones = int;

bool resuelveCaso() {
	// para mentener el orden de entrada
	std::vector<numero> lista_numeros;
	std::unordered_map<numero, numApariciones> dic;
	int N, n;
	std::cin >> N;

	if (!std::cin)
		return false;

	for (int i = 0; i < N; i++) {
		std::cin >> n;
		
		// si la tabla esta vacia o el numero leido no se encunetra, añadimos dicho numero a la tabla y al vector
		// en caso contrario sumamos 1 a la cantidad de veces que aparece ese numero en la lista
		if (dic.empty() || dic.count(n) == 0) {
			dic.insert(std::pair<numero, numApariciones>(n, 1));
			lista_numeros.push_back(n);
		}
		else {
			std::unordered_map<numero, numApariciones>::iterator it = dic.find(n);
			it->second= it->second + 1;
		}
	}

	// muestra la lista de numero ordenada en el vector por orden de aparicion
	for (size_t i = 0; i < lista_numeros.size(); i++) {
		std::unordered_map<numero, numApariciones>::iterator iter = dic.find(lista_numeros[i]);
		std::cout << iter->first << ' ' << iter->second << std::endl;
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