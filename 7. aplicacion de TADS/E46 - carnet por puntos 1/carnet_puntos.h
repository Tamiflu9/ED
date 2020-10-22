#ifndef carnet_puntos_h
#define carnet_puntos_h

#include <string>
#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <vector>

using namespace std;

int const MAX = 15;

using dni = string;
using puntos = int;

class carnet_puntos {
private:
	unordered_map<dni, puntos> autoescuela;
	vector<puntos> conductores_conNpuntos;

public:

	carnet_puntos(): conductores_conNpuntos(MAX+1, 0) { };

	// O(1)
	// coste constante ya que insertar en un unordered_map es de coste constante
	// sumar 1 a una componente del vector tambien es constante
	void nuevo(dni const& dni_conductor){
		auto it = autoescuela.insert({dni_conductor, 15});

		if (!it.second){
			throw domain_error("ERROR: Conductor duplicado");
		}
		
		conductores_conNpuntos[15]++;
	}

	// O(1)
	// coste constante ya que buscar en un unordered_map es constante
	// operar y consultar con una componente del vector tambien es constante
	void quitar(dni const&  dni_conductor, puntos const&  puntos_carnet) {
		auto conductor = autoescuela.find(dni_conductor);
		if (conductor != autoescuela.end()) {
			if (conductor->second < puntos_carnet) {
				--conductores_conNpuntos[conductor->second];
				conductor->second = 0;
				++conductores_conNpuntos[conductor->second];
			}
			else {
				--conductores_conNpuntos[conductor->second];
				conductor->second -= puntos_carnet;
				++conductores_conNpuntos[conductor->second];
			}
		}
		else {
			throw domain_error("ERROR: Conductor inexistente");
		}
	}

	// O(1)
	// coste constante ya que buscar en un unordered_map es constante
	int const &consultar(dni const&  dni_conductor) const{
		auto conductor = autoescuela.find(dni_conductor);
		if (conductor == autoescuela.end()) {
			throw domain_error("ERROR: Conductor inexistente");	
		}
		else {
			return conductor->second;
		}
	}

	// O(1)
	// coste constante ya que consultar una componente del vector es constate
	int cuantos_con_puntos(puntos const&  puntos_carnet) const{
		if (puntos_carnet > MAX) {
			throw domain_error("ERROR: Puntos no validos");
		}
		else {
			return conductores_conNpuntos[puntos_carnet];
		}
	}
};

#endif // !carnet_puntos_h
