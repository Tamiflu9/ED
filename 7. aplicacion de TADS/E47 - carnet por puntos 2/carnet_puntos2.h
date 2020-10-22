#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int const MAX = 15;

using dni = string;
using puntos = int;

class carnet_puntos {
private:
	vector<list<dni>> cuantos;
	unordered_map<dni, pair<puntos,list<dni>::iterator>> autoescuela;
	
public:

	carnet_puntos() : cuantos(MAX + 1) { };

	// O(1)
	// 
	void nuevo(dni const& dni_conductor) {
		if (autoescuela.count(dni_conductor) > 0) {
			throw domain_error("ERROR: Conductor duplicado");
		}
		else {
			cuantos[MAX].push_front(dni_conductor);
			autoescuela.insert({dni_conductor, {MAX, cuantos[MAX].begin()}});
		}
	}

	// O(1)
	//
	void quitar(dni const&  dni_conductor, puntos puntos_carnet) {
		auto it = autoescuela.find(dni_conductor);
		if (it == autoescuela.end()) {
			throw domain_error("ERROR: Conductor inexistente");
		}
		int nuevosPuntos = max(0, it->second.first - puntos_carnet);
		if (it->second.first != nuevosPuntos) {
			cuantos[it->second.first].erase(it->second.second);
			cuantos[nuevosPuntos].push_front(dni_conductor);
			it->second.first = nuevosPuntos;
			it->second.second = cuantos[nuevosPuntos].begin();
		}
	}

	void recuperar(dni const& dni_conductor, puntos puntos_carnet) {
		auto it = autoescuela.find(dni_conductor);
		if(it == autoescuela.end()) {
			throw domain_error("ERROR: Conductor inexistente");
		}
		int nuevosPuntos = min(MAX, it->second.first+puntos_carnet);
		if (it->second.first != nuevosPuntos) {
			cuantos[it->second.first].erase(it->second.second);
			cuantos[nuevosPuntos].push_front(dni_conductor);
			it->second.first = nuevosPuntos;
			it->second.second = cuantos[nuevosPuntos].begin();
		}
	}

	// O(1)
	// 
	int consultar(dni const& dni_conductor) {
		auto it = autoescuela.find(dni_conductor);
		if (it == autoescuela.end()) {
			throw domain_error("ERROR: Conductor inexistente");
		}
		return it->second.first;
	}

	// O(1)
	//
	int cuantos_con_puntos(puntos puntos_carnet) {
		if (0 <= puntos_carnet && puntos_carnet <= MAX) {
			return cuantos[puntos_carnet].size();
		}
		else {
			throw domain_error("ERROR: Puntos no validos");
		}
	}

	list<dni>& lista_por_puntos(puntos puntos_carnet) {
		if (0 <= puntos_carnet && puntos_carnet <= MAX) {
				return cuantos[puntos_carnet];			
		}
		else {
			throw domain_error("ERROR: Puntos no validos");
		}
	}
};

#endif // !carnet_puntos_h
