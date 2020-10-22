#ifndef autoes
#define autoes

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
/*
tenemos dos diccionarios no ordenados:
-> uno donde las claves son alumnos y el valor asociado un par que cuenta con el profesor y la nota de ese alumno
-> otro donde la clave son los profesores y como valor asociado es un conjunto ordenado ya que necesitamos
	los alumnos ordenados alfabeticamente para imprimirlos en la operacion de 'examen'
*/

using namespace std;

using alumno = string;
using profesor = string;
using nota = int;

class autoescuela {
private:
	unordered_map<alumno, pair<profesor, nota>> alumnos;
	unordered_map<profesor, set<alumno>> profesores;

public:

	// O(log n) insertar y eliminar en un conjunto ordenado es de coste logaritmo
	void alta(string const& a, string const& p) {
		auto it = alumnos.find(a);

		if (it == alumnos.end()) {
			alumnos.insert({ a, {p,0} });
			profesores[p].insert(a);
		}
		else {
			profesores[it->second.first].erase(a);
			it->second.first = p;
			profesores[p].insert({ a });
		}
	}

	// O(1)
	bool es_alumno(string const& a, string const& p) {
		auto it = alumnos.find(a);

		if (it != alumnos.end() && it->second.first == p) {
			return true;
		}
		else {
			return false;
		}
	}

	// O(1)
	int puntuacion(string const& a) {
		auto it = alumnos.find(a);
		if (it == alumnos.end()) {
			throw domain_error("ERROR");
		}
		else {
			return it->second.second;
		}
	}

	// O(1)
	void actualizar(string const& a, int n) {
		auto it = alumnos.find(a);
		if (it == alumnos.end()) {
			throw domain_error("ERROR");
		}
		else {
			it->second.second += n;
		}
	}

	// O(n) n es el numero de alumnos del profesor
	vector<string> examen(string const& profe, int n) {
		vector<string> l;
		auto it = profesores.find(profe);
		if (it != profesores.end()) {
			auto s = it->second;
			for (auto i = s.begin(); i != s.end(); ++i) {
				if (alumnos.at(*i).second >= n) {
					l.push_back(*i);
				}
				
			}
		}
		return l;
	}

	// O(log n) eliminar en un conjunto ordenado es de coste logaritmico
	void aprobar(string const& a) {
		auto it = alumnos.find(a);

		if (it != alumnos.end()) {
			string p = it->second.first;
			
			profesores[p].erase(a);
			
			alumnos.erase(it);
		}
		else {
			throw domain_error("ERROR");
		}
	}
};

#endif // !autoes
